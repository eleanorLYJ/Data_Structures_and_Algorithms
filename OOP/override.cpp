#include <iostream>
using namespace std;
class animal {
  public:
    void bark();
    virtual void
    name(string str) = 0; // pure virtual function -> make class virtual~
};
void animal::bark() { cout << "wow\n"; }
class cat : public animal {
  public:
    void bark();
    void name(string str) override;
    // == virtual void name(string str) override;
    // == void name(string str);
};
void cat::bark() { cout << "meow\n"; }
void cat::name(string str) { cout << "My name is " + str << endl; }

int main() {
    cat kitty;
    kitty.bark();
    kitty.name("kitty");
}