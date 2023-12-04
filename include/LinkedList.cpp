#pragma once

#include <iostream>

template<class Data>
class LinkedList {
	struct Node {
		Data data;
		Node* next;
	};
	Node* _head = nullptr;

public:
	LinkedList() {
		_head = new Node();
		_head->next = _head;
	};
	LinkedList(const LinkedList& other): LinkedList() {
		Node* temp = other._head->next;
		while (temp != other._head) {
			this->push_tail(temp->data);
			temp = temp->next;
		}
	};
	~LinkedList() {
		Node* temp = _head;
		while (temp->next != _head) {
			temp = temp->next;
		}
		temp->next = nullptr;
		while (_head) {
			Node* count = _head;
			_head = _head->next;
			delete count;
		}
	};
	LinkedList& operator+=(const LinkedList& second) {
		int len1 = 0, len2 = 0;
		Node* temp1 = _head->next;
		Node* temp2 = second._head->next;
		while (temp1 != _head) {
			temp1 = temp1->next;
			len1++;
		}
		while (temp2 != second._head) {
			temp2 = temp2->next;
			len2++;
		}
		if (len1 != len2) {
			throw std::runtime_error("Different sizes of lists");
		}
		temp1 = _head->next;
		temp2 = second._head->next;
		while (temp1 != _head) {
			temp1->data += temp2->data;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		return *this;
	};
	LinkedList operator+(const LinkedList& second) const {
		LinkedList new_list(*this += second);
		return new_list;
	};
	
	Data& operator[](const int index) {
		if (index < 0) {
			throw std::out_of_range("Out of range");
		}
		int count = 0;
		Node* temp = _head->next;
		while (temp != _head) {
			if (count == index) {
				return temp->data;
				temp = temp->next;
				count++;
			}
		}
		throw std::out_of_range("Out of range");
	};
	Data operator[](const int index) const {
		if (index < 0) {
			throw std::out_of_range("Out of range");
		}
		int count = 0;
		Node* temp = _head->next;
		while (temp != _head) {
			if (count == index) {
				return temp->data;
				temp = temp->next;
				count++;
			}
		}
		throw std::out_of_range("Out of range");
	};

	void push_tail(const Data& data) {
		Node* new_node = new Node();
		new_node->data = data;
		new_node->next = _head;
		Node* temp = _head;
		while (temp->next != _head) {
			temp = temp->next;
		}
		new_node->next = _head;
		temp->next = new_node;
	};
	void push_tail(const LinkedList list) {
		Node* temp = list._head->next;
		while (temp != list._head) {
			this->push_tail(temp->data);
			temp = temp->next;
		}
	};
	void push_head(const Data& data) {
		Node* new_node = new Node();
		new_node->data = data;
		new_node->next = _head->next;
		_head->next = new_node;
	};
	void push_head(const LinkedList list) {
		Node* temp = list._head->next;
		while (temp != list._head) {
			this->push_head(temp->data);
			temp = temp->next;
		}
	};
	void pop_tail() {
		Node* temp = _head;
		while (temp->next->next != _head) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = _head;
	};
	void pop_head() {
		Node* temp = _head->next;
		_head->next = _head->next->next;
		delete temp;
	};
	void delete_node(const Data& data){
		Node* temp = _head;
		do {
			if (temp->next->data == data) {
				Node* deleted = temp->next->next;
				delete temp->next;
				temp->next = deleted;
			}
			temp = temp->next;
		} while (temp != _head);
	};

	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list) {
		Node* temp = list._head->next;
		int count = 0;
		while (temp != list._head) {
			stream << temp->data<< "x^"<< count << "\t";
			count++;
			temp = temp->next;
		}
		return stream;
	}
};