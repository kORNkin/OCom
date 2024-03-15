#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m1,n1,m2,n2;
    cin>>m1>>n1;
    int mat1[m1][n1];
    for(int i=0;i<m1;i++)
        for(int j=0;j<n1;j++)
            cin>>mat1[i][j];
    cin>>m2>>n2;
    int mat2[m2][n2];
    for(int i=0;i<m2;i++)
        for(int j=0;j<n2;j++)
            cin>>mat2[i][j];
    if(n1!=m2){
        cout << "Can not multiply";
        return 0;
    }
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            int sum=0;
            for(int k=0;k<n1;k++){
                sum+=mat1[i][k]*mat2[k][j];
            }
            cout << sum << " ";
        } cout << "\n";
    }

    return 0;
}
