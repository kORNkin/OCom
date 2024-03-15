#include<bits/stdc++.h>
using namespace std;

int a, b, c;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b >> c;
    int arr[a + b + 1];
    memset(arr, 0 , sizeof(arr));
    arr[a + b] = 2;
    for(int i = a + b - 1; i >= a; i--)
        arr[i] = 1;

    //for(int i = 0 ; i <= a + b; i++) cout << arr[i] << ' ';
    //cout << '\n';

    do {
        int ch = 0;
        for(int i = a + b ; i >= 0; i--){
            if(arr[i] == 1) ch = 1;
            else if(arr[i] == 2 && ch){
                ch = 2; break;
            } 
        }
        if(ch == 2) continue;
        c--;
        //for(int i = 0 ; i <= a + b; i++) cout << arr[i] << ' ';
        //cout << '\n';
    } while(c && next_permutation(arr, arr + a + b + 1));
    if(c) cout << "NONE";
    else {
        int res = 0;
        for(int i = a + b; i >= 0; i--){
            res += arr[i] * ((1<<(a + b - i + 1)) - 1);
        }
        cout << res;
    }

    return 0;
}
/*
0 0 0 0

*/