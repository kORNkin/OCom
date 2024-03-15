#include<bits/stdc++.h>
using namespace std;

string ip(string s){
    string ans;
    stack<char> st;
    for(auto c:s){
        if(c >= 'A' && c <= 'Z') ans += 'c';
        else {
            if(st.empty()) st.push(c);
            else if(st.top() == '[' || c == '[') st.push(c);
            else if(c == ']'){
                while(st.top() != '['){
                    ans += st.top(); st.pop();
                } st.pop();
            } 
            else {
                while(!st.empty() && st.top() != '[' && st.top() >= c){
                    ans += st.top(); st.pop();
                } st.push(c);
            }
        }
    }
    while(!st.empty()) ans += st.top(), st.pop();

    return ans;
}

int pe(string s){
    int ans = 0;
    stack<int> st;
    for(auto c:s){
        if(c == 'c') st.push(20);
        else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            double op = (1<<(c-'0' + 1)) / 100.0;
            st.push(a + b + (a + b)*op);
        }
    }
    return st.top();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin>>s;
    cout << pe(ip(s));

    return 0;
}