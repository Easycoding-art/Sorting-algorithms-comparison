#pragma once
#include <iostream>
#include <fstream>
#include "Sorter.h"
#include "Sequence.h"
using namespace std;
void write_file(int sort_numbers) {
	Sequence<int> vector = Sequence<int>();
	Sorter sort;
	Time_info t;
	int number1 = sort_numbers / 10;
	int number2 = sort_numbers % 10;
	srand(time(0)); // инициализация генерации случайных чисел
	int k = 10;
	int size = 10;
	int iterations = 10;
	int** arr_unsorted = new int* [iterations];
	int** arr_sorted = new int* [iterations];
	for (int i = 0; i < iterations; i++) {
		for (int j = 0; j < size + k * i; j++) {
			vector = vector.add(rand());
		}
		arr_unsorted[i] = t.get_time(vector, number1, number1);
		vector = sort.quick_sort(vector, vector.size());
		arr_sorted[i] = t.get_time(vector, number1, number1);

		for (int a = 0; a < size + k * i; a++) {
			vector = vector.pop();
		}
	}
	ofstream f("Lab1_graph_data_unsorted.txt");
	f << sort_numbers << "\n";
	for (int n = 0; n < iterations; n++) {
		f << arr_unsorted[n][0] << " " << arr_unsorted[n][1] << " " << arr_unsorted[n][2] << "\n";
	}
	f.close();

	ofstream f2("Lab1_graph_data_sorted.txt");
	f2 << sort_numbers << "\n";
	for (int m = 0; m < iterations; m++) {
		f2 << arr_sorted[m][0] << " " << arr_sorted[m][1] << " " << arr_sorted[m][2] << "\n";
	}
	f2.close();
	delete[] arr_unsorted;
	delete[] arr_sorted;
}