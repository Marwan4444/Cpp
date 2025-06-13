#include <iostream>
using namespace std;

void main_func();
void add_teacher();
void add_student();


class Student
{
    string name ;
    int age ;
    int id;

public:

    Student(string name , int age , int id)
    {
        this ->name =name;
        this ->age =age;
        this ->id =id;
    }

    void show(int number)
    {
        cout<<"\n============= Student ("<<number+1<<") information =============\n";
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"ID : "<<id<<endl;
    }

    void setter_name(string name )
    {
        this ->name =name;
    }

    string getter_name()
    {
        return name;
    }

    void setter_age(int age )
    {
        this ->age =age;
    }

    int getter_age()
    {
        return age;
    }

    void setter_id(int id )
    {
        this ->id =id;
    }

    int getter_id()
    {
        return id;
    }
};


class Teacher
{
    string name ;
    int age ;
    int salary;

public:

    Teacher(string name , int age , int salary)
    {
        this ->name =name;
        this ->age =age;
        this ->salary =salary;
    }

    void show(int teacher_number)
    {
        cout<<"\n============= Teacher ("<<teacher_number+1<<") information =============\n";
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
        cout<<"Salary : "<<salary<<endl;
    }

    void setter_name(string name )
    {
        this ->name =name;
    }

    string getter_name()
    {
        return name;
    }

    void setter_age(int age )
    {
        this ->age =age;
    }

    int getter_age()
    {
        return age;
    }

    void setter_salary(int salary )
    {
        this ->salary =salary;
    }

    int getter_salary()
    {
        return salary;
    }
};



int main()
{
main_func();
    return 0;
}


void main_func()
{
    int choice;

    do
    {
        cout<< "\n=============  System Options ============= "
                "\n1- Add teacher"
                "\n2- Add student"
                "\n3- Exit";
        cout<<"\n----------------------\n";
        cin>>choice;
        cout<<"----------------------\n";

        switch(choice)
        {
            case 1:
                add_teacher();
                break;
            case 2:
                add_student();
                break;
            case 3:
                break;
            default:
                cout<< " enter a valid choice!! \n";
                main_func();

        }

    }while(choice !=3);



}


 void add_teacher()
 {

     int teacher_number;
     cout<<"enter teachers number :";
     cin>>teacher_number;
     cout<<"\n----------------------------\n";

     string names[teacher_number];
     int ages[teacher_number];
     int salaries[teacher_number];

     for(int counter =0; counter <teacher_number ;counter++)
     {
         cout<< "enter name "<<counter+1<<":";
         cin>>names[counter];
         cout<<"----------------------------\n";
         cout<< "enter age "<<counter+1<<":";
         cin>>ages[counter];
         cout<<"----------------------------\n";
         cout<< "enter salary "<<counter+1<<":";
         cin>>salaries[counter];

         cout<<"----------------------------\n";

     }

     for(int counter =0; counter<teacher_number ;counter++)
     {
         Teacher teacher(names[counter],ages[counter],salaries[counter]);
         teacher.show(counter);

     }

 }

 void add_student()
 {
        int student_number;
     cout<<"enter students number :";
     cin>>student_number;
     cout<<"\n----------------------------\n";

     string names[student_number];
     int ages[student_number];
     int id[student_number];

     for(int counter =0; counter <student_number ;counter++)
     {
         cout<< "enter name "<<counter+1<<":";
         cin>>names[counter];
         cout<<"----------------------------\n";
         cout<< "enter age "<<counter+1<<":";
         cin>>ages[counter];
         cout<<"----------------------------\n";
         cout<< "enter ID "<<counter+1<<":";
         cin>>id[counter];

         cout<<"----------------------------\n";

     }

     for(int counter =0; counter<student_number ;counter++)
     {
       Student student(names[counter],ages[counter],id[counter]);
         student.show(counter);

     }

 }
