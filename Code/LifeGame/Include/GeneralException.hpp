#ifndef GE
#define GE

#include <exception>

class GeneralException : public std::exception
{
	private:
		std::string err_msg;
	public:
		//GeneralException(const char *msg) : err_msg(msg) {};
		GeneralException(){};
	    ~GeneralException() throw() {};
	    const char *what() const throw() { return this->err_msg.c_str(); };
}; 

#endif
