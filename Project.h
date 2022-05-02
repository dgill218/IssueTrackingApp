#ifndef PROJECT_H
#define PROJECT_H
#include "Sprint.h"
#include "IssueTypeEnum.h"
#include <ctime>
#include <fstream>
#include <vector>

class Project {
    public:
        Project(std::vector<Issue*> todoList, std::vector<Sprint*> inProgressList, std::vector<Issue*> workDoneList,
                time_t deadlineDate, std::vector<std::string> userNameList);
        ~Project();
        void addIssue(Issue*);
        void deleteIssue(int);
        void writeData(std::fstream);
        void viewIssue(int);
        Issue* getIssue(int);
        void view();
        void moveIssue(int, IssueType);
        void moveIntoSprint(int, int);
        IssueType getIssueType(int);
    private:
        std::vector<Issue*> todo;
        std::vector<Sprint*> inProgress;
        std::vector<Issue*> workDone;
        time_t deadline; // change this
        std::vector<std::string> userNames;
};

#endif