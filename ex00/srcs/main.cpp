#include "../include/Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat b(1);
		std::cout << b;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	return (0);
}