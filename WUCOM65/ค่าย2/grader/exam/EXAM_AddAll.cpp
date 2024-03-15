#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        pq.push(x);
    }
    int sum=0;
    while(!pq.empty()){
        int a=pq.top();
        pq.pop();
        if(pq.empty()) {
            break;
        }
        int b=pq.top();
        pq.pop();

        sum+=a+b;
        pq.push(a+b);
    }
    cout << sum;

    

    return 0;
}
