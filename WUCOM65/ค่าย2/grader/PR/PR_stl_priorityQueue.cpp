#include<bits/stdc++.h>
using namespace std;
void print(priority_queue<int,vector<int>> arr){
    while(!arr.empty()){
        cout << arr.top() << " ";
        arr.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;cin>>T;
    while(T--){
        int n; cin>>n;
        priority_queue<int,vector<int>> arr; 
        while(n--){
            char c; cin>>c;
            int x;
            if(c=='1') {
                cin>>x;
                arr.push(x);
                print(arr);
            }else if(c=='2'){
                cout << arr.top() << ' ';
                arr.pop();
            }else if(c=='3'){
                cout << arr.top() << ' ';
            }else if(c=='4'){
                cout << arr.size() << ' ';
            }else if(c=='5'){
                print(arr);
            }
        } cout << '\n';
    }

    return 0;
}