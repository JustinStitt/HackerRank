#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */
// @lc code=start
class Solution {
 public:
  bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
      if (!std::isalnum(s[i]))
        ++i;
      else if (!std::isalnum(s[j]))
        --j;
      else if (tolower(s[i++]) != tolower(s[j--]))
        return false;
    }

    return true;
  }
};
// @lc code=end
/* other solutions: */

// class Solution {
//  public:
//   bool isAlpha(const char& c) {
//     return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
//   }

//   bool isNumeric(const char& c) { return (c >= '0' && c <= '9'); }

//   bool isPalindrome(string s) {
//     int start = 0, end = s.size() - 1;
//     string cleaned = "";

//     for (const char& c : s) {
//       if (isAlpha(c))
//         cleaned.push_back(tolower(c));
//       else if (isNumeric(c))
//         cleaned.push_back(c);
//     }

//     for (int i = 0, j = cleaned.size() - 1; i < j; ++i, --j)
//       if (cleaned[i] != cleaned[j]) return false;

//     return true;
//   }
// };

// class Solution {
//  public:
//   bool isAlpha(const char& c) {
//     return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
//   }

//   bool isNumeric(const char& c) { return (c >= '0' && c <= '9'); }

//   bool isPalindrome(string s) {
//     s.erase(std::remove_if(
//                 s.begin(), s.end(),
//                 [&](const char& c) { return !isAlpha(c) && !isNumeric(c); }),
//             s.end());
//     /* s is now alphanumeric only */

//     for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
//       if (tolower(s[i]) != tolower(s[j])) return false;
//     }

//     return true;
//   }
// };