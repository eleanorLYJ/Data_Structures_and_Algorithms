#include <iostream>
using namespace std;
// practice overload "opearator >"

class student {
  public:
    int getter_score();
    int getter_sid();
    bool operator>(student&);
    student(int, int);

  private:
    int score;
    int sid;
};

student::student(int sid, int score) {
    this->sid = sid;
    this->score = score;
}
int student::getter_score() { return score; }
int student::getter_sid() { return sid; }
bool student::operator>(student& other) { // a > b == a.operator>(b)
    if (score > other.score)
        return true;
    else
        return false;
}

int main() {
    student A(1, 90);
    student B(2, 100);
    cout << "student ID " << A.getter_sid() << "'s score: " << A.getter_score()
         << endl;
    cout << "student ID " << B.getter_sid() << "'s score: " << B.getter_score()
         << endl;
    cout << (B > A) << endl; // 1
    cout << (A > B) << endl; // 0
    return 0;
}