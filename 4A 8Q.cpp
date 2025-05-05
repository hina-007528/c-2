#include <iostream>
#include <string>
using namespace std;
const int MAX_COURSES = 100; 
const int MAX_STUDENTS = 100;


struct Course {
    string courseName;
  string instructor;
    int credits;
  string courseID;
    string enrolledStudents[MAX_STUDENTS];
    int numStudents; 
};

Course courses[MAX_COURSES];
int numCourses = 0;  


void addCourse(const string& courseName, const string& instructor, int credits, const string& courseID) {
    if (numCourses >= MAX_COURSES) {
        cout << "Error: Cannot add new course. Maximum number of courses reached." << endl;
        return;
    }

    courses[numCourses] = {courseName, instructor, credits, courseID, {}, 0};
    ++numCourses;
    cout << "Course added successfully." << endl;
}


void enrollStudent(const string& courseID, const string& studentName) {
    for (int i = 0; i < numCourses; ++i) {
        if (courses[i].courseID == courseID) {
            if (courses[i].numStudents >= MAX_STUDENTS) {
                cout << "Error: Course is full." << endl;
                return;
            }
            for (int j = 0; j < courses[i].numStudents; ++j) {
                if (courses[i].enrolledStudents[j] == studentName) {
                    cout << "Error: Student is already enrolled in this course." <<endl;
                    return;
                }
            }
            courses[i].enrolledStudents[courses[i].numStudents++] = studentName;
            cout << "Student enrolled successfully." << endl;
            return;
        }
    }
    cout << "Error: Course ID not found." << endl;
}


void dropStudent(const string& courseID, const string& studentName) {
    for (int i = 0; i < numCourses; ++i) {
        if (courses[i].courseID == courseID) {
            bool found = false;
            for (int j = 0; j < courses[i].numStudents; ++j) {
                if (courses[i].enrolledStudents[j] == studentName) {
                    found = true;
                   
                    for (int k = j; k < courses[i].numStudents - 1; ++k) {
                        courses[i].enrolledStudents[k] = courses[i].enrolledStudents[k + 1];
                    }
                    --courses[i].numStudents;
                    cout << "Student dropped successfully." <<endl;
                    return;
                }
            }
            if (!found) {
                cout << "Error: Student not found in this course." << endl;
                return;
            }
        }
    }
    cout << "Error: Course ID not found." << endl;
}


void listCoursesForStudent(const string& studentName) {
    bool enrolled = false;
    for (int i = 0; i < numCourses; ++i) {
        for (int j = 0; j < courses[i].numStudents; ++j) {
            if (courses[i].enrolledStudents[j] == studentName) {
                cout << "Course ID: " << courses[i].courseID << endl;
                cout << "Course Name: " << courses[i].courseName << endl;
                cout << "Instructor: " << courses[i].instructor << endl;
                cout << "Credits: " << courses[i].credits << endl;
               cout << "----------------------" << endl;
                enrolled = true;
                break;
            }
        }
    }
    if (!enrolled) {
       cout << "No courses found for student: " << studentName << endl;
    }
}

int main() {
    
    addCourse("Introduction to Programming", "Dr. Smith", 3, "CS101");
    addCourse("Data Structures", "Prof. Johnson", 4, "CS102");

    
    enrollStudent("CS101", "Alice");
    enrollStudent("CS101", "Bob");
    enrollStudent("CS102", "Alice");

    
    dropStudent("CS101", "Bob");

   cout << "\nCourses for Alice:" << endl;
    listCoursesForStudent("Alice");

  cout << "\nCourses for Bob:" << endl;
    listCoursesForStudent("Bob");

    return 0;
}