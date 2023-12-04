#include "LinkedList.cpp"
#include <iostream>

using namespace std;
int main() {
	LinkedList<int> list1;
	list1.push_head(10);
	list1.push_head(20);
	list1.push_head(15);
	list1.push_head(3);
	list1.push_head(2);
	list1.push_tail(100);
	cout << list1 << endl;
}