const int START = 1,END = -1;

struct Event{
    int x1,x2,y,type;
};

struct Node {
    int covered_cnt;
    int covered_len;
    bool left_covered = false;
    bool right_covered = false;
};

struct SegmentTree {
    vector<int> vals;
    vector<Node> tree;
    int sz;

    SegmentTree(const set<int>& st)
        : tree(4 * st.size()), sz(st.size()) {
        vals.assign(st.begin(), st.end());
    }

    void update(int l, int r, int delta, int v, int vl, int vr) {
        if (vl > r || vr < l) return;
        int mid = (vl + vr) / 2;

        if (l <= vl && vr <= r) {
            tree[v].covered_cnt += delta;
        } else {
            update(l, r, delta, v*2, vl, mid);
            update(l, r, delta, v*2+1, mid+1, vr);
        }

        if (tree[v].covered_cnt) {
            tree[v].covered_len = vals[vr] - vals[vl] + 1;
            tree[v].left_covered = tree[v].right_covered = true;
        } else if (vl == vr) {
            tree[v].covered_len = 0;
            tree[v].left_covered = tree[v].right_covered = false;
        } else {
            tree[v].covered_len =
                tree[v*2].covered_len + tree[v*2+1].covered_len;

            if (tree[v*2].right_covered &&
                tree[v*2+1].left_covered) {
                tree[v].covered_len += vals[mid+1] - vals[mid] - 1;
            }

            tree[v].left_covered = tree[v*2].left_covered;
            tree[v].right_covered = tree[v*2+1].right_covered;
        }
    }

    void update_range(int l, int r, int delta) {
        update(l, r, delta, 1, 0, sz - 1);
    }

    int covered() {
        return tree[1].covered_len;
    }
};



class Solution {
public:
    double separateSquares(vector<vector<int>>& squares){
        set<int>xs;
        for(auto& s: squares){
            xs.insert(s[0]-1);
            xs.insert(s[0]);
            xs.insert(s[0] + s[2]-1);
            xs.insert(s[0] + s[2]);
        }

        map<int,int> idx;
        for(int x : xs){
            idx[x] = idx.size();
        }

        vector<Event> events;
        for(auto& s : squares){
            int x1 = s[0];
            int x2 = s[0] + s[2] - 1;
            events.push_back({idx[x1],idx[x2],s[1],START});
            events.push_back({idx[x1],idx[x2],s[1] + s[2],END});
        }
        sort(events.begin(), events.end(),
             [](auto& a, auto& b){ return a.y < b.y; });

        SegmentTree st(xs);
        long long total = 0;
        int prevY = 0;

        for (auto& e : events) {
            total += 1LL * (e.y - prevY) * st.covered();
            prevY = e.y;
            st.update_range(e.x1, e.x2, e.type);
        }

        long long cur = 0;
        prevY = 0;

        for (auto& e : events) {
            long long next = cur + 1LL * (e.y - prevY) * st.covered();
            if (next >= total / 2.0) {
                return prevY + (total / 2.0 - cur) / st.covered();
            }
            cur = next;
            prevY = e.y;
            st.update_range(e.x1, e.x2, e.type);
        }
        return -1;
    }
};