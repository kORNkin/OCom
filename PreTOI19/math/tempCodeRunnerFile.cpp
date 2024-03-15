    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            memset(vis,0,sizeof(vis));
            solve(i,j,1,1);
        }
    }