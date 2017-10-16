#ifndef FLOODEXCEPTION_H
#define FLOODEXCEPTION_H

#include <iostream>
#include <sstream>
#include <exception>

namespace oli{

/*!
 * \brief The FloodException class
 * This is the exception class used for the game .
 */
class FloodException : public std::exception{
private:
    std::string msg;

public:
    FloodException( const char * Msg){
        std::ostringstream output;
        output << Msg;
        this->msg = output.str();
    }

    virtual ~FloodException() throw(){}

    const char * what() const throw(){
        return msg.c_str();
    }
};

}

#endif // FLOODEXCEPTION_H
