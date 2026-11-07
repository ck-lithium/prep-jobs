#include "team.h"

#include <algorithm>
#include <stdexcept>

Team::Team(const std::vector<std::string>& names) {
    for (const std::string& name : names) members_.push_back({name, 0});
}

std::vector<std::string> Team::pickReviewers(const std::string& author, int count) {
    std::vector<Member> candidates;
    for (const Member& member : members_) {
        if (member.name != author) candidates.push_back(member);
    }

    std::sort(candidates.begin(), candidates.end(), [](const Member& a, const Member& b) {
        if (a.activeReviews != b.activeReviews) return a.activeReviews < b.activeReviews;
        return a.name < b.name;
    });

    std::vector<std::string> picked;
    for (Member& member : candidates) {
        if (static_cast<int>(picked.size()) == count) break;
        member.activeReviews++;
        picked.push_back(member.name);
    }
    return picked;
}

void Team::finishReviews(const std::vector<std::string>& reviewers) {
    for (const std::string& name : reviewers) {
        for (Member& member : members_) {
            if (member.name == name && member.activeReviews > 0) member.activeReviews--;
        }
    }
}

int Team::activeReviews(const std::string& name) const {
    for (const Member& member : members_) {
        if (member.name == name) return member.activeReviews;
    }
    throw std::out_of_range(name + " is not on the team");
}
