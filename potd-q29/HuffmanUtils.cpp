#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>

using std::string;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string output = "";
    HuffmanNode* root = huffmanTree;

    if(root==NULL){
      return output;
    }

    for(int i = 0; i < (int)binaryString.length(); i++){

    if(binaryString[i] == '1')
     root = root->right_;

    if(binaryString[i] == '0')
     root = root->left_;

    if(root->right_ == NULL && root->left_ == NULL){
     output += root->char_;
     root = huffmanTree;
    }
    }
   return output;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */

    string output = "";
    HuffmanNode* root = huffmanTree;

    if(root==NULL){
      return output;
    }

    for(int i = 0; i < (int)charString.length(); i++){

    if(root->char_ != charString[i])
     root = root->right_;
     output+='1';

    if(root->char_ != charString[i])
     root = root->left_;
     output+='0';

    if(root->right_ == NULL && root->left_ == NULL){
     
     root = huffmanTree;
    }
    }
   return output;
    // string output = "";
    // HuffmanNode* root = huffmanTree;
    // int count =0;
    //
    //
    //
    // // HuffmanNode * tLeft= root->left_;
    // // HuffmanNode * tRight= root->right_;
    //
    //   //left
    //   if(root ==NULL){
    //     return output;
    //   }
    //   else if(root->char_ == charString[count]){
    //       count++;
    //       return output;
    //   }
    //   else{
    //     output+='0';
    //     stringToBinary(charString, root->left_);
    //
    //     output[output.length()-1]='\0';
    //     output+='1';
    //     stringToBinary(charString, root->right_);
    //   }
    //
    // return output;
  }
    // if(root->left_==NULL && root->right_ ==NULL){
    //   return output;
    // }
    //
    // if(root->left_!=NULL){
    //   output+='0';
    //   root=root->left_;
    //   stringToBinary(charString, root);
    //
    // }
    // else if(root->right_!=NULL){
    //   output+='1';
    //   root=root->right_;
    //   stringToBinary(charString, root);
    //
    // }
    // root=huffmanTree;
