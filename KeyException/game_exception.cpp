#include "game_exception.h"


GameException::GameException( int line,
	const char* file,
	const char* function,
	const std::string& msg ) noexcept
	:
	KeyException{line, file, function, msg}
{

}

const std::string GameException::getType() const noexcept
{
	return typeid( this ).name();
}

const char* GameException::what() const noexcept
{
	return KeyException::what();
}