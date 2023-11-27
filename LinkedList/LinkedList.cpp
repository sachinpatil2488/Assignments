// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <initializer_list>

using namespace std;

template <class T>
struct Node
{
	Node(T& val) {
		m_data = val;
		m_link = nullptr;
	}

	T m_data;
	Node* m_link;
};


template <class T>
class LinkList
{
private:
	Node<T>* m_head = nullptr;
	Node<T>* m_tail = nullptr;
	size_t length = 0;

public:
	LinkList(std::initializer_list<T> list)
	{
		for (auto i : list) {
			insert(i);
		}
	}

	void print()
	{
		auto n = m_head;
		std::cout << "\n list : { ";

		while (n != nullptr) {
			std::cout << n->m_data << ", ";
			n = n->m_link;
		}

		std::cout << "}\n\n";
	}
	
	Node<T>* toNode(T val) 
	{
		return new Node<T>(val);
	}
	void insert(T value)
	{
		auto node = toNode(value);

		if (m_head != nullptr) {
			m_tail->m_link = node;
			m_tail = node;
		}
		else {
			m_head = m_tail = node;
		}

		++length;
	}

	void insertBegin(T value)
	{
		auto node = toNode(value);

		if (m_head != nullptr) {
			node->m_link = m_head;
			m_head = node;
		}
		else {
			m_head = m_tail = node;
		}

		++length;
	}

	void remove(T value)
	{
		if (m_head == nullptr)
			return;

		Node* temp = nullptr;
		if (m_head->data == value) {
			auto toBeDelete = m_head;
			m_head = m_head->m_link;

			delete toBeDelete;
			toBeDelete = nullptr;
			--length;
			return;
		}

		auto temp = m_head;
		while (temp->m_link != nullptr) {

			if (temp->m_link->data == value)
			{
				auto toBeDelete = temp->m_link;
				temp->m_link = temp->m_link->m_link;

				delete toBeDelete;
				toBeDelete = nullptr;

				--length;

				return;
			}
			temp = temp->m_link;
		}
	}

	void removeNode(Node<T>* node)
	{
		remove(node->m_data);
	}

	bool find(T value)
	{
		Node* temp = m_head;
		while (temp != nullptr)
		{
			if (temp->data == value)
			{
				return true;
			}

			temp = temp->m_link;
		}

		return false;
	}

	void deleteKFromEnd(int k)
	{
		if (k > length)
			return;

		Node<T>* p, * n;

		p = n = m_head;
		for (int i = 1; i < k; ++i) {
			n = n->m_link;
		}

		Node<T>* pre = nullptr;

		while (n->m_link != nullptr) {
			n = n->m_link;
			pre = p;
			p = p->m_link;
		}

		if (pre == nullptr) {
			auto toBeDelete = m_head;
			m_head = m_head->m_link;
		}
		pre->m_link = p->m_link;

	}

	void sort()
	{
		//sort 1
		int k = length;
        while (k) {
			auto temp = m_head;
			int i = k;
			while (temp->m_link != nullptr && i--) {
				if (temp->m_data > temp->m_link->m_data) {
					temp->m_data = temp->m_data ^ temp->m_link->m_data;
					temp->m_link->m_data = temp->m_data ^ temp->m_link->m_data;
					temp->m_data = temp->m_data ^ temp->m_link->m_data;
				}

				temp = temp->m_link;
			}
			--k;
        }
	}

	Node<T>* reverse(Node<T>* head, int k, Node<T>*& nextBucket) 
	{
		Node<T>* prev = nullptr;

		while (k) {
			auto next = head->m_link;
			head->m_link = prev;
			prev = head;
			head = next;
			--k;
		}

		nextBucket = head;
		return prev;
	}

	Node<T>* bucketReverse(Node<T>* head, int k, Node<T>* nextBucket)
	{
		if (nextBucket == nullptr)
			return nullptr;

		auto newHead = reverse(head, k, nextBucket);

		head->m_link = bucketReverse(nextBucket, k, nextBucket);

		return newHead;
	}

	void bucketReverse(int k)
	{
		Node<T>* nextBucket = m_head;
		m_head = bucketReverse(m_head, k, nextBucket);
	}

	bool printPN(Node<T>*&p, Node<T>* n)
	{
		if (n == nullptr)
			return true;

		if (printPN(p, n->m_link)) {

			cout << p->m_data << " , " << n->m_data << " , ";
			p = p->m_link;

			return p != n;
		}

		return false;
	}

	bool reorder(Node<T>*& p, Node<T>* n)
	{
		if (n == nullptr)
			return true;

		// 1 2 3 4 5 6
		if (reorder(p, n->m_link)) {

            if (p == n) {
				p->m_link = nullptr;
				return false;
			}
			if (p->m_link == n) {
				n->m_link = nullptr;
				return false;
			}

            auto temp = p->m_link;
            p->m_link = n;
            n->m_link = temp;
            p = temp;

			return true;
		}

		return false;
	}

	void printPN()
	{
		//std::cout << "\n list : { ";
		//printPN(m_head, m_head);
		//cout << "}";
		auto temp = m_head;
		reorder(temp, m_head);
	}
};

int main()
{
	LinkList<int> list {1, 2, 3, 4, 5, 6 };
	list.print();
	//list.deleteKFromEnd(2);
	//list.sort();
	//list.bucketReverse(3);
	list.printPN();
	list.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
