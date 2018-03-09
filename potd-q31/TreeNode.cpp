#include "TreeNode.h"
#include <string>
#include <iostream>
#include <cmath>

bool isHeightBalanced(TreeNode* root) {
  int lh; /* for height of left subtree */
     int rh; /* for height of right subtree */
     /* If tree is empty then return true */
     if(root == NULL)
      return true;

     /* Get the height of left and right sub trees */
     lh = height(root->left_);
     rh = height(root->right_);

     if( abs(lh-rh) <= 1 &&
         isHeightBalanced(root->left_) &&
         isHeightBalanced(root->right_))
       return true;

     /* If we reach here then tree is not height-balanced */
     return false;
  }

  int max(int a, int b)
  {
    return (a >= b)? a: b;
  }


int height(TreeNode* root)
{
   /* base case tree is empty */
   if(root == NULL)
       return 0;

   /* If tree is not empty then height = 1 + max of left
      height and right heights */
   return 1 + max(height(root->left_), height(root->right_));
}


void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
