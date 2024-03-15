#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int mx=0,idx;
    int n; cin>>n;
    int arr[n+1];  
    int qs[n+1]; memset(qs,0,sizeof(qs));
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        qs[i]=arr[i]+qs[i-1];
        if(qs[i]<0) qs[i]=0;
        if(qs[i]>mx) mx=qs[i],idx=i;
    }
    if(!mx) {
        cout << "Empty sequence";
        return 0;
    }
    stack<int> st;
    while(qs[idx]>0){
        st.push(arr[idx]);
        idx--;
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    } cout << '\n' << mx;

    return 0;
}