#pragma once

#include <memory>
#include "token.hpp"
#include "exception.hpp"

class AstNode
{
public:
    virtual int eval() const = 0;
    virtual ~AstNode() = default;
};

class Integer : public AstNode
{
private:
    int value;

public:
    Integer(int value) : value(value) {}
    int eval() const override
    {
        return this->value;
    }
};

class BinaryOperation : public AstNode
{
private:
    std::shared_ptr<AstNode> left, right;
    Token::Type operation = Token::Type::NONE;

public:
    int eval() const override
    {
        int left = this->left ? this->left->eval() : 0;
        int right = this->right ? this->right->eval() : 0;
        if (this->operation == Token::Type::ADD)
            return left + right;
        else if (operation == Token::Type::SUBTRACT)
            return left - right;
        else if (this->operation == Token::Type::MULTIPLY)
            return left * right;
        else if (this->operation == Token::Type::DIVIDE)
            return left / right;
        else if (operation == Token::Type::POWER)
            return std::pow(left, right);
        else
            throw Exception{"operation not defined"};
    }

    std::shared_ptr<AstNode> getRightChild()
    {
        return this->right;
    }

    std::shared_ptr<AstNode> getLeftChild()
    {
        return this->left;
    }

    Token::Type getOperation()
    {
        return this->operation;
    }

    void setRightChild(std::shared_ptr<AstNode> child)
    {
        this->right = child;
    }

    void setLeftChild(std::shared_ptr<AstNode> child)
    {
        this->left = child;
    }

    void setOperation(Token::Type op)
    {
        this->operation = op;
    }
};