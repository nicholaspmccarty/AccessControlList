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
  std::unordered_map<std::string, std::unordered_map<std::string, std::string>> userPermissions;
  


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

void add_file(std::vector<File>& files, const std::string& name, const std::string& password) {
    files.push_back({name, password});
}

void remove_file(std::vector<File>& files, const std::string& name, const std::string& password) {
    int counter = 0;
    for (File& k : files) {
        if (k.file == name && k.fileContent == password) {
            files.erase(files.begin() + counter);
            break; // exit the loop after removing the user
        }
        counter++;
    }
}

void set_permissions(ACL& database,
                     const std::string& username, const std::string& filename,
                     const std::string& permissions) {
    database.userPermissions[username][filename] = permissions;
}

std::string get_permissions(const ACL& database,
                             const std::string& username, const std::string& filename) {
    auto userIt = database.userPermissions.find(username);
    if (userIt != database.userPermissions.end()) {
        auto fileIt = userIt->second.find(filename);
        if (fileIt != userIt->second.end()) {
            return fileIt->second;
        }
    }
    return ""; // Return an empty string if permissions are not found
}



void displayUsers(const std::vector<User>& users) {
    for (User k : users) {
        std::cout << k.username << std::endl;
    }
}


void displayItems(const std::vector<File>& users) {
    for (File k : users) {
        std::cout << k.file << std::endl;
    }
}

void queryPermissions(std::string username, std::vector<File> files, ACL acl) {
    
    for (File k : files) {
        if (get_permissions(acl, username, k.file) != "") {
            std::cout << '\t' << "-" << k.file << " : ";
            std::string temp = get_permissions(acl, username, k.file);
            std::cout << temp << std::endl;
        }
    }
}


void print_system(std::vector<User> users, std::vector<File> files, ACL acl) {
    std::cout << "ACCESS CONTROL LIST" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    for (User k : users) {
        std::cout << k.username << std::endl;
        std::cout << '\t' << "-password: " << k.password << std::endl;
        queryPermissions(k.username, files, acl);
    }
    std::cout << "FILES" << std::endl;
    for (File k : files) {    
        std::cout << '\t' << k.file << ":" << k.fileContent << std::endl;
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
  
    add_file(files, "file1", "pasta");
    add_file(files, "file2", "burgers");
    add_file(files, "file3", "fries");
    
    ACL database;
    
    set_permissions(database, "root", "file1", "read/write/execute/delete" );
    set_permissions(database, "root", "file2", "read/write/execute/delete" );
    set_permissions(database, "root", "file3", "read/write/execute/delete" );

    set_permissions(database, "user1", "file1", "read/execute" );
    set_permissions(database, "user1", "file2", "read/execute" );
    set_permissions(database, "user1", "file3", "read/execute" );

    set_permissions(database, "user2", "file1", "read/write/execute");
    set_permissions(database, "user3", "file3", "read/write/execute");
    print_system(users, files, database);
    std::string perms = get_permissions(database, "user1", "file3");

    // If you want to add, you need to create a member in each struct as shown above.


  


    return -1;
}