#include<bits/stdc++.h>
using namespace std;

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(0)); 
    
    for(int j = 5; j <= 10; j++){
        ofstream fout;
        fout.open("./input/input" + (j == 10? "10" : "0" + to_string(j)) + ".txt");

        int n, t;
        n = (rand() % (100000 - 50000 + 1)) + 50000;
        t = (rand() % (10000 - 1000 + 1)) + 1000;

        fout << n << ' ' << t << '\n';

        int x, s;
        int l = 0, r = 4, range = 0;
        for(int i = 0; i < n ; i++){
            range = (rand() % 5) + 1;

            x = (rand() % (r - l + 1)) + l;

            l += r - l + 1;
            r += range;

            s = (rand() % (10000 - 1000 + 1)) + 1000;

            fout << x << ' ' << s << '\n';
        }
    }

    return 0;
}
