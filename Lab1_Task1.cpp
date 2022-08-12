#include <bits/stdc++.h>
using namespace std;

class Course
{
    public:
        std::string name;
        std::string instructorInCharge;
        int numberOfStudents;
        int totalMarks;
        Course(string Name,string Instructor,int Number,int Total)
        {
            name=Name;
            instructorInCharge=Instructor;
            numberOfStudents=Number;
            totalMarks=Total;
        }

    private:
        // initializing a vector of size numberOfStudents.
        std::vector<int> studentMarks;
        friend class Lab;
};  

class Lab : public Course
{
    public:
        Lab():Course("DSA","Jacob",5,100)
        {
            
        }
        int count=0;
        std::vector <int> labMarks;
        int countNC(int threshold)
        {
            for(int i=0;i<numberOfStudents;i++)
            {
                if(studentMarks[i]+labMarks[i] < threshold)
                    count++;
            }
            return count;
        }
};
