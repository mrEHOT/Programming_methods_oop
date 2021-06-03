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
	public:
		long size;
		node* head;

		bool Input(ifstream& ifst);
		void Output(ofstream& ofst);
		void FilteredOutput(ofstream& ofst);
		void Clear();
		void Sort();
		container();
		~container() { Clear(); };
	};
} // end namespace simple_matrix
#endif // !container_definition