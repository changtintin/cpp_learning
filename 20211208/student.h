#include <string>
using namespace std;

class student {
    public:
        string name;

        void showData();
        void changeAge(int a);

        student();
        student(int i, string n);
        student(int i, int a, string n);
    
    private:
        int id, age;
    
    protected:
        // nothing
};