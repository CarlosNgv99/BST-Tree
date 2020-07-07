//
//  main.cpp
//  ABB
//
//  Created by Carlos NG on 6/9/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#include <iostream>
#include "abb.hpp"

int main(int argc, const char * argv[]) {
    Tree<int> tree;
    
    tree.Insert(tree.getRoot(), 13);
    tree.Insert(tree.getRoot(), 7);
    tree.Insert(tree.getRoot(), 5);
    tree.Insert(tree.getRoot(), 23);
    tree.Insert(tree.getRoot(), 2);

    tree.Insert(tree.getRoot(), 31);



    cout << "Valor de Magic: " << endl;
    cout << tree.magic(tree.getRoot()) << endl;
    cout << "Arbol generado (Se recorre en Pre-Order): " << endl;
    tree.Preorder(tree.getRoot());
    cout << endl;
    cout << "Arbol generado (Se recorre en Post-Order): " << endl;
    tree.Postorder(tree.getRoot());
    cout << endl;
    return 0;
}
