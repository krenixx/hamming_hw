#include "hamming.h"
#include <iostream>

std::vector<uint8_t> Encode::HammingEncode(std::vector<uint8_t> bits, size_t m, size_t n) {
    std::vector<uint8_t> result;
    result.resize(n);
    
    size_t index = 0;
    for (int pos = 0; pos < n; pos++) {
        if ((pos & (pos + 1)) != 0) {
            result[pos] = bits[index++];
        }
    }
    
    for (int p = 1; p <= n; p *= 2) {
        uint8_t parity = 0;
        for (int pos = 0; pos < n; pos++) {
            if (((pos + 1) & p) != 0) {
                parity ^= result[pos];
            }
        }
        result[p - 1] = parity;
    }
    
    return result;
}

std::vector<uint8_t> Decode::HammingDecode(std::vector<uint8_t> bits, size_t n) {
    std::vector<uint8_t> result;
    uint8_t syndrome = 0;
    for (int p = 1; p <= n; p *= 2) {
        uint8_t parity = 0;
        for (int pos = 0; pos <= n; pos++) {
            if (((pos + 1) & p) != 0) {
                parity ^= bits[pos];
            }
        }
        if (parity != 0) {
            syndrome |= p;
        }
    }

    if (syndrome > 0 && syndrome <= n) {
        bits[syndrome - 1] ^= 1;
    }

    for (int pos = 0; pos < n; pos++) {
        if ((pos & (pos + 1)) != 0) {
            result.push_back(bits[pos]);
        }
    }

    return result;
}

bool Valid::IsValid(std::vector<uint8_t> bits, size_t n) {
    for (int p = 1; p <= n; p *= 2) {
        uint8_t parity = 0;
        for (int pos = 0; pos < n; pos++) {
            if (((pos + 1) & p) != 0) {
                parity ^= bits[pos];
            }
        }
        if (parity != 0) {
            return false;
        }
    }

    return true;

}
