#include <iostream>

class A {
	mutable int data_;

public:
	explicit A(int data) : data_(data) {}
	void DoSomething(int x) const {
		data_ = x;
	}

	void PrintData() const {
		std::cout << "data:" << data_ << std::endl;
	}
};

int main() {
	A a(10);
	a.DoSomething(3);
	a.PrintData();

	//A b = 10;	//explicit로 인해 불가능
}