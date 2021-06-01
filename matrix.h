#pragma once
#ifndef matrix_definition
#define matrix_definition
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
namespace simple_matrix
{
	class matrix
	{
	public:
		long sideSize;
		enum outputStyle { LINEBYLINE, BYCOLUMNS, ONEDIMENARR }; // ����� ������� ������ �������: 1)���������; 2)�� ��������; 3)� ���� ����������� �������
		outputStyle style;

		virtual void ClearMtx() = 0;
		static matrix* MtxInput(ifstream& ifst);
		virtual bool Input(ifstream& ifst) = 0;
		virtual void Output(ofstream& ofst) = 0;
		~matrix() {};
	};
} // end namespace simple_matrix
#endif // !matrix_definition