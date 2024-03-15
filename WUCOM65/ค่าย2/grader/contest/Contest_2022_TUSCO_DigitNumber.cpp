#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin>>s;
    string num[] = {"ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT" , "NINE"};
    for(int i=0;i<9;i++){
        int k=0;
        bool ch=0;
        for(int j=0;j<s.size();j++){
            if(s[j] == num[i][k]){
                k++;
            }
            if(k== num[i].size()){
                ch=1; break;
            }
        }
        if(ch) {
            cout << i+1;
            return 0;
        }
    } cout << "NO";

    return 0;
}