#include "list_set.h"
using namespace list_set;
Set::Set() {
	set = list<int>();
}
Set Set::create_empty() {
	Set* newSet = new Set();
	return *newSet;
}
Set::Set(int size, int min, int max, int k) {
	Set set = create_empty();
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
		set.push_front(newEl);
	}
}
bool Set::is_empty() {
	return set.empty();
}
bool Set::is_belongs(int value) {
	for (auto i = set.begin(); i != set.end(); i++) {
		if (*i == value) {
			return true;
		}
	}
	return false;
}
int Set::get_size() {
	return set.size();
}

string Set::print_set(string delim) {
	string res;
	if (is_empty()) return "EMPTY";
	for (auto i = set.begin(); i != --set.end(); i++)
		res += to_string(*i) + delim;
	res += to_string(set.back());
	return res;

}
void Set::deleteSet() {
	set.erase(set.begin(), set.end());
}
bool Set::check_sub(Set another) {
	if (is_empty()) return true;
	if (another.is_empty()) return false;
	if (get_size() > another.get_size()) return false;
	for (auto i = set.begin(); i != set.end(); i++)
		if (!another.is_belongs(*i))
			return false;
	return true;
}
bool Set::equals(Set another) {
	return check_sub(another) && another.check_sub(*this);
}
Set Set::merge(Set another) {
	if (is_empty()) return another;
	if (another.is_empty()) return *this;
	Set newSet = another;
	for (auto i = set.begin(); i != set.end(); i++)
		if (!another.is_belongs(*i))
			newSet.add(*i);
	return newSet;
}
Set Set::identical_elemsAB(Set another) {
	if (is_empty() || another.is_empty()) return create_empty();
	Set newSet = create_empty();
	for (auto i = set.begin(); i != set.end(); i++)
		if (another.is_belongs(*i))
			newSet.add(*i);
	return newSet;
}
Set Set::different_elemsAB(Set another) {
	Set newSet = Set();
	if (is_empty()) return newSet;
	if (another.is_empty()) return *this;
	for (auto i = set.begin(); i != set.end(); i++)
		if (!another.is_belongs(*i))
			newSet.add(*i);
	return newSet;
}
Set Set::symmetric_difference(Set another) {
	Set NewSet = merge(another);
	Set Test = identical_elemsAB(another);
	return NewSet.different_elemsAB(Test);
}
