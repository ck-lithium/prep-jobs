#include <stdexcept>
#include <string>
#include <vector>

#include "minitest.hpp"
#include "review_service.h"

namespace {

ReviewService makeService() { return ReviewService(Team({"alice", "bob", "carol", "dave"})); }

}  // namespace

TEST(Open, FirstPrsGetIdsOneAndTwo) {
    ReviewService service = makeService();
    EXPECT_EQ(service.open("alice", "Add login page", 50), 1);
    EXPECT_EQ(service.open("bob", "Fix typo", 3), 2);
}

TEST(Open, RejectsEmptyPr) {
    ReviewService service = makeService();
    EXPECT_THROW(service.open("alice", "Nothing", 0), std::invalid_argument);
}

TEST(Reviewers, SmallPrGetsOneReviewerWhoIsNotTheAuthor) {
    ReviewService service = makeService();
    int id = service.open("bob", "Fix typo", 3);
    std::vector<std::string> expected = {"alice"};  // nobody has reviews yet, so alphabetical
    EXPECT_EQ(service.get(id).reviewers, expected);
}

TEST(Reviewers, LargePrGetsTwoReviewers) {
    ReviewService service = makeService();
    int id = service.open("alice", "New payment flow", 800);
    std::vector<std::string> expected = {"bob", "carol"};
    EXPECT_EQ(service.get(id).reviewers, expected);
}

TEST(Reviewers, ReviewsAreSpreadAcrossTheTeam) {
    ReviewService service = makeService();
    int first = service.open("alice", "Change 1", 10);
    int second = service.open("alice", "Change 2", 10);
    int third = service.open("alice", "Change 3", 10);
    std::vector<std::string> bob = {"bob"}, carol = {"carol"}, dave = {"dave"};
    EXPECT_EQ(service.get(first).reviewers, bob);
    EXPECT_EQ(service.get(second).reviewers, carol);
    EXPECT_EQ(service.get(third).reviewers, dave);
    EXPECT_EQ(service.team().activeReviews("bob"), 1);
}

TEST(Approve, OnlyAssignedReviewersCanApprove) {
    ReviewService service = makeService();
    int id = service.open("bob", "Fix typo", 3);  // reviewer: alice
    EXPECT_THROW(service.approve(id, "carol"), std::invalid_argument);
    EXPECT_THROW(service.approve(id, "bob"), std::invalid_argument);  // the author
}

TEST(Approve, SmallPrIsApprovedAfterOneApproval) {
    ReviewService service = makeService();
    int id = service.open("bob", "Fix typo", 3);
    service.approve(id, "alice");
    EXPECT_EQ(service.get(id).status, PrStatus::Approved);
}

TEST(Approve, PrOf200LinesNeedsTwoApprovals) {
    ReviewService service = makeService();
    int id = service.open("alice", "Refactor parser", 200);
    const std::vector<std::string> reviewers = service.get(id).reviewers;
    ASSERT_EQ(reviewers.size(), 2u);
    service.approve(id, reviewers[0]);
    EXPECT_EQ(service.get(id).status, PrStatus::Open);
    service.approve(id, reviewers[1]);
    EXPECT_EQ(service.get(id).status, PrStatus::Approved);
}

TEST(Merge, RequiresApproval) {
    ReviewService service = makeService();
    int id = service.open("bob", "Fix typo", 3);
    EXPECT_THROW(service.merge(id), std::logic_error);
}

TEST(Merge, RemovesPrAndFreesReviewers) {
    ReviewService service = makeService();
    int id = service.open("bob", "Fix typo", 3);  // reviewer: alice
    EXPECT_EQ(service.team().activeReviews("alice"), 1);
    service.approve(id, "alice");
    service.merge(id);
    EXPECT_EQ(service.openIds(), std::vector<int>{});
    std::vector<int> mergedLog = {id};
    EXPECT_EQ(service.mergedIds(), mergedLog);
    EXPECT_EQ(service.team().activeReviews("alice"), 0);
}
