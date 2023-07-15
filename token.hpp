#pragma once

#include <iostream>
#include <string>
#include <vector>

class Token
{
public:
    enum class Type : int
    {
        INTEGER,
        ADD, 
        NONE // null value
    };

    static std::vector<std::string> TypeStr;

    Token(Token::Type type, std::string value):type(type), value(value){}

    Token::Type getTokenType()
    {
        return this->type;
    }

    std::string getTokenValue()
    {
        return this->value;
    }

    std::string getTokenTypeStr()
    {
        return Token::TypeStr[(int)this->type];
    }

    friend std::ostream &operator<<(std::ostream &os, Token &token)
    {
        os << "Token Type -> " << token.getTokenTypeStr() << ", Token Value -> " << token.value << std::endl;
        return os;
    }

private:
    Token::Type type;
    std::string value;
};

std::vector<std::string> Token::TypeStr = {"Integer", "Add","None"};