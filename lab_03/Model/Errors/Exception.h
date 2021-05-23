//
// Created by Екатерина on 21.05.2021.
//

#ifndef LAB_03_EXCEPTION_H
#define LAB_03_EXCEPTION_H


#include <exception>
#include <string>
#include <string.h>
class BaseException : public std::exception //base_matrix nam
{
public:
    BaseException(const char* file, int line, const char* time, const char* msg);

    virtual ~BaseException();

    virtual const char * what() const noexcept override;

protected:
    char * err_str;
};

class Load_Exception : public BaseException
{
public:
    Load_Exception(const char* file, int line, const char* time, const char* msg);

    virtual const char *what() const noexcept override;

    virtual ~Load_Exception();

};

class IdException : public BaseException
{
public:
    IdException(const char* file, int line, const char* time, const char* msg);

    virtual const char *what() const noexcept override;

    virtual ~IdException();

};


#endif //LAB_03_EXCEPTION_H
