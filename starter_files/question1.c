#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <openssl/sha.h>

void generate_sha256_hash(const char *message, unsigned char *hash) {
  // TODO: Implement the function
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
    0x31, 0x5f, 0x5b, 0xdb, 0x76, 0xd0, 0x78, 0xc4,
    0x3b, 0x8a, 0xc0, 0x06, 0x4e, 0x4a, 0x01, 0x64,
    0x61, 0x2b, 0x1f, 0xce, 0x77, 0xc8, 0x69, 0x34,
    0x5b, 0xfc, 0x94, 0xc7, 0x58, 0x94, 0xed, 0xd3
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
