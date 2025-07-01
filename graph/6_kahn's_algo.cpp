// Problem : https://www.naukri.com/code360/problems/topological-sort_982938?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM

// It is nothing but the topological sort using BFS 
// isme hum har node ki indegree nikalenge ki kitne nodes is node ko point karte hain aur jo 0 honge unhe queue me dalte jaenge 
// aur ab jab vo node humne traverse krliya to uske adjacent nodes ki indegree ko decrease karte jaenge again jo 0 hua q me daldo

#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int a = edges[i][0];
        int b = edges[i][1];
        adj[a].push_back(b);
    }
    vector<int> indegree(v,0);
    for(auto i:adj)
        for(auto j:i)
            indegree[j]++;
    
    queue<int> q;
    vector<int> ans;
    for(int i=0 ; i<indegree.size();i++)
        if(indegree[i]==0)
            q.push(i);

    while(!q.empty()){
        int a = q.front();
        q.pop();
        ans.push_back(a);
        for(auto i:adj[a]){
            indegree[i]--;
            if(indegree[i]==0)
                q.push(i);
        }
    }
    return ans;
}