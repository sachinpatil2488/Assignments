/******************************************************************************

							  Online C++ Compiler.
			   Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>

using namespace std;

struct node
{
	node* next = nullptr;
	int data;

	node(int val, node* link = nullptr) : data(val), next(link)
	{
	}
};


node* divideList(node* first, node*& second)
{
	node* middle = nullptr;
	node* slow = first, * fast = first, * slow_pre = nullptr;

	//1 2 3 4 5 6


	while (fast && fast->next) {
		fast = fast->next->next;

		slow_pre = slow;
		slow = slow->next;
	}

	if (fast) {
		middle = slow;
		second = middle->next;
	}
	else {
		second = slow;
	}

	slow_pre->next = nullptr;

	return middle;
}

bool isPalindrom(node* l1, node* l2)
{
	while (l1 && l2) {
		if (l1->data != l2->data) {
			return false;
		}

		l1 = l1->next;
		l2 = l2->next;
	}

	return l1 == l2;
}

void reverse(node*& head)
{
	node* pre = nullptr;

	while (head) {
		node* next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}

	head = pre;
}

bool isListPalindrome(node* head)
{
	node* first = head, * second = nullptr;
	node* middle = divideList(first, second);

	reverse(first);
	bool result = isPalindrom(first, second);

	reverse(first);

	while (first->next != nullptr) {
		first = first->next;
	}

	if (middle) {
		first->next = middle;
	} else {
		first->next = second;
	}

	return result;
}

int main()
{
	node n1(1);
	node n2(2, &n1);
	node n3(3, &n2);
	node n4(2, &n3);
	node n5(1, &n4);


	cout << isListPalindrome(&n5);

	return 0;
}
