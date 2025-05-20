#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Subject {
public:
    string name;
    float grade;
    int credit;

    Subject(string n, float g, int c) {
        name = n;
        grade = g;
        credit = c;
    }
};

class CGPACalculator {
private:
    vector<Subject> subjects;

public:
    void addSubject(string name, float grade, int credit) {
        subjects.push_back(Subject(name, grade, credit));
    }

    float calculateCGPA() {
        float totalGradePoints = 0;
        int totalCredits = 0;

        for (auto& subject : subjects) {
            totalGradePoints += subject.grade * subject.credit;
            totalCredits += subject.credit;
        }

        if (totalCredits == 0) return 0;
        return totalGradePoints / totalCredits;
    }

    void printSubjects() {
        cout << "\nSubjects entered:\n";
        for (auto& subject : subjects) {
            cout << "- " << subject.name << ": Grade = " << subject.grade << ", Credit = " << subject.credit << endl;
        }
    }
};

bool isValidGrade(float grade) {
    return grade >= 0.0 && grade <= 10.0;
}

bool isValidCredit(int credit) {
    return credit > 0 && credit <= 10;
}

int main() {
    CGPACalculator calc;
    int numSubjects;

    cout << "Enter number of subjects: ";
    cin >> numSubjects;
    cin.ignore(); // Clear newline after number input

    for (int i = 0; i < numSubjects; ++i) {
        string name;
        float grade;
        int credit;

        cout << "\nEnter name of subject " << i + 1 << ": ";
        getline(cin, name);

        // Grade input with validation
        do {
            cout << "Enter grade for " << name << " (0.0 - 10.0): ";
            cin >> grade;
            if (!isValidGrade(grade)) {
                cout << "Invalid grade. Please enter a value between 0 and 10.\n";
            }
        } while (!isValidGrade(grade));

        // Credit input with validation
        do {
            cout << "Enter credit for " << name << " (1 - 10): ";
            cin >> credit;
            if (!isValidCredit(credit)) {
                cout << "Invalid credit. Please enter a positive value up to 10.\n";
            }
        } while (!isValidCredit(credit));

        cin.ignore(); // Clear newline for next getline

        calc.addSubject(name, grade, credit);
    }

    calc.printSubjects();

    float cgpa = calc.calculateCGPA();
    cout << "\nYour CGPA is: " << cgpa << endl;

    return 0;
}
