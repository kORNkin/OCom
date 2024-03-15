#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k; cin >> k;
    stack<int> st;
    pair<int, int> h[k + 1];
    for(int i = 0; i < k; i++) {
        cin >> h[i].second >> h[i].first;
        bool ch = 1;
        while(!st.empty()){
            int x = h[st.top()].first, y = h[st.top()].second;
            if(y >= h[i].second - h[i].first + x && y <= h[i].second + h[i].first - x){
                st.pop();
            } else if(h[i].second >= y - x + h[i].first && h[i].second <= y + x - h[i].first){
                ch = 0; break;
            } 
            else break;
        }
        if(ch) st.push(i);
    }
    cout << st.size();

    return 0;
}