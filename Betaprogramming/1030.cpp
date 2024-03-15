#include<bits/stdc++.h>
using namespace std;

struct rice{
    int wg_left;
    double ppk;
    bool operator<(const rice& r) const{
        return ppk < r.ppk;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout<<fixed<<setprecision(3);

    int n;
    cin>>n;
    deque<rice> rc;
    while(n--){
        int wg,pc;
        cin>>pc>>wg;
        double ppk = double(pc*1.0/wg*1.0);
        rc.push_back({wg,ppk});
    }
    sort(rc.begin(),rc.end());

    int k;
    double ans;
    cin>>n;
    while(n--){
        ans=0;
        cin>>k;
        for(auto &e:rc){
            if(e.wg_left==0) {
                rc.pop_front();
                continue;
            }
            if(e.wg_left>=k){
                ans+=e.ppk*k;
                e.wg_left-=k;
                break;
            }else {
                k-=e.wg_left;
                ans+=e.ppk*e.wg_left;
                e.wg_left=0;
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}