#include<iostream>
using namespace std;

template<class T>
class MySharedPtr
{
	T* _ptr;
	int* counter;

public:

	MySharedPtr()
	{
		_ptr = nullptr;
		counter = new int(1);
	}

	MySharedPtr(T* ptr)
	{
		_ptr = ptr;
		counter = new int(1);
	}

	MySharedPtr(const MySharedPtr& other)
	{
		this->_ptr = other._ptr;
		this->counter = other.counter;
		(*counter)++;
	}

	MySharedPtr& operator=(const MySharedPtr& other)
	{
		if (this->_ptr != nullptr)
		{
			delete this->_ptr;
			_ptr = nullptr;
		}

		_ptr = other._ptr;
		(*counter)++;
	}

	void reset()
	{
		(*counter)--;
		if (*counter == 0)
		{
			if (this->_ptr != nullptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		else
		{
			_ptr = nullptr;
		}
	}

	T* get()
	{
		return _ptr;
	}

	int count()
	{
		return *counter;
	}

	T& operator*()
	{
		return *_ptr;
	}

	bool unique() const
	{
		if (*counter == 1)
			return true;
		return false;
	}

	~MySharedPtr()
	{
		if (*counter == 1)
		{
			if (_ptr != nullptr)
			{
				delete _ptr;
				delete counter;
				_ptr = nullptr;
			}
		}
	}


};


int main()
{
	MySharedPtr<int>ptr(new int(15));
	MySharedPtr<int>ptr_2(ptr);
	MySharedPtr<int>ptr_3(ptr);

	//cout << (*ptr) << endl;
	//cout << (*ptr_2);


	//cout << ptr_2.count() << endl;

	//cout << *ptr << endl;
	//cout << ptr.unique();

	cout << ptr.count();
	//ptr.reset();
	//ptr.reset();
	//ptr.reset();

	MySharedPtr<int>ptr11(new int(15));
	MySharedPtr<int>ptr_22(ptr11);
	MySharedPtr<int>ptr_33(ptr11);

	cout << ptr.count();

}