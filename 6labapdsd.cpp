#include <iostream>
#include <vector>
#include <chrono>
#include "struct_set.h"
#include "class_set.h"
#include "list_set.h"    
#include "set_set.h"
#include "vector.h"
#include <regex>

void render(string name, __int64 arr[]) {
	cout << "\n" << name;
	for (int i = 0; i < 10; i++) {
		printf("%*d  |", 8, arr[i]);
	}
}
template <class T>
void getTime(T a, T b, __int64 arr[], string name)
{
	auto start = std::chrono::high_resolution_clock::now();
	a.get_size();
	auto finish = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
	arr[1] = time.count();

	auto start1 = std::chrono::high_resolution_clock::now();
	a.check_sub(a);
	auto finish1 = std::chrono::high_resolution_clock::now();
	auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish1 - start1);
	arr[2] = time1.count();

	auto start2 = std::chrono::high_resolution_clock::now();
	a.check_sub(b);
	auto finish2 = std::chrono::high_resolution_clock::now();
	auto time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish2 - start2);
	arr[3] = time2.count();

	auto start3 = std::chrono::high_resolution_clock::now();
	a.equals(a);
	auto finish3 = std::chrono::high_resolution_clock::now();
	auto time3 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish3 - start3);
	arr[4] = time3.count();

	auto start4 = std::chrono::high_resolution_clock::now();
	a.equals(b);
	auto finish4 = std::chrono::high_resolution_clock::now();
	auto time4 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish4 - start4);
	arr[5] = time4.count();

	auto start5 = std::chrono::high_resolution_clock::now();
	a.merge(b);
	auto finish5 = std::chrono::high_resolution_clock::now();
	auto time5 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish5 - start5);
	arr[6] = time5.count();

	auto start6 = std::chrono::high_resolution_clock::now();
	a.identical_elemsAB(b);
	auto finish6 = std::chrono::high_resolution_clock::now();
	auto time6 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish6 - start6);
	arr[7] = time6.count();

	auto start7 = std::chrono::high_resolution_clock::now();
	a.different_elemsAB(b);
	auto finish7 = std::chrono::high_resolution_clock::now();
	auto time7 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish7 - start7);
	arr[8] = time7.count();

	auto start8 = std::chrono::high_resolution_clock::now();
	a.symmetric_difference(b);
	auto finish8 = std::chrono::high_resolution_clock::now();
	auto time8 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish8 - start8);
	arr[9] = time8.count();

	render(name, arr);
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	
	string cinN;
	cout << "Введите мощность : " ;
	cin >> cinN;
	regex size_regex("^[0-9]+$");
