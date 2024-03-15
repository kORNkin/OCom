#include<bits/stdc++.h>
using namespace std;
char thaiNum[] = {'๐','๑','๒','๓','๔','๕','๖','๗','๘','๙'};

string rev(string s)
{
    string tmp;
    for(int i=s.length()-1;i>=0;i--)
        tmp.push_back(s[i]);
    return tmp;
}
int ttoa(char n)
{
    for(int i=0;i<10;i++){
        if(n==thaiNum[i]) return i;
    }
}
string Plus(string a,string b){
    int n=a.length();
    int m=b.length();
    string x = rev(a);
    string y = rev(b);
    string ans;
    int i=0,c,d,tmp,k=0;
    for(;i<m;i++){
        c=ttoa(x[i]);
        d=ttoa(y[i]-'0');
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a,b; cin>>a>>b;
    if(a.length()<b.length())
        swap(a,b);
    cout << Plus(a,b) << "\n";

    return 0;
}