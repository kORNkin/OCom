#include<bits/stdc++.h>
using namespace std;
int par[100001];

void solve(string in, string out){

    ifstream fin;
    ofstream fout;

    fin.open(in);
    fout.open(out);

    int n, t; fin >> n >> t;

    vector<long long> v;
    for(int i = n - 1; i >= 0; i--){
        long long x, s; fin >> x >> s;
        x = - (x + s * t);
        if(v.empty() || v.back() <= x) {
            v.push_back(x);
        }
        else {
            auto it = upper_bound(v.begin(),v.end(), x);
            *it = x;
        }
    }

    fout << v.size() << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 10; i++){
        solve("./input/input" + (i == 10 ? "10" : "0" + to_string(i)) + ".txt", 
            "./output/output" + (i == 10 ? "10" : "0" + to_string(i)) + ".txt");
    }

    return 0; 
}