#include <iostream>
using namespace std;

// practice "protect" and see the sequence of the event from construction to
// destruction

class parent {
  public:
    ~parent() { cout << "destruct parent!\n"; }
    parent() { cout << "construct parent 1 \n"; }

  protected:
    void printa();
    int a, b, c;
};

void parent::printa() { cout << a << endl; }

class child : protected parent {
  public:
    child() { cout << "construct child 1 \n"; }
    child(int x, int y, int z) {
        a = x, b = y, c = z;
        cout << "construct child 2 \n";
    }
    ~child() { cout << "destruct child! \n"; }
    void print();
};

void child::print() {
    printa();
    return;
}

int main() {
    child* A = new child(1, 2, 3);
    A->print(); // 1
    delete A;
    return 0;
}