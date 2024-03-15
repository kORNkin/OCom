#include<bits/stdc++.h>
using namespace std;
string rev(string s){
    string tmp="";
    for(int i=s.size()-1;i>=0;i--)
        tmp.push_back(s[i]);
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s,tmp=""; getline(cin,s);
    for(int i=0;i<s.length();i++){       
        if(s[i] != ' '){
            tmp.push_back(s[i]);
        }else {           
            cout << rev(tmp) << " ";
            tmp="";
        }
    }
    cout << rev(tmp) << " ";

    return 0;
}