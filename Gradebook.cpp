#include <iostream>
#include <limits>
using namespace std;

const int NUMBER_OF_TESTS = 4;
const int NUMBER_OF_STUDENTS = 5;

//function prototypes
double inputValidate();
void getStudentTestScores(double[]);
double calculateAverageOfArray(const double[], int);
string getAverageLetterGrade(double);
void getStudentNames(string[]);
void getAllTestScores(const string[],
                      double[],
                      double[],
                      double[],
                      double[],
                      double[]);
void calculateAndDisplayAverages(const string[],
                                 const double[],
                                 const double[],
                                 const double[],
                                 const double[],
                                 const double[]);

int main()
{
    // Arrays to hold student names and each student's test scores
    string studentNames[NUMBER_OF_STUDENTS];

    double student1TestScores[NUMBER_OF_TESTS];
    double student2TestScores[NUMBER_OF_TESTS];
    double student3TestScores[NUMBER_OF_TESTS];
    double student4TestScores[NUMBER_OF_TESTS];
    double student5TestScores[NUMBER_OF_TESTS];

    //Get all student names
    getStudentNames(studentNames);

    // get each student's test scores
    getAllTestScores(studentNames,
                     student1TestScores,
                     student2TestScores,
                     student3TestScores,
                     student4TestScores,
                     student5TestScores);

    // calculate and display averages + pass/fail results
    calculateAndDisplayAverages(studentNames,
                                student1TestScores,
                                student2TestScores,
                                student3TestScores,
                                student4TestScores,
                                student5TestScores);

    return 0;
}

void getStudentNames(string studentNames[])
{
    cout << "Enter student names:\n";

    // clears leftover newline from previous cin use
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // FIX 1

    // Read names using getline so spaces are allowed
    for (int i = 0; i < NUMBER_OF_STUDENTS; i++)
    {
        cout << "Student " << (i + 1) << " name: ";
        getline(cin, studentNames[i]);
    }
}

void getAllTestScores(const string studentNames[],
                      double student1TestScores[],
                      double student2TestScores[],
                      double student3TestScores[],
                      double student4TestScores[],
                      double student5TestScores[])
{
    // Ask for scores for each student individually
    cout << "\nEnter test scores for " << studentNames[0] << endl;
    getStudentTestScores(student1TestScores);

    cout << "\nEnter test scores for " << studentNames[1] << endl;
    getStudentTestScores(student2TestScores);

    cout << "\nEnter test scores for " << studentNames[2] << endl;
    getStudentTestScores(student3TestScores);

    cout << "\nEnter test scores for " << studentNames[3] << endl;
    getStudentTestScores(student4TestScores);

    cout << "\nEnter test scores for " << studentNames[4] << endl;
    getStudentTestScores(student5TestScores);
}

void getStudentTestScores(double array[])
{
    // Get four test scores for a student
    for (int i = 0; i < NUMBER_OF_TESTS; i++)
    {
        cout << "Test #" << (i + 1) << ": ";
        array[i] = inputValidate();   // Ensures valid score
    }
}

double inputValidate()
{
    double number;

    // Ensures input is a number between 0 and 100
    while (!(cin >> number) || number < 0 || number > 100)
    {
        cout << "Error. A number from 0 to 100 must be entered: ";
        cin.clear(); // clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}

void calculateAndDisplayAverages(const string studentNames[],
                                 const double s1[],
                                 const double s2[],
                                 const double s3[],
                                 const double s4[],
                                 const double s5[])
{
    double average;
    string grade;

    // Student 1
    average = calculateAverageOfArray(s1, NUMBER_OF_TESTS);
    cout << "\nAverage test score for " << studentNames[0] << " = " << average << endl;
    grade = getAverageLetterGrade(average);
    cout << "results = " << grade << endl << endl;

    // Student 2
    average = calculateAverageOfArray(s2, NUMBER_OF_TESTS);
    cout << "Average test score for " << studentNames[1] << " = " << average << endl;
    grade = getAverageLetterGrade(average);
    cout << "results = " << grade << endl << endl;

    // Student 3
    average = calculateAverageOfArray(s3, NUMBER_OF_TESTS);
    cout << "Average test score for " << studentNames[2] << " = " << average << endl;
    grade = getAverageLetterGrade(average);
    cout << "results = " << grade << endl << endl;

    // Student 4
    average = calculateAverageOfArray(s4, NUMBER_OF_TESTS);
    cout << "Average test score for " << studentNames[3] << " = " << average << endl;
    grade = getAverageLetterGrade(average);
    cout << "results = " << grade << endl << endl;

    // Student 5
    average = calculateAverageOfArray(s5, NUMBER_OF_TESTS);
    cout << "Average test score for " << studentNames[4] << " = " << average << endl;
    grade = getAverageLetterGrade(average);
    cout << "results = " << grade << endl << endl;
}

double calculateAverageOfArray(const double array[], int ARRAY_SIZE)
{
    double sum = 0;

    // add all test scores
    for (int i = 0; i < ARRAY_SIZE; i++)
        sum += array[i];

    return sum / ARRAY_SIZE; // return average
}

string getAverageLetterGrade(double average)
{
    // grading based on score ranges
    if (average >= 75)
        return "pass with Distinction";
    if (average >= 50)
       return "pass";
    return "Fail";
}
