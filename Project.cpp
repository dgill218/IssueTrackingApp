#include "Project.h"

Project::Project(std::vector<Issue *> todoList, std::vector<Sprint *> inProgressList, std::vector<Issue *> workDoneList,
                 time_t deadlineDate, std::vector<std::string> userNameList) {
    todo = todoList;
    inProgress = inProgressList;
    workDone = workDoneList;
    deadline = deadlineDate;
    userNames = userNameList;
}

Project::~Project() {}

/**
 * Adds an issue to our project. For this method, it goes right int the to-do list.
 */
void Project::addIssue(Issue* i) {
    todo.push_back(i);
}

/**
 * Gets the category that the issue is in.
 */
IssueType Project::getIssueType(int issueId) {
    // Going through each issue in the to-do list.
    for (int i = 0; i < todo.size(); i++) {
        // Found issue, so delete it.
        if (todo.at(i)->getIssueId() == issueId) {
            return TODO;
        }
    }

    // Going through each issue in each sprint
    for (int i = 0; i < inProgress.size(); i++) {
        std::vector<Issue*> cur = inProgress.at(i)->getIssueList();
        for (int j = 0; j < cur.size(); j++) {
            // Found issue, so delete it.
            if (cur.at(j)->getIssueId() == issueId) {
                return IN_PROGESS;
            }
        }
    }

    // Going through each issue in the work done list.
    for (int i = 0; i < workDone.size(); i++) {
        // Found issue, so delete it.
        if (workDone.at(i)->getIssueId() == issueId) {
            return FINISHED;
        }
    }
}


/**
 * Deletes the issue with the given issue id.
 */
void Project::deleteIssue(int issueId) {
    IssueType iType = getIssueType(issueId);
    switch (iType) {
        case TODO:
            for (int i = 0; i < todo.size(); i++) {
                // Found issue, so delete it.
                if (todo.at(i)->getIssueId() == issueId) {
                    todo.erase(todo.begin() + i);
                    return;
                }
            }
            break;
        case IN_PROGESS:
            for (int i = 0; i < inProgress.size(); i++) {
                std::vector<Issue*> cur = inProgress.at(i)->getIssueList();
                for (int j = 0; j < cur.size(); j++) {
                    // Found issue, so delete it.
                    if (cur.at(j)->getIssueId() == issueId) {
                        cur.erase(cur.begin() + j);
                        return;
                    }
                }
            }
            break;
        case FINISHED:
            for (int i = 0; i < workDone.size(); i++) {
                // Found issue, so delete it.
                if (workDone.at(i)->getIssueId() == issueId) {
                    workDone.erase(workDone.begin() + i);
                    return;
                }
            }
            break;
    }
}

/**
 * Writes the data about a project to a file.
 */
void Project::writeData(std::fstream) {

}

/**
 * Prints out some information about an issue
 */
void Project::viewIssue(int issueId) {
    Issue* i = getIssue(issueId);
    std::cout << i->getCompletionPercentage() << std::endl;
}

/**
 * Returns the issue with the given issueId.
 */
Issue* Project::getIssue(int issueId) {
    IssueType iType = getIssueType(issueId);
    switch (iType) {
        case TODO:
            for (int i = 0; i < todo.size(); i++) {
                // Found issue, so delete it.
                if (todo.at(i)->getIssueId() == issueId) {
                    return todo.at(i);
                }
            }
            break;
        case IN_PROGESS:
            for (int i = 0; i < inProgress.size(); i++) {
                std::vector<Issue*> cur = inProgress.at(i)->getIssueList();
                for (int j = 0; j < cur.size(); j++) {
                    // Found issue, so delete it.
                    if (cur.at(j)->getIssueId() == issueId) {
                        return cur.at(j);
                    }
                }
            }
            break;
        case FINISHED:
            for (int i = 0; i < workDone.size(); i++) {
                // Found issue, so delete it.
                if (workDone.at(i)->getIssueId() == issueId) {
                    return workDone.at(i);
                }
            }
            break;
    }
}

void Project::view() {

}

/**
 * Moves the project with the given issue id to the given issueType.
 * This method does not move issue into springs.
 */
void Project::moveIssue(int issueId, IssueType issueType) {
    Issue* i = getIssue(issueId);

    if (getIssueType(issueId) == issueType) {
        std::cout << "Issue is already in this category!" << std::endl;
        return;
    }
    // Delete issue from current list
    deleteIssue(issueId);
    // Adding issue to new list.
    switch (issueType) {
        case TODO:
            todo.push_back(i);
            break;
        case FINISHED:
            workDone.push_back(i);
            break;
        default:
            break;
    }
}

/**
 * Moves the given issue with the corresponding issue id
 * into the sprint with the corresponding sprintId.
 */
void Project::moveIntoSprint(int issueId, int sprintId) {
    Issue* iss = getIssue(issueId);

    // Delete the issue from old spot
    deleteIssue(issueId);

    for (int i = 0; i < inProgress.size(); i++) {
        if (inProgress.at(i)->getSprintId() == sprintId) {
            // Found the sprint to add it to, move it in there.
            inProgress.at(i)->getIssueList().push_back(iss);
        }
    }
}


