#include "DictionaryADT.cpp"
#include "BSTNode.cpp"
#include <iostream>

#ifndef NULL
#define NULL 0
#endif


using namespace std;


// Binary Search Tree implementation for the Dictionary ADT
template <typename Key>
class BST : public Dictionary<Key> {

private:
    BSTNode<Key>* root; // Root of the BST

    int nodecount; // Number of nodes in the BST

    // Private "helper" functions
    void clearhelp(BSTNode<Key>*);

    BSTNode<Key>* inserthelp(BSTNode<Key>*, const Key&);

    BSTNode<Key>* deletemin(BSTNode<Key>*);

    BSTNode<Key>* deletemax(BSTNode<Key>*);

    BSTNode<Key>* getmin(BSTNode<Key>*);

    BSTNode<Key>* getmax(BSTNode<Key>*);

    BSTNode<Key>* removehelp(BSTNode<Key>*, const Key&);

    bool findhelp(BSTNode<Key>*, const Key&) const;

    void printhelp(BSTNode<Key>*, int) const;

    void pre_traverseHelp(BSTNode<Key>*, int) const;

    void post_traverseHelp(BSTNode<Key>*, int) const;

    void in_traverseHelp(BSTNode<Key>*, int) const;

public:

    BST() {
        root = NULL;
        nodecount = 0;
    } // Constructor

    ~BST(){
         clearhelp(root);
    } // Destructor

    void clear() // Reinitialize tree
    {
        clearhelp(root);
        root = NULL;
        nodecount = 0;
    }


    // Insert a record into the tree.
    // k Key value of the record.
    // e The record to insert.
    void insert(const Key& k) {
        root = inserthelp(root, k);
        nodecount++;
    }


    // Remove a record from the tree.
    // k Key value of record to remove.
    // Return: The record removed, or NULL if there is none.
    Key remove(const Key& k) {
        bool temp = findhelp(root, k); // First find it
        if (temp) {
            root = removehelp(root, k);
            nodecount--;
        } else {
            cout << "Invalid Operation" << endl;
            return NULL;
        }

        return k;
    }



    // Remove and return the root node from the dictionary.
    // Return: The record removed, null if tree is empty.
    Key removeAny() { // Delete min value
        if (root != NULL) {
            Key temp = root->key();
            root = removehelp(root, root->key());
            nodecount--;
            return temp;
        }

        else return NULL;
    }



    // Return Record with key value k, NULL if none exist.
    // k: The key value to find. */
    // Return some record matching "k".
    // Return true if such exists, false otherwise. If
    // multiple records match "k", return an arbitrary one.
    bool find(const Key& k) const {
        return findhelp(root, k);
    }


    // Return the number of records in the dictionary.
    int size() {
        return nodecount;
    }


    void print() const { // Print the contents of the BST
        if (root == NULL)
            cout << "The BST is empty.\n";

        else {
            printhelp(root, 0);
            cout << endl;
        }
    }

    void pre_traverse() const {
        if(root == NULL)
            cout << "The BST is empty. \n";
        else {
            pre_traverseHelp(root, 0);
            cout << endl;
        }

    }

    void post_traverse() const {
        if(root == NULL)
            cout << "The BST is empty. \n";
        else {
            post_traverseHelp(root, 0);
            cout << endl;
        }

    }

    void in_traverse() const {
        if(root == NULL)
            cout << "The BST is empty. \n";
        else {
            in_traverseHelp(root, 0);
            cout << endl;
        }

    }
};


template <typename Key>
bool BST<Key>::findhelp(BSTNode<Key>* root, const Key& k) const {
    if (root == NULL)
        return false; // Empty tree

    if (k < root->key())
        return findhelp(root->left(), k); // Check left
    else if (k > root->key())
        return findhelp(root->right(), k); // Check right
    else
        return true; // Found it
}
////


