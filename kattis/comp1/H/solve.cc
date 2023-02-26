#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool go(ll& stk, ll n) {
  // find first ocelot
  ll i = n - 1;
  bool found = false;
  for (; i >= 0; --i) {
    ll shift = 1 << i;
    if ((stk & shift) == 0) {
      found = true;
      // cout << "found" << endl;
      stk += shift;
      break;
    }
  }
  if (!found) return false;

  // now clear all bits from i to n incl.
  for (; i <= n - 1; ++i) {
    ll shift = 1 << i;
    // cout << "before: " << stk << endl;
    stk ^= shift;
    // cout << "after: " << stk << endl;
  }


  return true;
}

int main() {
  // ...
  ll n;
  ll stk{};
  cin >> n;
  string inp;

  for (ll x{}; x < n; ++x) {
    cin >> inp;
    if (inp == "Z") // Z = 1, O = 0
      stk += (1 << x);
  }
  ll count = 0;
  while (1) {
    bool result = go(stk, n);
    if (!result) break;
    count += result;
  }

  cout << count << "\n";

  return 0;
}
