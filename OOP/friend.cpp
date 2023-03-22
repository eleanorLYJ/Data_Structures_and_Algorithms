// practice friend class
// topic: teacher can know student's score

#include <iostream>
using namespace std;

class student {
  public:
    student(int sid, int score) {
        this->sid = sid;
        this->score = score;
    }
    friend class teacher;

  private:
    int score;
    int sid;
};
class teacher {
  public:
    void know_score(student s) { cout << s.score; }
};

int main() {
    student a(1, 100);
    teacher tea;
    tea.know_score(a);
    return 0;
}