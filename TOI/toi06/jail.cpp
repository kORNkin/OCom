#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin>>n>>m;
    deque<int> q;
    for(int i=1;i<=n;i++)
        q.push_back(i);
    while(!q.empty()){
        for(int i=0;i<m-1;i++){
            q.push_back(q.front());
            q.pop_front();
        }
        cout << q.front() << ' ';
        q.pop_front();
    }

    return 0; 
}