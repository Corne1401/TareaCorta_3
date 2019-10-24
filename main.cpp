#include <iostream>
#include <map>
#include "Helpers/Helper.h"
#include "Helpers/BST.h"
#include "Helpers/CacheNode.h"


using namespace std;

int main() {
    BSTTree tree;

    map<int, CacheNode> cacheMemory;

    clientRead();
    loadBST(tree);
    defaultCacheInit(cacheMemory);

//    tree.inorder(tree.root);



    string op;
    while (true){
        cout << "Welcome to users menu" << endl;
        cout << "1) Find Client" << endl;
        cout << "2) Print Tree Preorder" << endl;
        cout << "3) Print Cache" << endl;
        cout << "4) Insert Client" << endl;
        cout << "5) Delete Client" << endl;
        cout << "6) Purge Files" << endl;
        cout << "7) Exit" << endl;

        cin >> op;

        if(op=="1"){
            findClient(tree, cacheMemory);
        } else if (op=="2"){
            tree.preorder(tree.root);
        } else if(op=="3"){
            printCache(cacheMemory);
        } else if(op=="4"){
            //TODO
        } else if (op=="5"){
            deleteClient(cacheMemory, tree);
        } else if(op=="6"){
            purgeClient();
        } else if(op=="7"){
            break;
        }
    }



    return 0;
}