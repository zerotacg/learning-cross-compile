#include <iostream>
#include <openssl/sha.h>

int main() {
    std::cout << "Creating ssl context" << std::endl;

    unsigned char hash[32];
    SHA256("my hash input", sizeof hash, hash);

    std::cout << "hash is: " << std::hex;
    for (const auto &e: hash) {
        std::cout << e;
    }
    std::cout << std::endl;

    return 0;
}
