#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <openssl/evp.h>
#include <openssl/aes.h>

int aes_encrypt(const unsigned char *plaintext, int plaintext_len, const unsigned char *key, const unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int len;
    int ciphertext_len;

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len);
    ciphertext_len = len;

    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int aes_decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, const unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    int len;
    int plaintext_len;

    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len);
    plaintext_len = len;

    EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

bool compare_strings(const unsigned char *str1, const unsigned char *str2, int length) {
    for (int i = 0; i < length; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    const unsigned char key[] = "01234567890123456789012345678901"; // 32-byte key
    const unsigned char iv[] = "0123456789012345"; // 16-byte IV
    const unsigned char plaintext[] = "Hello, world!";
    const int plaintext_len = strlen((const char *)plaintext);

    unsigned char ciphertext[1024];
    int ciphertext_len = aes_encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    unsigned char decrypted[1024];
    int decrypted_len = aes_decrypt(ciphertext, ciphertext_len, key, iv, decrypted);

    if (compare_strings(plaintext, decrypted, plaintext_len)) {
        printf("Decryption successful. The decrypted output matches the original plaintext.\n");
        return 0; // Success
    } else {
        printf("Decryption unsuccessful. The decrypted output does not match the original plaintext.\n");
        return 1; // Failure
    }
}
