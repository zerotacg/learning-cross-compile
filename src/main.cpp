#include <iostream>
#include <openssl/evp.h>
#include <openssl/rsa.h>

int main()
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << "Generating a Key" << std::endl;

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);

    return 0;
}
