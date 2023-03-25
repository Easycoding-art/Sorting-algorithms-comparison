#pragma once
//#ifndef MY_CLASS_H // include guard
#define MY_CLASS_H
#include <iostream>
using namespace std;
template<typename T> class Sequence
{
private:
    T* arr = NULL;
    int sequense_size = 0;
public:
    Sequence() {
        arr = new T[0];
        sequense_size = 0;
    }

    Sequence(T* array, int size) {
        arr = new T[size];
        sequense_size = size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = array[i];
        }
    }


    int size() {
        return this->sequense_size;
    }

    T peek(int count) {
        return arr[count];
    }

    Sequence<T> swap(int i, int j) {
        T a = arr[i];
        T b = arr[j];
        T* array = new T[sequense_size];
        for (int n = 0; n < sequense_size; n++) {
            if (n != i && n != j) {
                array[n] = arr[n];
            }
            if (n == i) {
                array[n] = b;
            }
            if (n == j) {
                array[n] = a;
            }
        }
        Sequence sequence = Sequence(array, sequense_size);
        delete[] array;
        return sequence;
    }

    Sequence<T> pop() {
        T* array = new T[sequense_size - 1];
        for (int i = 0; i < sequense_size - 1; i++)
        {
            array[i] = arr[i];
        }
        Sequence sequence = Sequence(array, sequense_size - 1);
        delete[] array;
        return sequence;
    }

    Sequence<T> add(T value) {
        T* result = new T[sequense_size + 1];
        for (int i = 0; i < sequense_size; i++) {
            result[i] = arr[i];
        }
        result[sequense_size] = value;
        Sequence sequence = Sequence(result, sequense_size + 1);
        delete[] result;
        return sequence;
    }
    void erase() {
        arr = (T*)realloc(arr, 1);
    }
    //void map();
    //void where(bool (*func)(int));
};