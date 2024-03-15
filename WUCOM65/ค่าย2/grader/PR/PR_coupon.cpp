#include<bits/stdc++.h>
using namespace std;
int n,k,mx=0;
int arr[8001];
string s,ans;
void solve(int sum,int idx,int amt){
    /*if(sum>k) {
        if(amt < 3) return ;
        if(mx < sum-arr[idx]){
            mx = sum-arr[idx];
            ans = s;
            ans.pop_back();
        }

        return ;
    }*/

    for(int i=idx+1;i<n;i++){
        if(sum+arr[i] > k){
            if(amt > 3) continue;

            if(mx < sum){
                mx = sum;
                ans = s;
            }

            continue;
        }

        s.push_back(i+'0');
        solve(sum+arr[i],i,amt+1);
        s.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        s.push_back(i+'0');
        solve(arr[i],i,1);
        s.pop_back();
    } 
    
    for(auto c:ans){
        cout << arr[c-'0'] << '\n';
    }

    return 0;
}