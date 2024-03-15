#include<bits/stdc++.h>
using namespace std;

//1100++ ms --> less than 400 ms

template<typename T>
void scan (T &x) {
    x = 0; bool r = 0; int c;
    while ((!(c > 47 && c < 58)) && c != '-') c = getchar();
    if (c == '-') r = 1, c = getchar();
    for (; (c > 47 && c < 58); c = getchar()) x = (x << 1) + (x << 3) + c - 48;
    if (r) x = -x;
}

//or this
int scan2() {
	int c = getchar();
	bool negative = false;
	int result{0};
	if (c == '-') {
		negative = true;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		result *= 10;
		result += c - '0';
		c = getchar();
	}
	if (negative)
		result *= -1;
	return result;
}

int n, w, mx, len, sum;
deque<pair<int, int>> dq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //cin >> n >> w;
    scan(n), scan(w);
    
    dq.emplace_back(0,0);
    for(int i = 1; i <= n; i++){
        int x; 
        //cin >> x;
        scan(x);
        sum += x;
        while(!dq.empty() && i - dq.front().first > w) dq.pop_front();
        while(!dq.empty() && sum <= dq.back().second) dq.pop_back();
        dq.emplace_back(i, sum);
        if(mx < sum - dq.front().second){
            mx = sum - dq.front().second;
            len = i - dq.front().first;
        }else if(mx == sum - dq.front().second) len = min(len, i - dq.front().first);
    }
    
    cout << mx << '\n' << len;

    return 0;
}
