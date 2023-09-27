class BSTiterator{
    private:
    stack<TreeNode*> st;
    bool reverse = true;
    public:
    BSTiterator(TreeNode* root,bool flag){
        reverse = flag;
        pushAll(root);
    }
    
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        
        if(reverse){
            pushAll(temp->left);
        }
        else{
            pushAll(temp->right);
        }
        
        return temp->val;
    }
    
    bool hasNext(){
        return !st.empty();
    }
    
    void pushAll(TreeNode* root){
        // while root not equal to null
        while(root){
            st.push(root);
            if(reverse){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
    }
};
