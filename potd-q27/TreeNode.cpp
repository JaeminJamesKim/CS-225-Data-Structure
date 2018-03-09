#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  int tLeft=-1;
  int tRight=-1;
   if(left_ != NULL){
       tLeft = left_->getHeight();
   }
   if(right_ != NULL){
       tRight = right_->getHeight();
   }
   if(tLeft > tRight){
       return ++tLeft;
   } else{
       return ++tRight;
   }

}
