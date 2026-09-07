#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

// Search for a student by ID
void searchStudent(string names[], long long ids[], double gpas[],
                   int n, long long id)
{
    for (int i = 0; i < n; i++)
    {
        if (ids[i] == id)
        {
            cout << "\nStudent Found!\n";
            cout << "Name: " << names[i] << endl;
            cout << "ID: " << ids[i] << endl;
            cout << "GPA: " << fixed << setprecision(2)
                 << gpas[i] << endl;

            return;
        }
    }

    cout << "\nStudent with ID " << id
         << " not found.\n";
}


void maxGPA(string names[], double gpas[], int n)
{
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (gpas[i] > gpas[maxIndex])
        {
            maxIndex = i;
        }
    }

    cout << "Highest GPA: "
         << names[maxIndex]
         << " - "
         << fixed << setprecision(2)
         << gpas[maxIndex] << endl;
}


void minGPA(string names[], double gpas[], int n)
{
    int minIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (gpas[i] < gpas[minIndex])
        {
            minIndex = i;
        }
    }

    cout << "Lowest GPA: "
         << names[minIndex]
         << " - "
         << fixed << setprecision(2)
         << gpas[minIndex] << endl;
}

int main()
{
    int n;
    long long id;

    string names[MAX_STUDENTS];
    long long ids[MAX_STUDENTS];
    double gpas[MAX_STUDENTS];

    cout << "Enter the number of students: ";
    cin >> n;

    // Validate number of students
    if (n <= 0 || n > MAX_STUDENTS)
    {
        cout << "Invalid number of students." << endl;
        return 0;
    }

    // Input student data
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter data for student "
             << i + 1 << ":\n";

        cout << "Name: ";
        cin >> names[i];

        cout << "ID: ";
        cin >> ids[i];

        cout << "GPA: ";
        cin >> gpas[i];

        // Validate GPA
        if (gpas[i] < 0.0 || gpas[i] > 4.0)
        {
            cout << "Invalid GPA. GPA must be between 0.00 and 4.00."
                 << endl;
            return 0;
        }
    }

    // Display all students
    cout << "\n========== Student Details ==========\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Name: " << names[i]
             << " | ID: " << ids[i]
             << " | GPA: " << fixed << setprecision(2)
             << gpas[i] << endl;
    }

    // GPA statistics
    cout << "\n========== GPA Statistics ==========\n";

    maxGPA(names, gpas, n);
    minGPA(names, gpas, n);

    // Search for a student
    cout << "\nEnter the ID of the student to search: ";
    cin >> id;

    searchStudent(names, ids, gpas, n, id);

    return 0;
}
