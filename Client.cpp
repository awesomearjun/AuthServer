#include <iostream>

void login(std::string usernameArg, std::string passwordArg, bool newAccount) {
    if(newAccount) {
        // wow making a new register yayayyayaya
    } else {
        // finding out your password o-o
    }
}

int main() {
    std::string username;
    std::string password;
    std::string mode;

    std::cout << "Hello! Welcome to CoolManTheCool and Arj404's UPDATED login system in C++!" << std::endl; 

    std::cout << "Would you like to login, or register? (login/register)" << std::endl;
    std::cin >> mode;

    if(mode == "register") {
        std::cout << "Welcome! Enter a username: " << std::endl;
        std::cin >> username;

        std::cout << "Enter a password: " << std::endl;
        std:: cin >> password;

        login(username, password, true);
    } else if(mode == "login") {
        std::cout << "Welcome back! Enter your username: " << std::endl;
        std::cin >> username;

        std::cout << "Enter your password: " << std::endl;
        std:: cin >> password;

        login(username, password, false);
    }   
}
