#include "triangularMtx.h"
namespace simple_matrix
{
	bool triangularMtx::Input(ifstream& ifst)
	{
		string content = "";
		string delimiter = ",";
		string part = "";
		size_t pos = 0;
		int col = 0;
		int count = 1;
		int check = 0;

		ifst >> content;

		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				count++;
			}
		} // Считаем количество элементов в матрице

		sideSize = (long)sqrt(count) + 1;

		check = (1 + sideSize) * sideSize / 2;
		if (count == check)
		{
			currentMtx = new int[count];

			while ((pos = content.find(delimiter)) != string::npos)
			{
				part = content.substr(0, pos);
				currentMtx[col] = atoi(part.c_str());
				col++;
				content.erase(0, pos + delimiter.length());
			}
			currentMtx[col] = atoi(content.c_str());
			return true;
		}
		else
		{
			return false;
		} // Если ввод матрицы выполнить нельзя => вернем FALSE
	}

	void triangularMtx::Output(ofstream& ofst)
	{
		int count = 0;
		ofst << "It is Triangular matrix. Matrix side size: " << sideSize << endl;
		for (int row = 0; row < sideSize; row++)
		{
			for (int col = 0; col < sideSize; col++)
			{
				if (col < row + 1)
				{
					ofst << currentMtx[count] << "\t";
					count++;
				}
				else
				{
					ofst << "0" << "\t";
				}
			}
			ofst << endl;
		}
		ofst << endl;
	}

	void triangularMtx::ClearMtx()
	{
		delete[] currentMtx;
	}
} // end namespace simple_matrix