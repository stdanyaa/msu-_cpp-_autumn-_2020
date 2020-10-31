#include "TokenParser.h"
#include <cassert>

void DefaultTest(){
    TokenParser tparser;
    std::string text("0 3453 dsadh443 dfs32\n\tds");
    tparser.Parse(text);
    //no tokens
    text = " \n\t\t  ";
    tparser.Parse(text);
}

void SetCallbacksTest(){
    int *dig_n = new int;
    int *str_n = new int;
    *dig_n = *str_n = 0;
    TokenParser tparser;
    digittokencallback_t PrintDigitCount = [dig_n](uint64_t digit) {
        *dig_n += 1;
    }; 
    stringtokencallback_t PrintStringCount = [str_n](std::string& token){
        *str_n += 1;
    };
    tparser.SetDigitTokenCallback(PrintDigitCount);
    tparser.SetStringTokenCallback(PrintStringCount);
    std::string text("1 1 2 23 a b c deee 4 fg");
    tparser.Parse(text);

    assert((*dig_n == 5)&&(*str_n == 5));
    
    delete dig_n;
    delete str_n;
}

void MultipleUseTest(){
    TokenParser tparser;
    int *parse_n = new int;
    *parse_n = 0;
    std::string text("a$#@1ds 21аоап 12230 ()/ 1337");
    callback_t ParseCallCount = [parse_n](){
        *parse_n += 1;
    };
    tparser.SetStartCallback(ParseCallCount);
    tparser.Parse(text);
    text = "... ,,, -111 23456";
    tparser.Parse(text);
    tparser.Parse("");
    assert(*parse_n == 3);

    delete parse_n;
}

int main(){
    DefaultTest();
    SetCallbacksTest();
    MultipleUseTest();
}