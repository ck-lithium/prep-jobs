// HIDDEN TESTS: these stand in for the assessment's hidden tests.
// Don't read this file until you've finished the exercise.
#include <stdexcept>
#include <string>
#include <vector>

#include "minitest.hpp"
#include "review_service.h"

namespace {

ReviewService makeService() { return ReviewService(Team({"alice", "bob", "carol", "dave"})); }

void approveAll(ReviewService& service, int id) {
    const std::vector<std::string> reviewers = service.get(id).reviewers;
    for (const std::string& reviewer : reviewers) service.approve(id, reviewer);
}

}  // namespace

TEST(HiddenIds, NotReusedAfterTheNewestPrIsMerged) {
    ReviewService service = makeService();
    service.open("alice", "First", 10);
    int second = service.open("alice", "Second", 10);
    approveAll(service, second);
    service.merge(second);
    EXPECT_EQ(service.open("bob", "Third", 10), 3);
}

TEST(HiddenIds, MergeLogHasNoDuplicates) {
    ReviewService service = makeService();
    for (int i = 0; i < 5; i++) {
        int id = service.open("alice", "Change", 10);
        approveAll(service, id);
        service.merge(id);
    }
    std::vector<int> expected = {1, 2, 3, 4, 5};
    EXPECT_EQ(service.mergedIds(), expected);
}

TEST(HiddenIds, OpenIdsStayUniqueAfterMerges) {
    ReviewService service = makeService();
    int a = service.open("alice", "A", 10);
    int b = service.open("bob", "B", 10);
    approveAll(service, b);
    service.merge(b);
    int c = service.open("carol", "C", 10);
    std::vector<int> expected = {a, c};
    EXPECT_EQ(service.openIds(), expected);
    EXPECT_TRUE(c != b);
}

TEST(HiddenApprovals, SameReviewerApprovingTwiceCountsOnce) {
    ReviewService service = makeService();
    int id = service.open("alice", "Big change", 500);
    const std::string reviewer = service.get(id).reviewers[0];
    service.approve(id, reviewer);
    service.approve(id, reviewer);
    EXPECT_EQ(service.get(id).status, PrStatus::Open);
    EXPECT_THROW(service.merge(id), std::logic_error);
}

TEST(HiddenApprovals, BothReviewersInAnyOrder) {
    ReviewService service = makeService();
    int id = service.open("alice", "Big change", 500);
    const std::vector<std::string> reviewers = service.get(id).reviewers;
    ASSERT_EQ(reviewers.size(), 2u);
    service.approve(id, reviewers[1]);
    service.approve(id, reviewers[1]);
    EXPECT_EQ(service.get(id).status, PrStatus::Open);
    service.approve(id, reviewers[0]);
    EXPECT_EQ(service.get(id).status, PrStatus::Approved);
}

TEST(HiddenApprovals, Pr199LinesNeedsOneApproval) {
    ReviewService service = makeService();
    int id = service.open("alice", "Medium change", 199);
    ASSERT_EQ(service.get(id).reviewers.size(), 1u);
    approveAll(service, id);
    EXPECT_EQ(service.get(id).status, PrStatus::Approved);
}

TEST(HiddenReviewers, FreedReviewersArePickedAgain) {
    ReviewService service(Team({"alice", "bob", "carol"}));
    int first = service.open("alice", "First", 10);   // bob
    service.open("alice", "Second", 10);               // carol
    approveAll(service, first);
    service.merge(first);                              // bob is free again
    int third = service.open("alice", "Third", 10);
    std::vector<std::string> expected = {"bob"};
    EXPECT_EQ(service.get(third).reviewers, expected);
    EXPECT_EQ(service.team().activeReviews("bob"), 1);
    EXPECT_EQ(service.team().activeReviews("carol"), 1);
    EXPECT_EQ(service.team().activeReviews("alice"), 0);
}

TEST(HiddenReviewers, LoadIsCountedAcrossLargeAndSmallPrs) {
    ReviewService service = makeService();
    service.open("alice", "Big", 300);              // bob, carol
    int small = service.open("bob", "Small", 5);    // alice and dave have 0: alice
    std::vector<std::string> expected = {"alice"};
    EXPECT_EQ(service.get(small).reviewers, expected);
    int next = service.open("alice", "Small 2", 5); // bob 1, carol 1, dave 0: dave
    std::vector<std::string> expectedNext = {"dave"};
    EXPECT_EQ(service.get(next).reviewers, expectedNext);
}
