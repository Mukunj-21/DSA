// Problem Statement: https://leetcode.com/problems/course-schedule/

// visited ke saath ek dfsvisited array bhi rakhte hain aur jab dono true hogye kisi node ke liye which means ki cycle aagyi hai 
// kyuki visited se pata chalta hai ki node ko visit kiya hai aur dfsvisited se pata chalta hai ki current path mein hai ya nahi

class Solution {
    public:
        bool check(int node, vector<bool>& visited, vector<bool>& dfsvisited, vector<vector<int>>& adj) {
            visited[node] = true;
            dfsvisited[node] = true;
    
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    if (check(neighbor, visited, dfsvisited, adj))
                        return true;
                } else if (dfsvisited[neighbor]) {
                    return true;
                }
            }
    
            dfsvisited[node] = false;
            return false;
        }
    
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj(numCourses);
    
            for (auto& p : prerequisites) {
                int a = p[1];
                int b = p[0];
                adj[a].push_back(b);
            }
    
            vector<bool> visited(numCourses, false);
            vector<bool> dfsvisited(numCourses, false);
    
            for (int i = 0; i < numCourses; i++) {
                if (!visited[i]) {
                    if (check(i, visited, dfsvisited, adj))
                        return false;
                }
            }
    
            return true;
        }
    };
    