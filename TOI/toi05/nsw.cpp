#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string key;
    cin>>key;
    deque<int> wl[3];
    for(int i=0;i<3;i++){
        int n = key[i]-'0';
        for(int j=0;j<9;j++){
            if(n==10) n=1;
            wl[i].push_back(n);
            n++;
        }
    }
    
    string code;
    cin>>code;
    for(int s=0;s<code.size();s++){
        int x = code[s]-'0';
        for(int j=0;j<3;j++){
            x = wl[j][x-1];
        }
        cout << x;

        for(int j=0;j<3;j++){
            int n;
            if(j==1){
                n = wl[j].back();
                wl[j].pop_back();
                wl[j].push_front(n);
            }else {
                n = key[j]-'0';
                for(int k=0;k<n;k++){
                    wl[j].push_back(wl[j][0]);
                    wl[j].pop_front();
                }
            }
        }        
    }

    return 0;
}