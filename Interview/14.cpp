#include <iostream>
#include <list>

using namespace std;

void print(list<int> &myList){
  for(list<int>::iterator it = myList.begin(); it != myList.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;
}

void removeKthNode(list<int> &myList, int n){
  if(n <= 0) return;

  list<int>::iterator it = myList.begin();

  while(!myList.empty()){
    for(int i = 1; i < n; i++){
      it++;
      if(it == myList.end()) it = myList.begin();
    }
    myList.erase(it++);

    print(myList);

    if(it == myList.end()) it = myList.begin();
  }
}

int main(int argc, char *argv[]){
  list<int> myList;

  for(int i = 0; i < 10; i++){
    myList.push_back(i);
  }

  print(myList);

  removeKthNode(myList, 4); 

  return 0;
}
