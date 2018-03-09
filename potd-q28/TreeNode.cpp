#include "TreeNode.h"
#include <iostream>

TreeNode * deleteNode(TreeNode* root, int key) {
  // base case
  if (root == NULL) return root;

  // If the key to be deleted is smaller than the root's key,
  // then it lies in left subtree
  if (key < root->val_)
      root->left_ = deleteNode(root->left_, key);

  // If the key to be deleted is greater than the root's key,
  // then it lies in right subtree
  else if (key > root->val_)
      root->right_ = deleteNode(root->right_, key);

  // if key is same as root's key, then This is the node
  // to be deleted
  else
  {
      // node with only one child or no child
      if (root->left_ == NULL)
      {
          TreeNode *temp = root->right_;
          return temp;
      }
      else if (root->right_ == NULL)
      {
          TreeNode *temp = root->left_;
          return temp;
      }

      // node with two children: Get the inorder successor (smallest
      // in the right subtree)

      TreeNode* smallest = root->right_;
      while(smallest->left_!=NULL){
        smallest=smallest->left_;
      }

      // Copy the inorder successor's content to this node
      root->val_ = smallest->val_;

      // Delete the inorder successor
      root->right_ = deleteNode(root->right_, smallest->val_);
  }
  return root;



  // your code here
  // if(root->val_==key && root->right_==NULL && root->left_==NULL){
  //   return root;
  // }
  //
  // TreeNode * tRight = root->right_;
  // TreeNodde * tLeft = root->left_;
  //
  // if(root->val_==key &&(root->right_==NULL&&root->left_!=NULL)){
  //   temp->left_=
  // }

}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
