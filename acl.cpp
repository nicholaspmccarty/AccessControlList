#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>



struct User {
    std::string username;
    std::string password;
};

struct File {
    std::string file;
    std::string fileContent;

};

struct ACL {
  std::unordered_map<std::string, std::string> userPermissions;

};

void add_user(std::vector<User>& users, const std::string& name, const std::string& password) {
    users.push_back({name, password});
}

void remove_user(std::vector<User>& users, const std::string& name, const std::string& password) {
    int counter = 0;
    for (User& k : users) {
        if (k.username == name && k.password == password) {
            users.erase(users.begin() + counter);
            break; // exit the loop after removing the user
        }
        counter++;
    }
}

void displayUsers(std::vector<User> users) {
    for (User k : users) {
        std::cout << k.username << std::endl;
    }
}

int main() {
    std::vector<User> users;
    std::vector<File> files;
    // Testing add_user works properly. 
    add_user(users, "root", "hellothere");
    add_user(users, "user1", "password");
    add_user(users, "user2", "secret");
    add_user(users, "user3", "dolphin");
    displayUsers(users);
    remove_user(users, "root", "hellothere");
    displayUsers(users);




    return -1;
}