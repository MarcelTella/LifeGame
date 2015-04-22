
#ifndef IIE
#define IIE

#include <GeneralException.hpp>

class IncorrectInitialEstimateException : public GeneralException
{
	private:
		std::string err_msg;
	public:
		IncorrectInitialEstimateException() {};
		~IncorrectInitialEstimateException() throw() {};
		const char *what() const throw() { return this->err_msg.c_str(); };
};

#endif
