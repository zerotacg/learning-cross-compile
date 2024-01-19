#include <iostream>
#include <openssl/evp.h>
#include <openssl/rsa.h>

int main() {
    std::cout << "Creating ssl context" << std::endl;

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);

    if (ctx) {
        std::cout << "Contex created" << std::endl;
    }

    return 0;
}
