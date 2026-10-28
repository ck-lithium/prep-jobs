#pragma once

#include <string>
#include <vector>

#include "pull_request.h"
#include "team.h"

// Assigns reviewers to pull requests (PRs) and tracks approvals and merges.
//
// Rules:
//   - PR IDs start at 1 and are never reused, even after a PR is merged.
//   - A PR that changes fewer than 200 lines needs 1 approval; a PR that
//     changes 200 lines or more needs 2. A PR gets one reviewer per approval
//     it needs.
//   - Only assigned reviewers can approve, and each reviewer's approval counts once.
//   - A PR can be merged once it has all the approvals it needs. Merging
//     removes it from the open list and frees its reviewers.
class ReviewService {
public:
    explicit ReviewService(const Team& team);

    // Opens a PR, assigns its reviewers and returns its ID.
    // Throws std::invalid_argument if linesChanged is not positive.
    int open(const std::string& author, const std::string& title, int linesChanged);

    // Records an approval. Throws std::invalid_argument if `reviewer` is not
    // assigned to the PR, and std::out_of_range if there is no such open PR.
    void approve(int prId, const std::string& reviewer);

    // Merges an approved PR. Throws std::logic_error if it isn't approved yet,
    // and std::out_of_range if there is no such open PR.
    void merge(int prId);

    // The open PR with this ID. Throws std::out_of_range if there is none.
    const PullRequest& get(int prId) const;

    // IDs of all open PRs, in ascending order.
    std::vector<int> openIds() const;

    // Audit log: IDs of merged PRs, in the order they were merged.
    const std::vector<int>& mergedIds() const;

    const Team& team() const;

private:
    static constexpr int kLargePrLines = 200;

    int nextId() const;
    int requiredApprovals(const PullRequest& pr) const;
    PullRequest& find(int prId);

    Team team_;
    std::vector<PullRequest> open_;  // in the order they were opened
    std::vector<int> merged_;
};
