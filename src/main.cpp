#include <iostream>
#include <openssl/sha.h>

int main() {
    std::cout << "Creating ssl context" << std::endl;

    const std::string input = "my hash input";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    auto result = SHA256(input.c_str(), input.length(), hash);
    if (result == nullptr) {
        std::cerr << "error calculating hash" << std::endl;
    }

    std::cout << "hash is: " << std::hex;
    for (const auto &e: hash) {
        std::cout << e;
    }
    std::cout << std::endl;

    return 0;
}
