#include <iostream>
#include <string>
using namespace std;
const int MAX_EMPLOYEES = 100; 


struct Employee {
   string name;
    string position;
    double salary;
    int employee_id;
};

Employee employees[MAX_EMPLOYEES];
int employee_count = 0;


void addEmployee(const string& name, const string& position, double salary, int employee_id) {
    if (employee_count >= MAX_EMPLOYEES) {
       cout << "Database is full. Cannot add more employees.\n";
        return;
    }


    employees[employee_count++] = {name, position, salary, employee_id};
   cout << "Employee added successfully.\n";
}


void removeEmployee(int employee_id) {
    for (int i = 0; i < employee_count; ++i) {
        if (employees[i].employee_id == employee_id) {
         
            for (int j = i; j < employee_count - 1; ++j) {
                employees[j] = employees[j + 1];
            }
            --employee_count;
           cout << "Employee with ID " << employee_id << " removed successfully.\n";
            return;
        }
    }
   cout << "Employee with ID " << employee_id << " not found.\n";
}


void updateEmployeeSalary(int employee_id, double new_salary) {
    for (int i = 0; i < employee_count; ++i) {
        if (employees[i].employee_id == employee_id) {
            employees[i].salary = new_salary;
            cout << "Salary for employee with ID " << employee_id << " updated successfully.\n";
            return;
        }
    }
    cout << "Employee with ID " << employee_id << " not found.\n";
}


void listEmployees() {
    if (employee_count == 0) {
       cout << "No employees to display.\n";
        return;
    }

   cout << "ID\tName\tPosition\tSalary\n";
   cout << "--\t----\t--------\t------\n";
    for (int i = 0; i < employee_count; ++i) {
      cout << employees[i].employee_id << '\t'
                  << employees[i].name << '\t'
                  << employees[i].position << '\t'
                  << employees[i].salary << '\n';
    }
}

int main() {
  
    addEmployee("Alice Johnson", "Software Engineer", 75000, 101);
    addEmployee("Bob Smith", "Project Manager", 85000, 102);
    addEmployee("Charlie Brown", "Designer", 60000, 103);

   
    listEmployees();

    
    updateEmployeeSalary(101, 80000);

    removeEmployee(102);

    listEmployees();

    return 0;
}