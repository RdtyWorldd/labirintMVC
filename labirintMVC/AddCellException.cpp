#include "AddCellException.h"

AddCellException::AddCellException() :exception() {
	message = "illeagal add cells";
}
AddCellException::AddCellException(const char* const& _message) : message(_message) {}
AddCellException::AddCellException(const AddCellException& exception)noexcept {
	message = exception.message;
}

const char* AddCellException::what() const noexcept {
	return message.c_str();
}