#pragma once
#define MY_CLASS_H
#include <iostream>
#include <string>
#include "Sequence.h"
using namespace std;
class tree_elem
{
public:
    int m_data;
    tree_elem* m_left;
    tree_elem* m_right;
    tree_elem(int val) {
        m_left = NULL; // В С++11 лучше использовать nullptr
        m_right = NULL;
        m_data = val;
    }
};

class binary_tree
{
private:
    tree_elem* m_root = NULL;
    int m_size = 0;
    Sequence<int> print_tree(tree_elem*, Sequence<int>);
    void delete_tree(tree_elem*);
    void map_recursive(tree_elem* curr, int (*func)(int));
    int* get_element_array(tree_elem*, int*, int);
    void str_maker(tree_elem* curr, string& str);
public:
    binary_tree(int);
    binary_tree(binary_tree*);
    binary_tree(binary_tree*, bool (*func)(int));
    binary_tree(string str);
    //~binary_tree();
    bool find(int);
    void insert(int);
    void erase(int);
    int size();
    binary_tree* map(int (*func)(int));
    void print_subtree(int);
    binary_tree* Where(bool (*func)(int));
    string& get_str();
    binary_tree* merge(binary_tree*);
    Sequence<int> get_sequence();
};
int change_element(int);
bool check_element(int);