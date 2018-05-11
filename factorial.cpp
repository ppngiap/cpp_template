#include <iostream>

template <size_t n> struct fact;

template <> // base case
struct fact<0> {
	const static auto value = 1;
};

template <size_t n> // recursive definition
struct fact {
	const static auto value = n * fact<n - 1>::value;
};

int main() 
{
	std::cout << "Hello World." << std::endl;
	std::cout << fact<2>::value << " ";
	std::cout << fact<3>::value << " ";
	std::cout << fact<5>::value << " ";
	std::cout << fact<8>::value << " ";
	std::cout << fact<9>::value << " ";
	return 0;
}
