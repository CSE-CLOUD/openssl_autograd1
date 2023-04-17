#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/aes.h>

int aes_encrypt(const unsigned char *plaintext, int plaintext_len, const unsigned char *key, const unsigned char *iv, unsigned char *ciphertext) {
    // TODO: Implement the function
}

int aes_decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, const unsigned char *iv, unsigned char *plaintext) {
    // TODO: Implement the function
}

int main() {
    // TODO: Test your implementation
    return 0;
}
