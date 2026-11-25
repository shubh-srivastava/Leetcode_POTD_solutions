// 25th November 2026

class Solution {
public:
        int smallestUniqueSubarray(vector<int>& A) {
        int n = A.size();
        long long b = 215215;
        long long mod = (1LL << 31) - 1;
        int l = 1, r = n;
        while (l < r) {
            int k = (l + r) / 2;
            long long h = 0, p = 1;
            for (int i = 0; i < k; ++i) {
                h = (h * b + A[i]) % mod;
                p = (p * b) % mod;
            }
            unordered_map<long long, int> c;
            c[h]++;
            for (int i = k; i < n; ++i) {
                h = (h * b + A[i] - A[i - k] * p % mod) % mod;
                if (h < 0) h += mod;
                c[h]++;
            }
            bool found = false;
            for (auto& pair : c) {
                if (pair.second == 1) {
                    found = true;
                    break;
                }
            }
            if (found) {
                r = k;
            } else {
                l = k + 1;
            }
        }
        return l;
    }
};