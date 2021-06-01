#pragma once
#ifndef container_definition
#define container_definition
#include <string>
#include <iostream>
#include <fstream>
#include "node.h"
using namespace std;
namespace simple_matrix
{
	class container
	{
		long size;
		node* head;
	public:
		bool Input(ifstream& ifst);
		void Output(ofstream& ofst);
		void Clear();

		container();
		~container() { Clear(); };
	};
} // end namespace simple_matrix
#endif // !container_definition