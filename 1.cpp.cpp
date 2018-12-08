/**Q1:Write C++ code in object oriented approach for the students.Student can be rewarded from the department
if he gets good GPA in a semester and solved atleast 100 ACM problems in the last year.Department will publish
the top 5 students name in their honor board. As a student of CSE, write OOP code for the project.**/

#include<bits/stdc++.h>
using namespace std;

float array[10];

class Person
{
public:
    string Name;
    int Age;

    Person(string name, int age){this->Name=name; this->Age=age;}
};

class Student:public Person
{
private:
    float GPA;
    int ACM_Solve;

public:
	Student(string n, int a, float g, int s) : Person(n,a), GPA(g), ACM_Solve(s) {}
	void showStudent(){cout << setw(10) << Name << setw(13) <<  GPA << setw(13) << ACM_Solve << endl << endl;}

	int checkGPA(float gpa)
    {
        if(GPA==gpa && ACM_Solve>=100)
            return 1;

        else return 0;
    }

    float accessGPA()
    {
        return GPA;
    }
};

int main()
{
    int i,j;
    Student *details[8]=
    {
        new Student("Akash",20,3.52,45),
        new Student("Joy",23,3.91,110),
        new Student("Rabby",21,3.45,150),
        new Student("Sohan",20,3.26,310),
        new Student("Tanzir",23,3.28,250),
        new Student("Rony",21,3.88,100),
        new Student("Showrov",22,3.63,200),
        new Student("Ashik",22,3.27,99)
    };

    float temp;
    int count=0;
    float max;

    for(i=7;i>=0;i--)
    {
        array[i]=details[i]->accessGPA();
        for(j=0;j<=7-i;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j+1];
                array[j+1]=array[j];
                array[j] = temp ;
            }
        }
    }

    cout << "TOP 5 students on the Honor Board are:" << endl << endl<<endl;
    cout << setw(10) << "Student Name"  << setw(10) << "GPA" << setw(17) <<  "ACM Solve" << endl  ;
    cout << setw(10) << "____________"  << setw(10) << "___" << setw(17) << "_________" << endl << endl ;

    for(i=7;i>=0;i--)
    {
        max=array[i];

        for(j=0;j<7;j++)
        {
            if(details[j]->checkGPA(max)==1)
            {
                count++;
                details[j]->showStudent();
            }

            if(count==5) break;
        }
    }
    return 0;
}
