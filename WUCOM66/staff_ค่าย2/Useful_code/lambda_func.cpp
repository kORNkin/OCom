#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
    bool operator < (Point &rhs){
        if(x == rhs.x) return y < rhs.y;
        return x < rhs.y;
    }
} P[101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> P[i].x >> P[i].y;
    }

    sort(P, P + n);
    for(int i = 0; i < n; i++){
        cout << "(" << P[i].x << ", " << P[i].y << ") ";
    } cout << '\n';

    //Lambda Expressions
    sort(P, P + n, [&](Point a, Point b){
        if(a.x == b.x) return a.y > b.y;
        return a.x > b.x;
    });
    for(int i = 0; i < n; i++){
        cout << "(" << P[i].x << ", " << P[i].y << ") ";
    }


    return 0;
}