//copy in class with pointer
#include <iostream>
//#include <stdlib.h>

template <typename T>
class Array{
public:
  Array(unsigned arraySize) : data(0), size(arraySize){
    if(size > 0) data = new T[size];
  }
  
  Array(const Array &copy) : data(0), size(copy.size){
    if(size > 0){
      data = new T[size];
      for(int i = 0; i < size; ++i){
	setValue(i, copy.getValue(i));
      }
    }
  }

  const Array &operator = (const Array &copy){
    if(this == copy) return *this;
    
    if(data != NULL){
      delete[] data;
      data = NULL;
    }

    size = copy.size;
    if(size > 0){
      data = new T[size];
      for(int i = 0; i < size; ++i){
	setValue(i, copy.getValue(i));
      }
    }
  }

  ~Array(){
    if(data) delete[] data;
  }

  void setValue(unsigned index, const T &value){
    if(index < size) data[index] = value;
  }

  T getValue(unsigned index) const{
    if(index < size)
      return data[index];
    else
      return T();
  }

private:
  T *data;
  unsigned size;
};

int main(int argc, char *argv[]){
  Array<int> * myArray = new Array<int>(10);

  Array<int> myArray2(5);
  myArray2.setValue(3, 103);
  Array<int> myArray3(myArray2);
  Array<int> myArray4 = myArray3;
  std::cout << myArray4.getValue(3) << std::endl;
  

  return 0;
}
