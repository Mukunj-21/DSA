// Problem :https://www.codingninjas.com/codestudio/problems/1039990?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// stack approach use karenge , as we know ki preorder me sabse pehle root aata hai 
// to hum stack ka pair banake root ko push karenge whose value will be 1 initially 
// fir jab pre me push krwa diya jinki value 1 hogi unki value 2 karke firse push krdenge kyuki abhi in and post me bhi dalega
// push krwane ke baad left child ko push karenge (because Parent,Left,Right) then similarly jab in me push krwaenge to value 2 se 3 kar denge
// and right child ko push karenge (because Left,Parent,Right) then atlast sab kuch post me hi push hota jaega 


/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;
    if(!root)
        return ans;
    vector<int> pre , ino , post;
    //1->PreOrder , 2-> InOrder , 3(else)-> PostOrder
    stack<pair<TreeNode* , int>> s;
    s.push({root , 1});
    while(!s.empty()){
        auto it = s.top();
        s.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->left)
                s.push({it.first->left,1});
        }
        else if(it.second==2){
            ino.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->right)
                s.push({it.first->right,1});
        }
        else
            post.push_back(it.first->data);
    }
    ans.push_back(ino);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}