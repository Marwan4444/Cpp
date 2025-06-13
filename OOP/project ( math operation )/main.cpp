#include <iostream>
#include<string>

using namespace std;

class Math_processes
{
    public:
    float firstNum =1;
    float secondNum=2;
    int mathChoise;

    void sum()
    {
        cout<<"\n--------------------------\n";
        cout<< "the result of "<<firstNum <<'+'<< secondNum<<'='<<firstNum+secondNum;
        cout<<"\n--------------------------\n";
    }
    void sub()
    {
        cout<<"\n--------------------------\n";
        cout<< "the result of "<<firstNum <<'-'<< secondNum<<'='<<firstNum-secondNum;
        cout<<"\n--------------------------\n";
    }
    void div()
    {
        cout<<"\n--------------------------\n";
        cout<< "the result of "<<firstNum <<'/'<< secondNum<<'='<<firstNum/secondNum;
        cout<<"\n--------------------------\n";
    }
    void mult()
    {
        cout<<"\n--------------------------\n";
        cout<< "the result of "<<firstNum <<'*'<< secondNum<<'='<<firstNum*secondNum;
        cout<<"\n--------------------------\n";
    }

};

class String_processes
{
    public:

    string firstString ="marwan" ;
    string secondString = "marwaa";
    int StringChoise;

    void add()
    {
        cout<<"\n--------------------------\n";
        cout<<"the result of " <<firstString<<"+"<<secondString << " is "<<firstString+" "+secondString;
        cout<<"\n--------------------------\n";
    }

    void compare()
    {
        if(firstString.length()== secondString.length())
        {
            if(firstString == secondString)
            {
                cout<<"\n--------------------------\n";
                cout<< "the two string are the same ";
                cout<<"\n--------------------------\n";

            }
            else
            {
                for(int counter ; counter < firstString.length() ;counter++)
                {
                    if(firstString[counter] != secondString[counter])
                    {
                        cout<<"\n--------------------------\n";
                        cout<<"the two string are different in "<<counter+1
                        <<"\n"<< firstString[counter] << " in "<< firstString
                        <<"\n"<<  secondString[counter] << " in " << secondString;
                        cout<<"\n--------------------------\n";
                    }
                }

            }

        }
        else
        {
            cout<<"\n--------------------------\n";
            cout<<"the two string are not the same length";
            cout<<"\n--------------------------\n";
        }


    }


};
void intput_math( Math_processes processes);
void intput_string( String_processes processe);



int main()
{
    Math_processes obj_math_user;
    String_processes obj_string_user;
    int main_chiose;

    cout<< "***********Welcome***********\n";
    do
    {
        main_page:
        cout<<"choose the mode :"
              "\n1-Math mode"
              "\n2-String mode"
              "\n3-Exit";
        cout<<"\n==============================\n";
        cin>>main_chiose;

        switch(main_chiose)
        {
            case 1:
                intput_math(obj_math_user);
                break;
            case 2:
                intput_string(obj_string_user);
                break;
            case 3:
                break;
            default:
                cout<<"enter a valid choice";
                goto main_page;
                break;

        }
    }while(main_chiose!=3);

    return 0;
}


void intput_math( Math_processes processe)
{
    int flag =0;
    do
    {
        New_number:
        cout<< "enter the first number :";
        cin>>processe.firstNum;
        cout<<"\n--------------------------\n";

        cout<< "enter the second number :";
        cin>>processe.secondNum;
        cout<<"\n--------------------------\n";
        main_page:
        cout<< "choose the processe :"
                "\n1-summation"
                "\n2-subtraction"
                "\n3-multiplication"
                "\n4-division"
                "\n5-enter new numbers"
                "\n6-return to main page";
        cout<<"\n--------------------------\n";
        cin>>processe.mathChoise;


        switch(processe.mathChoise)
        {
            case 1:
                processe.sum();
                break;
            case 2:
                processe.sub();
                break;
            case 3:
                processe.mult();
                break;
            case 4:
                processe.div();
                break;
            case 5:
                goto New_number;
                break;
            case 6:
                break;
            default:
            cout<<"enter a valid choice";
            goto main_page;

        }
        flag =1;
    }while(processe.mathChoise!=6 && flag == 0);

}


void intput_string( String_processes processe)
{

    int flag=0;
    do
    {
        New_string:
        cout<< "enter the first string :";
        cin>>processe.firstString;
        cout<<"\n--------------------------\n";

        cout<< "enter the second string :";
        cin>>processe.secondString;
        cout<<"\n--------------------------\n";
        main_page:
        cout<< "choose the processe :"
                "\n1-add two string"
                "\n2-compare two string"
                "\n3-enter new strings"
                "\n4-return to main page";
        cout<<"\n--------------------------\n";
        cin>>processe.StringChoise;

        switch(processe.StringChoise)
        {
            case 1:
                processe.add();
                break;
            case 2:
                processe.compare();
                break;
            case 3:
                goto New_string;
                break;
            case 4:
                break;
            default:
            cout<<"enter a valid choice";
            goto main_page;

        }
        flag =1;
    }while(processe.StringChoise!=4 && flag == 0);


}













