#include<bits/stdc++.h>
using namespace std;

int n, w;
int arr[200001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    } cout << '\n';

    int a = 0, b = n - 1, cnt = 0;
    while(a < b){
        cout << a << ' ' << b << '\n';
        if(arr[a] + arr[b] <= w){
            a++, b--;
        }else {
            b--;
        }
        cnt++;
    }
    if(a == b) cnt++;

    cout << cnt;

    return 0;
}