#include<iostream>
#include"lexer.hpp"


int main(){

    Lexer lexer{"23+2"};

    auto tokens = lexer.lex();

    for(auto token : tokens)
        std::cout<<token;

    return 0;
}