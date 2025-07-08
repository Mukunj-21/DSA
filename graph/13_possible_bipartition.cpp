// Problem Link: https://leetcode.com/problems/possible-bipartition/

// same hai kabhi bhi question aajaye jisme 2 partitions banane ho to graph ko bipartite check karna hai
// color ka vector bana do aur adjacents ko dusra color dedo agar color same aagya adjacent ka to return false

class Solution {
    public:
        bool bfs(int num , vector<vector<int>> &adj , vector<int> &color){
            color[num] = 0;
            queue<int> q;
            q.push(num);
            while(!q.empty()){
                int a = q.front();
                q.pop();
                for(auto neighbour : adj[a]){
                    if(color[neighbour] == color[a])
                        return false;
                    else if(color[neighbour] == -1){
                        color[neighbour] = 1 - color[a];
                        q.push(neighbour);
                    }
                }
            }
            return true;
        }
        
        bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
            vector<vector<int>> adj(n + 1);
            for(auto edge : dislikes){
                int a = edge[0];
                int b = edge[1];
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            vector<int> color(n+1 , -1);
            for(int i=1;i<=n;i++){
                if(color[i] == -1 && !bfs(i , adj , color))
                    return false;
            }
            return true;
        }
    };