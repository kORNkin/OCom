#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin>>n;
    string s; cin>>s;
    char arr[101][s.size()];
    int x=0,y=0,k=1;
    int tmp = n - 1 ;
    while(y<s.size()){
        arr[x][y] = '*';
        x+=k; y++;
        if(y==tmp) {
            k*=-1;
            tmp+= n-1;
        }
    }
    k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<s.size();j++){
            if(arr[i][j]=='*'){
                arr[i][j]=s[k];
                k++;
            }else arr[i][j]=' ';
        } 
    }

    x=0,y=0,k=1;
    tmp = n - 1 ;
    while(y<s.size()){ 
        if(y==tmp) {
            k*=-1;
            tmp+= n-1;
        }
        cout << arr[x][y]; 
        y++;
        x+=k; 
    } cout << '\n';

    for(int i=0;i<n;i++){
        for(int j=0;j<s.size();j++){
            cout << arr[i][j];
        } cout <<'\n';
    }


    return 0;
}