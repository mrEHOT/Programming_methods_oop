#include <iostream>
#include <fstream>
#include "container.h"
using namespace std;
using namespace simple_matrix;

int main(int argc, char* argv[])
{


	if (argc != 3)
	{
		cout << "incorrect command line!" << endl;
		cout << "Waited: command infile outfile" << endl;
		exit(1);
	}

	ifstream ifst(argv[1]);
	if (!ifst.is_open())
	{
		cout << "Input file is not open!" << endl;
		return 1;
	} // Проверка открытия файла Input

	ofstream ofst(argv[2]);
	if (!ofst.is_open())
	{
		cout << "Input file is not open!" << endl;
		return 1;
	} // Проверка открытия файла Output
	cout << "Start" << endl;

	container cont;

	cont.Input(ifst); // Заполняем контейнер данными из потока
	cont.Sort(); //Сортируем контейнер по возрастнию суммы элементов матрицы
	cout << "Filled container. " << endl;
	cont.Output(ofst); // Вывод заполненного контейнера

	cont.Clear(); //Очистка контейнера
	cout << "Empty container. " << endl;
	cont.Output(ofst); // Вывод пустого контейнера

	cout << "Stop" << endl;

	return 0;
}