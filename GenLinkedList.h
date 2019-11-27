#ifndef GenLinkedList_H
#define GenLinkedList_H

#include <iostream>

using namespace std;

template <class T>
class ListNode{
  public:
      T data;
      ListNode<T> *next;
      ListNode();
      ListNode(T d);
      ~ListNode();

};

template <class T>
ListNode<T>::ListNode(){

}

template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL; //nullptr
}

template <class T>
ListNode<T>::~ListNode(){

  if(next == NULL)
    delete next;
}

template <class T>
class GenLinkedList{
  private:
    ListNode<T> *front;
    unsigned int size;
  public:
    GenLinkedList();
    ~GenLinkedList();

    void insertFront(T d);
    T removeFront();
    T returnPos(int pos);
    T deletePos(int pos);
    T find(T d);

    bool isEmpty();
    void printList();
    unsigned int getSize();

};

template <class T>
GenLinkedList<T>::GenLinkedList(){
    size = 0;
    front = NULL;

}

template <class T>
GenLinkedList<T>::~GenLinkedList(){

}

template <class T>
unsigned int GenLinkedList<T>::getSize(){
    return size;
}

template <class T>
bool GenLinkedList<T>::isEmpty(){
  if(size==0){
    return true;
  }
  return false;
}

template <class T>
void GenLinkedList<T>::printList(){
  ListNode<T> *curr = front;
  while (curr !=NULL) {
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template <class T>
void GenLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);
  node -> next= front;
  front = node;


  size++;
}

template <class T>
T GenLinkedList<T>::removeFront(){
  T temp = front->data;
  ListNode<T> *f = front;
  front = front->next;
  f->next = NULL;
  delete f;

  size--;
  return temp;
}

template <class T>
T GenLinkedList<T>::returnPos(int pos){

    int idx = 0;
    ListNode<T> *prev = front;
    ListNode<T> *curr = front;

    while(idx!=pos){
      prev = curr; // stays back 1 position
      curr = curr -> next;
      idx++;
    }

    T temp = curr -> data;
    return temp;
}

template <class T>
T GenLinkedList<T>::deletePos(int pos){

    int idx = 0;
    ListNode<T> *prev = front;
    ListNode<T> *curr = front;

    while(idx!=pos){
      prev = curr; // stays back 1 position
      curr = curr -> next;
      idx++;
    }

    prev->next = curr->next;
    curr->next = NULL;
    T temp = curr -> data;
    delete curr;
    size--;
    return temp;
    //make sure to add checks for vali pos and curr != nullptr

}

template <class T>
T GenLinkedList<T>::find(T d){

  int idx = 0;
  ListNode<T> *curr = front;

  while(curr != NULL){
      if(curr ->data == d){
        return idx;
      }
      idx++;
      curr = curr->next;
  }
  return -1;

}

#endif
