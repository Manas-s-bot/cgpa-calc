#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of subjects: ";
    cin >> n;

    vector<float> grades(n), credits(n);
    float totalCredits = 0, weightedSum = 0;

    for (int i = 0; i < n; ++i) {
        cout << "Enter grade point for subject " << i + 1 << ": ";
        cin >> grades[i];
        cout << "Enter credit for subject " << i + 1 << ": ";
        cin >> credits[i];

        weightedSum += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    if (totalCredits == 0) {
        cout << "Invalid input. Total credits cannot be zero.";
    } else {
        float cgpa = weightedSum / totalCredits;
        cout << "Your CGPA is: " << cgpa << endl;
    }

    return 0;
}
