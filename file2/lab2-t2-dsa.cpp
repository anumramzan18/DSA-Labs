#include <iostream>
using namespace std;

class employee
{
public:
    virtual float calculatesalary() = 0;
};

class fulltimeemployee : public employee
{
private:
    float fixedsalary;
public:
    fulltimeemployee(float salary)
    {
        fixedsalary = salary;
    }
    float calculatesalary()   // FIXED: name must match base class
    {
        return fixedsalary;
    }
};

class parttimeemployee : public employee
{
private:
    int hoursworked;
    float hourlyrate;
public:
    parttimeemployee(int hours, float rate)
    {
        hoursworked = hours;
        hourlyrate = rate;
    }

    float calculatesalary()
    {
        return hoursworked * hourlyrate;
    }
};

int main()
{
    fulltimeemployee emp1(50000);
    parttimeemployee emp2(20, 500);

    cout << "full time employee salary " << emp1.calculatesalary() << endl;
    cout << "part time employee salary " << emp2.calculatesalary() << endl;

    return 0;
}