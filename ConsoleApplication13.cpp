#include <iostream>
#include<cstring>

//Конструктор перемещения + метод pushback
using namespace std;



class Array {
	int* arr;
	int size;
	int capacity;
public:
	Array(int capacity) :arr(new int[capacity]), size(0), capacity(capacity) {
		cout << "Конструктор с параметром " << this << endl;
	}
	
	
	//конструктор по умолчанию
	Array() :Array(5) {}



	//Конструктор копирования  //arr(array.arr)
	Array(const Array& array) :arr(new int[array.capacity]), size(array.size), capacity(array.capacity) {
		for (int i = 0; i < size; i++)
		{
			arr[i] = array.arr[i];
		}
		cout << "Конструктор копирования " << this << endl;
	}
	~Array() {
		cout << "Деструктор " << arr << endl;

		delete[] arr;
	}

	void randomize() {

		size = capacity;

		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 100;
		}
	}
	void print() {
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	Array& operator=(const Array& array) {
		if (this != &array) {
			if (capacity != array.capacity) {
				resize(array.capacity);
			}
			for (int i = 0; i < size; i++)
			{
				this->arr[i] = array.arr[i];
			}
		}
		return *this;
	}

	void pushback(int value) // добавляет один элемент с любым значением в конец массива
	{
		if (size == capacity)
		{
			resize(capacity == 0 ? 1 : capacity * 2); //если capacity равно нулю, то передаем capacity единичку, в любом другом случае capacity умножаем на 2
		}
		arr[size++] = value;
	}
private:
	void resize(int newCapacity)
	{
		int* newArr = new int[newCapacity];

		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
	
		arr = newArr;
		capacity=newCapacity;
	}



};

Array arrayFactory(int arrSize) // функция создающая массив на заданное количество элементов

{
	//создаем новый массив с размером arrSize (для старого стандарта)
	Array arr(arrSize);
	arr.randomize();
	return arr;
}

int main() {
	setlocale(LC_ALL, "ru");

	Array array1(10);

	Array array2 = arrayFactory(10); //вызываем функцию arrayFactory, и создаем массив на 10 элементов, которые хранятся в объекте array2;
	
	int x = 42;
	int& refX = x;
	cout << refX<< endl;

	const int& cRef = x;
	const int& cRefX = x + 24;
	cout << cRefX << endl;

	int&& cRefX = x+24; //благодаря двум аперсантам можно создать неконстантную ссылку на временные переменные (rvalue ссылка)

	//array1.pushback(10);
	//array1.pushback(10);
	//array1.pushback(10);
	//array1.randomize();
	//array1.print();


}
