#include<iostream>
#include"lexer.hpp"
#include"parser.hpp"

int main(){

    Lexer lexer{"23+27+50"};

    auto tokens = lexer.lex();

    for(auto token : tokens)
        std::cout<<token;

    Parser parser{tokens};
    auto res=parser.parse();

    std::cout<<"result is -> "<<res<<std::endl;
    return 0;
}