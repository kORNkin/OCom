#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int n=s.size();
        bool ch=1;
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                ch=0;
                break;
            }
        }
        if(ch) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
