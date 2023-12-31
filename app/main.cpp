#include "LinkedList.cpp"
#include <iostream>

using namespace std;

int main() {
	LinkedList<int> list1;

	list1.push_head(10);
	list1.push_head(20);
	list1.push_head(15);
	cout << "1: " << "\t";
	cout << list1 << endl;

	list1.push_tail(2);
	list1.push_tail(100);
	list1.push_tail(100);
	list1.push_tail(100);
	list1.push_tail(3);
	cout << "2: " << "\t";
	cout << list1 << endl;

	list1.pop_head();
	list1.pop_tail();
	cout << "3: " << "\t";
	cout << list1 << endl;

	list1.push_head(0);
	list1.push_head(0);
	cout << "4: " << "\t";
	cout << list1 << endl;

	list1.delete_node(100);
	list1.delete_node(2);
	cout << "5: " << "\t";
	cout << list1 << endl;

	int result = calculate_polynomial(list1, 2);
	cout << "Test:" << result << endl;

	LinkedList<int> list2;
	list2.push_head(10);
	list2.push_head(5);
	list2.push_head(4);
	cout << "6: " << "\t";
	cout << list2 << endl;

	result = calculate_polynomial(list2, 2);
	cout << "Test:" << result << endl;

	int temp = list2[0];
	cout << temp << "\t";
	temp = list2[1];
	cout << temp << "\t";
	temp = list2[2];
	cout << temp << endl;

	list2[0] = 20;
	cout << "7: " << "\t";
	cout << list2 << endl;

	result = calculate_polynomial(list2, 1);
	cout << "Test:" << result << endl;

	LinkedList<double> list3(10, 100.0, 1.0);
	cout << "8: " << "\t";
	cout << list3 << endl;
	double res = calculate_polynomial(list3, 1.1);
	cout << "Test: " << res << endl;

	list1.push_head(list2);
	cout << "9: " << "\t";
	cout << list1 << endl;

	list1 += list1;
	cout << "10: " << "\t";
	cout << list1 << endl;


	LinkedList<int> list5(10, 100, 10);
	LinkedList<int> list4;
	list4.push_head(list5);
	cout << "list1 " << list5 << endl;
	cout << "list4 " << list4 << endl;
}