#include<bits/stdc++.h>
using namespace std;

void HelloWorld(){
    cout << "HelloWorld\n";
}
void printArray(int arr[],int n){
    
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << "\n";
}
string rev(string s){
    string tmp="";
    for(int i=s.length()-1;i>=0;i--)
        tmp+=s[i];
    return tmp;
}
int Plus(int a,int b){
    return a+b;
}

string DecToBinary(int n)
{
    string bi="";
    while(n){
        char tmp=n%2+'0';
        bi=tmp+bi;
        n/=2;
    }
    return bi;
}

int BiToDec(long long n)
{
    int dec=0,i=0;
    while(n){
        dec+= n%10 * pow(2,i);
        i++; n/=10;
    }
    return dec;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    HelloWorld();

    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    
    string s;
    cin>>s;
    cout << rev(s) << "\n";
    
    int a,b;
    cin>>a>>b;
    int sum = Plus(a,b);
    cout << sum << "\n";

    int dec;
    cin>>dec;
    cout << DecToBinary(n);

    long long bi; cin>>bi;
    cout << BiToDec(bi);

    return 0;
}

