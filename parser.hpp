#pragma once

#include "token.hpp"

class Parser{
    private:
        std::vector<Token> tokens;

    public:
        Parser(std::vector<Token>& tokens):tokens(tokens){}

        int parse(){
            int res =0;
            Token::Type operation = Token::Type::NONE;
            int i=0;
            while(i<this->tokens.size()){
                auto currentToken = this->tokens.at(i);
                auto currentTokenType = currentToken.getTokenType();
                auto currentTokenValue = currentToken.getTokenValue();

                if(currentTokenType==Token::Type::ADD)
                    operation = currentTokenType;
                else if(currentTokenType == Token::Type::INTEGER){
                    int val =std::stoi(currentTokenValue);
                    if(operation == Token::Type::NONE)
                        res = val;
                    else if(operation == Token::Type::ADD)
                        res+=val;    
                }    
                i++;
            }
            return res;
        }    
};