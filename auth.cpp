#include "auth.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>
#include <random>
#include <cstdlib>


bool authenticate(const std::string& user, const std::string& pass) {
    std::ifstream file("users.txt");
    std::string u, salt, stored_hash;

    while (file >> u >> salt >> stored_hash) {
        if (u == user ) {
            std::string input_hash = sha256(salt + pass);

            std::cout << "Stored hash: " << stored_hash << std::endl;
            std::cout << "Input  hash: " << input_hash << std::endl;

            return input_hash == stored_hash;
        }
    }
    return false;
}

void sign_up() {
    std::string user, pass;
    std::cout << "Create username: ";
    std::cin >> user;
    std::cout << "Create password: ";
    std::cin >> pass;

    std::string salt = generate_salt();
    std::string hashed = sha256(salt + pass);

    std::ofstream file("users.txt", std::ios::app);
    system("openssl enc -aes-256-cbc -salt -in users.txt -out users.enc -pass pass:yourMasterPassword");
    system("rm users.txt");
    file << user << " " << salt << " " << hashed << std::endl;
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

// Generate random salt
std::string generate_salt(size_t length) {
    static const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string salt;
    std::default_random_engine rng(std::random_device{}());
    std::uniform_int_distribution<> dist(0, sizeof(charset) - 2);
    for (size_t i = 0; i < length; ++i) {
        salt += charset[dist(rng)];
    }
    return salt;
}

// Hash with SHA-256
std::string sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);
    std::ostringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    return ss.str();
}
