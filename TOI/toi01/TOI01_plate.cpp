#include <bits/stdc++.h>
using namespace std;
#define endll "\n"
typedef long long ll;
typedef double db;

struct sd
{
    int cl;
    int id;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a,b;
    cin >> a >> b;
    
    sd data[b];
    for(int i=0;i<b;i++)
    {
        cin >> data[i].cl >> data[i].id;
    }

    list<sd> l;
    char com;
    cin >> com;
    while(com!='X')
    {
        if(com=='E')
        {
            int x;
            cin >> x;
            for(int i=0;i<b;i++)
            {
                if(data[i].id==x)
                {
                    if(!l.empty())
                    {
                        bool is=1;
                        for(auto j=l.begin(); j!=l.end();++j)
                        {
                            if( j->cl == data[i].cl)
                            {
                                //cout << "    " << j->cl << "    ";
                                l.insert(j,1,data[i]);
                                is=0;
                                break;
                            }
                        }
                        if(is) l.push_front(data[i]);

                        
                    }else l.push_front(data[i]);
                
                }
            }
            /*for(auto x:l)
            {
                cout << x.id << " ";
            } cout << endll << "------" << endll;*/
        }
        else if(com=='D')
        {
            if(!l.empty()){
                cout << l.back().id << endll;
                l.pop_back();
            }else cout << "empty" << endll;
        }
        cin >> com;
    }
    cout << 0;

    return 0;

}