#include <iostream>
using namespace std;
// to practicing upcsting
// to ensure what super class print.
class Animal {
public:
  virtual void speak() { cout << "a"; }
};
class human : public Animal {
public:
  void speak() { cout << "hi"; }
};
int main() {

  human A;
  Animal *B = &A;

  A.speak(); // hi
  cout << endl;
  B->speak(); // a

  return 0;
}