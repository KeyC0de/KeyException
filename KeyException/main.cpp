#include <iostream>
#include "key_exception.h"
#include "game_exception.h"


void throwTheKey()
{
	throwKeyException( "Oh No! Exception incoming!" );
}

void throwTheGame()
{
	throwGameException( "Game Exception!" );
}

int main()
{
	try
	{
		//throwTheKey();
		throwTheGame();
	}
	catch ( const KeyException& ex )
	{
		std::cerr << ex.what();
	}
	catch ( const GameException& ex )
	{
		std::cerr << ex.what();
	}
	catch ( const std::exception& ex )
	{
		std::cerr << ex.what();
	}
	catch ( ... )
	{
		std::cout << "Unknown exception!\n";
	}

	
#if defined _DEBUG && !defined NDEBUG
	while ( !getchar() );
#endif
	return EXIT_SUCCESS;
}