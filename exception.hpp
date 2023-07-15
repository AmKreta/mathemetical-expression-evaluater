#pragma once

#include <exception>
#include <string>

class Exception : public std::exception
{
private:
    std::string err;

public:
    Exception(std::string err):err(err){}
    
    const char *what() const noexcept override
    {
        return this->err.c_str();
    }
};