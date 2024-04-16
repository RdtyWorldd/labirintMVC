#pragma once

#include <exception>
#include <string>

using namespace std;

class AddCellException : public exception {
    string message;
public:
    AddCellException();
    AddCellException(const char* const& _message);

    AddCellException(const AddCellException&) noexcept;
    AddCellException& operator=(const AddCellException&) noexcept;

    virtual const char* what() const noexcept; // возвращает сообщение об исключении
};