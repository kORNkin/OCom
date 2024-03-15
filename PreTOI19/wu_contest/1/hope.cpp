#include<bits/stdc++.h>
using namespace std;

int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cnt = 0;
    for(int i = 0; i <= n; i++){
        if(i % 10 == 0) {
            cout << " ( " << cnt << " )\n";
            cout << i << " - " << i + 9 << " : ";
            cnt = 0;
        }
        int tmp = i;
        while(tmp){
            if(tmp % 10 == 4) {
                cout << i << ' ';
                cnt++;
                break;
            }
            tmp /= 10;
        }
    }


    return 0;
}
