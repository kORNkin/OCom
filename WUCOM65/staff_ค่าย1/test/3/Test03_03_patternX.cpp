#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    int arr[]={1,2,3,4,5,6,7,8,9,0};
    int k=0;
    for(int i=0;i<n*2-1;i++){
        for(int j=0;j<n*2-1;j++){
            if(i==j || i+j==(n-1)*2){
                cout << arr[k%10];                      
            }else cout<<0;
        }
        if(i<n-1) k++;
        else k--;  
        cout << "\n";
    }

    return 0;
}
