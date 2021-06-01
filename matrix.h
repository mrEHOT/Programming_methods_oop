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
		enum outputStyle { LINEBYLINE, BYCOLUMNS, ONEDIMENARR }; // Выбор способа вывода матрицы: 1)Построчно; 2)По столбцам; 3)В виде одномерного массива
		outputStyle style;

		virtual void ClearMtx() = 0;
		static matrix* MtxInput(ifstream& ifst);
		virtual bool Input(ifstream& ifst) = 0;
		virtual void Output(ofstream& ofst) = 0;
		~matrix() {};
	};
} // end namespace simple_matrix
#endif // !matrix_definition