#include<bits/stdc++.h>
using namespace std;

int n, q, l[100001], o[100001], v[100001], e[100001];
vector<int> o_idx, v_idx, e_idx;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string s; cin >> s;
    for(int i = 1; i < s.size(); i++){
        l[i] = l[i - 1] + (s[i - 1] == 'L');
        o[i] = o[i - 1] + (s[i - 1] == 'O');
        v[i] = v[i - 1] + (s[i - 1] == 'V');
        e[i] = e[i - 1] + (s[i - 1] == 'E');
        if(s[i - 1] == 'O') o_idx.push_back(i);
        else if(s[i - 1] == 'V') o_idx.push_back(i);
        else if(s[i - 1] == 'E') o_idx.push_back(i);
    }

    cin >> q;
    while(q--){
        int l, r; cin >> l >> r;

        
    }   

    return 0;
}
