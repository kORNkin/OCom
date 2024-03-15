#include<bits/stdc++.h>
using namespace std;

void solve(string in, string out){

    ifstream read(in);
    ofstream fout(out);

	int num_chickens, num_cows;
	read >> num_chickens >> num_cows;

	vector<int> chickens(num_chickens);
	for (int &c : chickens) { read >> c; }
	std::sort(chickens.begin(), chickens.end());

	vector<pair<int, int>> cows(num_cows);
	for (pair<int, int> &c : cows) { read >> c.first >> c.second; }
	// sort by starting time, tiebreak by ending time
	std::sort(cows.begin(), cows.end());

	int num_helped = 0;
	int cow_at = 0;
	std::priority_queue<int> available_cows;
	for (int c : chickens) {
		// add all the cows whose start times now include the chicken's time
		while (cow_at < cows.size() && cows[cow_at].first <= c) {
			available_cows.push(-cows[cow_at].second);
			cow_at++;
		}
		// remove all the ending times that end too early for the chicken
		while (!available_cows.empty() && -available_cows.top() < c) {
			available_cows.pop();
		}
		// have the cow help the chicken w/ the earliest ending time
		if (!available_cows.empty()) {
			num_helped++;
			available_cows.pop();
		}
	}

	fout << num_helped;
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
