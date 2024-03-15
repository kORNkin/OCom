#include<bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
    long long operator + (P &r){
        return (long long)(abs(x - r.x) + abs(y - r.y));
    }
} p[65];

int n, m;
long long dis[65][65];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dis, 127, sizeof(dis));

    cin >> n >> m;
    for(int i = 0; i < n * 2; i++){
        cin >> p[i].x >> p[i].y;
    } 

    for(int i = 0; i < n * 2; i++){
        for(int j = 0; j < n * 2; j++){
            dis[i][j] = p[i] + p[j];
        }
    } 

    for(int i = 0; i < n * 2; i += 2){
        dis[i][i + 1] = dis[i + 1][i] = 0;
    }

    for(int k = 0; k < n * 2; k++){
        for(int i = 0; i < n * 2; i++){
            for(int j = 0; j < n * 2; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    while(m--){
        P a, b; cin >> a.x >> a.y >> b.x >> b.y;
        long long ans = a + b;
        for(int i = 0; i < n * 2; i++){
            for(int j = 0; j < n * 2; j++){
                if(i == j) continue;
                ans = min(ans, (a + p[i]) + (p[j] + b) + dis[i][j]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
