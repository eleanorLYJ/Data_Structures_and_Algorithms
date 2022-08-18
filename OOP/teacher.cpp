// friend class
#include <iostream>
using namespace std;

class student{
    public:
        student(int s, int score){
            this->sid = s;
            this->score = score;
        }
        int getter_score(){
            return score;
        }
        friend class teacher;
    private:
        int score;
        int sid;
};
class teacher{
    public:
        void know_score(student s){
            cout << s.score;
        }
};

int main(){
    student a(1, 100);
    teacher tea;
    tea.know(a);
    return 0;
}