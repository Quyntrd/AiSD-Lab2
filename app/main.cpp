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

	LinkedList<int> list2;
	list2.push_head(10);
	list2.push_head(5);
	list2.push_head(4);
	cout << "6: " << "\t";
	cout << list2 << endl;
	int temp = list2[0];
	cout << temp << "\t";
	temp = list2[1];
	cout << temp << "\t";
	temp = list2[2];
	cout << temp << endl;
	list2[0] = 20;
	cout << "7:" << "\t";
	cout << list2 << endl;
}