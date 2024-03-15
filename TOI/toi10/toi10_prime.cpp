#include<bits/stdc++.h>
using namespace std;
#define f(i, a, b, c, d) for(i = a; i <= b && d; i+=c)

vector<int> p;
bitset<7368788> noP;

void prime(){
    int n, i, j, cnt = 1;
    cin >> n;
    p.emplace_back(2); 
    f(i,4,7368788,2,1){ noP[i] = 1; }
    f(i,3,7368788,2,cnt<n){ if(!noP[i]) { p.emplace_back(i), ++cnt; f(j,i+i,7368788,i,1) noP[j] = 1; }}
    cout << p[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
   
    prime();

    return 0;
}