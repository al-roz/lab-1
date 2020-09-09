#include <iostream>
#include "set.hpp"

int main()
{
	Set s("set.txt");
	s.output();
	std::cout << s.chek_on_field();
}