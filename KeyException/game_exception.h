#pragma once

#include "key_exception.h"


class GameException final
	: public KeyException
{
public:
	GameException( int line, const char* file, const char* function,
		const std::string& msg ) noexcept;

	const std::string getType() const noexcept override;
	virtual const char* what() const noexcept override;
};


#define throwGameException( msg ) throw GameException( __LINE__,\
	__FILE__,\
	__FUNCTION__,\
	msg );