// Problem: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// use queue to implement , jo node visit ho gyi use visited map me store krlo taaki repeat na ho 
// and unke adjacency se unke neighbours ko queue me daal do

#include<queue>
#include<unordered_map>
// #include<set>
#include<vector>
void bfs(vector<vector<int>> &adj , vector<int> &ans ,
         unordered_map<int,bool> &visited , int node){
    
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        ans.push_back(a);
        for(auto i:adj[a]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }

}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    unordered_map<int,bool> visited;
    // for(int i=0;i<n;i++)
        if(!visited[0])
            bfs(adj , ans , visited , 0);
    return ans;
}