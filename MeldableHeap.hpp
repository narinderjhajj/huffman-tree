#include <string> 
#include "HNode.h"
#include <cstdlib>
/*struct Node is to store the date in x and has left, right and parent pointers.*/
template<typename T> struct Node{
		T x;
		Node *left;
		Node *right;
		Node *parent;
		
/*Constructor of node will intialize x with u which will be passed when creating a Node object.
	The left, right and parent pointers are set null initially.	*/
		Node(T u)
		{
			x = u;
			left = right = parent = nullptr;
		}
};

template<typename T> class MeldableHeap
{
	
public:
	Node<T> *r;
	int n;
	
	MeldableHeap()
	{
		r = nullptr;
		n = 0;
	}
	
	bool add(T x) {
		Node<T> *u = new Node<T>(x);
		r = merge(u, r);
		r->parent = nullptr;
		n++;
		return true;
	}

	Node<T>* merge(Node<T> *h1, Node<T> *h2) {
		if (h1 == nullptr) return h2;
		if (h2 == nullptr) return h1;
		if ((h1->x) > (h2->x)) std::swap(h1,h2);

		if (rand() % 2) {
		h1->left = merge(h1->left, h2);
		if (h1->left != nullptr) h1->left->parent = h1;
		} else {
		h1->right = merge(h1->right, h2);
		if (h1->right != nullptr) h1->right->parent = h1;
		}
		return h1;
	}
	
	T remove(){
		T x;
		x = r->x;
		r = merge(r->left,r->right);
		n--;
		return x;
	}
	


};
