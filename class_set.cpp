#include "class_set.h"
using namespace class_set;
Set::Set() {
	first = nullptr;
}
Set Set::create_empty() {
	Set* newSet = new Set();
	return *newSet;
}
Set::Set(int size, int min, int max, int k) {
	Set* set = nullptr;
	while (size > 0) {
		int value = rand_val(min, max);
		if (value % k == 0 && !is_belongs(value)) {
			add(value);
			size--;
		}
	};
}
int Set::rand_val(int a, int b) {
	if (a > 0) return a + rand() % (b - a);
	else return a + rand() % (abs(a) + b);
}
void Set::add(int newEl) {
	if (!is_belongs(newEl)) {
		Elem* tmp = new Elem;
		tmp->value = newEl;
		tmp->next = first;
		first = tmp;
	}
}
bool Set::is_empty() {
	return first == nullptr;
}
bool Set::is_belongs(int value) {
	Elem* tmp = first;
	bool res = false;
	if (is_empty()) return false;
	while (tmp != nullptr) {
		if (tmp->value == value) {
			res = true;
			break;
		}
		tmp = tmp->next;
	}
	return res;
}
int Set::get_size() {
	int size = 0;
	Elem* tmp = first;
	if (is_empty()) {
		return 0;
	}
	while (tmp->next) {
		tmp = tmp->next;
		size++;
	}
	size++;
	return size;
}


string Set::print_set(string delim) {
	if (is_empty()) return "EMPTY";
	Elem* tmp = first;
	string res;
	while (tmp->next) {
		res += to_string(tmp->value) + delim;
		tmp = tmp->next;
	}
	res += to_string(tmp->value);
	return res;

}
void Set::deleteSet() {
	Elem* tmp = first;
	while (first->next) {
		tmp = first;
		first = first->next;
		delete tmp;
	}
	first = nullptr;
}
bool Set::check_sub(Set set) {
	if (is_empty())
		return true;

	if (get_size() > set.get_size())
		return false;
	Elem* temp = first;
	while (temp->next) {
		if (!set.is_belongs(temp->value))
			return false;
		temp = temp->next;
	}
	return true;
}
bool Set::equals(Set set) {
	return check_sub(set) && set.check_sub(*this);
}
Set Set::merge(Set set) {
	Elem* tmp = first;
	if (is_empty()) return set;
	if (set.is_empty()) return create_empty();
	while (tmp != nullptr) {
		if (!set.is_belongs(tmp->value))
			set.add(tmp->value);
		tmp = tmp->next;
	}
	return set;
}
Set Set::identical_elemsAB(Set set) {
	if (is_empty() || set.is_empty()) return create_empty();
	Elem* tmp1 = first;
	Set newSet = create_empty();
	while (tmp1 != nullptr) {
		if (set.is_belongs(tmp1->value)) {
			newSet.add(tmp1->value);
		}
		tmp1 = tmp1->next;
	}
	return newSet;
}
Set Set::different_elemsAB(Set set) {
	Set newSet = Set();
	if (is_empty()) {
		return newSet;
	}
	if (set.is_empty()) {
		return *this;
	}
	Elem* tmp1 = first;
	while (tmp1 != nullptr) {
		if (!set.is_belongs(tmp1->value)) {
			newSet.add(tmp1->value);
		}
		tmp1 = tmp1->next;
	}

	return newSet;
}

Set Set::symmetric_difference(Set set) {
	Set NewSet = merge(set);
	Set Test = identical_elemsAB(set);
	return NewSet.different_elemsAB(Test);
}