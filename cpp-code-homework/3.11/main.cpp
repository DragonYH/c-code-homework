#include <iostream>
using namespace std;

class Salary
{
private:
    double Wage, Subsidy, Rent, WaterFee, ElecFee;

public:
    Salary(double _Wage,double _Subsidy,double _Rent,double _WaterFee,double _ElecFee){Wage=_Wage;Subsidy=_Subsidy;Rent=_Rent;WaterFee=_WaterFee;ElecFee=_ElecFee;};
    Salary() { Wage = Subsidy = Rent = WaterFee = ElecFee = 0; };
    void setWage(double f) { Wage = f; };
    double getWage() { return Wage; };
    void setSubsidy(double f) { Subsidy = f; };
    double getSubsidy() { return Subsidy; };
    void setRent(double f) { Rent = f; };
    double getRent() { return Rent; };
    void setWaterFee(double f) { WaterFee = f; };
    double getWaterFee() { return WaterFee; };
    void setElecFee(double f) { ElecFee = f; };
    double getElecFee() { return ElecFee; };
    double RealSalary()
    {
        return Wage + Subsidy - Rent - WaterFee - ElecFee;
    }
    ~Salary();
};

class Worker
{
private:
    string name, Dept;
    int age;
    Salary salary;
    static int count;

public:
    Worker() { count++; };
    void setname(string f) { name = f; };
    string getname() { return name; };
    void setDept(string f) { Dept = f; };
    string getDept() { return Dept; };
    void setage(int f) { age = f; };
    int getage() { return age; };
    ~Worker();
};

int Worker::count = 0;

int main()
{
    system("pause");
    return 0;
}
