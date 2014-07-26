#ifndef UTIL_ALGO_STRING_H_
#define UTIL_ALGO_STRING_H_

#include <string>

/**
 * <p><code>String</code> has some static methods on string that doesn't 
 * available in <code>std::string</code> class</p>
 *
 * <p><b>Requirements:</b>
 * <ul>
 *   <li>Standard ANSI C++, 32-bit compiler</li>
 * </ul>
 * </p>
 *
 * <p>Copyright &copy; 1997, Afrigis, Inc. All rights reserved.</p>
 * 
 * @author  Sowrov
 * @date    09-06-2009
 * @version 1.0.0
 */
class String{
public:

    /**
     * <p>Make a whole string to uppercase</p>
     *
     * @param str input string
     * @return Uppercase version of the input string
     */
    static std::string toUpperCase(std::string str){
        for(int i=0; i<str.length(); i++){
            str[i]=toupper(str[i]);
        }
        return str;
    }

    /**
     * <p>Make a whole string to lowercase</p>
     *
     * @param str input string
     * @return Lowercase version of the input string
     */
    static std::string toLowerCase(std::string str){
        for(int i=0; i<str.length(); i++){
            str[i]=tolower(str[i]);
        }
        return str;
    }
    
    /**
     * <p>
     * checks whether a character is in a string
     * </p>
     *
     * @param str string where to check
     * @param ch the character
     * @return boolean
     */
    static bool isInString(const std::string& str, char ch){
        if(str.find(ch)!=std::string::npos){
            return true;
        }
        return false;

        /*for(UInt32 i=0; i<str.length(); i++){
            if(str.at(i) == ch){
                return true;
            }
        }
        return false;*/
    }
};

#endif
