// Problem :https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// basic concept is we have to calculate the distance of every node (left-> -1, right-> +1) from the root node (0)
// for every node we will store the distance and the value in a map and update it along the way
// at the end we will traverse the map and return the values in order of distance



class Solution {
    public:
      vector<int> bottomView(Node *root) {
          // Your Code Here
          vector<int> ans;
          if(!root)
              return ans;
          queue<pair<Node*,int>> q;
          q.push({root,0});
          map<int,int> m;
          while(!q.empty()){
          auto x = q.front();
          q.pop();
          Node* temp = x.first;
          int dist = x.second;
          m[dist] = temp->data;
          if(temp->left)
              q.push({temp->left,dist-1});
          if(temp->right)
              q.push({temp->right,dist+1});
          }
          for(auto val : m)
              ans.push_back(val.second);
          return ans;
      }
  };