/*
A questionnaire was sent to a random selection of the alumni of a college.
In all, 95 questionnaires were returned.

The questionnaire requested the following items:
Age
Salary

Design a program where it asks the user for an age range then prints out the average salary for that age range.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream ageFile("age.txt");
    ifstream salaryFile("Salary.txt");

    int j = 0;

    int age = 0;
    int salary = 0;

    int ages[95];
    int salaries[95];

    int lowerRange = 0;
    int upperRange = 0;

    int salarySum = 0;
    int salaryCount = 0;

    if (!ageFile) {
        cout << "Error Reading age.txt" << endl;
        return 0;
    }
    if (!salaryFile) {
        cout << "Error Reading Salary.txt" << endl;
        return 0;
    }
    
    while (ageFile >> age && salaryFile >> salary) {
        ages[j] = age;
        salaries[j] = salary;
        j++;
    }

    cout << "Lower Age Range: ";
    cin >> lowerRange;
    cout << "Upper Age Range: ";
    cin >> upperRange;

    for (int i = 0; i < 95; i++) {
        if (ages[i] <= upperRange && ages[i] >= lowerRange) {
            salarySum += salaries[i];
            salaryCount++;
        }
    }
    
    double out = (double)salarySum/(double)salaryCount;

    cout << "\nThe average salary between ages " << lowerRange << " and " << upperRange << " is " << fixed << setprecision(2) << out << "." << endl;

    return 0;
}