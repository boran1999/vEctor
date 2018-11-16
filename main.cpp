#include<iostream>
#include<locale.h>
#include"Array.h"

using namespace std;

ostream& operator <<(ostream& out, const Array& arr)
{
	out << "Total size: " << arr.size << endl;
	for (int i = 0; i < arr.size; i++)
		out << arr.ptr[i] << endl;
	return out;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Array arr(6);
	for (int i = 0; i < 6; i++)
		arr.insert(i + 1);
	cout << arr << endl;

	for (int i = 0; i < 12; i += 2)
		arr.insert(i+2, i);
	cout << arr << endl;

	for (int i = 1; i < 8; i += 2)
		arr[i] = 20 + i;
	cout << arr << endl;

	for (int i = 6; i >= 0; i -= 3)
		arr.remove(i);
	cout << arr << endl;

	system("pause");
	return 0;
}
