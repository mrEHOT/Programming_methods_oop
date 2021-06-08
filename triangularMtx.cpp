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
		int check = 0;

		ifst >> content;
		numberOfElements = 1;
		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				numberOfElements++;
			}
		}

		sideSize = (long)sqrt(numberOfElements) + 1;
		check = (1 + sideSize) * sideSize / 2;

		if (numberOfElements == check)
		{
			if ((numberOfElements <= 1) || (numberOfElements > 55))
			{
				cout << "Incorrect number of elements in triangular matrix! Re-enter items! Recommended amount: 2 to 55." << endl;
				return false;
			}
			else
			{
				currentMtx = new int[numberOfElements];

				while ((pos = content.find(delimiter)) != string::npos)
				{
					part = content.substr(0, pos);
					currentMtx[col] = atoi(part.c_str());
					string str = to_string(currentMtx[col]);
					if (part != str)
					{
						cout << "Trinagular matrix cast error, number cannot be cast to int!" << endl;
						ClearMtx();
						return false;
					}
					col++;
					content.erase(0, pos + delimiter.length());
				}
				currentMtx[col] = atoi(content.c_str());

				MtxSum();
				return true;
			}
		}
		else
		{
			cout << "Triangular matrix input error! The entered elements are not enough to enter the lower triangular matrix!" << endl;
			return false;
		}
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
			for (int col = 0; col < numberOfElements; col++)
			{
				ofst << currentMtx[col] << " ";
			}
			ofst << "]" << endl;
			break;
		default:
			break;
		}

		ofst << endl;
	}

	void triangularMtx::MMMatrix(matrix* other, ofstream& ofst)
	{
		other->MMTriangular(ofst);
	}

	void triangularMtx::MMSquare(ofstream& ofst)
	{
		ofst << "Square Matrix and Triangular Matrix" << endl << endl;
	}

	void triangularMtx::MMDiagonal(ofstream& ofst)
	{
		ofst << "Diagonal Matrix and Triangular Matrix" << endl << endl;
	}

	void triangularMtx::MMTriangular(ofstream& ofst)
	{
		ofst << "Triangular Matrix and Triangular Matrix" << endl << endl;
	}

	void triangularMtx::ClearMtx()
	{
		delete[] currentMtx;
	}

	triangularMtx::triangularMtx()
	{
		currentMtx = NULL;
		numberOfElements = 0;
	}

	triangularMtx::triangularMtx(int style)
	{
		sideSize = 0;
		numberOfElements = 0;
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
			for (int row = 0; row < numberOfElements; row++)
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