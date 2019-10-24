#pragma once
// C program to demonstrate delete operation in binary search tree
#include<cstdio>
#include<cstdlib>
#include "BSTNode.h"

using namespace std;
class BSTTree {
public:
    BSTNode *root;

    explicit BSTTree(){root = nullptr;}

    // A utility function to do inorder traversal of BST
    static void inorder(BSTNode *root);
    static void preorder(BSTNode *root);

/* A utility function to insert a new node with given key in BST */
    static BSTNode *insert(BSTNode *node, int key, int index);

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
    static BSTNode *minValueNode(BSTNode *node);

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
    static BSTNode *deleteNode(BSTNode *root, int key);

    static bool isIdOnTree(BSTNode *root, int key);
    static BSTNode *getClientById(BSTNode *root, int key);
};

void BSTTree::inorder(BSTNode *root) {
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << "; " << root->index << endl;
        inorder(root->right);
    }
}

void BSTTree::preorder(BSTNode *root) {
    if (root != nullptr)
    {
        cout << root->key << "; " << root->index << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

BSTNode *BSTTree::insert(BSTNode *node, int key, int index) {
    /* If the tree is empty, return a new node */
    if (node == nullptr) {
        return new BSTNode(key, index);
    }

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key, index);
    else
        node->right = insert(node->right, key, index);

    /* return the (unchanged) node pointer */
    return node;
}

BSTNode *BSTTree::minValueNode(BSTNode *node) {
    auto current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

BSTNode *BSTTree::deleteNode(BSTNode *root, int key) {
    // base case
    if (root == nullptr) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

        // if key is same as root's key, then This is the node
        // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == nullptr)
        {
            auto *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr)
        {
            auto *temp = root->left;
            delete(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        auto *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

bool BSTTree::isIdOnTree(BSTNode *root, int key) {
    if (root == nullptr){
        return false;
    } else {
        if(root->key==key){
            return true;
        } else{
            if (key>root->key){
                return isIdOnTree(root->right, key);
            } else {
                return isIdOnTree(root->left, key);
            }
        }
    }
}

BSTNode *BSTTree::getClientById(BSTNode *root, int key) {
    if (root == nullptr){
        return root;
    } else {
        if(root->key==key){
            return root;
        } else{
            if (key>root->key){
                return getClientById(root->right, key);
            } else {
                return getClientById(root->left, key);
            }
        }
    }
}