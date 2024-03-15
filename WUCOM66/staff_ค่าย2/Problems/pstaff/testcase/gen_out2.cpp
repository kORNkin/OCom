#include<bits/stdc++.h>
using namespace std;

int nchicken, ncow;
int T[20001];
pair<int, int> N[20001];

void solve(string in, string out){

    ifstream read(in);
    ofstream fout(out);

	read >> nchicken >> ncow;
    for(int i = 0; i < nchicken; i++) read >> T[i];
    for(int i = 0; i < ncow; i++) read >> N[i].first >> N[i].second;

    sort(N, N + ncow);
    sort(T, T + nchicken);

	priority_queue<int, vector<int>, greater<int>> now;
	int cow_idx = 0, cnt = 0;
	for(int i = 0; i < nchicken; i++){
		while(cow_idx < ncow && T[i] >= N[cow_idx].first) {
			now.push(N[cow_idx].second);
			cow_idx++;
		}

		while(!now.empty() && now.top() < T[i]) {
			now.pop();
		}

		if(!now.empty()){
			cnt++;
			now.pop();
		}
	}

    fout << cnt;
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
