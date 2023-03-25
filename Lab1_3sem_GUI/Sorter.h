#pragma once
#include <iostream>
#include <chrono>
#include "Sequence.h"
#include "Binary_tree.h"
using namespace std::chrono;
class Sorter {
public:
//private:

    Sequence<int> tree_sort(Sequence<int>);
    Sequence<int> quick_sort(Sequence<int>, int);
    Sequence<int> shaker_sort(Sequence<int>);
    Sequence<int> bubble_sort(Sequence<int>);
};
Sequence<int> Sorter::tree_sort(Sequence<int> vector) {
    binary_tree tree = binary_tree(vector.peek(0));
    for (int i = 1; i < vector.size(); i++)
    {
        tree.insert(vector.peek(i));
    }
    Sequence<int> result;//
    result = tree.get_sequence();
    return result;
}

Sequence<int> Sorter::quick_sort(Sequence<int> vector, int size) {
    int mid = vector.peek(size / 2);
    int i = 0;
    int j = size - 1;
    do {
        while (vector.peek(i) < mid) {
            i++;
        }

        while (vector.peek(j) > mid) {
            j--;
        }

        if (i <= j) {
            vector = vector.swap(i, j);

            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0) {
        vector = quick_sort(vector, j + 1);
    }
    if (i < size) {
        vector = quick_sort(vector, size - i);
    }
    return vector;
}

Sequence<int> Sorter::shaker_sort(Sequence<int> vector) {
    int control = vector.size() - 1;
    int left = 0;
    int right = vector.size() - 1;
    do {
        for (int i = left; i < right; i++) {
            if (vector.peek(i) > vector.peek(i + 1)) {
                vector = vector.swap(i, i + 1);
                control = i;
            }
        }
        right = control;
        for (int i = right; i > left; i--) {
            if (vector.peek(i) < vector.peek(i - 1)) {
                vector = vector.swap(i, i - 1);
                control = i;
            }
        }
        left = control;
    } while (left < right);
    return vector;
}

Sequence<int> Sorter::bubble_sort(Sequence<int> vector) {
    for (int j = 0; j < vector.size() - 1; j++)
    {
        for (int i = 0; i < vector.size() - 1; i++) {
            if (vector.peek(i) > vector.peek(i + 1)) {
                vector = vector.swap(i, i + 1);
            }
        }
    }
    return vector;
}

class Time_info : public Sorter {
public:
    int* get_time(Sequence<int>, int, int);
};
int* Time_info::get_time(Sequence<int> vector, int sort1, int sort2) {
    high_resolution_clock::time_point t1_sort1;
    high_resolution_clock::time_point t2_sort1;
    high_resolution_clock::time_point t1_sort2;
    high_resolution_clock::time_point t2_sort2;
    Sequence<int> v;
    auto duration1 = 0;
    auto duration2 = 0;
    int* arr = new int[3];
    switch (sort1)
    {
    case 1:
        t1_sort1 = high_resolution_clock::now();
        v = tree_sort(vector);
        t2_sort1 = high_resolution_clock::now();
        duration1 = duration_cast<microseconds>(t2_sort1 - t1_sort1).count();
        v.erase();

    case 2:
        t1_sort1 = high_resolution_clock::now();
        v = quick_sort(vector, vector.size());
        t2_sort1 = high_resolution_clock::now();
        duration1 = duration_cast<microseconds>(t2_sort1 - t1_sort1).count();
        v.erase();
    case 3:
        t1_sort1 = high_resolution_clock::now();
        v = shaker_sort(vector);
        t2_sort1 = high_resolution_clock::now();
        duration1 = duration_cast<microseconds>(t2_sort1 - t1_sort1).count();
        v.erase();
    case 4:
        t1_sort1 = high_resolution_clock::now();
        v = bubble_sort(vector);
        t2_sort1 = high_resolution_clock::now();
        duration1 = duration_cast<microseconds>(t2_sort1 - t1_sort1).count();
        v.erase();
    default:
        break;
    }

    switch (sort2)
    {
    case 1:
        t1_sort2 = high_resolution_clock::now();
        v = tree_sort(vector);
        t2_sort2 = high_resolution_clock::now();
        duration2 = duration_cast<microseconds>(t2_sort2 - t1_sort2).count();
        v.erase();
    case 2:
        t1_sort2 = high_resolution_clock::now();
        v = quick_sort(vector, vector.size());
        t2_sort2 = high_resolution_clock::now();
        duration2 = duration_cast<microseconds>(t2_sort2 - t1_sort2).count();
        v.erase();
    case 3:
        t1_sort2 = high_resolution_clock::now();
        v = shaker_sort(vector);
        t2_sort2 = high_resolution_clock::now();
        duration2 = duration_cast<microseconds>(t2_sort2 - t1_sort2).count();
        v.erase();
    case 4:
        t1_sort2 = high_resolution_clock::now();
        v = bubble_sort(vector);
        t2_sort2 = high_resolution_clock::now();
        duration2 = duration_cast<microseconds>(t2_sort2 - t1_sort2).count();
        v.erase();
    default:
        break;
    }
    arr[0] = vector.size();
    arr[1] = duration1;
    arr[2] = duration2;
    vector.erase();
    return arr;

}