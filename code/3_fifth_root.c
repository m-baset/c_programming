#include <stdio.h>
#include <math.h>
// #include<conio.h>

int roundoff(long double);
long double power(long double,long double);
long double cal(long double num, long double p);

long double cal(long double num, long double p)
{
    long double i, answer, counter = 1, z = 0.0000001, ans;
    for (i = 0; i < num; i = i + z)
    {
        if ((power(i, power(10, counter))) > num)
        {
            i = i - z;
            break;
        }
    }
    p = (p * power(10, counter));
    p = roundoff(p);
    answer = power(i, p);
    return answer;
}

int roundoff(long double num)
{
    long double limit;
    limit = (int)num + 0.5;
    if (num > limit){
        return ((int)num + 1);
    }
    else{
        return ((int)num);
    }
}

long double power(long double num, long double i)
{

    long double j;
    long double product = 1;

    for (j = 0; j < i; j++)
    {
        product *= num;
    }
    return product;
}

int main()
{
    long double num, p, a, b, pi, pf, answer;
    // clrscr();
    printf("ENTER ANY NUMBER : ");
    scanf("%Lf", &num);

    // printf("ENTER THE POWER : ");
    // scanf("%Lf", &p);
    p = 0.2;
    pi = (int)p;
    pf = p - pi;

    a = cal(num, pf);
    b = power(num, pi);

    answer = a * b;

    printf("my answer= %Lf\n"
           "correct answer = %f\n",
           answer, pow((double)num, (double)p));
    // getch();
    return 1;
}