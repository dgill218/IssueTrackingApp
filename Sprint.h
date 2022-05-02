#ifndef SPRINT_H
#define SPRINT_H
#include "Issue.h"
class Sprint {
    public:
        Sprint(int id, std::vector<Issue*> issueVect);
        ~Sprint();
        void removeIssue(int);
        void addIssue(Issue*);
        int getSprintId();
        std::vector<Issue*> getIssueList();
    private:
        // Date deadline
        std::vector<Issue*> issues;
        int sprintID;
};

#endif