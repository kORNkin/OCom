#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define f first
#define s second
struct P{
    int x1, y1, x2, y2;
};

int n, cnt;
vector<pair<double, double>> slope;

double cal(double x, double y){
    if(!x) return 1e9;
    return y * 100 / x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;;
        double a, b;
        a = cal(x1, y1);
        b = cal(x2, y2);
        if(a > b) swap(a, b);
        slope.push_back({a, b});
    }
    
    sort(slope.begin(), slope.end(), [&] (pair<double ,double> a, pair<double, double> b){
        return (a.second == b.second ? a.first < b.first : a.second < b.second);
    });

    int cnt = 0;
    double prev = -1;
    for(auto s : slope){
        if(prev < s.first) {
            cnt ++;
            prev = s.second;
        }
    }

    cout << n - cnt;

    return 0;
}
/*
3
1 1 1 1
1 1 1 1
0 0 0 0
*/