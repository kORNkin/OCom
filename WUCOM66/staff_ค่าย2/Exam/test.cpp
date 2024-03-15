/*
Problem: 3ValueSort
Auther: CCYod
*/

#include <iostream>
using namespace std;

int a[100001], one, two;
long long c;

int main () {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) ++one;
        else if (a[i] == 2) ++two;
    }
    two += one;
    for (int i = n-1; i >= one; --i) if (a[i] == 1) {
        bool b = 1;
        if (i < two) for (int j = 0; j < one && b; ++j) if (a[j] == 2) swap(a[i], a[j]), ++c, b = 0;
        for (int j = 0; j < one && b; ++j) if (a[j] == 3) swap(a[i], a[j]), ++c, b = 0;
        for (int j = 0; j < one && b; ++j) if (a[j] == 2) swap(a[i], a[j]), ++c, b = 0;
    }
    for (int i = one; i < two; ++i) if (a[i] == 3) {
        bool b = 1;
        for (int j = n-1; j >= two && b; --j) if (a[j] == 2) swap(a[i], a[j]), ++c, b = 0;
    }
    cout << c;
}