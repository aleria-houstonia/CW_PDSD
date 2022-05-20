#pragma once
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

//namespace struct_set {}
	struct Elem {
		int value;
		Elem* next;
	};
	Elem* create_empty_set();
	bool is_empty_set(Elem*);
	bool is_belongs(Elem*, int value);
	Elem* add_new_elem(Elem*, int new_elem);
	Elem* create_set(int size, int min, int max, int k);
	int get_size_of_set(Elem* A);
	Elem* delete_set(Elem* A);
	string print_set(Elem* A, string delim);
	int rand_val(int a, int b);
	bool checkSub(Elem* main, Elem* sub);
	bool checkEquals(Elem* A, Elem* B);
	Elem* mergerOfSets(Elem* A, Elem* B);
	Elem* create_with_identical_elemsAB(Elem* A, Elem* B);
	Elem* create_with_different_elemsAB(Elem* A, Elem* B);
	Elem* create_with_symmetric_difference(Elem* A, Elem* B);