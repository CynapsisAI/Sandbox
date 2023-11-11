//Includes
#include "Test.h"
#include <iostream>


//Making a template for adding two numbers 
template <typename T,typename U> class Adder{

private:
	T num1;
	U num2;


//adds two numbers of different types, can be int, float

public:
	auto add(T num1, U num2);
};

template <typename T, typename U>  auto Adder<T, U>::add(T num1, U num2) {
	
	U result = num1 + num2; 
	std::cout<<result; 
}



int main() {
	Adder<int, double> myAdder;

	// Call the add function with an int and a double
	int num1 = 5;
	double num2 = 3.5;
	myAdder.add(num1, num2);
}



