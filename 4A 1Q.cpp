#include <iostream>
#include <string>
using namespace std;
const int MAX_STUDENTS = 100;

struct Student {
string name;
    int age;
    char grade;
    int id;
};

Student students[MAX_STUDENTS];
int student_count = 0;


void addStudent(const string& name, int age, char grade, int id) {
    if (student_count >= MAX_STUDENTS) {
        cout << "Cannot add more students. The list is full.\n";
        return;
    }

    students[student_count++] = {name, age, grade, id};
    cout << "Student added successfully.\n";
}


void displayStudents() {
    if (student_count == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "ID\tName\tAge\tGrade\n";
    cout << "--\t----\t---\t-----\n";
    for (int i = 0; i < student_count; ++i) {
        cout << students[i].id << '\t'
                  << students[i].name << '\t'
                  << students[i].age << '\t'
                  << students[i].grade << '\n';
    }
}


Student* searchStudentById(int id) {
    for (int i = 0; i < student_count; ++i) {
        if (students[i].id == id) {
            return &students[i];
        }
    }
    return nullptr;
}


void updateStudentGrade(int id, char newGrade) {
    Student* student = searchStudentById(id);
    if (student) {
        student->grade = newGrade;
       cout << "Grade updated successfully.\n";
    } else {
        cout << "Student with ID " << id << " not found.\n";
    }
}

int main() {
    
    addStudent("Alice", 20, 'A', 1);
    addStudent("Bob", 21, 'B', 2);
    addStudent("Charlie", 22, 'C', 3);

    displayStudents();

 
    int searchId = 2;
    Student* student = searchStudentById(searchId);
    if (student) {
       cout << "Found student: " << student->name
                  << ", Age: " << student->age
                  << ", Grade: " << student->grade << '\n';
    } else {
        cout << "Student with ID " << searchId << " not found.\n";
    }

    
    updateStudentGrade(2, 'A');

    displayStudents();

    return 0;
}
