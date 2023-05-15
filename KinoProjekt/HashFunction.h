#include <openssl/sha.h>
#include <string>

class HashFunction {
public:
    static std::string hashPassword(const std::string& password) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, password.c_str(), password.length());
        SHA256_Final(hash, &sha256);

        std::string hashedPassword;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            hashedPassword += toHex(hash[i]);
        }
        return hashedPassword;
    }

private:
    static std::string toHex(unsigned char c) {
        char hex[3];
        sprintf(hex, "%02x", c);
        return std::string(hex);
    }
};
