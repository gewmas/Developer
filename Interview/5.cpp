//find k least number in an array
#include <iostream>
#include <set>

using namespace std;

void findKLeastNumber(int array[], int size, multiset<int> *myMultiset, int k){
  if(k <= 0) return;

  for(int i = 0; i < size; i++){
    //    cout << array[i] << endl;
    if(myMultiset->size() < k) myMultiset->insert(array[i]);
    else{
      multiset<int>::iterator it = myMultiset->end();
      --it;
      myMultiset->erase(it);
      myMultiset->insert(array[i]);
    }
  }

}

int main(int argc, char *argv[]){
  // int array[] = {1, 3, 2, 5, 6, 8, 9, 4, 7, 0};
  int array[] = {};
  multiset<int> * myMultiset = new multiset<int>();

  findKLeastNumber(array, sizeof(array)/sizeof(array[0]), myMultiset, 0);

  for(multiset<int>::iterator it = myMultiset->begin(); it != myMultiset->end(); ++it){
    cout << *it << endl;
  }

  return 0;
}
