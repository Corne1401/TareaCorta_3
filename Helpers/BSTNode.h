#pragma once


class BSTNode {
public:
    explicit BSTNode(int key, int index){
        this->index = index;
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }

    int key;
    int index;
    BSTNode *left, *right;
};