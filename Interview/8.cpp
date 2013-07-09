//1+2+...+n
#include <iostream>

using namespace std;

class Temp{
public:
  Temp(){
    ++N;
    Sum += N;
  }

  static void Reset(){
    N = 0;
    Sum = 0;
  }

  static int GetSum(){
    return Sum;
  }

private:
  static int N;
  static int Sum;
};

int Temp::N = 0;
int Temp::Sum = 0;

int solution1_Sum(int n){
  Temp::Reset();

  Temp *a = new Temp[n];
  delete[] a;
  a = 0;

  return Temp::GetSum();
}

int main(int argc, char *argv[]){
  cout << solution1_Sum(100) << endl;

  return 0;
}
