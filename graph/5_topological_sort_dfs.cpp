//Problem Statement: https://www.codingninjas.com/codestudio/problems/topological-sort_1082550?leftPanelTab=0

// Topological Sort is basically koi aisa path jo adjency list ko follor kare which means ki given directed graph me koi aisa path ho 
// jo ki hamesha adjency list me jo bhi element hai us se pehle aaye.
// to simply stack ka use krke ise implement karenge like jo element bilkul end me aagya ki ab aage ni jaa skte use stack me daaldo
// at the end jese jese nikalenge vo ek valid path hi dedega hame

#include <bits/stdc++.h> 

void dfs(int node , vector<bool> &visited , stack<int> &st , vector<vector<int>> &adj){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i])
            dfs(i , visited , st , adj);
    }
    st.push(node);
    return ;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int a = edges[i][0];
        int b = edges[i][1];
        adj[a].push_back(b);
    }
    vector<bool> visited(v , false);
    stack<int> st;
    vector<int> ans;
    for(int i=0;i<v;i++)
        if(!visited[i])
            dfs(i , visited , st , adj);
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}