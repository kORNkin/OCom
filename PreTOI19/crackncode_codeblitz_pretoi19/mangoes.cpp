#include<bits/stdc++.h>
using namespace std;
struct tree{
    int x, y, w;
};
int n, m, r, c;
int qs[5001][5001];
vector<tree> t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r >> c;

    while(n--){
        int x, y, w; cin >> x >> y >> w;
        t.push_back({x, y, w});
    }

    while(m--){
        int x, y; cin >> x >> y;
        qs[x][y] = 1; 
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            qs[i][j] += qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1];
        }
    }

    int L = 1, R = max(r, c);
    while(L < R){
        int mid = (L + R) >> 1;

        bool less = 0;
        for(auto &[x, y, w] : t){
            int a = min(x + mid, r);
            int b = min(y + mid, c);
            int c = max(y - mid - 1, 0);
            int d = max(x - mid - 1, 0);
            int area = qs[a][b] - qs[a][c] - qs[d][b] + qs[d][c];
            if(area < w) less = 1;
        }

        if(less) L = mid + 1;
        else R = mid;
    }

    cout << L;


    return 0;
}
