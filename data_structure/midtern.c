#include<stdio.h>
int Factorial(int n){
    if(n == 0)
        return 1;
    else 
        return Factorial(n - 1) * n;
}

int Factor(int a, int b){
    if(b == 0)
        return a;
    else
        return Factor(b, a % b);
}

int main()
{
    int ans = Factorial(5);
    printf("%d", ans);

    int a = Factor(42,14);
    printf("\n%d", a);
}