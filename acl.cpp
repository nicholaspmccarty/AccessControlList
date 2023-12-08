#include <iostream>
#include <string>
#include <unordered_map>



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

void addUser(User& user, const std::string& userName, const std::string& passWord) {
    user.username = userName;
    user.password = passWord;
}


int main() {
    
    return -1;
}