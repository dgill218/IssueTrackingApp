#include "Sprint.h"

Sprint::Sprint(int id, std::vector<Issue*> issueVect) {
    sprintID = id;
    issues = issueVect;
}

Sprint::~Sprint() {}
void Sprint::removeIssue(int issueId) {
    for (int i = 0; i < issues.size(); i++) {
        if (issues.at(i)->getIssueId() == issueId) {
            issues.erase(issues.begin() + i);
        }
    }
}

void Sprint::addIssue(Issue* i) {
    issues.push_back(i);
}
int Sprint::getSprintId() {
    return sprintID;
}

std::vector<Issue*> Sprint::getIssueList() {
    return issues;
}

