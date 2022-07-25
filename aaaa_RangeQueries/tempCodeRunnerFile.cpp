n = A; SCC();
    // if(cnt==2)return 1;
    // int indeg[cnt]{};
    // for(int i=1;i<=n;i++){
    //     for(auto node : graph[i]){
    //         if(ans[i]!=ans[node])indeg[ans[node]]++;
    //     }
    // }
    // int start = 1;
    // for(int i=1;i<cnt;i++){
    //     if(indeg[i]==0){
    //         start = i;
    //         break;
    //     }
    // }
    // int u = 1;
    // for(int i=1;i<=n;i++){
    //     if(ans[i]==start){
    //         u = i; break;
    //     }
    // }
    // int done[n+1]{}; cnt = 0;
    // function<void(int)> dfs = [&](int node){
    //     done[node] = 1; cnt++;
    //     for(auto i : graph[node]){
    //         if(!done[i])dfs(i);
    //     }
    // };
    // dfs(u);