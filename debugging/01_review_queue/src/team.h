#pragma once

#include <string>
#include <vector>

// The engineers who review code, and how many open reviews each one has.
class Team {
public:
    explicit Team(const std::vector<std::string>& names);

    // Picks `count` reviewers for a PR written by `author` and adds one active
    // review to each of them. Never picks the author. People with the fewest
    // active reviews go first; ties go to the name that is first alphabetically.
    std::vector<std::string> pickReviewers(const std::string& author, int count);

    // Called when a PR is merged: each of its reviewers has one review less.
    void finishReviews(const std::vector<std::string>& reviewers);

    // How many unmerged PRs `name` is reviewing.
    // Throws std::out_of_range for someone who is not on the team.
    int activeReviews(const std::string& name) const;

private:
    struct Member {
        std::string name;
        int activeReviews = 0;
    };
    std::vector<Member> members_;
};
