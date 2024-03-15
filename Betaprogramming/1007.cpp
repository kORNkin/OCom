#include<bits/stdc++.h>
using namespace std;    

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<pair<int,int>> mem;
    int a=1,b=1,c=0,tmp;
    for(int i=0;i<24;i++){
        tmp=b;
        b=a+b+c;
        c=tmp;
        mem.push_back({b,a+b+c});
    }
    cin>>c;
    while(c!=-1){
        cout<<mem[c-1].first<< " " <<mem[c-1].second<<"\n";
        cin>>c;
    }

    return 0;
}