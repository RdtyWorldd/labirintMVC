#include "ExitException.h"

ExitException::ExitException(int _nextRoom) :exception(), nextRoom(_nextRoom) {
	message = "nextRoom is" + nextRoom;
}
ExitException::ExitException(const char* const& _message, int _nextRoom) :nextRoom(_nextRoom), message(_message) {}
ExitException::ExitException(const ExitException& exception) noexcept {
	message = exception.message;
	nextRoom = exception.nextRoom;
}
ExitException& ExitException::operator=(const ExitException& exception) noexcept {
	if (this == &exception) {
		return *this;
	}
	message = exception.message;
	nextRoom = exception.nextRoom;
	return *this;
}

const char* ExitException::what() const noexcept {
	return message.c_str();
}

int ExitException::getNextRoom() {
	return nextRoom;
}