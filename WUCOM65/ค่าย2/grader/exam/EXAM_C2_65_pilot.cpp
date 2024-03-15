//2 solve: sliding window || dsu set(hard)
//I don't understand yet.

//solve by someone on internet
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e6 + 5;
const int lg = 60;
const int mod = 998244353;
const long long oo = 1e18;
const int lim = 1e6;
ll cnt[N], h[N], r[N], l[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector<ll> st;
    for (int i = 1; i <= n; i++){
        while (st.size()){
            if (h[st.back()] <= h[i]){
                st.pop_back();
            } else break;
        }
        if (st.size()) l[i] = st.back() + 1;
        else l[i] = 1;
        st.push_back(i);
    }
    st.clear();
    for (int i = n; i >= 1; i--){
        while (st.size()){
            if (h[st.back()] < h[i]){
                st.pop_back();
            } else break;
        }
        if (st.size()) r[i] = st.back() - 1;
        else r[i] = n;
        st.push_back(i);
    }
    for (int i = 1; i <= n; i++){
        cnt[h[i]] += (i - l[i] + 1) * (r[i] - i + 1);
    }
    for (int i = 2; i <= lim; i++) cnt[i] += cnt[i - 1];
    while (q--){
        ll x;
        cin >> x;
        cout << cnt[x] << endl;
    }
}

/*
//P'Tokyo's solve

#include<bits/stdc++.h>

using namespace std;

int n , q ; 

int height[1000002] , pa[1000002] , group[1000002] ;
vector<int>idx_h[1000002] ;
long long qs[1000002] ;
bool visited[1000002] ;

int fp(int x){
    if(pa[x] == x)return x ;
    return pa[x] = fp(pa[x]) ;
}

long long cal(long long x){
    return x * (x + 1) / 2 ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){
        pa[i] = i ;
        cin >> height[i] ;
        idx_h[height[i]].push_back(i) ;
        group[i] = 1 ;
    }

    //preprocess

    qs[0] = 0 ;

    for(int h = 1 ; h <= 1000000 ; h ++ ){

        qs[h] = qs[h - 1] ;

        for(auto idx : idx_h[h]){

            if(visited[idx - 1] && visited[idx + 1]){

                visited[idx] = true ;

                int root_now = fp(idx) ;
                int root_r = fp(idx + 1) ;
                int root_l = fp(idx - 1) ;

                qs[h] -= cal(group[root_l]) ;
                qs[h] -= cal(group[root_r]) ;

                group[root_now] += group[root_l] ;
                group[root_now] += group[root_r] ;

                group[root_l] = 0 ;
                group[root_r] = 0 ;

                pa[root_l] = root_now ;
                pa[root_r] = root_now ;


                qs[h] += cal(group[root_now]) ;

            }

            else if(visited[idx - 1]){

                visited[idx] = true ;

                int root_now = fp(idx) ;
                int root_l = fp(idx - 1) ;

                qs[h] -= cal(group[root_l]) ;

                group[root_now] += group[root_l] ;
                group[root_l] = 0 ;
                pa[root_l] = root_now ;

                qs[h] += cal(group[root_now]) ;

            }

            else if(visited[idx + 1]){
                
                visited[idx] = true ;

                int root_now = fp(idx) ;
                int root_r = fp(idx + 1) ;

                qs[h] -= cal(group[root_r]) ;

                group[root_now] += group[root_r] ;
                group[root_r] = 0 ;
                pa[root_r] = root_now ;

                qs[h] += cal(group[root_now]) ;
            }

            else {
                visited[idx] = true ;
                qs[h] += 1 ;
            }

        }

    }

    while(q -- ){
        int x ; cin >> x ;
        cout << qs[x] << '\n' ;
    }

    return 0 ;
}
*/