#ifndef SYSTEM_H
#define SYSTEM_H
#include "Project.h"
#include "User.h"

class System {
    public:
        System(std::vector<Project*> projectList, std::vector<User*> userList);
        ~System();
        std::vector<User*> getUserList();
        std::vector<Project*> getProjectList();
        void createProject(Project*);
        void createUser(User*);
    private:
        std::vector<Project*> projects;
        std::vector<User*> users;
};


#endif