#include<bits/stdc++.h>
using namespace std;

//thx yingyang for save my ~400ms
void scan(int &n){
    bool neg = 0; char c;
    n = 0; c = getchar();
    if(c == '-') neg = 1, c = getchar();
    for(; (c > 47 && c < 58); c = getchar())
        n = n * 10 + c - 48;
    if(neg) n = -n;
}

int n, k, h[5000002];
vector<int> peak, ans;

int main()
{
    scan(n), scan(k);
    for(int i = 1; i <= n; i++) scan(h[i]);
    for(int i = 1; i <= n; i++)
        if(h[i] > h[i - 1] && h[i] > h[i + 1]) peak.emplace_back(h[i]);

    if(peak.empty()){
        cout << "-1\n"; return 0;
    }
    
    sort(peak.begin(), peak.end());
    peak.resize(unique(peak.begin(), peak.end())- peak.begin()); 
    if(peak.size() < k) for(auto &hh:peak) printf("%d\n", hh);
    else for(int i = peak.size() - 1; i >=0 && k--; i--) printf("%d\n", peak[i]);

    return 0;
}
