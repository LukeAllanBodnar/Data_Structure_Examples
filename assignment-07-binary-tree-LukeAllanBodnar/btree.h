#include "node.h"
#include <vector>
#ifndef H_BTREE
#define H_BTREE

template <typename T> class BinaryTree{

public:

    BinaryTree() : root(nullptr) {}
    BinaryTree(Node<T>* rootNode) : root(rootNode) {}
        
        
        // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*y)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*y)(const T&));   // private version of Inorder()
};
 
#endif // End of H_BTREE
