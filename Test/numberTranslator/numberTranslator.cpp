/*Given any integer, print an English 
phrase that describes the integer 
(e.g., "One Thousand, Two Hundred Thirty Four")*/

#include <iostream>
#include <assert.h>

#include <stack>
#include <string>

using namespace std;

template <typename T>
class Translator{
public:
	Translator(T n){
		cout << n << endl;
		number = n;
		cout << number << endl;

		myStack = new stack<T>();
		myString = new string();
	}

	void process(){
		T tempNumber = number;

		if (tempNumber == 0)
		{
			cout << "zero" << endl;
			return;
		}

		while(tempNumber > 0){
			// cout << tempNumber%1000 << endl;
			myStack->push(tempNumber%1000);
			tempNumber /= 1000;
		}

		while(!myStack->empty()){
			// cout << myStack->top() << endl;
			processThreeDigits(myStack->top());
			if(myStack->top()) outerName(myStack->size());
			myStack->pop();
		}
	}

	void processThreeDigits(int digits){
		int first = 0, second = 0, third = 0;

		// cout << digits << endl;
		third = digits % 10;
		digits /= 10;
		second = digits % 10;
		digits /= 10;
		assert(digits < 10);
		first = digits % 10;

		// cout << first << second << third << endl;

		if (first != 0)
		{
			insideName(first);
			cout << " hundred ";
		}

		if (second != 0 && second != 1)
		{
			switch(second){
				case 2: cout << "twenty "; break;
				case 3: cout << "thirty "; break;
				case 4: cout << "fourty "; break;
				case 5: cout << "fifty "; break;
				case 6: cout << "sixty "; break;
				case 7: cout << "seventy "; break;
				case 8: cout << "eighty "; break;
				case 9: cout << "ninety "; break;
				default: assert(false);
			}

			insideName(third);
		} else if(second == 1){
			switch(third){
				case 0: cout << "ten "; break;
				case 1: cout << "eleven "; break;
				case 2: cout << "twelve "; break;
				case 3: cout << "thirteen "; break;
				case 4: cout << "fourteen "; break;
				case 5: cout << "fifteen "; break;
				case 6: cout << "sixteen "; break;
				case 7: cout << "seventeen "; break;
				case 8: cout << "eighteen "; break;
				case 9: cout << "nineteen "; break;
				default: assert(false);
			}
		} else if(second == 0){
			insideName(third);
		} else {
			assert(false);
		}

		/*if (first == 0 && second == 0 && third == 0)
		{
			cout << "zero ";
		}*/

		cout << endl;
	}

	void outerName(int size){
		switch(size){
			case 1: break;
			case 2:	cout << "thousand" << endl; break;
			case 3: cout << "million" << endl; break;
			case 4: cout << "billion" << endl; break;
			// case 5: cout << "thousand" << endl; break;
			default: assert(false);
		}
	}

	void insideName(int digit){
		switch(digit){
			case 1: cout << "one "; break;
			case 2: cout << "two "; break;
			case 3: cout << "three "; break;
			case 4: cout << "four "; break;
			case 5: cout << "five "; break;
			case 6: cout << "six "; break;
			case 7: cout << "seven "; break;
			case 8: cout << "eight "; break;
			case 9: cout << "nine "; break;
			default: break;			
		}

	}

private:
	T number;
	stack<T> *myStack;
	string *myString;

};

int main(int argc, char *argv[]){
	// Translator<int> *myTranslator = new Translator<int>(123456789);
	Translator<int> myTranslator(32310); //check 0032310!!!

	myTranslator.process();

	return 0;
}