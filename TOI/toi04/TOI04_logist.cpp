#include<bits/stdc++.h>
using namespace std;
struct Ans{
    char c,nxt;
    double med;
};
vector<Ans> out;
map<char,vector<pair<char,int>>> m;
set<char> s;
double sum=0;
void solve(char c){
    vector<int> ans;
    char nxt;
    double med=0;
    s.erase(c);
    for(auto x:m[c]){
        if(s.find(x.first) != s.end()){
            nxt = x.first;
            ans.push_back(x.second);
        }
    } 
    if(!ans.size()){
        cout << "broken";
        sum=0;
        return;
    }

    med=ans.size()+1;
    bool ch=0;
    if((int)med%2!=0) ch=1;
    med=floor(med/2);
    sort(ans.begin(),ans.end());
    if(ch) med = (ans[med-1]+ans[med])/2.0;
    else med = ans[med-1];
    out.push_back({c,nxt,med});
    sum+=med;

    if(nxt == 'Y') return;
    solve(nxt);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    
    while(n--){
        char a,b; int x;
        cin>>a>>b>>x;
        m[a].push_back({b,x});
        m[b].push_back({a,x});
        s.insert(a);
        s.insert(b);
    }
    solve('X');
    if(sum){
        for(auto x:out){
            cout << x.c << " " << x.nxt << " ";
            cout << fixed << setprecision(1) << x.med << '\n';
        }
        cout << fixed << setprecision(1) << sum;
    } 

    return 0;   
}