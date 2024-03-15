#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int par[1001];
int rankk[1001];
int cnt=0;

int finds(int i){ cnt++; return (par[i]==i? i: finds(par[i])); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        pair<int,int> p[n+1];
        vector<pair<int,pair<int,int>>> arr;
        for(int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                arr.push_back({abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second), {i,j}});
            }
        }
        sort(arr.begin(),arr.end());
        
        for(int i=1;i<=n;i++) par[i]=i, rankk[i]=0;
        int cnt=n;
        for(auto e:arr){
            if(cnt==k) break;
            int a = finds(e.s.f); 
            int b = finds(e.s.s);
            if(a==b) continue;
            if(rankk[a] < rankk[b]) par[a] = b, cnt--;
            else {
                par[b] = a; cnt--;
                if(rankk[a] == rankk[b]) rankk[a]++;
            }
        } int mn = 1e9;
        for(auto e:arr){
            int a = finds(e.s.f); 
            int b = finds(e.s.s);            
            if(a != b){
                mn = min(mn,e.f);
            }
        } cout << mn << '\n';
    }

    return 0;
}

/*
// Chat GPT algorithm (faster than me ;-; we gonna lose our job)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person {
    int x, y, id;
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<Person> people;
vector<Edge> edges;
int parent[1005], sz[1005];
int n, k;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
}

int distance(int i, int j) {
    return abs(people[i].x - people[j].x) + abs(people[i].y - people[j].y);
}

int min_strength() {
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    int count = n;
    for (auto edge : edges) {
        if (count == k) break;
        int u = edge.u, v = edge.v;
        if (find(u) != find(v)) {
            merge(u, v);
            count--;
        }
    }
    int min_d = 2e9;
    for (auto edge : edges) {
        int u = edge.u, v = edge.v, w = edge.w;
        if (find(u) != find(v)) {
            min_d = min(min_d, w);
        }
    }
    return min_d;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        people.clear();
        edges.clear();
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            people.push_back({x, y, i});
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                edges.push_back({i+1, j+1, distance(i, j)});
            }
        }
        cout << min_strength() << endl;
    }
    return 0;
}


*/