//Implement Queue using two stacks
#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class CQueue{
public:
  CQueue() {
    myStack1 = new stack<T>();
    myStack2 = new stack<T>();
  }

  ~CQueue() {
    delete myStack1;
    delete myStack2;
  }

  void appendTail(const T& node){
    myStack1->push(node);
  }

  void deleteHead(){
    if(myStack2->empty() && myStack1->empty()) return;

    if(myStack2->empty()){
      while(!myStack1->empty()){
	myStack2->push(myStack1->top());
	myStack1->pop();
      }
    }

    cout << myStack2->top() << endl;
    myStack2->pop(); 
 }

private:
  stack<T> *myStack1;
  stack<T> *myStack2;
};

int main(int argc, char *argv[]){
  CQueue<int> *myQueue = new CQueue<int>();
  
  //  myQueue->appendTail(1);
  //  myQueue->appendTail(2);
  //  myQueue->appendTail(3);
  myQueue->deleteHead();
  //  myQueue->appendTail(4);
  //  myQueue->appendTail(5);
  myQueue->appendTail(6);
  myQueue->deleteHead();
  myQueue->deleteHead();
  myQueue->deleteHead();
  myQueue->deleteHead();
  myQueue->deleteHead();
  return 0;
}
