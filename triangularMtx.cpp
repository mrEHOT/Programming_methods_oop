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
			currentMtxSize = count;

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

		ofst << "It is Triangular matrix. Matrix side size: " << sideSize << ". The sum of the elements of the matrix: " << sum << endl;

		switch (style)
		{
		case 0:
			ofst << "Matrix output style - \"Line by line\" " << endl;
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
			break;
		case 1:
			ofst << "Matrix output style - \"Output by columns\" " << endl;
			for (int col = 0; col < sideSize; col++)
			{
				for (int row = 0; row < sideSize; row++)
				{
					if (row >= col)
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
			break;
		case 2:
			ofst << "Matrix output style - \"Output to a one-dimensional array\" " << endl;
			ofst << "[ ";
			for (int col = 0; col < currentMtxSize; col++)
			{
				ofst << currentMtx[col] << " ";
			}
			ofst << "]" << endl << endl;
			break;
		default:
			break;
		}

		ofst << endl;
	}

	void triangularMtx::ClearMtx()
	{
		delete[] currentMtx;
	}

	triangularMtx::triangularMtx(int style)
	{
		sideSize = 0;
		currentMtxSize = 0;
		currentMtx = NULL;

		switch (style)
		{
		case 0:
			this->style = LINEBYLINE;
			break;
		case 1:
			this->style = BYCOLUMNS;
			break;
		case 2:
			this->style = ONEDIMENARR;
			break;
		default:
			break;
		}
	}

	int triangularMtx::MtxSum()
	{
		if (!sumMarker)
		{
			for (int row = 0; row < currentMtxSize; row++)
			{
				sum += currentMtx[row];
			}
			sumMarker = true; // Устанавливаем маркер в TRUE (сумма элементов посчитана)
			return sum;
		} // Выполняется, если сумма элементов не была вычислена ранее
		else
		{
			return sum;
		} // Если сумма уже была посчитана => просто вернем ее
	}
} // end namespace simple_matrix