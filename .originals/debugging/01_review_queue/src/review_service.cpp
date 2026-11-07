#include "review_service.h"

#include <algorithm>
#include <stdexcept>

ReviewService::ReviewService(const Team& team) : team_(team) {}

int ReviewService::open(const std::string& author, const std::string& title, int linesChanged) {
    if (linesChanged <= 0) throw std::invalid_argument("a PR must change at least one line");

    PullRequest pr;
    pr.id = nextId();
    pr.author = author;
    pr.title = title;
    pr.linesChanged = linesChanged;
    pr.reviewers = team_.pickReviewers(author, requiredApprovals(pr));
    open_.push_back(pr);
    return pr.id;
}

void ReviewService::approve(int prId, const std::string& reviewer) {
    PullRequest& pr = find(prId);
    bool assigned = std::find(pr.reviewers.begin(), pr.reviewers.end(), reviewer) != pr.reviewers.end();
    if (!assigned) {
        throw std::invalid_argument(reviewer + " is not a reviewer of PR " + std::to_string(prId));
    }
    pr.approvals++;
    if (pr.approvals >= requiredApprovals(pr)) pr.status = PrStatus::Approved;
}

void ReviewService::merge(int prId) {
    PullRequest& pr = find(prId);
    if (pr.status != PrStatus::Approved) {
        throw std::logic_error("PR " + std::to_string(prId) + " is not approved yet");
    }
    team_.finishReviews(pr.reviewers);
    merged_.push_back(pr.id);
    open_.erase(std::remove_if(open_.begin(), open_.end(),
                               [prId](const PullRequest& p) { return p.id == prId; }),
                open_.end());
}

const PullRequest& ReviewService::get(int prId) const {
    for (const PullRequest& pr : open_) {
        if (pr.id == prId) return pr;
    }
    throw std::out_of_range("no open PR with ID " + std::to_string(prId));
}

PullRequest& ReviewService::find(int prId) {
    return const_cast<PullRequest&>(get(prId));
}

std::vector<int> ReviewService::openIds() const {
    std::vector<int> ids;
    for (const PullRequest& pr : open_) ids.push_back(pr.id);
    std::sort(ids.begin(), ids.end());
    return ids;
}

const std::vector<int>& ReviewService::mergedIds() const { return merged_; }

const Team& ReviewService::team() const { return team_; }

int ReviewService::nextId() const {
    int highest = 0;
    for (const PullRequest& pr : open_) highest = std::max(highest, pr.id);
    return highest + 1;
}

int ReviewService::requiredApprovals(const PullRequest& pr) const {
    return pr.linesChanged > kLargePrLines ? 2 : 1;
}
