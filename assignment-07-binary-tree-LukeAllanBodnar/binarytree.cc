#include <math.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "btree.h"

using namespace std;

//***************************************************************************
//
//   Name: Luke Allan Bodnar
//    ZID: Z1808328
// Course: CSCI 340
//
//  I certify that this is my own work and where appropriate an extension 
//  of the starter code provided for the assignment.
//
//***************************************************************************

#define SEED 1  // seed for RNGs

#define N1    100   // size of 1st vector container
#define LOW1  -999  // low val for rand integer
#define HIGH1 999   // high val for rand integer

#define N2    50      // size of 2nd vector container
#define LOW2  -99999  // low val for rand float
#define HIGH2 99999   // high val for rand float
#define PREC  2       // no of digits after dec pt

#define LSIZE  12  // no of vals printed on line
#define ITEM_W 7   // no of spaces for each item




template <typename T>
unsigned BinaryTree<T>::getSize() const {

    return _getSize(root)-1;

}

template <typename T>
unsigned BinaryTree<T>::_getSize(Node<T>* node) const {

    if (node == nullptr) {
        return 0;
    }
    else {

        unsigned left = _getSize(node->left);
        unsigned right = _getSize(node->right);
        return left+right+1;

    }

}

template <typename T>
unsigned BinaryTree<T>::getHeight() const{

    return _getHeight(root);

}

template <typename T>
unsigned BinaryTree<T>::_getHeight(Node<T>* node) const{

    if (node == nullptr) {
        return 1;
    }
    else {

        unsigned left = _getHeight(node->left);
        unsigned right = _getHeight(node->right);
        return (left > right ? left : right) + 1;

    }
}

template <typename T>
void BinaryTree<T>::Inorder(void (*y)(const T&)) {

    BinaryTree<T>::_Inorder(root, y);

}

template <typename T>
void BinaryTree<T>::_Inorder(Node<T>* node, void (*y)(const T&)) {

    if (node == nullptr) {
        return;
    }
    else {
        _Inorder(node->left, y);
         y(node->data);
        _Inorder(node->right, y);
    }

}

typedef enum { left_side, right_side } SIDE;

SIDE rnd() {
    return rand() % 2 ? right_side : left_side;
}



template <typename T>
void BinaryTree<T>::Insert(const T& x) {
    
    _Insert(root, x);
 
}

template <typename T>
void BinaryTree<T>::_Insert(Node<T>*& node, const T& x) {

    if (node == nullptr) {
        node = new Node<T>(x);
    }

    switch (rnd()) {  // creates two cases where 
    case left_side: 

        if (node->left == nullptr) {
            node->left = new Node<T>(x);
        }
        else {
            _Insert(node->left, x);
        }
        break;

    case right_side:

        if (node->right == nullptr) {
            node->right = new Node<T>(x);
        }
        else {
            _Insert(node->right, x);
        }
        break;
    }
}
    
   


// prints single value
template <typename T>
void print(const T&);

// prints data vals in tree
template <typename T>
void print_vals(BinaryTree<T>&, const string&);

// class to generate rand ints
class RND1 {
 private:
  int low, high;

 public:
  RND1(const int& l = 0, const int& h = 1) : low(l), high(h) {}
  int operator()() const { return rand() % (high - low + 1) + low; }
};

// class to generate rand floats
class RND2 {
 private:
  int low, high, prec;

 public:
  RND2(const int& l = 0, const int& h = 1, const int& p = 0) : low(l), high(h), prec(p) {}
  float operator()() const { return (static_cast<float>(rand() % (high - low + 1) + low)) / pow(10, prec); }
};

// prints val passed as argument
template <typename T>
void print(const T& x) {
  static unsigned cnt = 0;
  cout << setw(ITEM_W) << x << ' ';
  cnt++;
  if (cnt % LSIZE == 0) cout << endl;
}

// prints size and height of bin tree and data val in
// each node in inorder
template <typename T>
void print_vals(BinaryTree<T>& tree, const string& name) {
  cout << name << ": ";  // print name of tree

  // print size and height of tree
  cout << "size = " << tree.getSize() << ", ";
  cout << "height = " << tree.getHeight() << endl << endl;

  // print data values of tree in inorder
  cout << "Data values in '" << name << "' inorder:\n\n";
  tree.Inorder(print);
  cout << endl;
}

// driver program: to test several member functions of BinaryTree class

int main() {
  srand(SEED);  // set seed for RNGs

  // create 1st vector and fill it with rand ints
  vector<int> A(N1);

 
  generate(A.begin(), A.end(), RND1(LOW1, HIGH1));
   

  // create binary tree with int vals in vector A,
  // and print all vals of tree

  BinaryTree<int> first;
  for (unsigned i = 0; i < A.size(); i++) first.Insert(A[i]);


  print_vals(first, "first");
  cout << endl;

  // create 2nd vector and fill it with rand floats
  vector<float> B(N2);
  generate(B.begin(), B.end(), RND2(LOW2, HIGH2, PREC));

  // create binary tree with float vals in vector B,
  // and print all vals of tree

  BinaryTree<float> second;
  for (unsigned i = 0; i < B.size(); i++) second.Insert(B[i]);
  print_vals(second, "second");
  cout << endl;

  return 0;
}
