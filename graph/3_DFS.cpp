//Problem Statement: https://www.codingninjas.com/codestudio/problems/depth-first-search_1095650

// simply adjency list bana lo and then for every node dfs call karo agar visited nahi hai to uske neighbopurs ko call krdo 

void dfs(int node , unordered_map<int , bool> &visited ,
    unordered_map<int , list<int> > &adj , vector<int> &v){
v.push_back(node);
visited[node] = 1;
for(auto i:adj[node]){
    if(!visited[i])
        dfs(i , visited , adj , v);
}
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
unordered_map<int , list<int> > adj;
for(int i=0 ; i<edges.size() ; i++){
    int a = edges[i][0];
    int b = edges[i][1];
    adj[a].push_back(b);
    adj[b].push_back(a);
}

vector<vector<int>> ans;
unordered_map<int , bool> visited;
for(int i=0;i<V;i++){
    if(!visited[i]){
        vector<int> v;
        dfs(i , visited , adj , v);
        ans.push_back(v);
    }
}
return ans;
}