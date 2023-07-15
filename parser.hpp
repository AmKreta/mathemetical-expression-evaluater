#pragma once

#include<memory>
#include "token.hpp"
#include "ast.hpp"

class Parser
{
private:
    std::vector<Token> tokens;

public:
    Parser(std::vector<Token> &tokens) : tokens(tokens) {}

    std::shared_ptr<BinaryOperation> parse()
    {
        auto res = std::make_shared<BinaryOperation>();
        Token::Type operation = Token::Type::NONE;
        int i = 0;
        while (i < this->tokens.size())
        {
            auto currentToken = this->tokens.at(i);
            auto currentTokenType = currentToken.getTokenType();
            auto currentTokenValue = currentToken.getTokenValue();

            if (currentTokenType == Token::Type::INTEGER)
            {
               auto integer = std::make_shared<Integer>(std::stoi(currentTokenValue));
               res->getLeftChild()
                    ?res->setRightChild(integer)
                    :res->setLeftChild(integer);
            }
            else if(
                currentTokenType == Token::Type::ADD || 
                currentTokenType == Token::Type::SUBTRACT || 
                currentTokenType == Token::Type::MULTIPLY || 
                currentTokenType == Token::Type::DIVIDE || 
                currentTokenType == Token::Type::POWER
            ){
                if(res->getOperation()!=Token::Type::NONE){
                    auto astParent = std::make_shared<BinaryOperation>();
                    astParent->setLeftChild(res);
                    res = astParent;
                }    
                res->setOperation(currentTokenType);
            }
            i++;
        }
        return res;
    }
};