#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
namespace class_set {
	struct Elem {
		int value;
		Elem* next;
	};
	class Set
	{
		Elem* first;
	public:
		Set();
		Set(int size, int min, int max, int k);
		bool is_empty();
		Set create_empty();
		bool is_belongs(int value);
		void add(int new_elem);
		int get_size();
		string print_set(string delim);
		void deleteSet();
		int rand_val(int a, int b);
		bool check_sub(Set set);
		bool equals(Set set);
		Set merge(Set set);
		Set identical_elemsAB(Set set);
		Set different_elemsAB(Set set);
		Set symmetric_difference(Set set);
	};

}
