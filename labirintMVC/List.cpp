#include "List.h"



template<class T>
List<T>::List<T>() : arr(nullptr), size(0) {}

template<class T>
List<T>::List<T>(const List<T>& list)
{
	if (list.arr == nullptr) {
		arr = nullptr;
		size = 0;
		return;
	}

	arr = new T[list.size];
	size = list.size;
	for (int i = 0; i < size; i++) {
		// подумать над нормальным копированием
		arr[i] = list.arr[i];
	}
}

template<class T>
List<T>& List<T>::operator=(const List<T>& list)
{
	
}

template<class T>
List<T>::~List<T>()
{
	delete[] arr;
}

