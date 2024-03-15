#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    char table[5][5];
    set<char> alp;
    for(int i=0;i<26;i++)
        alp.insert('a'+i);
    string key; cin>>key;
    map<char,pair<int,int>> posi;
    int i=0,j=0;
    for(auto c:key){
        table[i][j]=c;
        posi[c]={i,j};
        j++;
        if(j>4){
            j%=5; i++;
        }
        alp.erase(c);
    } 
    for(i;i<5;i++){
        for(j;j<5;j++){
            if(*alp.begin()=='j'){
                alp.erase(*alp.begin());
            }
            table[i][j] = *alp.begin();
            posi[*alp.begin()] = {i,j};
            alp.erase(*alp.begin());
        } if(j>4) j%=5;
    }

    /*for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            cout << table[i][j] << ' ';
        } cout << '\n';
    }*/
    
    string txt,s; cin>>txt;
    for(int i=0;i<txt.size();i++){
        if(txt[i]==txt[i+1]) {
            s.push_back(txt[i]);
            s.push_back('x');
        }else {
            s.push_back(txt[i]);
            if(i+1 < txt.size())s.push_back(txt[i+1]);
            i++;
        }
    }
    if(s.size()%2!=0) s.push_back('x');
    string ans;
    for(int i=0;i<s.size();i+=2){
        int x1=posi[s[i]].first, y1=posi[s[i]].second;
        int x2=posi[s[i+1]].first, y2=posi[s[i+1]].second;
        if(y1==y2){
            x1++; x1%=5;
            x2++; x2%=5;
            
        }else if(x1==x2){
            
            y1++; y1%=5;
            y2++; y2%=5;
        }else {
            swap(y1,y2);
        }
        ans.push_back(table[x1][y1]);
        ans.push_back(table[x2][y2]);
    } cout << ans;

    return 0;
}