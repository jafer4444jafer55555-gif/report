#include <iostream>
#include <string>
#include <vector>
#include <iomanip> //

using namespace std;

class StudentResult {
private:
    string studentName;
    double grades[6];
    string subjects[6] = {"Math", "Physics", "Chemistry", "English", "CS", "Biology"};
    double total = 0;
    double average = 0;
    int failedCount = 0;

public:
    void inputData() {
        cout << "Enter Student Name: ";
        getline(cin >> ws, studentName);

        cout << "Enter grades for 6 subjects (0-100):" << endl;
        for (int i = 0; i < 6; i++) {
            do {
                cout << subjects[i] << ": ";
                cin >> grades[i];
                if (grades[i] < 0 || grades[i] > 100) {
                    cout << "Invalid grade! Please enter between 0 and 100." << endl;
                }
            } while (grades[i] < 0 || grades[i] > 100);

            total += grades[i];
            if (grades[i] < 50) {
                failedCount++;
            }
        }
        average = total / 6.0;
    }

    void displayResult() {
        cout << "\n------------------------------" << endl;
        cout << "      STUDENT REPORT CARD      " << endl;
        cout << "------------------------------" << endl;
        cout << "Name           : " << studentName << endl;
        cout << "Total Marks    : " << total << "/600" << endl;
        cout << "Average        : " << fixed << setprecision(2) << average << "%" << endl;
        cout << "Failed Subjects: " << failedCount << endl;


        cout << "Final Status   : ";
        if (failedCount > 2 || average < 50) {
            cout << "FAIL (Academic Probation)" << endl;
        } else if (average >= 85 && failedCount == 0) {
            cout << "EXCELLENT (Honors List)" << endl;
        } else {
            cout << "PASS" << endl;
        }
        cout << "------------------------------" << endl;
        
        if (average >= 50) {
            cout << "Keep it up! You are doing great." << endl;
        } else {
            cout << "Don't give up! Try harder next time." << endl;
        }
    }
};

int main() {
    StudentResult student;

    student.inputData();
    student.displayResult();

    return 0;
}
