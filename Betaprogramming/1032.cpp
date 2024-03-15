#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    int base[9][9];
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            cin>>base[i][j];
    int sdk[9][9];
    bool across[9],down[9];
    for(int x=1;x<=n;x++){
        bool ch=0;
        memset(across,0,sizeof(across));
        memset(down,0,sizeof(down));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>sdk[i][j];
                if(base[i][j]!=0 && sdk[i][j]!=base[i][j])
                    ch=1;
            }
        }
        if(ch) continue;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(!across[sdk[i][j]-1])
                    across[sdk[i][j]-1]=1;
                else{
                    ch=1;
                    break;
                }
                if(!down[sdk[j][i]-1])
                    down[sdk[j][i]-1]=1;
                else{
                    ch=1;
                    break;
                }
            }
            memset(across,0,sizeof(across));
            memset(down,0,sizeof(down));
        }
        if(ch) continue;
        memset(down,0,sizeof(down));
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(ch) continue;
                        if(!down[sdk[k][l]-1])
                            down[sdk[k][l]-1]=1;
                        else ch=1;
                    }
                }
                if(ch) continue;
                memset(down,0,sizeof(down));
            }if(ch) continue;
        }
        cout << x << "\n";

    }
    cout<<"END";

    return 0;
}