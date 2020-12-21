#pragma once
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int STACK_MAX_SIZE = 1000000;

template<class T>
class TStack {
private:
	T* array;
	int maxsize;
public:
	int size;
	TStack(int ms = 100); //конструктор с параметром
	TStack(const TStack& ts); //конструктор копирования
	~TStack(); //деструктор
	TStack& operator=(const TStack& ts); //присваивание
	void clear(); //очистить стек
	bool isFull(); //заполнен ли стек?
	bool isEmpty(); //пуст ли стек?
	T top(); //вершина стека
	T pop(); //удалить элемент из стека
	void push(const T& element); //добавить элемент в стек
	T operator[](int pos);
	bool operator!=(const TStack& s) const;
	bool operator==(const TStack& s) const;
};

template<class T>
TStack<T>::TStack(int ms) {
	if (ms <= 0 || ms > STACK_MAX_SIZE) throw ms;
	maxsize = ms;
	size = 0;
	array = new T[maxsize];
}

template<class T>
TStack<T>::TStack(const TStack<T>& ts) {
	maxsize = ts.maxsize;
	size = ts.size;
	array = new T[maxsize];
	for (int i = 0; i < size; i++) array[i] = ts.array[i];
}

template<class T>
TStack<T>::~TStack() {
	delete[] array;
}

template <class T>
TStack<T>& TStack<T>::operator=(const TStack& s) {
	maxsize = s.maxsize;
	size = s.size;
	if (array!=0) delete[] array;
	array = new T[maxsize];
	for (int i = 0; i < size; i++)
		array[i] = s.array[i];
	return *this;
}

template<class T>
bool TStack<T>::isFull() {
	return size == maxsize;
}

template<class T>
bool TStack<T>::isEmpty() {
	return size == 0;
}

template<class T>
T TStack<T>::top() {
	if (isEmpty()) throw - 1;
	return array[size - 1];
}

template<class T>
T TStack<T>::pop() {
	if (isEmpty()) throw - 1;
	size--;
	return array[size];
}

template<class T>
void TStack<T>::push(const T& element) {
	if (isFull())
	{
		maxsize *= 2.0;
		T* temp = new T[maxsize];
		memmove(temp, array, sizeof(array) * size);
		delete[] array;
		array = temp;
	}
	array[size] = element;
	size++;;
}

template<class T>
void TStack<T>::clear() {
	size = 0;
}

template <class T>
T TStack<T>::operator[](int pos) {
	if (pos < 0 || pos > maxsize) throw -1;
	return array[pos];
}

template <class T>
bool TStack<T>::operator!=(const TStack& s) const {
	return !(s == *this);
}

template <class T>
bool TStack<T>::operator==(const TStack& s) const {
	if ((size != s.size) || (maxsize != s.maxsize))	return false;
	for (int i = 0; i < maxsize; i++)
	{
		if (array[i] != s.array[i])	return false;
	}
	return true;
}

template <class T>
class TQueue : public TStack <T> {
protected:
	TStack<T> St_1, St_2;
	int start_index;
	public:
		TQueue(int s=7) {
			TStack <T> temp(s);
			St_1 = St_2 = temp;
			start_index = 0;
		}

		~TQueue() {}

		void pop() {
			if ((St_1.isEmpty()) && (St_2.isEmpty())) throw "Error!";
			if (St_2.isEmpty()) {
				while (!St_1.isEmpty()) {
					St_2.push(St_1.top()); //дублируем из вершины 1-го стека во 2-ой
					St_1.pop(); //и удаляем элемент, который дублировали 
				}
			}
			St_2.pop(); //удаляем элемент из 2-го стека
			size--;
		}

		void push(int n) {
			St_1.push(n);
			size++;
		}
		
		bool operator==(const TQueue& q) {
			if ((!q.St_1.isEmpty()) && (!St_1.isEmpty()))
				if (St_1 == q.St_1) return true;
			if ((!q.St_2.isEmpty()) && (!St_2.isEmpty()))
				if (St_2 == q.St_2) return true;
			return false;
		}

		bool operator!=(const TQueue& q) {
			if (q == *this) return false;
			return true;
		}

		T operator[](int pos) {
			if (pos >= size) throw - 1;
			if (St_2.isEmpty()) return St_1[pos];
			if (St_1.isEmpty()) return St_2[St_2.size - pos -1];
			else {
				if (pos < St_2.size) return St_2[St_2.size - pos - 1];
				else return St_1[pos - St_2.size];
			}
		}
};

