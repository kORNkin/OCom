#include<bits/stdc++.h>
using namespace std;

bool ch[300];

float randomFloat()
{
    return (float)(rand()) / (float)(RAND_MAX);
}
 
int randomInt(int a, int b)
{
    if (a > b)
        return randomInt(b, a);
    if (a == b)
        return a;
    return a + (rand() % (b - a));
}

float randomFloat(int a, int b)
{
    if (a > b)
        return randomFloat(b, a);
    if (a == b)
        return a;
 
    return (float)randomInt(a, b) + randomFloat();
}

int main(){ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    srand(time(NULL)); 
    
    for(int j = 0; j <= 0; j++){

        ofstream fout;
        fout.open("./input/input" + (j==10? "10" : "0" + to_string(j)) + ".txt");
        
        int N = (rand() % (10 - 1 + 1)) + 1 ;

        N = 1;

        fout << N << '\n';
        while(N--){

            vector<int> x;
            vector<double> y;
            
            int d = (rand() % 4) + 1 ;
            d = 2;

            int lb = 14, ub = 18;

            int sz = (rand() % (ub - lb + 1)) + lb;

            fout << sz << '\n';

            lb = 0, ub = 50;

            memset(ch, 0, sizeof(ch));
            for(int i = 0; i < sz; i++) {
                int n = (rand() % (ub - lb + 1)) + lb;
                while(ch[n]) 
                    n = (rand() % (ub - lb + 1)) + lb;
                ch[n] = 1;

                float a = randomFloat(5, 6);
                float c = randomFloat(200, 210);

                x.push_back(n);
                y.push_back(a*pow(n, d) + c);
            }

            for(int i = 0; i < sz; i++){
                fout << x[i] << ", ";
            } fout << '\n';

            for(int i = 0; i < sz; i++){
                fout << fixed << setprecision(3) << y[i] << ", ";
            } fout << '\n';


            for(int i = 0; i < sz; i++){
                fout << x[i] << " ";
            } fout << '\n';

            for(int i = 0; i < sz; i++){
                fout << fixed << setprecision(3) << y[i] << " ";
            } fout << '\n';
        }
    }

    return 0;
}
