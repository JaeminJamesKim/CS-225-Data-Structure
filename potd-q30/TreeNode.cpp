#include "TreeNode.h"

int getHeightBalance(TreeNode* root) {
  // your code here
  int depth=0;
  return getHeightBalance(root, depth);
}

int getHeightBalance(TreeNode* root, int depth){

  int lh; /* for height of left subtree */
   int rh; /* for height of right subtree */

   /* If tree is empty then return true */
   if(root == NULL)
    return 0;

   /* Get the height of left and right sub trees */
   lh = maxDepth(root->left_);
   rh = maxDepth(root->right_);

   return lh-rh;


  // int leftDepth = root->left_ != NULL?
  // getHeightBalance( root->left_, depth + 1 ) : depth;
  //
  // int rightDepth = root->right_ != NULL?
  // getHeightBalance( root->right_, depth + 1 ) : depth;
  //
  // return leftDepth-rightDepth;
}

int maxDepth(TreeNode* node)
{
   if (node==NULL)
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left_);
       int rDepth = maxDepth(node->right_);

       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}





void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
