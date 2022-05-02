#include "System.h"

System::System(std::vector<Project *> projectList, std::vector<User *> userList) {
    projects = projectList;
    users = userList;
}

System::~System(){}

std::vector<User*> System::getUserList() {
    return users;
}
std::vector<Project*> System::getProjectList() {
    return projects;
}
void System::createProject(Project* p) {
    projects.push_back(p);
}
void System::createUser(User* u) {
    users.push_back(u);
}