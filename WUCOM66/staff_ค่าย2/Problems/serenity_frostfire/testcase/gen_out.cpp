/*
Problem: Serenity Frostfire
Author: kornkin.png
Algor: Math
BigO: n^2 * t
*/
#include<bits/stdc++.h>
using namespace std;

void solve(string in, string out){

    ifstream fin;
    ofstream fout;

    cout << in << '\n'; 

    fin.open(in);
    fout.open(out);

    int T; fin >> T;
    int sum = 0;
    while(T--){
        double delta[8], x[101];
        int n; fin >> n;
        for(int i = 0; i < n; i++){
            fin >> x[i];
        }

        map<double, double> y;

        double meanD = 0;
        double mx = -1e9, mn = 1e9;
        for(int i = 0; i < n; i++){
            double m; fin >> m;
            y[x[i]] = m;
        }

        double mxDelta = -1e9;

        for(int i = 1; i <= 4; i++){

            double meanA = 0, meanC = 0, cnt = 0;

            for(int j = 0; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    double tmp = pow(x[j], i) - pow(x[k], i);
                    if(tmp == 0) continue;
                    double a = (double)(y[x[j]] - y[x[k]])/ tmp;
                    double c = y[x[j]] - a * pow(x[j], i);
                    meanA += a;
                    meanC += c;
                    cnt ++;
                }   
            }

            meanA /= cnt;
            meanC /= cnt;

            mxDelta = -1e9;
            for(int j = 0 ;j < n; j++){
                mxDelta = max(mxDelta, abs(y[x[j]] - meanA * pow(x[j], i) - meanC) / y[x[j]]);
            }

            delta[i] = mxDelta;
        }

        mn = 1e9;
        int idx;
        for(int i = 1; i <= 4; i++){
            if(mn > delta[i]){
                mn = delta[i];
                idx = i;
            }
        }

        cout << idx << '\n';
        sum += idx;
    }

    cout << sum << '\n';
    fout << sum;
}

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 10; i++){
        solve("./input/input" + (i == 10 ? "10" : "0" + to_string(i)) + ".txt", 
            "./output/output" + (i == 10 ? "10" : "0" + to_string(i)) + ".txt");
    }

    return 0;
}
