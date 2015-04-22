
#ifndef NFFEX
#define NFFEX

#include <GeneralException.hpp>

class NoFileFoundException : public GeneralException
{
	private:
		std::string err_msg;
	public:
		//NoFileFoundException();
		//NoFileFoundException(const char *msg);
		NoFileFoundException();
		~NoFileFoundException() throw() {}
		const char *what() const throw() { return this->err_msg.c_str(); }
};

NoFileFoundException::NoFileFoundException()
{

}

#endif