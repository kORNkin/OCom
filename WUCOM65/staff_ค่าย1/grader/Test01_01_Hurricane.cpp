#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string name[] = {"Depression","Tropical Storm","Category 1 hurricane","Category 2 hurricane","Category 3 hurricane","Category 4 hurricane","Category 5 hurricane"};
    int num[] = {55,103,134,155,182,219,500};
    int n;
    cin>>n;
    for(int i=0;i<7;i++){
        if(n<=num[i]){
            cout << name[i]; break;
        }
    }

    return 0;
} 

