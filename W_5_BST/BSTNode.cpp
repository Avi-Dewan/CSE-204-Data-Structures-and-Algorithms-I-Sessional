// Simple binary tree node implementation

#include "BinNodeADT.cpp"

#ifndef NULL
#define NULL 0
#endif

template <typename Key> class BSTNode: public BinNode<Key> {

private:
    Key k; // The node’s key
    BSTNode* lc; // Pointer to left child
    BSTNode* rc; // Pointer to right child

public:

    // Two constructors -- with and without initial values
    BSTNode() {
        lc = rc = NULL;
    }

    BSTNode(Key K,  BSTNode* l =NULL, BSTNode* r =NULL){
        k = K;
        lc = l;
        rc = r;
    }

    ~BSTNode() {

    } // Destructor


    // Functions to set and return the key


    Key& key() {
         return k;
    }

    void setKey(const Key& K) {
         k = K;
    }


    // Functions to set and return the children
    inline BSTNode* left() const {
         return lc;
    }

    void setLeft(BinNode<Key>* b) {
        lc = (BSTNode*)b;
    }

    inline BSTNode* right() const {
        return rc;
    }

    void setRight(BinNode<Key>* b) {
         rc = (BSTNode*)b;
    }

    // Return true if it is a leaf, false otherwise
    bool isLeaf() {
        return (lc == NULL) && (rc == NULL);
    }
};
