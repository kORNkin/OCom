#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string num[10] = {" _ | ||_|","     |  |"," _  _||_ "," _  _| _|","   |_|  |"," _ |_  _|"," _ |_ |_|"," _   |  |"," _ |_||_|"," _ |_| _|"};
    int n,m; cin>>n>>m;
    string tmp; getline(cin,tmp);
    //cin.ignore();
    string a[3],b[3]; 
    for(int i=0;i<3;i++)
        getline(cin,a[i]);
    for(int i=0;i<3;i++)
        getline(cin,b[i]);
        
    long long int c=0,d=0;
    for(int i=0;i<n;i++){
        string arr;   
        bool ch=0;
        for(int j=0;j<3;j++){
            for(int k=i*4;k<(i*4)+3;k++){
                arr+=a[j][k];
            } 
        }
        for(int l=0;l<10;l++){  
            if(num[l] == arr){
                c+=l* ceil(pow(10,(n-i-1)));
                break;
            }
        } 
    }
    for(int i=0;i<m;i++){
        string arr;
        bool ch=0;
        for(int j=0;j<3;j++){
            for(int k=i*4;k<(i*4)+3;k++){
                arr+=b[j][k];
            } 
        }
        for(int l=0;l<10;l++){  
            if(num[l] == arr){
                d+=l* ceil(pow(10,(m-i-1)));
                break;
            }
        } 
    }
    cout << c+d;
    
    return 0;
}