/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fun(TreeNode* &root,int k){
        if(root==NULL){
            return ;
        }
        if(root->left!=NULL && root->left->val==k){
            if(root->left->left==NULL && root->left->right==NULL){
                root->left=NULL;


            }
            else if(root->left->left==NULL && root->left->right!=NULL){
                root->left=root->left->right;

            }
               else if(root->left->left!=NULL && root->left->right==NULL){
                 root->left=root->left->left;
                

            }
               else if(root->left->left!=NULL && root->left->right!=NULL){
                TreeNode* t;
                t=root->left->right;
                root->left=root->left->left;
                TreeNode* pu=root;
                pu=pu->left;
                while(pu->right!=NULL){
                    pu=pu->right;
                }
                pu->right=t;
                
            }

        }
        else if(root->right!=NULL && root->right->val==k){
                    if(root->right->left==NULL && root->right->right==NULL){
                root->right=NULL;


            }
            else if(root->right->left==NULL && root->right->right!=NULL){
                root->right=root->right->right;

            }
               else if(root->right->left!=NULL && root->right->right==NULL){
                 root->right=root->right->left;
                

            }
               else if(root->right->left!=NULL && root->right->right!=NULL){
                TreeNode* t;
                t=root->right->right;
                root->right=root->right->left;
                 TreeNode* pu=root;
                pu=pu->right;
                while(pu->right!=NULL){
                    pu=pu->right;
                }
                pu->right=t;
                
               
                
            }

        }
        fun(root->left,k);
        fun(root->right,k);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(root==NULL){
        return NULL;
      }
        if(root->val==key && root->left==NULL && root->right==NULL){
            return NULL;
        }
        else if(root->val==key && root->left==NULL && root->right!=NULL){
            return root->right;

        }
           else if(root->val==key && root->left!=NULL && root->right==NULL){
            return root->left;

        }   else if(root->val==key && root->left!=NULL && root->right!=NULL){
             TreeNode* t;
             t=root->left;
             root=root->right;
             TreeNode* p=root;
             while(p->left!=NULL){
                p=p->left;
             }
             p->left=t;
             return root;

        }

        fun(root,key);
        return root;
        
    }
};