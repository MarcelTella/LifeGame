
#ifndef IIE
#define IIE

#include <GeneralException.hpp>

class IncorrectInitialStateException : public GeneralException
{
	private:
		std::string err_msg;
	public:
		IncorrectInitialStateException(const char *msg) : err_msg(msg) {};
		IncorrectInitialStateException() {};
		~IncorrectInitialStateException() throw() {};
		const char *what() const throw() { return this->err_msg.c_str(); };
};

#endif
