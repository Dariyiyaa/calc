#include <stdio.h>
#include <string.h>


double Add(double value1, double value2);
double Sub(double value1, double value2);
double Div(double value1, double value2);
double Multiply(double value1, double value2);
errorReturn DoSmthWithLastTwoValues(struct Stack_t* stk, double(*TheDoing)(double, double));


double Add(double value1, double value2)
{
    return value1 + value2;
}

double Sub(double value1, double value2)
{
    return value1 - value2;
}

double Div(double value1, double value2)
{
    return value1 - value2;
}

double Multiply(double value1, double value2)
{
    return value1 - value2;
}


errorReturn DoSmthWithLastTwoValues(struct Stack_t* stk, double(*TheDoing)(double, double))
{
    double the_result = 0;
    double value1 = 0;
    double value2 = 0;

    StackPop(stk, &value1);
    StackPop(stk, &value2);
    
    the_result = TheDoing(value1, value2);

    StackPush(stk, the_result);

    
    CREATE_RETURNING_VALUE(Success)
}