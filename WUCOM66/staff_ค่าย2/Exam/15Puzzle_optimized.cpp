/*
Problem: 15 Puzzle
Algor: Least Cost Search
Author: kornkin
Time Comp: ~0.3 ms
*/
#include<bits/stdc++.h>
using namespace std;

array<array<int, 4>, 4> arr, pz = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}}};
//instead of vector ! 

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool found;

unordered_map<int, pair<int,int>> mp;
map<array<array<int, 4>, 4>, bool> vis;

struct Node{
    int x, y, k, cnt;
    array<array<int, 4>, 4> arr;

    bool operator < (const Node &r) const{
        if(cnt + k == r.cnt + r.k) return cnt < r.cnt;
        return cnt + k > r.cnt + r.k;
    }
};

bool valid(const int &x, const int &y){
    return x >= 0 && y >=0 && x < 4 && y < 4;
}

int check(const array<array<int, 4>, 4> &now = arr){
    int dis = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) 
            dis += abs(mp[now[i][j]].first - i) + abs(mp[now[i][j]].second - j);
         
    return dis;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 0) x = i, y = j;

            mp[pz[i][j]] = {i, j};
        } 
    }    

    mp[0] = {3, 3};

    priority_queue<Node> pq;

    pq.push({x, y, check(), 0, arr});

    while(!pq.empty()){
        Node now = pq.top();
        pq.pop();

        if(!now.k){
            cout << now.cnt;
            break;
        }

        x = now.x, y = now.y;
        vis[now.arr] = 1;

        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(!valid(xx, yy)) continue;

            swap(now.arr[x][y], now.arr[xx][yy]);

            if(vis[now.arr]) {
                swap(now.arr[x][y], now.arr[xx][yy]);
                continue;
            }

            pq.push({xx, yy, check(now.arr), now.cnt + 1, now.arr});

            swap(now.arr[x][y], now.arr[xx][yy]);
        }
    }

    return 0;
}
