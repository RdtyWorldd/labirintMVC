#pragma once
#include <string>
#include <exception>

using namespace std;

class ExitException : public exception {
    int nextRoom;
    string message;
public:
    ExitException(int _nextRoom);
    ExitException(const char* const& message, int nextRoom);

    ExitException(const ExitException&) noexcept;
    ExitException& operator=(const ExitException&) noexcept;

    virtual const char* what() const noexcept; // возвращает сообщение об исключении
    int getNextRoom();
};