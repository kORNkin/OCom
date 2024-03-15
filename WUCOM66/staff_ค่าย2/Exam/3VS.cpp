/*
Problem: 3ValueSort
Author: kornkin
Algor: Sorting + Greedy
*/
#include<bits/stdc++.h>
using namespace std;
long long n, arr[1000001], use[1000001];
int cnt[4][4];

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        use[i] = arr[i];
    }

    sort(use, use + n);
    for(int i = 0; i < n; i++){
        if(use[i] != arr[i]){
            cnt[use[i]][arr[i]]++;
        }
    }   

    int ans = 0;

    while(1){
        bool ch = 1;
        int x = 1, y = 1;

        for(int i = 1; i <= 3; i++){
            for(int j = i + 1; j <= 3; j++){
                if(cnt[i][j] && cnt[j][i]){
                    int tmp = min(cnt[i][j], cnt[j][i]);
                    ans += tmp;
                    cnt[i][j] -= tmp;
                    cnt[j][i] -= tmp;
                }else if(cnt[i][j]) x = i, y= j;
            }
        }
        
        if(cnt[x][y]){
            for(int i = 1; i <= 3; i++){
                if(cnt[y][i]){
                    int tmp = min(cnt[x][y], cnt[y][i]);
                    ans += tmp;
                    cnt[x][y] -= tmp;
                    cnt[y][i] -= tmp;
                    cnt[x][i] += tmp;

                    if(!cnt[x][y]) break;
                }
            }
        }

        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                if(cnt[i][j]) ch = 0; 
            }
        }

        if(ch) break;
    }

    cout << ans;

    return 0;
}
/*
1 1 2 2 2 3 3 3 3
3 1 2 3 1 2 3 3 2

1 1 2 3 3 2 3 3 2

1 2(1) 3(1)  2
2 1(2) 3(1)  3
3 2(2)       2
  1  2  3
1 0  0  0
2 0  0  2
3 0  2  0

1 1(1) 1(1)  2
2 2(1) 3(2)  3
3 2(2)       2

2 2 1 3 2 1 3
1 1 2 2 2 3 3 

1 2(2)       2
2 1(1) 3(1)  2
3 1(1)       1

  1  2  3
1 0  1  0
2 2  0   0
3 1  1  0
*/