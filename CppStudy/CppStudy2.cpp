#include <iostream>

int change_val(int *p)
{
	*p = 3;

	return 0;
}

int change_val_ref(int &p)
{
	p = 2;

	return 0;
}

int fn1(int &a) { return a; }
int &fn2(int &a) { return a; }

int main()
{
	int number{ 5 };

	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;
	change_val_ref(number);
	std::cout << number << std::endl;



	int &ref = number;
	int *p = &number;

	ref++;	//number + 1
	p++;	//포인터가 가르키는 곳의 주소 값의 증가

	std::cout << number << std::endl;
	std::cout << ref << std::endl;
	std::cout << *p << std::endl;

	std::cout << fn1(number) << std::endl;
	std::cout << ++fn2(number) << std::endl;
	
	return 0;
}