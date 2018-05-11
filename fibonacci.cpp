#include <iostream>

template <size_t n> struct fib;

template <> // base case
struct fib<0> {
	const static auto value = 1;
};

template <> // base case
struct fib<1> {
	const static auto value = 1;
};


template <size_t n> // recursive definition
struct fib {
	//const static auto value = fib<n - 1>::value + fib<n - 2>::value;
	const static auto value = fib<n - 1>::value + 1;
};

int main() 
{
	std::cout << "Hello World." << std::endl;
	std::cout << fib<2>::value << " ";
	std::cout << fib<3>::value << " ";
	std::cout << fib<5>::value << " ";
	std::cout << fib<8>::value << " ";
	std::cout << fib<9>::value << " ";
	std::cout << fib<256>::value << " ";
	return 0;
}