template <typename Key>
BSTNode<Key>* BST<Key>::
inserthelp(BSTNode<Key>* root, const Key& k) {

    if (root == NULL) // Empty tree: create node
        return new BSTNode<Key>(k, NULL, NULL);
    if (k < root->key())
        root->setLeft(inserthelp(root->left(), k));
    else
        root->setRight(inserthelp(root->right(), k));
    return root; // Return tree with node inserted
}






template <typename Key>
BSTNode<Key>* BST<Key>::
deletemin(BSTNode<Key>* rt) {
    if (rt->left() == NULL) // Found min
        return rt->right();
    else { // Continue left
        rt->setLeft(deletemin(rt->left()));
        return rt;
    }
}



template <typename Key>
BSTNode<Key>* BST<Key>::
deletemax(BSTNode<Key>* rt) {
    if (rt->right() == NULL) // Found min
        return rt->left();
    else { // Continue right
        rt->setRight(deletemax(rt->right()));
        return rt;
    }
}


template <typename Key>
BSTNode<Key>* BST<Key>::
getmin(BSTNode<Key>* rt) {
    if (rt->left() == NULL)
        return rt;
    else
        return getmin(rt->left());
}

template <typename Key>
BSTNode<Key>* BST<Key>::
getmax(BSTNode<Key>* rt) {
    if (rt->right() == NULL)
        return rt;
    else
        return getmax(rt->right());
}




// Remove a node with key value k
// Return: The tree with the node removed
template <typename Key>
BSTNode<Key>* BST<Key>::
removehelp(BSTNode<Key>* rt, const Key& k) {

    if (rt == NULL) return NULL; // k is not in tree
    else if (k < rt->key())
        rt->setLeft(removehelp(rt->left(), k));
    else if (k > rt->key())
        rt->setRight(removehelp(rt->right(), k));
    else { // Found: remove it
        BSTNode<Key>* temp = rt;
        if (rt->left() == NULL) { // Only a right child
            rt = rt->right(); // so point to right
            delete temp;
        }
        else if (rt->right() == NULL) { // Only a left child
            rt = rt->left(); // so point to left
            delete temp;
        }
        else { // Both children are non-empty
            BSTNode<Key>* temp = getmax(rt->left());
            rt->setKey(temp->key());
            rt->setLeft(deletemax(rt->left()));
            delete temp;
        }
    }

    return rt;
}


template <typename Key>
void BST<Key>::
clearhelp(BSTNode<Key>* root) {
    if (root == NULL)
        return;

    clearhelp(root->left());
    clearhelp(root->right());

    delete root;
}

template <typename Key>
void BST<Key>::
printhelp(BSTNode<Key>* root, int level) const {
    if (root == NULL)
        return; // Empty tree


    cout << root->key();  // Print node value

    if(!root->isLeaf()) {
        cout << "(";
        printhelp(root->left(), level+1); // Do left subtree
        cout << ")";

        cout << "(";
        printhelp(root->right(), level+1); // Do right subtree
        cout << ")";
    }
}

template <typename Key>
void BST<Key>::
pre_traverseHelp(BSTNode<Key>* root, int level) const {
    if (root == NULL)
        return; // Empty tree


    cout << root->key() << " ";  // Print node value

    if(!root->isLeaf()) {
        pre_traverseHelp(root->left(), level+1); // Do left subtree
        pre_traverseHelp(root->right(), level+1); // Do right subtree
    }
}

template <typename Key>
void BST<Key>::
post_traverseHelp(BSTNode<Key>* root, int level) const {
    if (root == NULL)
        return; // Empty tree


    if(!root->isLeaf()) {
        post_traverseHelp(root->left(), level+1); // Do left subtree
        post_traverseHelp(root->right(), level+1); // Do right subtree
    }

    cout << root->key() << " ";  // Print node value
}

template <typename Key>
void BST<Key>::
in_traverseHelp(BSTNode<Key>* root, int level) const {
    if (root == NULL)
        return; // Empty tree

    in_traverseHelp(root->left(), level+1); // Do left subtree

    cout << root->key() << " ";  // Print node value

    in_traverseHelp(root->right(), level+1); // Do right subtree

}






