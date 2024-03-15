/*
Problem: TwinCousinSexy
Author: kornkin
Algor: Sieve Of Eratosthenes
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
bitset<N> pm;
int a, b;
int t, c, s;

void sieve(){
    pm[0] = pm[1] = 0; 
    for(int i = 4; i <= b + 6; i += 2) {
        pm[i] = 0;
    }
    for(int i = 3; i <= b + 6; i += 2){
        if(pm[i]){
            for(int j = i + i; j <= b + 6; j += i) pm[j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> a >> b;
    
    for(int i = 0; i <= b + 6; i++) pm[i] = 1;

    sieve();
    
    for(int i = a; i <= b; i++){
        if(pm[i]){
            if((i > 2 && pm[i - 2]) || pm[i + 2]) t++; 
            if((i > 4 && pm[i - 4]) || pm[i + 4]) c++;
            if((i > 6 && pm[i - 6]) || pm[i + 6]) s++;
        }
    } 
    cout << t << '\n' << c << '\n' << s;


    return 0;
}