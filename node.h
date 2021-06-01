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
	public:
		matrix* mtx;
		node* next;
		node* prev;

		bool NodeAdd(ifstream& ifst);
		void NodeOutput(ofstream& ofst);
		void NodeRemove();
		~node() {};
	};
}  // end namespace simple_matrix
#endif // !node_definition