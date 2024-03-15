/*
Problem: 15 Puzzle
Algor: Least Cost Search
Author: kornkin
Time Comp: ~0.5 ms
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> arr(4, vector<int>(4)), pz(4, vector<int>(4));

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
bool found;

map<int, pair<int,int>> mp;
map<vector<vector<int>>, bool> vis;

struct Node{
    int x, y, k, cnt;
    vector<vector<int>> arr;

    bool operator < (const Node &r) const{
        if(cnt + k == r.cnt + r.k) return cnt < r.cnt;
        return cnt + k > r.cnt + r.k;
    }
};

bool valid(int x, int y){
    if(x < 0 || y < 0 || x > 3 || y > 3) return 0;
    return 1;
}

int check(vector<vector<int>> &now = arr){
    int dis = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) {
            dis += abs(mp[now[i][j]].first - i) + abs(mp[now[i][j]].second - j);
        } 
    }       
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

            pz[i][j] = 4 * i + j + 1;
            mp[pz[i][j]] = {i, j};
        } 
    }    
    pz[3][3] = 0;
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
            if(!valid(x + dx[i], y + dy[i])) continue;

            swap(now.arr[x][y], now.arr[x + dx[i]][y + dy[i]]);

            if(vis[now.arr]) {
                swap(now.arr[x][y], now.arr[x + dx[i]][y + dy[i]]);
                continue;
            }

            pq.push({x + dx[i], y + dy[i], check(now.arr), now.cnt + 1, now.arr});

            swap(now.arr[x][y], now.arr[x + dx[i]][y + dy[i]]);
        }
    }

    return 0;
}
