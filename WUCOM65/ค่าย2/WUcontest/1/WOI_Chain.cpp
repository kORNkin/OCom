#include<bits/stdc++.h>
using namespace std;
struct block{
    string data;
    string time;
};
int hash_func(string s,string t){
    int val = 0;
    for(int i=0;i<s.size();i++){
        val += s[i];
        val %= 1000000000 + 7;
    }
    for(int i=0;i<t.size();i++){
        val += t[i];
        val %= 1000000000 + 7;
    }
    return val;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n,pre=0; cin>>n;
    block arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].data>>arr[i].time;
        int h = hash_func(arr[i].data,arr[i].time);
        cout << "Block " << i+1 << ":\n";
        cout << "Data: " << arr[i].data << '\n';
        cout << "Timestamp: " << arr[i].time << '\n';
        cout <<  "Hash: " << h << '\n'; 
        cout << "Previous hash: " << pre << '\n';
        pre = h;
    }

    return 0;
}