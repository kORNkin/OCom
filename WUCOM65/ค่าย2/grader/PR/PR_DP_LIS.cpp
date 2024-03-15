#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        vector<int> lis;

        lis.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(lis.back()<arr[i]) 
                lis.push_back(arr[i]);
            else {
                auto it = upper_bound(lis.begin(),lis.end(),arr[i]);
                *it = arr[i];
            }
        } cout << lis.size() << '\n';
    }

	return 0;
}