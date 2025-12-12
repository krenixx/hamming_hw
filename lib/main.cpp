#include "hamming.h"
#include <iostream>
#include <cstring>


std::vector<uint8_t> NormalizeBits(char* bits) {
    std::vector<uint8_t> result;
    for (int i = 0; bits[i] != '\0'; i++) {
        result.push_back(static_cast<uint8_t>(bits[i] - '0'));
    }
    return result;
}

void PrintVector(std::vector<uint8_t> result) {
    for (int i = 0; i < result.size(); i++) {
        std::cout << static_cast<int>(result[i]);
    }
    std::cout << '\n';
}

int main(int argc, char* argv[]) {
    size_t m = 0;
    size_t n = 0;
    if (strcmp(argv[1], "encode") == 0) {
        m = static_cast<size_t>(atoll(argv[2]));
        n = static_cast<size_t>(atoll(argv[3]));
        std::vector<uint8_t> bits = NormalizeBits(argv[4]);
        auto result = Encode::HammingEncode(bits, m, n);
        PrintVector(result);
        
    }
    else if (strcmp(argv[1], "decode") == 0) {
        n = static_cast<size_t>(atoll(argv[2]));
        std::vector<uint8_t> bits = NormalizeBits(argv[3]);
        auto result = Decode::HammingDecode(bits, n);
        PrintVector(result);

    }
    else if (strcmp(argv[1], "is_valid") == 0) {
        n = static_cast<size_t>(atoll(argv[2]));
        std::vector<uint8_t> bits = NormalizeBits(argv[3]);
        bool valid = Valid::IsValid(bits, n);
        std::cout << valid << '\n';
    }
    else {
        return 1;
    }

    
    return 0;
}