#pragma once

#include <ostream>
#include <string>
#include <vector>

enum class PrStatus { Open, Approved };

inline std::ostream& operator<<(std::ostream& out, PrStatus status) {
    return out << (status == PrStatus::Open ? "Open" : "Approved");
}

struct PullRequest {
    int id = 0;
    std::string author;
    std::string title;
    int linesChanged = 0;
    PrStatus status = PrStatus::Open;
    std::vector<std::string> reviewers;  // assigned when the PR is opened
    int approvals = 0;
};
