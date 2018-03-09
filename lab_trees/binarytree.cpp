/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>
/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    mirror(root);
}

template <typename T>
void BinaryTree<T>::mirror(Node * subRoot){
	if(subRoot->right == NULL&&subRoot->left==NULL){
		return;
	}
	if(subRoot->right != NULL)
		mirror(subRoot->right);
	if(subRoot->left != NULL)
		mirror(subRoot->left);
	Node * temp = subRoot->right;
	subRoot->right = subRoot->left;
  subRoot->left = temp;
// if(root==NULL || (root->left==NULL && root->right==NULL))
//       return;
//
// Node * temp = root;
// // Node * tright=root->right;
// // Node * tleft=root->left;
//
// while(height(root->right)!=-1){
//   root->right->right=root->right->left;
//   root->right->left=temp->right->right;
//
//   root->right=root->right->right;
// }
// while(height(root->left)!=-1){
//   root->left->left=root->left->right;
//   root->left->right=temp->left->left;
//
//   root->left=root->left->left;
// }
//
// root->right=root->left;
// root->left=temp;

// temp=NULL;
// tright=NULL;
// tleft=NULL;

}

/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    // your code here
    // return isOrderedIterative(root);
    bool fk=true;
      InorderTraversal<int> iot(root);
      for (TreeTraversal<int>::Iterator aa = iot.begin(); aa != iot.end()&&fk; ++aa) {
        if(root<(root->left)){
          fk=false;
        }
        else if(root>(root->right)){
          fk=false;
        }

      }
      return fk;
}

// template <typename T>
// bool BinaryTree<T>::isOrderedIterative(const Node* subRoot) const
// {
// bool fk=true;
//   InorderTraversal<int> iot(root);
//   for (TreeTraversal<int>::Iterator aa = iot.begin(); aa != iot.end()&&fk; ++aa) {
//     if(subRoot<(subRoot->left)){
//       fk=false;
//     }
//     else if(subRoot>(subRoot->right)){
//       fk=false;
//     }
//   }
//     // your code here
// //   bool lOrdered = false, rOrdered = false;
// //   int rMost = 0, lMost = 0;
// //
// // if(subRoot==NULL){(*aa)->elem
// //   return true;
// // }
// //
// // while((subRoot->left)!= NULL){
// //   subRoot=subRoot->left;
// // }
// // lMost=subRoot;
// // return false;
// //
// //
// // if (lOrdered && rOrdered && (lMost>=subRoot->elem) && (rMost<=subRoot->elem))
// //     return true;
// return fk;
// }



/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
//   bool lOrdered = false, rOrdered = false;
//   int rMost = 0, lMost = 0;
//
// if(subRoot==NULL){
//   return true;
// }
//
// while((subRoot->left)!= NULL){
//   subRoot=subRoot->left;
// }
// lMost=subRoot;
// return false;
//
//
// if (lOrdered && rOrdered && (lMost>=subRoot->elem) && (rMost<=subRoot->elem))
//     return true;
template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{

  return isOrderedRecursive(root);
}
  bool lOrdered = false, rOrdered = false;
 int rMost = 0, lMost = 0;
template <typename T>
bool BinaryTree<T>::isOrderedRecursive(const Node* subRoot) const
{
  bool lOrdered = false, rOrdered = false;
 int rMost = 0, lMost = 0;
 if (subRoot == NULL)
     return true;
 if (subRoot->left != NULL)
 {
     lOrdered = isOrderedRecursive(subRoot->left);
     rMost = rightMost(subRoot->left);
 }
 else
 {
     lOrdered = true;
     rMost = subRoot->elem;
 }

 if (subRoot->right != NULL)
 {
     rOrdered = isOrderedRecursive(subRoot->right);
     lMost = leftMost(subRoot->right);
 }
 else
 {
     rOrdered = true;
     lMost = subRoot->elem;
 }
 if (lOrdered && rOrdered && (lMost>=subRoot->elem) && (rMost<=subRoot->elem))
     return true;
return false;
}

template <typename T>
T BinaryTree<T>::leftMost(const Node* subRoot) const
{
    if (subRoot->left == NULL)
        return subRoot->elem;
    return leftMost(subRoot->left);
}

/**
 * return the right-most node on the tree
 */
template <typename T>
T BinaryTree<T>::rightMost(const Node* subRoot) const
{
    if (subRoot->right == NULL)
        return subRoot->elem;
    return rightMost(subRoot->right);

}
/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
template <typename T>
void BinaryTree<T>::printPaths(vector<vector<T> > &paths) const
{
  vector<T> temp;
printPaths(root, temp);
}

template <typename T>
void BinaryTree<T>::printPaths(const Node * subRoot, vector<T> & temp)const
{
	if(!subRoot)
		return;
	temp.push_back(subRoot->elem);
	if((!subRoot->left)&&(!subRoot->right))
		printl(temp);

	printPaths(subRoot->left,temp);
	printPaths(subRoot->right,temp);

	temp.pop_back();
}

template <typename T>
void BinaryTree<T>::printl(vector<T> temp) const
{
	vector<T> a;
	while (!temp.empty())
	{
		a.push_back(temp.back());
		temp.pop_back();
	}

	cout << "Path:";

	while(!a.empty())
	{
		cout<< ' '<<a.back();
		a.pop_back();
	}

	cout << endl;
	return;
}
    // your code here

//     std::vector <const BinaryTree<T>::Node *> treeVec;
//     	printPaths(treeVec, root);
// }
//
//     template <typename T>
//     void BinaryTree<T>::printPaths(vector <const BinaryTree<T>::Node *> &treeVec, const Node* subRoot) const
//     {
//         // your code here
//     	treeVec.push_back(subRoot);
//     	if(subRoot->left == NULL&&subRoot->right == NULL)
//     		printVector(treeVec);
//     	if(subRoot->left != NULL)



//     		printPaths(treeVec, subRoot->left);
//     	if(subRoot->right != NULL)
//     		printPaths(treeVec, subRoot->right);
//     	treeVec.pop_back();
//     	return;
    // }

/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    int sum = 0;
    return sumDistances(-1,root,sum);
}


template <typename T>
int BinaryTree<T>::sumDistances(int distanceHave, const Node* subRoot, int &sum) const
{
  distanceHave++;
  	sum += distanceHave;
  	if(subRoot->left != NULL)
  		sum = sumDistances(distanceHave, subRoot->left, sum);
  	if(subRoot->right != NULL)
  		sum = sumDistances(distanceHave, subRoot->right, sum);
  return sum;
}
