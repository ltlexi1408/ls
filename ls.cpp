#include <iostream>
#include <filesystem>
#include <algorithm>

#include <string>

void permissions(std::filesystem::perms p);

int main(int argc, char** argv){
    std::string path = ".";

    for(auto const& entry : std::filesystem::directory_iterator(path)){
        std::string file = entry.path().string();
        permissions(std::filesystem::status(entry).permissions());
        std:: cout << "\t";
        if(!entry.is_directory()){std::cout << entry.file_size();} else {std::cout << 4096;}
        std:: cout << "\t";
        std::cout << file.substr(2);
        std::cout << std::endl;
    }
    
    return 0;
}

void permissions(std::filesystem::perms p){
    auto show = [=](char op, std::filesystem::perms perm){
        std::cout << (std::filesystem::perms::none == (perm & p) ? '-' : op);
    };

    show('r', std::filesystem::perms::owner_read);
    show('w', std::filesystem::perms::owner_write);
    show('x', std::filesystem::perms::owner_exec);
    show('r', std::filesystem::perms::group_read);
    show('w', std::filesystem::perms::group_write);
    show('x', std::filesystem::perms::group_exec);
    show('r', std::filesystem::perms::others_read);
    show('w', std::filesystem::perms::others_write);
    show('x', std::filesystem::perms::others_exec);
}