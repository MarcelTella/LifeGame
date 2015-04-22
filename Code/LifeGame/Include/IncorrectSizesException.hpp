
#ifndef ISE
#define ISE

#include "GeneralException.hpp"

class IncorrectSizesException : GeneralException
{
	private:
		std::string err_msg;
	public:
		IncorrectSizesException() {};
		~IncorrectSizesException() throw() {};
		const char *what() const throw() { return this->err_msg.c_str(); };
};

#endif
