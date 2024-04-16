#pragma once

template<class T> class IObserver {
public:
	virtual void event(T& model) = 0;
};