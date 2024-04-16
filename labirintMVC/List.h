#pragma once

template<class T>
class List {
	T* arr;
	int size;
public:
	List<T>();
	List<T>(const List<T>& list);
	List<T>& operator =(const List<T>& list);
	~List<T>();
	void add(T object);
	void add(int index, T object);
	void remove(int index);
};