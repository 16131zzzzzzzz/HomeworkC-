#include<iostream>
#include<string>
using namespace std;

class Employee
{
private:
    string employeeFirstName;
    string employeeLastName;
    int employeeSalary;
public:
    explicit Employee( string firstName, string lastName, int salary );
    int getSalary();
    void setSalary( float );
    void display();
};

Employee::Employee( string firstName, string lastName, int salary )
{
    employeeFirstName = firstName;
    employeeLastName = lastName;
    if(salary < 0)
    {
        employeeSalary = 0;
    }
    else
    {
        employeeSalary = salary;
    }
}

void Employee::setSalary( float percentage )
{
    employeeSalary = employeeSalary * (1+percentage);
}

int Employee::getSalary()
{
    return employeeSalary;
}

void Employee::display()
{
    cout << employeeFirstName << " " << employeeLastName << ";Yearly Salary:" << getSalary() << endl;
}

int main()
{
    Employee employee1("Bob", "Jones", 34500);
    Employee employee2("Susan", "Baker", 37800);
    cout << "Employee1:";
    employee1.display();
    cout << "Employee2:";
    employee2.display();
    employee1.setSalary(0.1);
    employee2.setSalary(0.1);
    cout << "Increasing employee salaries by 10%\n";
    cout << "Employee1:";
    employee1.display();
    cout << "Employee2:";
    employee2.display();
}