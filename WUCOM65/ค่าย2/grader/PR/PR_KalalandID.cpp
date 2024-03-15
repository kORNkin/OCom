#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(0);

    string s; cin>>s;
    if(next_permutation(s.begin(),s.end()))
        cout << s;
    else cout << "No Successor";

    return 0;
}