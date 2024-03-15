#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        pair<int, int> arr[n];
        for(int i = 0; i < n; i++){
            int id;
            cin >> id >> arr[i].second >> arr[i].first;
        }
        sort(arr, arr + n, greater<pair<int, int>>());
        bitset<101> vis(0);
        int sum = 0, day = 0;
        for(int i = 0; i < n; i++){
            for(int j = arr[i].second; j > 0; j--){
                if(!vis[j]){
                    sum += arr[i].first;
                    day++;
                    vis[j] = 1;
                    break;
                }
            }
        }

        cout << day << ' ' << sum << '\n'; 
    }

    return 0;
}