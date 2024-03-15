#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m,k,n; cin>>m>>k>>n;
    deque<int> arr;
    for(int i=0;i<m;i++)
        arr.push_back(i);
    
    string s; cin>>s;
    for(char c:s){
        if(c=='A'){
            int x = arr.front();
            arr.pop_front();
            arr.push_back(x);
        }else {
            int a = arr.front();
            arr.pop_front();
            arr.push_back(arr.front());
            arr.pop_front();
            arr.push_front(a);
        }
    }
    cout << arr[k-1] << '\n'<< arr[k] << '\n' << arr[k+1];

    return 0;
}