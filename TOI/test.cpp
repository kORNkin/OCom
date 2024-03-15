#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    
    string s, tmp;
    int r1 = 0, c1;
    getline(cin, s);

    for(int k = 0; k < s.size(); k++){
        if(s[k] >= '0' && s[k] <= '9'){
            tmp.push_back(s[k]);
        }else if(s[k] == '|'){
            r1 = stoi(tmp);
            tmp = "";
        }
    } c1 = stoi(tmp);

    int a[r1][c1];
    getline(cin, s);
    int i = 0, j = 0;
    tmp = "";
    for(int k = 0; k < s.size(); k++){
        if(j >= c1) i++, j %= c1;

        if(s[k] >= '0' && s[k] <= '9'){
            tmp.push_back(s[k]);
        }else if(s[k] == ','){
            a[i][j] = stoi(tmp);
            j++;
            tmp = "";
        }
    }

    int r2 = 0, c2;
    getline(cin, s);
    tmp = "";
    for(int k = 0; k < s.size(); k++){
        if(s[k] >= '0' && s[k] <= '9'){
            tmp.push_back(s[k]);
        }else if(s[k] == '|'){
            r2 = stoi(tmp);
            tmp = "";
        }
    } c2 = stoi(tmp);

    int b[r2][c2];
    getline(cin, s);
    i = 0, j = 0;
    tmp = "";
    for(int k = 0; k < s.size(); k++){
        if(j >= c2) i++, j %= c2;

        if(s[k] >= '0' && s[k] <= '9'){
            tmp.push_back(s[k]);
        }else if(s[k] == ','){
            b[i][j] = stoi(tmp);
            j++;
            tmp = "";
        }
    }

    int c[r1][c2];
    memset(c, 0, sizeof(c));

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            for(int k = 0; k < c2; k++){
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            cout << c[i][j] << ' ';
        } cout << '\n';
    }

    return 0;
}
