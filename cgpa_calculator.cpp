#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Subject class represents a single subject with its name, grade, and credit
class Subject {
private:
    string name;
    float grade;
    int credit;

public:
    Subject(string n, float g, int c) : name(n), grade(g), credit(c) {}

    string getName() const { return name; }
    float getGrade() const { return grade; }
    int getCredit() const { return credit; }
};

// Abstract base class
class CGPACalculator {
protected:
    vector<Subject> subjects;

public:
    void addSubject(const string& name, float grade, int credit) {
        subjects.push_back(Subject(name, grade, credit));
    }

    float calculateCGPA() const {
        float totalPoints = 0;
        int totalCredits = 0;

        for (const auto& sub : subjects) {
            totalPoints += sub.getGrade() * sub.getCredit();
            totalCredits += sub.getCredit();
        }

        return (totalCredits == 0) ? 0 : totalPoints / totalCredits;
    }

    virtual void displayResult() const = 0; // Polymorphism
};

// Inheritance: EngineeringCalculator inherits CGPACalculator
class EngineeringCalculator : public CGPACalculator {
public:
    void displayResult() const override {
        cout << "\nSubjects Entered:\n";
        for (const auto& sub : subjects) {
            cout << "- " << sub.getName()
                 << ": Grade = " << sub.getGrade()
                 << ", Credit = " << sub.getCredit() << endl;
        }

        float cgpa = calculateCGPA();
        cout << "\nFinal CGPA: " << cgpa << endl;
    }
};

// Input validation helpers
bool isValidGrade(float g) {
    return g >= 0.0 && g <= 10.0;
}

bool isValidCredit(int c) {
    return c > 0 && c <= 10;
}

// MAIN
int main() {
    CGPACalculator* calc = new EngineeringCalculator();  // Polymorphism
    int n;
    cout << "Enter number of subjects: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string name;
        float grade;
        int credit;

        cout << "\nSubject " << i + 1 << " name: ";
        getline(cin, name);

        do {
            cout << "Grade (0.0 - 10.0): ";
            cin >> grade;
            if (!isValidGrade(grade)) cout << "Invalid grade.\n";
        } while (!isValidGrade(grade));

        do {
            cout << "Credit (1 - 10): ";
            cin >> credit;
            if (!isValidCredit(credit)) cout << "Invalid credit.\n";
        } while (!isValidCredit(credit));

        cin.ignore(); // clear newline
        calc->addSubject(name, grade, credit);
    }

    calc->displayResult();

    delete calc;
    return 0;
}
