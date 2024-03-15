/*
Problem: StreatLamp
Author: kornkin
Algor: Sorting + Greedy
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    int arr[n + 5];
    for(int i= 0; i < n ; i++){
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int sum = 0, ans = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        ans += sum * 2;
    } cout << ans;
    
    return 0;
}