#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    string txt,s; cin>>txt>>s;
    long long sum=0;
    if(n){
        vector<int> mem[26];
        for(int i=txt.size()-1;i>=0;i--){
            mem[txt[i]-'a'].push_back(i);
        }
        vector<int> v;
        for(int i=0;i<s.size();i++){
            if(mem[s[i]-'a'].empty()) {
                cout << "-1"; return 0;
            }
            if(v.empty()){
                v.push_back(mem[s[i]-'a'].back());
                sum+=mem[s[i]-'a'].back()+1;
                mem[s[i]-'a'].pop_back();
                continue;
            }
            sort(v.begin(),v.end());
            auto it = lower_bound(v.begin(),v.end(),mem[s[i]-'a'].back()) - v.begin();
            sum += mem[s[i]-'a'].back()-it+1;
            v.push_back(mem[s[i]-'a'].back());
            mem[s[i]-'a'].pop_back();
        }
    }else {
        vector<int> mem[26];
        for(int i=txt.size()-1;i>=0;i--){
            mem[txt[i]-'a'].push_back(i);
        }
        for(int i=0;i<s.size();i++){
            if(mem[s[i]-'a'].empty()) {
                cout << "-1"; return 0;
            }
            sum+=mem[s[i]-'a'].back()+1;
            mem[s[i]-'a'].pop_back();
        }
    } cout << sum;

    return 0;
}