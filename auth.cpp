#include "auth.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool authenticate(const std::string& user, const std::string& pass) {
    std::ifstream file("users.txt");
    std::string u, p;
    while (file >> u >> p) {
        if (u == user && p == pass) return true;
    }
    return false;
}

void sign_up() {
    std::string user, pass;
    std::cout << "Create username: ";
    std::cin >> user;
    std::cout << "Create password: ";
    std::cin >> pass;

    std::ofstream file("users.txt", std::ios::app);
    file << user << " " << pass << std::endl;
    std::cout << "Sign up successful!\n";
}

bool sign_in() {
    std::string user, pass;
    std::cout << "Username: ";
    std::cin >> user;
    std::cout << "Password: ";
    std::cin >> pass;

    if (authenticate(user, pass)) {
        std::cout << "Login successful!\n";
        return true;
    } else {
        std::cout << "Invalid credentials.\n";
        return false;
    }
}
