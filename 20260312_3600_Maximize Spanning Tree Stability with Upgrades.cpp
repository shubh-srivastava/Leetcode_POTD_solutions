// 12th march 2026

class Solution {
    struct DSU {
        vector<int> p, r;
        DSU(int n) {
            p.resize(n);
            iota(p.begin(), p.end(), 0);
            r.resize(n, 0);
        }
        int find(int i) {
            if (p[i] == i) return i;
            return p[i] = find(p[i]);
        }
        bool unite(int i, int j) {
            int root_i = find(i), root_j = find(j);
            if (root_i != root_j) {
                if (r[root_i] < r[root_j]) p[root_i] = root_j;
                else if (r[root_i] > r[root_j]) p[root_j] = root_i;
                else { p[root_j] = root_i; r[root_i]++; }
                return true;
            }
            return false;
        }
    };

    bool check(int X, int n, const vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int comps = n;
        
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < X) return false;
                if (dsu.unite(e[0], e[1])) comps--;
            } else if (e[2] >= X) {
                if (dsu.unite(e[0], e[1])) comps--;
            }
        }
        
        if (comps - 1 > k) return false;
        
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < X && e[2] * 2 >= X) {
                if (dsu.unite(e[0], e[1])) comps--;
            }
        }
        
        return comps == 1;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int min_mandatory = 200000;
        DSU dsu(n);
        int comps = n;
        
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (!dsu.unite(e[0], e[1])) return -1;
                comps--;
                min_mandatory = min(min_mandatory, e[2]);
            }
        }
        
        for (const auto& e : edges) {
            if (e[3] == 0 && dsu.unite(e[0], e[1])) comps--;
        }
        
        if (comps > 1) return -1;
        
        int low = 1, high = min(200000, min_mandatory), ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, n, edges, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};
