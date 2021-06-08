#include "squareMtx.h"

namespace simple_matrix
{
	bool squareMtx::Input(ifstream& ifst)
	{
		string content = "";
		string delimiter = ",";
		string part = "";
		size_t pos = 0;
		int col = 0;

		ifst >> content;
		for (int i = 0; i < content.size(); i++)
		{
			if (content[i] == ',')
			{
				col++;
			}
		}
		if (col != 0)
		{
			cout << "Input Square matrix error! Side size must be one digit!" << endl;
			return false;
		}
		else
		{
			sideSize = atoi(content.c_str());
			content = "";
			col = 1;
		}

		if ((sideSize <= 1) || (sideSize > 10))
		{
			cout << "Incorrect Square matrix size! Re-enter the side size! Recommended size : 2 to 10." << endl;
			return false;
		}
		else
		{
			currentMtx = new int* [sideSize];
			for (int row = 0; row < sideSize; row++)
			{
				currentMtx[row] = new int[sideSize];
			}

			for (int row = 0; row < sideSize; row++)
			{
				ifst >> content;
				for (int i = 0; i < content.size(); i++)
				{
					if (content[i] == ',')
					{
						col++;
					}
				}

				if (col == sideSize)
				{
					col = 0;

					while ((pos = content.find(delimiter)) != string::npos)
					{
						part = content.substr(0, pos);
						currentMtx[row][col] = atoi(part.c_str());
						string str = to_string(currentMtx[row][col]);
						if (part != str)
						{
							cout << "Square matrix cast error, number cannot be cast to int!" << endl;
							ClearMtx();
							return false;
						}
						col++;
						content.erase(0, pos + delimiter.length());
					}

					currentMtx[row][col] = atoi(content.c_str());
					content = "";
					col = 1;
				}
				else
				{
					ClearMtx();
					cout << "Input Square matrix error! The number of items does not match the side size that was received!" << endl;
					return false;
				}
			}

			MtxSum();
			return true;
		}
	}

	void squareMtx::Output(ofstream& ofst)
	{
		ofst << "It is Square matrix. Matrix side size: " << sideSize << ". The sum of the elements of the matrix: " << sum << endl;

		switch (style)
		{
		case 0:
			ofst << "Matrix output style - \"Line by line\" " << endl;
			for (int row = 0; row < sideSize; row++)
			{
				for (int col = 0; col < sideSize; col++)
				{
					ofst << currentMtx[row][col] << "\t";
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
					ofst << currentMtx[row][col] << "\t";
				}
				ofst << endl;
			}
			break;
		case 2:
			ofst << "Matrix output style - \"Output to a one-dimensional array\" " << endl;
			ofst << "[ ";
			for (int row = 0; row < sideSize; row++)
			{
				for (int col = 0; col < sideSize; col++)
				{
					ofst << currentMtx[row][col] << " ";
				}
			}
			ofst << "]" << endl;
			break;
		default:
			break;
		}
		ofst << endl;
	}

	void squareMtx::FilteredMtxOut(ofstream& ofst)
	{
		Output(ofst);
	}

	void squareMtx::MMMatrix(matrix* other, ofstream& ofst)
	{
		other->MMSquare(ofst);
	}

	void squareMtx::MMSquare(ofstream& ofst)
	{
		ofst << "Square Matrix and Square Matrix" << endl << endl;
	}

	void squareMtx::MMDiagonal(ofstream& ofst)
	{
		ofst << "Diagonal Matrix and Square Matrix" << endl << endl;
	}

	void squareMtx::ClearMtx()
	{
		for (int row = 0; row < sideSize; row++)
		{
			delete currentMtx[row];
		}

		delete[] currentMtx;
	}

	squareMtx::squareMtx()
	{
		sideSize = 0;
		currentMtx = NULL;
	}

	squareMtx::squareMtx(int style)
	{
		sideSize = 0;
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

	int squareMtx::MtxSum()
	{
		if (!sumMarker)
		{
			for (int row = 0; row < sideSize; row++)
			{
				for (int col = 0; col < sideSize; col++)
				{
					sum += currentMtx[row][col];
				}
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