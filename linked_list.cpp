#include<iostream>
using namespace std;

class Node {
	public:
		int val;
		Node *next;

		Node() {
			this->val = 0;
			this->next = NULL;
		}

		Node(int val) {
			this->val = val;
			this->next = NULL;
		}
};

int main() {
	Node* head = new Node();
	cout<<"Linked list created!"<<endl;
	cout<<"Head is: "<<head->val<<endl;
	return 0;
}