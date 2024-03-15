#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(0));

    for(int k = 1; k <= 10; k++){

        ofstream fout;
        fout.open("./input/input" + (k == 10 ? "10" : "0" + to_string(k)) + ".txt");

        int n, c;

        n = (rand() % (20000 - 100 + 1)) + 100;
        c = (rand() % (20000 - 100 + 1)) + 100;

        fout << n << ' ' << c << '\n';

        for(int i = 0; i < n; i++){
            int x = (rand() % (200000 - 1 + 1)) + 1;
            fout << x << '\n';
        }

        for(int i = 0; i < c; i++){
            int l = (rand() % (1000 - 1 + 1)) + 1;
            int d = (rand() % (1000 - 0 + 1)) + 0;
            int r = (rand() % (l + d - l + 1)) + l;

            fout << l << ' ' << r << '\n';
        } 
    }

    return 0;
}

