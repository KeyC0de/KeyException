#include <iostream>
#include "key_exception.h"


void throwTheBall()
{
	throwKeyException( "Oh No! Exception incoming!" );
}

int main()
{
	try
	{
		throwTheBall();
	}
	catch( const KeyException& ex )
	{
		std::cerr << ex.what();
	}
	catch( const std::exception& ex )
	{
		std::cerr << ex.what();
	}
	catch( ... )
	{
		std::cout << "Unknown exception!\n";
	}

	std::system( "pause" );
	return EXIT_SUCCESS;
}