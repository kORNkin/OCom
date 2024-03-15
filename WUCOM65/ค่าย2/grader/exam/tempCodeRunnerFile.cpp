        while(x){
            sum+=x%10;
            x/=10;
        }
        cout << i << ' '<< abs(i-sum) << " " <<  abs(i-sum)/9  << '\n';
        if(abs(i-sum) >= s) {
            cnt++; ans=i;
        }