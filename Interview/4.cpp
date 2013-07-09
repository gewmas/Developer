//traverse bst print left to right
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class bst{
public:
  bst() : root(NULL) {}

  ~bst(){
    deleteNode(root);
  }

  void insert(const T & value){
    root = insert(value, root);
  }

  void traverseTopDown(){
    traverseTopDown(root);
  }

  void mirror(){
    mirror(root);
  }

  void findPathSum(int sum){
    vector<bst<T>::bstNode*> *myPath = new vector<bstNode*>();
    findPathSum(root, sum, myPath);
    delete myPath;
  }

  void print(){
    print(root);
  }

private:
  class bstNode{
  public:
    T value;
    bstNode *left;
    bstNode *right;
    bstNode(T v) : value(v), left(NULL), right(NULL) {}
  };
  bstNode *root;

  bstNode *insert(const T & value, bstNode *current){
    if(current == NULL) return new bstNode(value);

    if(value < current->value){
      current->left = insert(value, current->left);
    } else if(value > current->value){
      current->right = insert(value, current->right);
    }

    return current;
  }

  void traverseTopDown(bstNode *root){
    queue<bstNode *> *myQueue = new queue<bstNode *>();
    bstNode *current = root;

    myQueue->push(current);

    while(!myQueue->empty()){
      current = myQueue->front();
      myQueue->pop();

      if(current != NULL){
	cout << current->value << endl;
	myQueue->push(current->left);
	myQueue->push(current->right);
      }
    }

    delete myQueue;
  }

  void print(bstNode *current){
    if(current != NULL){
      print(current->left);
      cout << current->value << endl;
      print(current->right);
    }
  }

  void deleteNode(bstNode *current){
    if(current != NULL){
      deleteNode(current->left);
      deleteNode(current->right);
      delete current;
    }
  }

  void mirror(bstNode *current){
    if(current != NULL){
      mirror(current->left);
      mirror(current->right);

      bstNode *temp = current->left;
      current->left = current->right;
      current->right = temp;
    }
  }

  void findPathSum(bstNode *current, int sum, vector<bstNode*> *myPath){
    if(current != NULL){
      sum -= current->value;
      myPath->push_back(current);

      if(sum == 0){
	cout << "Sum is: " << sum << " with last node " << current->value << endl;
	
	for(int i = 0; i < myPath->size(); i++){
	  cout << (*myPath)[i]->value << " ";
	}

	//vector<bstNode*>::iterator it = myPath->begin();
	//for(vector<bstNode*>::iterator it = myPath->begin(); it != myPath->end(); ++it){
	//  cout << (*it)->value << " ";
	//}

	cout << endl;
      }

      findPathSum(current->left, sum, myPath);
      findPathSum(current->right, sum, myPath);

      sum += current->value;
      myPath->pop_back();
    }
  }
};

int main(int argc, char *argv[]){
  bst<int> * myBst = new bst<int>();
  
  myBst->insert(8);
  myBst->insert(6);
  myBst->insert(5);
  myBst->insert(10);
  myBst->insert(7);
  myBst->insert(11);
  myBst->insert(9);
  //myBst->print();
  /*
  //  myBst->traverseTopDown();

  cout << endl;
  myBst->mirror();
  myBst->print();

  cout << endl;
  myBst->mirror();
  myBst->print();
  */
  myBst->findPathSum(21);

  return 0;
}
