#include<bits/stdc++.h>
using namespace std;
struct mine{
    double a, b, sum;
    int idx;
};

int n, k;
double a[100001], b[100001], c[100001], qsa[100001], qsb[100001], ans;
priority_queue<double, vector<double>, greater<double>> pq;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i], qsa[i] = qsa[i - 1] + a[i];
    for(int i = 1; i <= n; i++) cin >> b[i], qsb[i] = qsb[i - 1] + b[i];
    
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            pq.push({(qsa[j] - qsa[i - 1]) / (qsb[j] - qsb[i - 1])});
            while(pq.size() > k) pq.pop();
        }
    }

    cout << fixed << setprecision(3) << floor(pq.top() * 1000) / 1000;

    return 0;
}
/*
5 1
6 5 14 3 6
7 3 11 11 2
*/