#include<bits/stdc++.h>
using namespace std;
string rev(string s)
{
    string tmp;
    for(int i=s.length()-1;i>=0;i--)
        tmp.push_back(s[i]);
    return tmp;
}
string Plus(string a,string b){
    int n=a.length();
    int m=b.length();
    string x = rev(a);
    string y = rev(b);
    string ans;
    int i=0,c,d,tmp,k=0;
    for(;i<m;i++){
        c=x[i]-'0';
        d=y[i]-'0';
        tmp=c+d+k;
        if(tmp>=10){
            k=tmp/10;
            tmp%=10;
        }
        else k=0;
        ans.push_back(tmp+'0');
    }   
    for(;i<n;i++){
        tmp=x[i]-'0';
        tmp+=k;
        if(tmp>=10){
            k=tmp/10;
            tmp%=10;
        }
        else k=0;
        ans.push_back(tmp+'0');
    }
    if(k!=0) ans.push_back(k+'0');
    return rev(ans);
}
string Times(string a,string b){
    //if(a.size() < b.size()) swap(a,b);
    //cout << a << " " << b <<'\n';
    string x[b.size()];

    for(int j=b.size()-1;j>=0;j--){
        int r = 0;
        for(int i=b.size()-1;i>j;i--) x[j].push_back('0');

        for(int i=a.size()-1;i>=0;i--){
            int n = (a[i]-'0') * (b[j]-'0') + r;
            x[j].push_back((n%10)+'0');
            r = n/10;
        } 
        if(r) x[j].push_back(r+'0');
    }
    string ans=rev(x[0]);
    for(int j=1;j<b.size();j++){
        ans = Plus(ans,rev(x[j]));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    string n = "1";
    while(t--){
        string x; cin>>x;
        n = Times(n,x);
        //cout << n << "\n";
    }
    for(auto c:n){
        if(c!='0'){
            cout << n;
            return 0;
        }
    }
    cout << 0;

    return 0;
}