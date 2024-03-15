    //g++  7.4.0
     
    #include <bits/stdc++.h>
     
    using namespace std;
     
    const int MOD = 1e9+7;
     
    #define pii pair<int, int>
    #define F first
    #define S second
     
    struct SegmentTree {
    public:
        
        SegmentTree (int _n) : n(_n) {
            tree.resize(4*n, {0, 1});
        }
        
        void update (int ind, pii val) {
            update (ind, val, 0, n-1, 0);
        }
        
        pii query (int x, int y) {
            return query (x, y, 0, n-1, 0);
        }
        
    private:
        
        vector<pii> tree;
        int n;
        
        void update (int ind, pii val, int l, int r, int i) {
            if (l == r) {
                tree[i] = val;
                return;
            }
            
            int m = (l+r) >> 1;
            if (m >= ind) update (ind, val, l, m, i*2+1);
            else update (ind, val, m+1, r, i*2+2);
            
            tree[i] = merge (tree[i*2+1], tree[i*2+2]);
        }
        
        pii query (int x, int y, int l, int r, int i) {
            if (r < x || l > y) return {0, 1};
            if (l >= x && r <= y) return tree[i];
            
            int m = (l+r) >> 1;
            return merge (
                query (x, y, l, m, i*2+1),
                query (x, y, m+1, r, i*2+2)
            );
        }
        
        pii merge (pii v1, pii v2) {
            if (v1.F == v2.F) {
                if (v1.F == 0) return {0, 1};
                
                pii result = {v1.F, (v1.S + v2.S)};
                if (result.S >= MOD) result.S -= MOD;
                return result;
            }
            return max (v1, v2);
        }
    };
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j ++) cin >> arr[j];
        
        vector<pii> val_and_ind;
        for (int j = 0; j < n; j ++) val_and_ind.push_back({arr[j], j});
        sort (val_and_ind.begin(), val_and_ind.end());
     
        vector<int> position(n);
        for (int j = 0; j < n; j ++) position[val_and_ind[j].S] = j;
        
        SegmentTree tree(n);
        
        for (int j = 0; j < n; j ++) {
            int lb = lower_bound (val_and_ind.begin(), val_and_ind.end(), make_pair(arr[j], -1)) - val_and_ind.begin();
            
            pii val = {1, 1};
            if (lb > 0)  {
                val = tree.query (0, lb-1);
                val.F ++;
                if (val.F >= MOD) val.F -= MOD;
            }
                    
            tree.update (position[j], val);
        }
        
        pii result = tree.query (0, n-1);
        cout << result.F << " " << result.S;
        
        return 0;
    } 