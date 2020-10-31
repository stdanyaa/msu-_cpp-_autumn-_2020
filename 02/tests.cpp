#include "TokenParser.h"

void DefaultTest(){
    TokenParser tparser;
    std::string text("0 3453 dsadh443 dfs32\n\tds");
    tparser.Parse(text);
}

void SetCallbacksTest(){
    TokenParser tparser;
    digittokencallback_t PrintDigitCount = [](uint64_t digit) {
        static int n = 0; 
        std::cout<<"digit count:\t"<<++n<<std::endl;
    }; 
    stringtokencallback_t PrintStringCount = [](std::string& token){
        static int n = 0;
        std::cout<<"string count:\t"<<++n<<std::endl;
    };
    callback_t PrintNameTest = [](){
        std::cout<<"SetCallbacksTest"<<std::endl;
    };
    tparser.SetStartCallback(PrintNameTest);
    tparser.SetEndCallback(PrintNameTest);
    tparser.SetDigitTokenCallback(PrintDigitCount);
    tparser.SetStringTokenCallback(PrintStringCount);
    std::string text("1 1 2 23 a b c deee 4 fg");
    tparser.Parse(text);
}

void NoTokensTest(){
    callback_t PrintNameTest = [](){
        std::cout<<"NoTokensTest\nEnd Callback"<<std::endl;
    };
    TokenParser tparser;
    tparser.SetEndCallback(PrintNameTest);
    std::string text(" \n\t\t  ");
    tparser.Parse(text);
}


void DoubleUseTest(){
    TokenParser tparser;
    std::string text("a$#@1ds 21аоап 12230 ()/ 1337");
    callback_t PrintNameTest = [](){
        std::cout<<"\nDoubleParseTest - First parse"<<std::endl;
    };
    tparser.SetStartCallback(PrintNameTest);
    tparser.Parse(text);
    text = "... ,,, -111 23456";
    PrintNameTest = [](){
        std::cout<<"DoubleParseTest - Second parse"<<std::endl;
    };
    tparser.SetStartCallback(PrintNameTest);
    tparser.Parse(text);
}

int main(){
    DefaultTest();
    SetCallbacksTest();
    NoTokensTest();
    DoubleUseTest();
}