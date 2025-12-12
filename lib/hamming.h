#include <vector>
#include <cstdint>

namespace Encode {
    std::vector<uint8_t> HammingEncode(std::vector<uint8_t> bits, size_t m, size_t n);
}

namespace Decode {
    std::vector<uint8_t> HammingDecode(std::vector<uint8_t> bits, size_t n);
}

namespace Valid {
    bool IsValid(std::vector<uint8_t> bits, size_t n);
}