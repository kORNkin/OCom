#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    map<char , vector<int>> m;
    m['F'] = {5,1,3,4,6,2};
    m['B'] = {2,6,3,4,1,5};
    m['L'] = {4,2,1,6,5,3};
    m['R'] = {3,2,6,1,5,4};
    m['C'] = {1,4,2,5,3,6};
    m['D'] = {1,3,5,2,4,6};

    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        int x=2;
        vector<int> a={1,2,3,4,5,6},b(6);
        for(auto& c:s){
            for(int i=0;i<=5;i++)
                b[i] = a[m[c][i]-1];
            a=b;
        }
        cout << a[1] << " ";
    }

    return 0;
}