class Translator {
private:
	string infix;
	string postfix;
	TStack<char> stc;
	TStack<double> std;
	int priority(char zn) {
		switch (zn) {
		case '(':
			return 0;
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		}
	}
	bool checkBrakets();// не используем
	bool checkInfix(); 
	bool isZnak(int);// не используем
public:
	string getInfix() { return infix; }
	string getPostfix() { return postfix; }
	void setInfix(string _infix) { infix = _infix; }
	bool GoToPostfix();
	double GoToCalculate();
};

bool Translator::checkBrakets() {
	int bracket = 0;
	for (int i = 0; i < infix.size(); i++) {
		if (infix[i] == '(') bracket++;
		else if (infix[i] == ')') bracket--;
	}
	if (bracket < 0) return false;
	else return true;
}

bool Translator::checkInfix() {
	int status = 0;
	int braket = 0;
	int point = 0;
	for (int i = 0; i < infix.size(); i++) 
	{
		switch (status) {  // status - переменная состояния
		case 0:
			if (infix[i] == '\0') status = 2;
			if (infix[0] == '-')status = 3;
			if (infix[i] == '(') 
			{
				braket++;
				status = 0;
			}
			if ((infix[i] < '0' || infix[i] > '9') && infix[i] != '(' && infix[i] != '\0') status = 3;
			if (infix[i] >= '0' && infix[i] <= '9' || (infix[i + 1] == '.'))
			{
				{
					status = 1;
					int dt = 0;
					while (((infix[i + 1] >= '0') && (infix[i + 1] <= '9')) || (infix[i + 1] == '.'))
					{
						i++;
						if (infix[i] == '.')
						{
							dt++;
							if (infix[i + 1] == '.') dt++;
						}
					}
					if ((dt > 1) || (infix[i] == '.')) status = 3;
				}
			}
			break;
		case 1:
			if (infix[i] == '\0') status = 2;
			if (infix[i] == ')') {
				braket--;
				if (braket >= 0) status = 1;
				if (braket < 0) status = 3;
			}
			if (isZnak(i)) status = 0;
			if ((!isZnak(i)) && infix[i] != ')' && infix[i] != '\0') status = 3;
			break;
		case 2:
			if (braket == 0) status = 4;
			if (braket != 0) status = 3;
			break;
		case 3:
			return false;
			break;
		case 4:
			return true;
			break;
		}
	}
}

bool Translator::isZnak(int i) {
	if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') return true;
	else return false;
}

bool Translator::GoToPostfix() {
	postfix = "";
	stc.clear();
	stc.push(0);
	string tmp = "(" + infix + ")";
	if (!checkInfix()) return false;
	for (int i = 0; i < tmp.size(); i++) {
		if (tmp[i] >= '0' && tmp[i] <= '9' || tmp[i] == '.') postfix += tmp[i];
		else if (tmp[i] == '(') stc.push('(');
		else if (tmp[i] == '-' && tmp[i - 1] == '(') { postfix += tmp[i];  continue; }
		else if (tmp[i] == ')') {
			while (stc.top() != '(' && stc.top() ) {
				postfix += " ";
				postfix += stc.pop();

			}
			if (stc.top() == '(')
				stc.pop();
			else {
				postfix += " ";
				postfix += stc.pop();
			}
		}
		else if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/') {
			postfix += " ";
			while (priority(stc.top()) >= priority(tmp[i]))
				postfix += stc.pop();

			stc.push(tmp[i]);
			postfix += " ";
		}
	}
	postfix += " ";
	return true;
}
double Translator::GoToCalculate() {
	std.clear();
	double Result = 0;
	string tmp = "";
	for (int i = 0; i < postfix.size(); i++) {
		if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.' || (postfix[i] == '-' && postfix[i + 1] != ' ')) {
			tmp += postfix[i];
		}
		if (postfix[i] == ' ' && tmp.size()) {
			std.push(atof(tmp.c_str()));
			tmp = "";
		}

		if (postfix[i] == '+' || (postfix[i] == '-' && postfix[i + 1] == ' ') || postfix[i] == '*' || postfix[i] == '/' ) {
			switch (postfix[i]) {
			case '+':
				Result = std.pop() + std.pop();
				break;
			case '-':
				Result = -std.pop() + std.pop();
				break;
			case '*':
				Result = std.pop() * std.pop();
				break;
			case '/':
				double znam;
				znam = std.pop();
				if (znam == 0.0) {
					std::cout << "ERROR!" << std::endl;
					Result = -404;
				}
				else Result = (1 / znam) * std.pop(); 
				break;
			}

			std.push(Result);
		}
	}
	return std.pop();
}
