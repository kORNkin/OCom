#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,now=1;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        if(s.size() < 16) continue;
        string bin;
        for(int i=1;i<s.size();i+=2){
            string tmp;
            tmp.push_back(s[i-1]);
            tmp.push_back(s[i]);
            if(now==1){
                if(tmp == "00"){
                    bin.push_back('0');
                } 
                else{
                    bin.push_back('1'); 
                    now=2;
                } 
            }else if(now==2){
                if(tmp == "10"){
                    bin.push_back('0');
                    now=3;
                } 
                else{
                    bin.push_back('1'); 
                    now=4;
                } 
            }else if(now==3){
                if(tmp == "11"){
                    bin.push_back('0');  
                    now=1;
                } 
                else{
                    bin.push_back('1'); 
                    now=2;
                } 
            }else if(now==4){
                if(tmp == "01"){
                    bin.push_back('0');    
                    now=3;                
                } 
                else{
                    bin.push_back('1'); 
                } 
            }
        }
        int x=0;
        for(int i=0;i<bin.size();i++){
            if(bin[i] == '1') x+= pow(2,bin.size()-i-1);
        }
        cout << (char)x ;
    }
    return 0;
}
