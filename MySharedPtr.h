#pragma once


template <typename T>
class MySharedPtr
{
	T* _ptr;
	int* _counter;  //
public:
	MySharedPtr(T* ptr = nullptr);
	MySharedPtr(const MySharedPtr& other);

	int getCounter();
	T& operator*();
	MySharedPtr& operator=(const MySharedPtr& obj);

	~MySharedPtr();
};

//template<typename T>
//int MySharedPtr<T>::_counter = 0;

template<typename T>
inline MySharedPtr<T>::MySharedPtr(T* ptr) : _ptr(ptr), _counter(new int(1))
{
}

template<typename T>
inline MySharedPtr<T>::MySharedPtr(const MySharedPtr& obj)
{
	_ptr = obj._ptr;
	_counter = obj._counter;
	(*_counter)++;

}

template<typename T>
inline int MySharedPtr<T>::getCounter()
{
	return *_counter;
}

template<typename T>
inline T& MySharedPtr<T>::operator*()
{
	return *_ptr;
}

template<typename T>
inline MySharedPtr<T>& MySharedPtr<T>::operator=(const MySharedPtr<T>& obj)
{
	if (this != &obj)
	{
		(*_counter)--;
		if (*_counter == 0) // ?????
		{
			delete _ptr;
			delete _counter;
		}
		_ptr = obj._ptr;
		_counter = obj._counter;
		(*_counter)++;
	}
	return *this;
}


template<typename T>
inline MySharedPtr<T>::~MySharedPtr()
{
	(*_counter)--;
	if (*_counter == 0)
	{
		delete _ptr;
		delete _counter;
	}
}
