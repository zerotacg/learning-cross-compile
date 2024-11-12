#include <iostream>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>

int main() {
    std::cout << "Creating ssl context" << std::endl;

    EVP_PKEY_CTX* context = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);

    if (context) {
        std::cout << "Context created" << std::endl;
        unsigned char hash[32];
        SHA256("my hash input", sizeof hash, hash);

        std::cout << "hash is: " << std::hex;
        for (const auto& e : hash) {
            std::cout << e;
        }
        std::cout << std::endl;
    } else {
        std::cerr << "Context could not be created" << std::endl;
    }

    return 0;
}
