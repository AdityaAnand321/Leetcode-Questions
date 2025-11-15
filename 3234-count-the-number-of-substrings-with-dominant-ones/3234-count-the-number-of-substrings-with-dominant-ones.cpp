#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    long long numberOfSubstrings(const string &s) {
        int n = s.size();
        // collect positions of zeros with sentinels -1 and n
        vector<int> pos;
        pos.push_back(-1);
        for (int i = 0; i < n; ++i) if (s[i] == '0') pos.push_back(i);
        pos.push_back(n);
        int m = (int)pos.size() - 2; // actual zero count

        ll ans = 0;

        // k = 0 : substrings with zero zeros (all ones)
        for (int i = 0; i < n; ) {
            if (s[i] == '1') {
                int j = i;
                while (j < n && s[j] == '1') ++j;
                ll len = j - i;
                ans += len * (len + 1) / 2; // number of substrings in this 1-block
                i = j;
            } else ++i;
        }

        // We'll only need to check k up to sqrt(n)+1 because k^2 grows fast.
        int Kmax = (int)(sqrt(n)) + 2;

        // For each possible k (number of zeros in substring)
        for (int k = 1; k <= Kmax && k <= m; ++k) {
            // slide the window of k zeros across pos[] (pos has sentinel at start)
            for (int idx = 1; idx + k - 1 <= m; ++idx) {
                int left_zero = pos[idx];
                int right_zero = pos[idx + k - 1];

                // number of choices to extend left (start) and right (end)
                ll L = left_zero - pos[idx - 1];       // start can be moved L ways (0..L-1)
                ll R = pos[idx + k] - right_zero;      // end can be moved R ways (0..R-1)

                // ones already inside the minimal window between these zeros
                ll base_ones = (right_zero - left_zero + 1) - k;

                // we need a + b >= need where need = k*k - base_ones
                ll need = 1LL * k * k - base_ones;

                if (need <= 0) {
                    // any choice of (a,b) works
                    ans += L * R;
                    continue;
                }

                // if even with maximum expansions we cannot reach need, skip
                if (need > (L - 1) + (R - 1)) continue;

                // Count pairs (a,b) with 0<=a<L, 0<=b<R where a+b < need (bad pairs).
                // We'll do a simple loop on a (it runs at most min(L, need) times).
                ll sum_less = 0;
                ll maxA = min(L, need); // a in [0..maxA-1] might give a+b < need
                for (ll a = 0; a < maxA; ++a) {
                    // need a + b < need  => b < need - a
                    ll limitB = need - a - 1;    // max allowed b for a+b < need
                    if (limitB < 0) break;       // no b possible
                    // number of valid b's for this a is min(R, limitB+1)
                    ll cntB = min(R, limitB + 1);
                    sum_less += cntB;
                }

                ll total_pairs = L * R;
                ll good_pairs = total_pairs - sum_less;
                ans += good_pairs;
            }
        }

        return ans;
    }
};
