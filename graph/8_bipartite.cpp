// Problem: https://leetcode.com/problems/is-graph-bipartite/

// Bipartite Graph vo hote hai jinke adjancent nodes ka color alag hota hai.
// to bas ek visited ki jagah colour ka array bana lo initially -1 aur root ko 0 kardo and uske adjacent ko 1 - root ka colour dete jao
// agar kahi bhi same aagya adjacent and root ka colour to return false else it is a bipartite

class Solution {
    public:
        bool checkbfs(int node , vector<int> &color , vector<vector<int>>& graph){
            queue<int> q;
            q.push(node);
            color[node] = 0;
            while(!q.empty()){
                int a = q.front();
                q.pop();
                for(auto i:graph[a])
                    if(color[i]==-1){
                        color[i] = 1 - color[a];
                        q.push(i);
                    }
                    else if(color[i] == color[a])
                        return false;
            }
            return true;
        }
    
        bool checkdfs(int node , int c , vector<int> &color , vector<vector<int>>& graph){
            color[node] = c;
            for(auto i:graph[node])
                if(color[i]==-1){
                    if(!checkdfs(i , 1-c , color , graph))
                        return false;
                }
                else if(color[i]==c)
                    return false;
            return true;
        }
    
        bool isBipartite(vector<vector<int>>& graph) {
            int v = graph.size();
            vector<int> color(v,-1);
            for(int i=0;i<v;i++)
                if(color[i]==-1)
                    // if(!checkbfs(i , color , graph))
                    if(!checkdfs(i , 0 , color , graph))
                        return false;
            return true;
        }
    };