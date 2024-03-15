#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,1,-1,-1,0,0,1,-1};
int dy[] = {1,-1,1,-1,1,-1,0,0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL));

    for(int k = 0; k <= 0; k++){

        ofstream fout;
        fout.open("./input/input" + (k == 10 ? "10" : "0" + to_string(k)) + ".txt");

        int n, m;

        n = (rand() % (20 - 10 + 1)) + 10;
        m = (rand() % (20 - 10 + 1)) + 10;

        fout << n << ' ' << m << '\n';

        bool g[1005][1005];
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int x = (rand() % 4) + 1;
                if(x == 1) g[i][j] = 1;
                else g[i][j] = 0;
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int x = (rand() % 4) + 1;
                bool ch = 0;
                for(int l = 0; l < 8; l++){
                    if(g[i + dx[l]][j + dy[l]] == 1) ch = 1;
                }
                if(x == 1 && ch) g[i][j] = 1;
                else g[i][j] = 0;
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(g[i][j]) fout << '#';
                else fout << '.';
            } fout << '\n';
        }
    }

    return 0;
}

