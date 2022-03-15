// link = https://leetcode.com/problems/number-complement
class Solution {
public:
    int findComplement(int num) {
        int num_bits = int(log2(num)) + 1;
        uint64_t all_ones = static_cast<uint64_t>((1 << num_bits)) - 1;
        return num ^ all_ones;
    }
};
