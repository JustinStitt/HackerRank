#include <bits/stdc++.h>

using std::vector;

namespace compare {
    struct OddThenEven {
        bool operator()(int a, int b) {
            bool ao = (a & 1), bo = (b & 1);
            if (ao and bo) return a < b;
            else if (ao and !bo) return 1;
            else if (!ao and !bo) return a < b;
            return 0;
        }
    };
};

void evenOddSort(vector<int>& v) {
    #define all(a) a.begin(), a.end()
    std::sort(all(v), compare::OddThenEven()); 
}

int main() {
    vector<int> test = {7,8,1,4,5,7,11,6,14,26,13};
    evenOddSort(test);
    for(auto&& e : test) std::cout << e << " ";
    std::cout << "\n";
}