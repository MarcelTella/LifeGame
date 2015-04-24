
#ifndef NFFEX
#define NFFEX

#include <GeneralException.hpp>

class NoFileFoundException : public GeneralException
{
	private:
		std::string err_msg;
	public:
		NoFileFoundException(const char *msg) : err_msg(msg) {}
		NoFileFoundException() {}
		~NoFileFoundException() throw() {}
		const char *what() const throw() { return this->err_msg.c_str(); }
};

#endif
