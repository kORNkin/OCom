#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k; cin>>k;
    while(k--){
        double x1,y1,x2,y2,x3,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        cout << fixed << setprecision(2) << abs(x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3)/2 << "\n";
    }

    return 0;
}