while (!regex_match(cinN, size_regex))
	{
		cout << "Некорректный ввод" << endl;
		cout << endl;
		cout << "Введите мощность : ";
		cin >> cinN;
		cout << endl;
	}
	
	int N =atoi(cinN.c_str());
	vector<string> op = { "     "," create    |", "  size    |","sub AA    |","sub АВ    |",
	"equal АА  |","equal АВ  |","union     |","intersect |",
	"different |", "symm different" };

	for (int i = 0; i < 11; i++) {
		cout << op[i];
	}

	__int64 timesClass[10];
	__int64 timesVector[10];
	__int64 timesList[10];
	__int64 timesSet[10];
	__int64 timesStruct[10];
	auto startStruct0 = std::chrono::high_resolution_clock::now();
	Elem* set_a1 = create_set(N, 0, N*10, 3);
	auto finishStruct0 = std::chrono::high_resolution_clock::now();
	auto timeStruct0 = std::chrono::duration_cast<std::chrono::nanoseconds>(finishStruct0 - startStruct0);
	timesStruct[0] = timeStruct0.count();
	Elem* set_b1 = create_set(N, 0, N * 10, 3);
	auto startStruct = std::chrono::high_resolution_clock::now();
	get_size_of_set(set_a1);
	auto finishStruct = std::chrono::high_resolution_clock::now();
	auto timeStruct = std::chrono::duration_cast<std::chrono::nanoseconds>(finishStruct - startStruct);
	timesStruct[1] = timeStruct.count();
	auto startStruct1 = std::chrono::high_resolution_clock::now();
	checkSub(set_a1, set_a1);
	auto finishStruct1 = std::chrono::high_resolution_clock::now();
	auto timeStruct1 = std::chrono::duration_cast<std::chrono::nanoseconds>(finishStruct1 - startStruct1);
	timesStruct[2] = timeStruct1.count();
	auto startStruct2 = std::chrono::high_resolution_clock::now();
	checkSub(set_a1, set_b1);
	auto finishStruct2 = std::chrono::high_resolution_clock::now();
	auto timeStruct2 = std::chrono::duration_cast<std::chrono::nanoseconds>(finishStruct2 - startStruct2);
	timesStruct[3] = timeStruct2.count();
	auto startStruct3 = std::chrono::high_resolution_clock::now();
	checkEquals(set_a1, set_a1);
	auto finishStruct3 = std::chrono::high_resolution_clock::now();
	auto timeStruct3 = std::chrono::duration_cast<std::chrono::nanoseconds>(finishStruct3 - startStruct3);
	timesStruct[4] = timeStruct3.count();
	auto startStruct4 = std::chrono::high_resolution_clock::now();
	checkEquals(set_a1, set_b1);
	auto finishStruct4 = std::chrono::high_resolution_clock::now();
	auto timeStruct4 = std::chrono::duration_cast<std::chrono::nanoseconds>(finishStruct4 - startStruct4);
	timesStruct[5] = timeStruct4.count();
	auto startStruct5 = std::chrono::high_resolution_clock::now();
	mergerOfSets(set_a1, set_b1);
	auto finishStruct5 = std::chrono::high_resolution_clock::now();
	auto timeStruct5 = std::chrono::duration_cast<std::chrono::nanoseconds>(finishStruct5 - startStruct5);
	timesStruct[6] = timeStruct5.count();
	auto startStruct6 = std::chrono::high_resolution_clock::now();
	create_with_identical_elemsAB(set_a1, set_b1);
	auto finishStruct6 = std::chrono::high_resolution_clock::now();
	auto timeStruct6 = std::chrono::duration_cast<std::chrono::nanoseconds>(finishStruct6 - startStruct6);
	timesStruct[7] = timeStruct6.count();
	auto startStruct7 = std::chrono::high_resolution_clock::now();
	create_with_different_elemsAB(set_a1, set_b1);
	auto finishStruct7 = std::chrono::high_resolution_clock::now();
	auto timeStruct7 = std::chrono::duration_cast<std::chrono::nanoseconds>(finishStruct7 - startStruct7);
	timesStruct[8] = timeStruct7.count();
	auto startStruct8 = std::chrono::high_resolution_clock::now();
	create_with_symmetric_difference(set_a1, set_b1);
	auto finishStruct8 = std::chrono::high_resolution_clock::now();
	auto timeStruct8 = std::chrono::duration_cast<std::chrono::nanoseconds>(finishStruct8 - startStruct8);
	timesStruct[9] = timeStruct8.count();
	render("struct", timesStruct);

	auto start = std::chrono::high_resolution_clock::now();
	class_set::Set set_a3(N, 0, N * 10, 3);
	auto finish = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
	timesClass[0] = time.count();
	class_set::Set set_b3(N, 0, N * 10, 3);
	getTime(set_a3, set_b3, timesClass, "class ");

	auto start1 = std::chrono::high_resolution_clock::now();
	list_set::Set set_a4(N, 0, N * 10, 3);
	auto finish1 = std::chrono::high_resolution_clock::now();
	auto time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish1 - start1);
	timesList[0] = time1.count();
	list_set::Set set_b4(N, 0, N * 10, 3);
	getTime(set_a4, set_b4, timesList, "list  ");

	auto start2 = std::chrono::high_resolution_clock::now();
	set_set::Set set_a5(N, 0, N * 10, 3);
	auto finish2 = std::chrono::high_resolution_clock::now();
	auto time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish2 - start2);
	timesSet[0] = time2.count();
	set_set::Set set_b5(N, 0, N * 10, 3);
	getTime(set_a5, set_b5, timesSet, "set   ");

	auto start3 = std::chrono::high_resolution_clock::now();
	vector_set::Set set_a6(N, 0, N * 10, 3);
	auto finish3 = std::chrono::high_resolution_clock::now();
	auto time3 = std::chrono::duration_cast<std::chrono::nanoseconds>(finish3 - start3);
	timesVector[0] = time3.count();
	vector_set::Set set_b6(N, 0, N * 10, 3);
	getTime(set_a6, set_b6, timesVector, "vector");
	cout << endl << endl;
}
