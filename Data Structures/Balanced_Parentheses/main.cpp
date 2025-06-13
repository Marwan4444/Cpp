#include <iostream>
#include<string>
#include<stack>

using namespace std;

/** when expressions are different (wrong) function return false **/
 bool arePair(char Start , char End)
{
    if(Start == '(' && End == ')')
    {
        return true;
    }
    else if(Start == '[' && End == ']')
    {
        return true;
    }
    else if(Start == '{' && End == '}')
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool areBalanced (string exp)
{
    stack<char> s;

    for(int counter =0; counter<exp.length();counter++)
    {

        if(exp[counter]=='(' || exp[counter]=='{' || exp[counter]=='[')
            {
                s.push(exp[counter]);
            }
        else if(exp[counter]==')' || exp[counter]=='}' || exp[counter]==']')
            {
                /**** if stack is empty this is wrong  ***/
                if(s.empty())
                   {
                       cout<<"Stack is empty \n";
                       return false;
                   }
                /*** expressions are  different this is wrong too ***/
                else if(!arePair(s.top() , exp[counter]))
                   {
                       cout<< "Expressions are not pair \n"; //  ((}]
                       return false;

                   }
                else
                   {
                        s.pop();
                   }
            }
    }

    if( s.empty())
    {
        cout<< "Expressions are balanced\n"; //     ({})
        return  true;
    }
    else
    {
        cout<< "Expressions are  not balanced\n"; //  {{()}
        return false;
    }

}

int main()
{
    string exp;
    cout<<"enter the expressions :";
    cin>>exp;
    areBalanced(exp);

    return 0;
}
