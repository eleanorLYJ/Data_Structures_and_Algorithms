#include <iostream>
using namespace std;

class parent {
  public:
    parent() { cout << "parent construct\n"; }
    ~parent() { cout << "parent destruct\n"; }
};
class child : public parent {
  public:
    child() { cout << "child construct\n"; }
    ~child() { cout << "child destruct\n"; }
};
int main() {
    child x;
    // parent construct
    // child construct
    // child destruct
    // parent destruct
    return 0;
}