#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie(0);

    string pat = "aabaabaaa";
    int n = pat.size();

    int lps[n];

    lps[0] = 0;
    int i=0, j=1;

    while(j<n){
        if(pat[i] == pat[j]){
            lps[j] = i+1;
            i++;
            j++; 
        }
        else {
            if(i == 0){
                lps[j]=0;
                j++;
            }else {
                i = lps[i-1];
            }
        }
    }
    for(int i=0;i<n;i++) cout << lps[i] << ' ';

    return 0;
}
