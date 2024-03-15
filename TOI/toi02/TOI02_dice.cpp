#include <bits/stdc++.h>
using namespace std;

void swap(int& a,int& b,int& c,int& d) {
	int tmp = a;
	a = b;
	b = c;
	c = d;
	d = tmp;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		int t=1,f=2,l=3,r=4,bk=5,bm=6;
		for(int i=0;i<s.size();i++) {
			if (s[i]=='F') 
                swap(bk, bm, f, t);
			else if (s[i]=='B') 
                swap(t, f, bm, bk);
			else if (s[i]=='L') 
                swap(bm, l, t, r);
			else if (s[i]=='R') 
                swap(r, t, l, bm);
			else if (s[i]=='C') 
                swap(l, f, r ,bk);
			else if (s[i]=='D') 
                swap(bk, r, f, l);
		}
		cout << f << " ";
	}

    return 0;
}
