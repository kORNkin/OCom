#include<bits/stdc++.h>
using namespace std;

int n, p, q, ans, arr[1000001]; 
deque<int> mn, mx;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> q;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        
        //MAX
        while(!mx.empty() && arr[i] > arr[mx.back()]) mx.pop_back();
        mx.push_back(i);

        //MIN
        while(!mn.empty() && arr[i] < arr[mn.back()]) mn.pop_back();
        mn.push_back(i);

        int a = 0, b = 0;
        while(a < mx.size() && b < mn.size()){
            if(mx[a] > mn[b]){
                if(arr[mx[a]] - arr[mn[b]] >= p && arr[mx[a]] - arr[mn[b]] <= q){
                    if(!b) {
                        if(!a) ans += mn[b] + 1;
                        else ans += mn[b] - mx[a - 1];
                    }
                    else ans += mn[b] - mn[b - 1];
                }
                b++;
            }else {
                if(arr[mx[a]] - arr[mn[b]] >= p && arr[mx[a]] - arr[mn[b]] <= q) {
                    if(!a){
                        if(!b) ans += mx[a] + 1;
                        else ans += mx[a] - mn[b - 1];
                    }
                    else ans += mx[a] - mx[a - 1];
                }
                a++;
            }
        }
    } cout << ans;

    return 0;
}