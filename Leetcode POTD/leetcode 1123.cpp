class Solution {
    public:
        TreeNode* func(TreeNode *root, TreeNode *p, TreeNode *r){
            if(root==NULL) return NULL;
            if(root==p || root==r) return root;
            TreeNode *left = func(root->left, p, r);
            TreeNode *right = func(root->right, p, r);
            if(left==NULL) return right;
            else if(right==NULL) return left;
            else return root;
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            queue<TreeNode*> que;
            que.push(root);
            vector<vector<TreeNode*>> ans;
            while(!que.empty()){
                int s=que.size();
                vector<TreeNode*> temp;
                while(s--){
                    TreeNode* a=que.front(); que.pop();
                    temp.push_back(a);
                    if(a->left){
                        que.push(a->left);
                    }
                    if(a->right){
                        que.push(a->right);
                    }
                }
                ans.push_back(temp);
            }
            int n=ans.size();
            vector<TreeNode*> deepest=ans[n-1];
            if(deepest.size()==1){
                return deepest[0];
            }
            return func(root,deepest.front(),deepest.back());
        }
    };