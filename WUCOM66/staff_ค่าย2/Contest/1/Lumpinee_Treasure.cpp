#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k;
ll arr[16][16];
int di[] = {0,-1};
int dj[] = {-1,0};

bool valid(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= m) 
        return 0;
    return 1;
}

ll solve(int i, int j, int left){
    if(!left) return 0;
    ll sum = arr[i][j];
    ll mx = sum;
    for(int g = 0; g < 2; g++){
        if(valid(i + di[g], j + dj[g]))
            mx = max(mx, sum + solve(i + di[g], j + dj[g], left - 1));
    }   
    return mx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    ll mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j])
                mx = max(mx,solve(i, j, k));
        }
    }
    cout << mx;

    return 0;
}