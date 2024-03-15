#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(!b)
        return a;
    return gcd(b,a%b);
}

void bi(int n)
{
    if(!n) return;
    bi(n/2);
    cout << n%2; 
}   

void counter(vector<int> x,int m,int n)
{
    if(m==n){
        for(auto e:x)
            cout << e << " ";
        cout << "\n";
    }else {
        x[m]=0;
        counter(x,m+1,n);
        x[m]=1;
        counter(x,m+1,n);
    }

}

void biCounter(int n){
    vector<int> x(n,0);
    counter(x,0,n);
}

int fac(int n){
    if(n==1) return 1;
    return n*fac(n-1);
}

int fibo(int n){
    if(n==1 || n==2) return 1;
    return fibo(n-1) + fibo(n-2);
}

int mem[10000];
int fiboDP(int n){
    if(mem[n]) return mem[n];
    return mem[n]=fiboDP(n-1) + fiboDP(n-2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cout << gcd(144,120) << "\n"; //gcd
    bi(20); cout << "\n"; //dec to binary
    biCounter(4); //binary state space search
    cout << fac(5) << "\n"; //factory
    cout << fibo(6); //fibonucci

    memset(mem,0,sizeof(mem));
    mem[1]=1;
    mem[2]=1;
    cout << "\n"<<fiboDP(6);

    return 0;
} 

