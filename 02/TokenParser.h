#pragma once

#include <iostream>
#include <ctype.h>
#include <string>
#include <functional>

using callback_t = std::function<void()>;
using digittokencallback_t = std::function<void(uint64_t)>;
using stringtokencallback_t = std::function<void(std::string&)>;
class TokenParser
{
private:
    //Callback functions
    callback_t EndCallback, StartCallback; 
    digittokencallback_t DigitTokenCallback;
    stringtokencallback_t StringTokenCallback;
    
    //Working with text
    std::string GetToken(std::string::const_iterator&, std::string::const_iterator&);
    bool IsDigit(const std::string& token);
    uint64_t ToDigit(std::string token);


public:
    //Constructor
    TokenParser();
    //Callback functions setting
    void SetStartCallback(callback_t func);
    void SetEndCallback(callback_t func);
    void SetStringTokenCallback(stringtokencallback_t func);
    void SetDigitTokenCallback(digittokencallback_t func);

    //Main operation
    void Parse(const std::string &text);
};

