#include <iostream>
#include <string>
#include "Binary_tree.h"
#include "Sequence.h"
using namespace std;
//constructor
binary_tree::binary_tree(int key)
{
    m_root = new tree_elem(key);
    m_size = 1;
}

binary_tree::binary_tree(binary_tree* tree) {
    int* arr = new int[tree->m_size];
    arr = get_element_array(tree->m_root, arr, 0);
    m_root = new tree_elem(arr[0]);
    m_size = 1;
    for (int i = 1; i < tree->m_size; i++) {
        insert(arr[i]);
    }

    delete[] arr;
}

binary_tree::binary_tree(binary_tree* tree, bool (*func)(int)) {
    int i = 0;
    int* arr = new int[tree->m_size];
    arr = get_element_array(tree->m_root, arr, 0);
    while (func(arr[i]) != true) {
        if (func(arr[i]) == true) {
            insert(arr[i]);
        }
        i++;
    }
    m_root = new tree_elem(arr[i]);
    m_size = 1;
    for (int j = 0; j < tree->m_size; j++) {
        if (func(arr[j]) == true && j != i) {
            insert(arr[j]);
        }
    }
    delete[] arr;
}

int* binary_tree::get_element_array(tree_elem* curr, int* arr, int i) {
    if (curr) // Проверка на ненулевой указатель
    {
        arr = get_element_array(curr->m_left, arr, i + 1);
        arr[i] = (curr->m_data);
        arr = get_element_array(curr->m_right, arr, i + 1);
    }
    return arr;
}

binary_tree::binary_tree(string str) {
    int i = 0;
    int value = 0;
    int j = 0;
    while (str[i] != ' ') {
        value = (value * 10) + (int(str[i]) - 48);
        i++;
    }
    m_root = new tree_elem(value);
    m_size = 1;
    while (i < str.size() - 1) {
        while (str[i] != ' ') {
            value = (value * 10) + (int(str[i]) - 48);
            i++;
        }
        insert(value);
        value = 0;
        i++;
    }
}

//destructor
/*
binary_tree::~binary_tree()
{
    delete_tree(m_root);
}
*/

void binary_tree::delete_tree(tree_elem* curr)
{
    if (curr)
    {
        delete_tree(curr->m_left);
        delete_tree(curr->m_right);
        delete curr;
    }
}

Sequence<int> binary_tree::print_tree(tree_elem* curr, Sequence<int> vector)
{
    if (curr) // Проверка на ненулевой указатель
    {
        vector = print_tree(curr->m_left, vector);
        vector = vector.add(curr->m_data);
        vector = print_tree(curr->m_right, vector);
    }
    return vector;
}

//searching
bool binary_tree::find(int key)
{
    tree_elem* curr = m_root;
    while (curr && curr->m_data != key)
    {
        if (curr->m_data > key)
            curr = curr->m_left;
        else
            curr = curr->m_right;
    }
    return curr != NULL;
}

int binary_tree::size() {
    return m_size;
}

//addition
void binary_tree::insert(int key)
{
    tree_elem* curr = m_root;
    while (curr && curr->m_data != key)
    {
        if (curr->m_data > key && curr->m_left == NULL)
        {
            curr->m_left = new tree_elem(key);
            ++m_size;
            return;
        }
        if (curr->m_data < key && curr->m_right == NULL)
        {
            curr->m_right = new tree_elem(key);
            ++m_size;
            return;
        }
        if (curr->m_data > key)
            curr = curr->m_left;
        else
            curr = curr->m_right;
    }
}

//deleting
void binary_tree::erase(int key)
{
    tree_elem* curr = m_root;
    tree_elem* parent = NULL;
    while (curr && curr->m_data != key)
    {
        parent = curr;
        if (curr->m_data > key)
        {
            curr = curr->m_left;
        }
        else
        {
            curr = curr->m_right;
        }
    }
    if (!curr)
        return;
    if (curr->m_left == NULL)
    {
        // Вместо curr подвешивается его правое поддерево
        if (parent && parent->m_left == curr)
            parent->m_left = curr->m_right;
        if (parent && parent->m_right == curr)
            parent->m_right = curr->m_right;
        --m_size;
        delete curr;
        return;
    }
    if (curr->m_right == NULL)
    {
        // Вместо curr подвешивается его левое поддерево
        if (parent && parent->m_left == curr)
            parent->m_left = curr->m_left;
        if (parent && parent->m_right == curr)
            parent->m_right = curr->m_left;
        --m_size;
        delete curr;
        return;
    }
    // У элемента есть два потомка, тогда на место элемента поставим
    // наименьший элемент из его правого поддерева
    tree_elem* replace = curr->m_right;
    while (replace->m_left)
        replace = replace->m_left;
    int replace_value = replace->m_data;
    erase(replace_value);
    curr->m_data = replace_value;
}

void binary_tree::map_recursive(tree_elem* curr, int (*func)(int))
{
    if (curr) {
        map_recursive(curr->m_left, func);
        curr->m_data = func(curr->m_data);
        map_recursive(curr->m_right, func);
    }
}

binary_tree* binary_tree::map(int (*func)(int))
{
    binary_tree* a = new binary_tree(this);
    a->map_recursive(a->m_root, func);
    return a;
}

void binary_tree::print_subtree(int key)
{
    tree_elem* curr = m_root;
    while (curr && curr->m_data != key)
    {
        if (curr->m_data > key)
            curr = curr->m_left;
        else
            curr = curr->m_right;
    }
    //print_tree(curr);
}

binary_tree* binary_tree::Where(bool (*func)(int)) {
    binary_tree* a = new binary_tree(this, func);
    return a;
}

void binary_tree::str_maker(tree_elem* curr, string& str)
{
    if (curr) // Проверка на ненулевой указатель
    {
        str_maker(curr->m_left, str);
        std::string s = std::to_string(curr->m_data);
        str = str + s + " ";
        str_maker(curr->m_right, str);
    }
}

string& binary_tree::get_str()
{
    string* res = new string("");
    str_maker(m_root, *res);
    return *res;
}

binary_tree* binary_tree::merge(binary_tree* b) {
    binary_tree* c = new binary_tree(this);
    int* arr2 = new int[b->size()];
    arr2 = b->get_element_array(b->m_root, arr2, 0);
    for (int i = 0; i < b->m_size; i++) {
        if (arr2[i] != 0) {
            c->insert(arr2[i]);
        }
    }
    delete[] arr2;
    return c;
}
int change_element(int element) {
    return element + 20;
}
bool check_element(int element) {
    if (element < 30) {
        return true;
    }
    else {
        return false;
    }
}

Sequence<int> binary_tree::get_sequence() {
    Sequence<int> vector = Sequence<int>();
    cout << "\n";
    vector = print_tree(m_root, vector);
    return vector;
}
