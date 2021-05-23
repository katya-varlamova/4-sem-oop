//
// Created by Екатерина on 21.05.2021.
//

#include "Exception.h"
BaseException::BaseException(const char* file, int line, const char* time, const char* msg)
{
    this->err_str = (char *)malloc(strlen(file) + strlen(time) + strlen(msg) + 40);
    sprintf(this->err_str, "file: %s, line: %-3d, time: %s, error: %s", file, line, time, msg);
}
BaseException::~BaseException()
{
    delete[] err_str;
}
const char * BaseException::what() const noexcept
{
    return this->err_str;
}

Load_Exception::Load_Exception(const char* file, int line, const char* time, const char* msg) :
        BaseException(file, line, time, msg)
{
}
Load_Exception::~Load_Exception()
{
    delete[] err_str;
}
const char * Load_Exception::what() const noexcept
{
    return this->err_str;
}

IdException::IdException(const char* file, int line, const char* time, const char* msg) :
        BaseException(file, line, time, msg)
{
}
IdException::~IdException()
{
    delete[] err_str;
}
const char * IdException::what() const noexcept
{
    return this->err_str;
}