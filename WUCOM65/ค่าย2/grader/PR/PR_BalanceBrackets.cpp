#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--)
    {
        string t;
        cin >> t;

        stack<char> st;
        for(int i=0;i<t.length();i++)
        {
            if(st.empty() || t[i]=='(' || t[i]=='[' || t[i]=='{')
                st.push(t[i]);
            else if(!st.empty() && t[i]==')' && st.top() == '(') st.pop();
            else if(!st.empty() && t[i]=='}' && st.top() == '{') st.pop();
            else if(!st.empty() && t[i]==']' && st.top() == '[') st.pop();
        }
        if(st.empty()) cout << "Balanced\n";
        else cout << "Not Balanced\n";
    }
    

    return 0;

}