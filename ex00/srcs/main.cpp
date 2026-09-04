#include "../include/Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat bureaucrat(-1);
		std::cout << bureaucrat;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	return (0);
}