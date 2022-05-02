#ifndef ISSUE_H
#define ISSUE_H
#include <vector>
#include <iostream>
class Issue
{
public:
    Issue();
    ~Issue();
    int getIssueId();
    double getCompletionPercentage();
private:
    int issueId;
    std::string description;
    int priority;
    // Date createdDate;
    // Date deadline
    double completionPercentage;
};

#endif