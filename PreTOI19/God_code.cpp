#include<bits/stdc++.h>
 
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define stki stack<int>
#define pqi priority_queue<int>
#define pqpii priority_queue<pii>
#define minpqi priority_queue<int,vi,greater<>>
#define psi pair<string,int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tri pair<int,pii>
#define trll pair<ll,pll>
#define qi queue<int>
#define li list<int>
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
#define vvll vector<vector<ll>>
#define vvpll vector<vector<pll>>
#define vpii vector<pii>
#define vpll vector<pll>
#define mp(a, b) make_pair(a,b)
#define si set<int>
#define mlsi multiset<int>
#define sll set<ll>
#define sull set<ull>
#define mii map<int,int>
#define mll map<ll,ll>
#define mss map<string,string>
#define msi map<string,int>
#define mci map<char,int>
#define umii unordered_map<int,int>
#define umill unordered_map<int,ll>
#define umsi unordered_map<string,int>
#define umsll unordered_map<string,ll>
#define umss unordered_map<string,string>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define all(a) a.begin(), a.end()
#define alln(a, n) a, a + n
#define yes "YES"
#define no "NO"
#define spc ' '
#define INF INT_MAX
#define LLINF LONG_LONG_MAX
#define NINF INT_MIN
#define LLNINF LONG_LONG_MIN
#define pb push_back
#define pf push_front
#define eb emplace_back
#define F first
#define S second
#define cin(a) for(auto &_x:(a)) cin>>_x
#define cin2(a) for(auto &_x:(a))for(auto &__x:_x) cin>>__x
#define cout(a) for(auto &_x:(a)) cout<<_x<<spc
#define len(l, r) (r-l+1)
#define mid(l, r) (l+(r-l)/2)
#define yn(b) (b?yes:no)
#define between(x, l, r) (x >= l && x <= r)
#define between2(i, j, n, m) (between(i,0,n-1) && between(j,0,m-1))
#define CLION
 
 
const int MOD = 1e9 + 7;
 
using namespace std;
 
void solve() {
    //code here
}
 
bool multi = false;
 
int main() {
    fast;
#ifdef CLION
    freopen("../in.txt", "r", stdin);
    freopen("../out.txt", "w", stdout);
#endif
    int t = 1;
    multi && cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
        multi && cout << endl;
    }
}