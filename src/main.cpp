#include <iostream>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <curl/curl.h>

int main()
{
    std::cout << "Curl Version" << LIBCURL_VERSION << std::endl;
    std::cout << "Creating ssl context" << std::endl;

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
    CURL *curl_easy_init();

    if(ctx) {
        std::cout << "Contex created" << std::endl;
    }

    return 0;
}
