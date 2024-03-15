/*
Problem: Serenity Frostfire ( WU Contest 2024 pre-exam 1 )
Author: kornkin.png
Algor: Math
BigO: 4 * n^2 * t
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T; 
    //Input จำนวนมนุษย์
    
    int sum = 0;
    //เก็บคำตอบ

    while(T--){
    //Loop T ครั้ง

        double delta[8], n[10001]; 
        //delta คือ array เก็บความต่างกันของค่า d จริงและ d เฉลี่ยที่หาจากสมการ
        //n คือ array เก็บค่า n จาก input

        int N; cin >> N;
        //เก็บจำนวนครั้งในการสื่อสาร

        for(int i = 0; i < N; i++){
            cin >> n[i]; 
        }
        //รับค่า n
         
        map<double, double> d;
        //ตัวแปรเก็บค่า d (เป็น map จะได้เรียกง่าย ๆ) 

        for(int i = 0; i < N; i++){
            double dd; cin >> dd;
            d[n[i]] = dd;
        }
        //รับค่า d และใส่ใน d map

        for(int i = 1; i <= 4; i++){
        //loop เพื่อหาค่า delta ของแต่ละ s (1 - 4)

            double meanE = 0, meanC = 0, cnt = 0;
            //meanE เก็บค่าเฉลี่ยของ e จากแต่ละการสื่อสาร เพื่อนำมาหาค่า d เฉลี่ย
            //meanC เก็บค่าเฉลี่ยของ i, t, y จากแต่ละการสื่อสาร โดยรวมกันเป็นค่า c เพื่อนำมาหาค่า d เฉลี่ย
            //cnt นับจำนวนครั้งในการคำนวณ

            for(int j = 0; j < N; j++){
                for(int k = j + 1; k < N; k++){
            //Loop หาค่าเฉลี่ยของ e, c

                    double div = pow(n[j], i) - pow(n[k], i);
                    //หาผลต่างของค่า n1^s - n2^s

                    if(div == 0) continue;
                    //หากเท่ากันจะหาค่าอื่น ๆ ไม่ได้

                    double e = (double)(d[n[j]] - d[n[k]])/ div;
                    double c = d[n[j]] - e * pow(n[j], i);
                    //แก้สมการหา e, c

                    meanE += e;
                    meanC += c;
                    cnt++;
                    //หา e, c เฉลี่ย
                }   
            }           

            meanE /= cnt;
            meanC /= cnt;
            //หา e, c เฉลี่ย

            double mxDelta = -1e9;
            for(int j = 0; j < N; j++){
                mxDelta = max(mxDelta, abs(d[n[j]] - meanE * pow(n[j], i) - meanC) / d[n[j]]);
            }
            //Loop เพื่อหา max delta ของแต่ค่า s ที่เป็นไปได้ (1 - 4)

            delta[i] = mxDelta;
            //เก็บค่า delta
        }

        double mn = 1e9;
        double idx;
        for(int i = 1; i <= 4; i++){
            if(mn > delta[i]){
                mn = delta[i];
                idx = i;
            }
        }
        //เก็บค่า min delta

        sum += idx;
        //หา sum ของ s
    }

    cout << sum;

    return 0;
}