#include <iostream>
int main( int argc, char* argv[] )
{
	int* p = new int{20};// one int, initialized with 20.
	std::cout << *p << "\n";
	delete p;
}
