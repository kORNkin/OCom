#include<bits/stdc++.h>
using namespace std;
struct Point{
    long long x,y;

    long long operator - (Point &rhs){
        return abs(x-rhs.x) + abs(y + rhs.y);
    }
};
int n;
Point p[100001];
long long solve(int l,int r){
    if(l >= r) return 1e10;

    int m = (l+r)>>1;

    long long d = min(solve(l,m), solve(m+1,r));

    l = max(0,l-20);
    r = min(n-1,r+20);

    for(int i=l;i<=r;i++){
        if(i != m){
            d = min(d,p[m]-p[i]);
        }
    }

    return d;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
    }
    
    sort(p,p+n, [&](Point a, Point b){
        if(a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    });

    cout << solve(0,n-1);

    return 0;
}