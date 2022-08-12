#include <bits/stdc++.h>
using namespace std;

class Course
{
    public:
        std::string name;
        std::string instructorInCharge;
        int numberOfStudents;
        int totalMarks;

        template <typename T>
        T evaluateAnswer(T givenAnswer, T expectedAnswer)
        {
            return givenAnswer==expectedAnswer;
        }

    private:
        // initializing a vector of size numberOfStudents.
        std::vector<int> studentMarks;
};
