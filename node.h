#pragma once
#ifndef node_definition
#define node_definition
#include <string>
#include <iostream>
#include <fstream>
#include "matrix.h"
using namespace std;
namespace simple_matrix
{
	class node
	{
	private:
		static node* GetNode(node* head, int pos);
		static void NodeSwap(node* head, int first, int second);
	public:
		matrix* mtx;
		node* next;
		node* prev;

		static void NodeCompare(node* head, int size);
		bool NodeAdd(ifstream& ifst);
		void NodeOutput(ofstream& ofst);
		void NodeRemove();
		~node() {};
	};
}  // end namespace simple_matrix
#endif // !node_definition