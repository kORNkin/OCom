#include<bits/stdc++.h>
using namespace std;
#define N 8
int co=0;
void solve(int i,string s){
    if(s.size()==N){
        if(s.find("1111")!=-1) {
            co++;
            cout << co << " : " << s << '\n';
        }
        return ;
    }
    s.push_back('0');
    solve(i+1,s);
    s.pop_back();
    s.push_back('1');
    solve(i+1,s);
    s.pop_back();

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve(0,"");

    return 0;
}