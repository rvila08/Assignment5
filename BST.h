#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <class T>
class TreeNode
{
  public:
    TreeNode();
    TreeNode(T k); //k = key, which in this example is also the value(data)
    ~TreeNode(); //when creating a template class destructor must be virtual

    T key;
    TreeNode<T> *left;
    TreeNode<T> *right;

};

template <class T>
TreeNode<T>::TreeNode(){
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k){
  key = k;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){

}

template <class T>
class BST{
  private:

  public:
    BST();
    ~BST();

    TreeNode<T> *root;
    TreeNode<T>* search(T value);
    void insert(T value);
    bool deleteNode(T value);
    TreeNode<T>* getSuccessor(TreeNode<T> *d);

    //delete placeholder

    //helper functions
    bool isEmpty();
    TreeNode<T> *getMin();
    TreeNode<T> *getMax();
    void printTree();
    void recPrint(TreeNode<T> *node);
};

template <class T>
BST<T>::BST(){
  root = NULL; // empty tree
}

template <class T>
BST<T>::~BST(){

}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){

  if(node == nullptr){
    return;
  }
  recPrint(node->left);
  cout << node->key << endl;
  recPrint(node->right);
}

template <class T>
void BST<T>::printTree(){
  recPrint(root);
}

template <class T>
TreeNode<T>* BST<T>::getMax(){

  TreeNode<T> *current = root;

  if(root == NULL){
    return NULL;
  }
  while(current->right != NULL){
    current = current->right;
  }
  return current;

}

template <class T>
TreeNode<T>* BST<T>::getMin(){

  TreeNode<T> *current = root;

  if(root == NULL){
    return NULL;
  }
  while(current->left != NULL){
    current = current->left;
  }
  return current;

}

template <class T>
void BST<T>::insert(T value){
//check value exists in Tree

  TreeNode<T> *node = new TreeNode<T>(value);

  if(root == NULL){   //empty tree
    cout << "We have an empty tree" << endl;
    root = node;
  }
  else{
    //the tree is not empty, so let's find the insertion point
    TreeNode<T> *current = root;
    TreeNode<T> *parent = NULL;

    while(true){
      parent = current;

      if(value->operator<(current->key)){
        //go left
        cout << "going left" << endl;
        current = current->left;

        if(current==NULL){
          cout << "inserted" << endl;
          parent->left = node;
          break;
        }
      }
      else{
        cout << "going right" << endl;
        current = current->right;

        if(current== NULL){
          cout << "inserted" << endl;
          parent->right = node;
          break;
        }
      }

    }
  }

}

template <class T>
TreeNode<T>* BST<T>::search(T value){

  if(root == NULL){
    return NULL;
  }
  //tree is not empty
  else{
    TreeNode<T> *current = root;
    while(value->operator!=(current->key)){
      if(value->operator<(current->key)){
        current = current ->left;
      }
      else{
        current = current ->right;
      }
      if(current == NULL){
        return NULL;
      }
    }
    return current;
  }
}

template <class T>
bool BST<T>::deleteNode(T value){

  if(root == NULL){
    return false;
  }
  TreeNode<T> *parent = root;
  TreeNode<T> *current = root;
  bool isLeft = true;

  //let's attempt to find node to be deleted
  while(current->key->operator!= (value)){
    parent = current;
    if(value->operator<(current->key)){
      //go left
      isLeft = true;
      current = current ->left;
    }
    else{
      //go right
      isLeft = false;
      current = current->right;
    }
    if(current == NULL){
      return false;
    } // value doesn't exist

    //if we make it here, then we found the node to be deleted
    if(current->left== NULL && current->right== NULL){
      if(current== root)
        root == NULL;
      else if(isLeft){
        parent->left == NULL;
      }
      else{
        parent->right == NULL;
      }
    }
    else if(current->right== NULL){//node to be deleted has one child, it's a left (no right child)
      if(current== root){
        root = current->left;
      }
      else if(isLeft){
        parent->left = current->left;
      }
      else{
        parent->right = current->left;
      }
    }

    else if(current->left== NULL){//node to be deleted has one child, it's a right (no left child)
      if(current== root){
        root = current->right;
      }
      else if(isLeft){
        parent->left = current->right;
      }
      else{
        parent->right = current->right;
      }
    }
    else{
      //the node to be deleted has 2 children,
      //at this state the cortisol increase exponentially

      TreeNode<T> *successor = getSuccessor(current);
      if(current== root)
        root = successor;
      else if(isLeft){
        parent->left = successor;
      }
      else{
        parent->right = successor;
      }
      successor->left = current ->left;
    }
  }
  return true;
}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){ //d is node to be deleted

    TreeNode<T> *current = d->right;
    TreeNode<T> *sp = d; //successor's parent
    TreeNode<T> *successor = d;

    while(current != NULL){
      sp = successor;
      successor = current;
      current = current ->left;
    }
    //we made here, that means we found our successor
    if(successor != d->right){
      sp->left = successor->right;
      successor->right = d->right;
    }
    return successor;
}
#endif
