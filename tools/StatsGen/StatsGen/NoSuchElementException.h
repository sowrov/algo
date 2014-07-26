#ifndef UTIL_ALGO_NOSUCHELEMENTEXCEPTION_H_
#define UTIL_ALGO_NOSUCHELEMENTEXCEPTION_H_

#include <string>
#include <exception>

/**
 * <p>
 *  Thrown by the nextElement method of an Enumeration to indicate that there
 *  are no more elements in the enumeration. 
 * </p> 
 * <p><b>Requirements:</b>
 * <ul>
 *   <li>Standard ANSI C++, 32-bit compiler</li>
 * </ul>
 * </p>
 *
 * <p>Copyright &copy; 1997, Afrigis, Inc. All rights reserved.</p>
 * 
 * @author  Sowrov
 * @date    09-08-2009
 * @version 1.0.0
 */
class NoSuchElementException : public std::exception{
    //Exception Message
    const std::string msg;

public:
    
    /**
     * <p>
     * Default Constructor, set default message as "com::afrigis::util::NoSuchElementException"
     * </p>          
     */
    NoSuchElementException() : msg("NoSuchElementException"){}
    
    /**
     * <p>
     * Set Exception message
     * </p>
     *
     * @param str message to set     
     */
    NoSuchElementException(std::string str):
    msg(std::string("NoSuchElementException, ")+str){}
    
    ~NoSuchElementException() throw(){
        //Noting
    }
    
    //@override

    /**
     * <p>
     * Override method from std::exception class
     * </p>
     *
     * @return exception message char pointer
     */
    const char* what() throw(){
        return msg.c_str();
    }
};
#endif

