#include <iostream>


using namespace std;

class Exception {
protected:
	string text;
	string sourse;
	int line;
public:
	Exception(string text, string sourse, int line) : text(text), sourse(sourse), line(line) {}

	const string& getMessage()const {
		return  text;
	}
	void printMessage()const {

		cout << " ***************** Error Info ***************** " << endl;
		cout << " Error text: " << getMessage() << endl;
		cout << " Error sourse: " << sourse << endl;
		cout << " Error line: " << line << endl;
		cout << " ********************************************** " << endl;



	}
};

class OutofRangeException :public Exception {
public:
	OutofRangeException(string text, string sourse, int line) : Exception(text, sourse, line) {}
};

class InvalidArgumentException :public Exception {
public:
	InvalidArgumentException(string text, string sourse, int line) : Exception(text, sourse, line) {}
};

template<typename T>
class Array {
private:
	T* data;
	int size;
public:
	void show() noexcept { // exseption atmasin

	}
	int getsize()const {
		return size;
	}
	const T& getData()const {
		return data;
	}

	Array <T>& operator=(const Array<T>& other) = delete;
	Array(const Array<T>& other) = delete;

	T& operator[](int index) throw (OutofRangeException) {
		if (index < 0 || index >= size) {
			throw OutofRangeException("Out of Range Exception ", " Source.cpp ", 55);
		}
		return data[index];
	}

	Array(int size)throw (InvalidArgumentException)
	{
		if (size < 0 || size>1000) {
			throw InvalidArgumentException(" Invalid Argument Exception ", " Source.cpp ", 63);
		}
		this->size = size;
		data = new T[size]{};
	}

	~Array()
	{
		delete[]data;
	}
};





void main() {
	try
	{

		Array<int>obj(-10);
		cout << obj[-10] << endl;

	}
	catch (const OutofRangeException& ex)
	{
		ex.printMessage();
	}
	catch (const InvalidArgumentException& ex)
	{
		ex.printMessage();
	}

	cout << "\n ============================================== \n\n";

	try
	{

		Array<int>obj2(10);
		cout << obj2[-10] << endl;

	}
	catch (const OutofRangeException& ex)
	{
		ex.printMessage();
	}
	catch (const InvalidArgumentException& ex)
	{
		ex.printMessage();
	}



}