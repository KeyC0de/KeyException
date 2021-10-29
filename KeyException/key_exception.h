#pragma once

#include <string>
#include <stdexcept>


//=============================================================
// \class	KeyException
//
// \author	KeyC0de
// \date	2019/09/11 19:38
//
// \brief	Custom exception class - Rule of 0
//			child/specific exception classes are nested in other classes
//=============================================================
class KeyException
	: public std::exception
{
public:
	KeyException( int line, const char* file, const char* function,
		const std::string& msg ) noexcept;
	virtual ~KeyException() noexcept = default;

	virtual const char* what() const noexcept override;
	//===================================================
	// \brief returns the type of the exception - name of child exception class
	// \date 2019/09/11 20:18
	virtual const std::string getType() const noexcept;
	inline const unsigned getLine() const noexcept;
	inline const std::string getFile() const noexcept;
	inline const std::string getFunction() const noexcept;
private:
	int m_line;
	std::string m_file;
	std::string m_function;
protected:
	mutable std::string m_description;
};

#define throwKeyException( msg ) throw KeyException( __LINE__,\
	__FILE__,\
	__FUNCTION__,\
	msg );