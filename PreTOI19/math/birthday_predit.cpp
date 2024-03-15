#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(nullptr); cout.tie(nullptr);

    int day=0;
    int arr[]={1,2,4,8,16};
    for(int i=0;i<5;i++){
        int n=0;
        for(int j=1;j<=31;j++){
            if((j&arr[i]) == arr[i]){
                cout << setw(2) << j << " ";
                n++;
                if(n%5==0) cout<<"\n";
            }
        }
        cout<<"\nAre your birthday on this table? (Y/N)\n";
        char ans; cin>>ans;
        if(ans=='Y') day+=arr[i];
        cout << "\n";
    }
    cout << "Your birthday is "<<day;

    return 0;
}