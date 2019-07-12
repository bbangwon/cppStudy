#include <iostream>

int main()
{
	int aSize = 0;

	std::cout << "Array Size : ";
	std::cin >> aSize;

	int *element = new int[aSize];
	for (int i = 0; i < aSize; i++)
		std::cin >> element[i];

	for (int i = 0; i < aSize; i++)
	{
		std::cout << element[i] << std::endl;
	}

	delete[] element;  	 
	return 0;
}