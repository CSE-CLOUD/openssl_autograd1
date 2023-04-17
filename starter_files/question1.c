#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <openssl/sha.h>

void generate_sha256_hash(const char *message, unsigned char *hash) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message, strlen(message));
    SHA256_Final(hash, &sha256);
}

bool compare_hashes(const unsigned char *hash1, const unsigned char *hash2) {
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        if (hash1[i] != hash2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    const char *message = "Hello, world!";
    const unsigned char known_hash[SHA256_DIGEST_LENGTH] = {
        0x75, 0x07, 0x25, 0x6a, 0xe7, 0x73, 0xb6, 0x06,
        0x2d, 0x53, 0x7b, 0xa6, 0xf0, 0x7d, 0x9c, 0x24,
        0x6b, 0xaf, 0xe6, 0x30, 0xc2, 0x91, 0xc6, 0x84,
        0xc1, 0x6e, 0x7a, 0x8d, 0x79, 0xd1, 0x61, 0x4b
    };
    
    unsigned char hash[SHA256_DIGEST_LENGTH];
    generate_sha256_hash(message, hash);

    if (compare_hashes(hash, known_hash)) {
        printf("SHA-256 hash generated correctly.\n");
        return 0; // Success
    } else {
        printf("SHA-256 hash is incorrect.\n");
        return 1; // Failure
    }
}
