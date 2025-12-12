#include <vector>
#include <iostream>
#include <cassert>
#include "../lib/hamming.h"
#include <ctime>

int main() {
    
    int count = 1;
    std::cout << "Lite tests:" << '\n';
    {
        std::vector<uint8_t> in = {1, 0, 1, 1};
        std::vector<uint8_t> wait = {0, 1, 1, 0, 0, 1, 1};

        auto encode = Encode::HammingEncode(in, 4, 7);
        auto decode = Decode::HammingDecode(encode, 7);
        bool valid = Valid::IsValid(encode, 7);
        assert(valid == 1);
        assert(decode == in);
        assert(encode == wait);

        std::cout << "Test " << count++ << " passed" << '\n';
    }

    {
        std::vector<uint8_t> in = {1};
        std::vector<uint8_t> wait = {1, 1, 1};

        auto encode = Encode::HammingEncode(in, 1, 3);
        auto decode = Decode::HammingDecode(encode, 3);
        bool valid = Valid::IsValid(encode, 3);
        
        assert(valid == 1);
        assert(decode == in);
        assert(encode == wait);
        std::cout << "Test " << count++ << " passed" << '\n';
    }

    {
        std::vector<uint8_t> in = {0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1};
        std::vector<uint8_t> wait = {1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1};

        auto encode = Encode::HammingEncode(in, 11, 15);
        auto decode = Decode::HammingDecode(encode, 15);
        bool valid = Valid::IsValid(encode, 15);

        assert(valid == 1);
        assert(decode == in);
        assert(encode == wait);
        std::cout << "Test " << count++ << " passed" << '\n';
    }

    std::cout << "Medium tests:" << '\n';

    {
        std::vector<uint8_t> in = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1 , 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1};
        std::vector<uint8_t> wait = {0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1};

        auto encode = Encode::HammingEncode(in, 45, 51);
        assert(encode == wait);
        encode[21] ^= 1;
        auto decode = Decode::HammingDecode(encode, 51);
        bool valid = Valid::IsValid(encode, 51);

        assert(valid == 0);
        assert(decode == in);
        std::cout << "Test " << count++ << " passed" << '\n';
    }

    
    {
        std::vector<uint8_t> in = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0};
        std::vector<uint8_t> wait = {1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0};

        auto encode = Encode::HammingEncode(in, 138, 146);
        assert(encode == wait);
        encode[69] ^= 1;
        auto decode = Decode::HammingDecode(encode, 146);
        bool valid = Valid::IsValid(encode, 138);

        assert(valid == 0);
        assert(decode == in);
        std::cout << "Test " << count++ << " passed" << '\n';
    }
    
    std::cout << "Hard tests:" << '\n';

    {
        std::vector<uint8_t> in(100, 0);
        
        auto encode = Encode::HammingEncode(in, 100, 107);
        auto decode = Decode::HammingDecode(encode, 107);
        bool valid = Valid::IsValid(encode, 107);

        assert(decode == in);
        assert(valid == 1);
        std::cout << "Test " << count++ << " passed " << '\n';
    }

    {
        std::vector<uint8_t> in(100, 1);
        
        auto encode = Encode::HammingEncode(in, 100, 107);
        auto decode = Decode::HammingDecode(encode, 107);
        bool valid = Valid::IsValid(encode, 107);

        assert(decode == in);
        assert(valid == 1);
        std::cout << "Test " << count++ << " passed " << '\n';
    }

    {
        std::vector<uint8_t> in(10000);
        for (int i = 0; i < in.size(); i++) {
            in[i] = i % 2;
        }

        auto encode = Encode::HammingEncode(in, 10000, 10014);
        auto decode = Decode::HammingDecode(encode, 10014);
        bool valid = Valid::IsValid(encode, 10014);

        assert(decode == in);
        assert(valid == 1);
        std::cout << "Test " << count++ << " passed" << '\n';
    }

    {
        std::srand(std::time(nullptr));
        for (int i = 0; i < 100; i++) {
            std::vector<uint8_t> in(100);
            for (int i = 0; i < in.size(); i++) {
                in[i] = std::rand() % 2;
            }

            auto encode = Encode::HammingEncode(in, 100, 107);
            int err = std::rand() % encode.size();
            encode[err] ^= 1;
            auto decode = Decode::HammingDecode(encode, 107);
            bool valid = Valid::IsValid(encode, 107);

            assert(decode == in);
            assert(valid == 0);
        }
        std::cout << "Test " << count++ << " passed" << '\n';
    }

    std::cout << "All test passed!" << '\n';
}
