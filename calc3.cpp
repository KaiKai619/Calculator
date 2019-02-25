#include <iostream>
using namespace std;
int get_number()
{
    // read the number
    int num ;
    cin >> num ;

    // read the next character
    char s ;
    cin.get(s) ;

    // if the next character is ^, square the number
    if( s == '^' ) num = num * num ;

    // otherwise, don't consume s: put it back
    else cin.putback(s) ;

    return num ;
}

bool equation() // return true if an expression was evaluated
{
    int result = get_number() ; // initial result is the first number

    char oper ;
    while( cin >> oper && oper != ';' ) // till a ; is encountered
    {
        const int operand = get_number() ; // read in the operand

        switch(oper)
        {
            case '+' : result += operand ; break ;
            case '-' : result -= operand ; break ;
            case '*' : result *= operand ; break ;
            
        }
    }

    // if an expression was read, print the result
    if( cin ) cout << result << '\n' ;

    return cin.good() ; // return true if expression input was successful
}

int main()
{
    // keep evaluating expressions one by one
    // till there is no more input that can be read
    do cout << "enter equation: " ;
    while( equation() ) ;
}