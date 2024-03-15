#include<bits/stdc++.h>
using namespace std;
string txt = "ABABDABACDABABCABAB";
string pat = "ABABCABAB";
int m,n;

void preprocess(int lps[]){
    lps[0] = 0;
    int i = 0, j = 1;
    while(j < n){
        if(pat[i] == pat[j]){
            lps[j] = i+1;
            i++; j++;
        }else {
            if(i == 0){
                lps[j] = 0;
                j++;
            }else {
                i = lps[i-1];
            }
        
        }
    }
}

void KMP(){
    int lps[n];
    preprocess(lps);

    int i = 0, j = 0;
    while(n - i <= m - j){
        if(pat[i] == txt[j]){
            i++; j++;
            if(i == n){
                i = lps[i-1];
                cout << "found pattern at:" << j - n << '\n'; 
            }
        }else {
            if(i == 0) j++;
            else i = lps[i-1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    m = txt.size();
    n = pat.size();
    KMP();

    return 0;
}