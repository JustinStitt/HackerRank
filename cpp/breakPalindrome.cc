#include <bits/stdc++.h>

using std::string;

string breakPalindrome(string palindrome) {
  size_t n = palindrome.size();
  if (n == 1) return "";  // not possible
  for (int x{}; x < n; ++x) {
    char& c = palindrome[x];
    if (n & 1 && x == n / 2) continue;  // can never change middle
    if (c == 'a' && x != n - 1) continue;
    if ('a' < c) {
      c = 'a';
      break;
    }
    c = 'b';
  }
  return palindrome;
}

/*
ideas:
try to lower things to a,
if already a, go to next thing,
if we reach end and didn't downgrade anything  to an a
then we shall change the last thing to an a or if it is already an a, change to
a b
*/

int main() {
  {  // test 1
    string result = breakPalindrome("abccba");
    std::cout << "Result: " << result << " | Expected: "
              << "aaccba\n";
  }

  {  // test 2
    string result = breakPalindrome("zzz");
    std::cout << "Result: " << result << " | Expected: "
              << "azz\n";
  }

  {  // test 3
    string result = breakPalindrome("a");
    std::cout << "Result: " << result << " | Expected: "
              << "\n";
  }

  return 0;
}