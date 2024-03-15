#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Box{
    ll high, hole;
};
ll mn = LLONG_MAX;
ll sum = 0;
int main (){ 

    ios_base::sync_with_stdio(0);
    cin.tie(0); cin.tie(0);

    int n; cin >> n;
    Box box[n];
    for(int i = 0; i < n; i++){
        cin >> box[i].high;
        mn = min(mn, box[i].high);
    }
    for(int i = 0; i < n; i++)
        cin >> box[i].hole;
 
    sort(box, box + n, [&](Box a,Box b){
        return a.hole < b.hole;
    });

    for(int i = 1; i < n; i++){
        sum += box[i].hole - box[0].hole;
    }
    ll ind = box[0].hole , summ = sum;
    for(int i = 1; i < n; i++){
        if(box[i].hole > mn) break;
        sum -= (box[i].hole - box[i-1].hole)* n - box[i-1].high;
        if(sum < summ){
            summ = sum;
            ind = box[i].hole;
        }
    }
    cout << ind << " " << summ;
    return 0 ; 
} 