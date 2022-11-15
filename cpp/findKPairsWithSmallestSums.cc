#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
 private:
  struct minSum {
    bool operator()(const tuple<int, int, int>& a,
                    const tuple<int, int, int>& b) {
      return (get<0>(a) + get<1>(a)) > (get<0>(b) + get<1>(b));
    }
  };

  using MinHeap = std::priority_queue<tuple<int, int, int>,
                                      vector<tuple<int, int, int>>, minSum>;

 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    vector<vector<int>> ret;
    MinHeap mh;
    for (int i{}; i < nums1.size() && i < k; ++i)
      mh.push({nums1[i], nums2[0], 0});

    while (k-- > 0 && !mh.empty()) {
      tuple<int, int, int> top = mh.top();
      mh.pop();
      ret.push_back({get<0>(top), get<1>(top)});
      if (get<2>(top) == nums2.size() - 1) continue;
      mh.push({get<0>(top), nums2[get<2>(top) + 1], get<2>(top) + 1});
    }

    return ret;
  }
};
// @lc code=end
/*
  first pair is always u[0] v[0]
  following pairs are the hard part seems like we
  don't need to fullfil exactly k pairs if we run out of possiblities.
  pretty sure computing all possible pairs is out of the question.  10^5
  array size

        gut instincts:
        * 2 ptr approach

  -- choosing the next pair:
        two options, either progress left ptr or right ptr we want the minimized
        sum resulting from each progression of ptr if we progress a ptr, reset
        other ptr back to beginning use a queue? (maybe prio queue with sum
        lambda)

        idea: find first n^2 larger than k, compute those and place in min-heap
  with sum lambda. pop k of them off. if n^2 < k just return what we have

*/

/*
        examples:
        [1,2,5,7]
        [0,1,2,4]
        k = 3

        pattern: n^2 combinations.

        [0, 1], [0, 2], [1, 1]

                                [-2, -1, 9, 13]
                                [0 , 1, 4]
                                k = 2

 */