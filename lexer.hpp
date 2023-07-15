#pragma once

#include <sstream>
#include <string>
#include <vector>
#include "token.hpp"

class Lexer
{
private:
    std::string input;
    int currentPosition = 0;

public:
    Lexer(std::string input) : input(input) {}

    std::vector<Token> lex()
    {
        std::vector<Token> result;

        while (this->currentPosition < this->input.size())
        {
            auto ch = this->input[this->currentPosition];

            if (ch == '+')
            {
                result.push_back({Token::Type::ADD, "+"});
                this->currentPosition++;
            }

            else if (isdigit(ch))
            {
                std::ostringstream oss;
                oss << ch;
                this->currentPosition++;
                while (isdigit(this->input[this->currentPosition]))
                    oss << this->input[this->currentPosition++];
                result.push_back({Token::Type::INTEGER, oss.str()});
            }
        }

        return result;
    }
};