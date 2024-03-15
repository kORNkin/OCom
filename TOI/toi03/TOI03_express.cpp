#include<bits/stdc++.h>
using namespace std;
int op(char c){
    if(c=='+') return 1;
    if(c=='*') return 2;
    if(c=='^') return 3;
}
struct cmp{
    bool operator () (const int &a, const int &b){
        return op(a) < op(b);
    }
};

void print(bool nll ,int i,vector<int> &n, vector<string> &ans){
    cout << "op(";
    for(int j=n.size()-1;j>0;j--){
        if(j==1){
            cout << n[j] << ",p";
            for(int l=0;l<n.size()-1;l++)
                cout << ')';
            if(!nll)cout << "=" << ans[n[i]-1] << '\n';
            else cout << "=null\n";
        }else {
            cout << n[j]<<",op(";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s; cin>>s;   

    int q; cin>>q;
    while(q--){

        vector<string> ans;
        vector<int> n;
        int x; cin>>x; 
        n.push_back(1);
        while(x){
            n.push_back(x);
            cin>>x;
        } 

        bool nll=0;
        if(s.size()==1 && n.size()==1){
            if(n[0]!=1) nll=1;
            ans.push_back(s);
            print(nll,0,n,ans);
            continue;
        }

        int cnt_brac=0;
        bool brac_case=1;
        int brac=0;
        string tmp;
        ans.push_back(s);
        
        for(int i=0;i<n.size();i++){
            if(n[i] > ans.size()) {
                nll=1;
                break;
            }
            string ss= ans[n[i]-1];
        
            set<char,cmp> set;
            cnt_brac=0;
            brac_case=1;
            for(int j=0;j<ss.size();j++){
                char c=ss[j];
                if(c=='+' || c=='*' || c=='^')
                    set.insert(c);
                if(c=='(') cnt_brac++;
                else if(c==')') cnt_brac--;
                if(!cnt_brac && j!=ss.size()-1) brac_case = 0;
            }

            if(i!=n.size()-1) ans.clear();
            bool ch=0;
            brac=0;
            if(ss.size() == 1){
                ans.push_back(ss);
            }
            while(!ch && !set.empty() && i!=n.size()-1){
                
                for(int j=0;j<ss.size();j++){
                    if(brac_case && ss[j]=='(' && ss[ss.size()-1]==')'){
                        j++;
                        while(j<ss.size()-1){
                            tmp+=ss[j];
                            j++;
                        }
                        ans.push_back(tmp);
                        ch=1;
                        break;
                    }
                    if(ss[j]==*set.begin() && !brac){
                        ans.push_back(tmp);
                        tmp="";
                        ch=1;
                    }else {
                        tmp.push_back(ss[j]);
                        if(ss[j]=='(') brac++;
                        else if(ss[j]==')') brac--;
                    }
                } set.erase(*set.begin());
                if(!brac_case) ans.push_back(tmp);
                if(!ch) ans.clear();
                tmp="";
            }
            if(i==n.size()-1){
                print(nll,i,n,ans);
            }
        }
        if(nll) print(nll,0,n,ans);
    }
    return 0;
}