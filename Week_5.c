#include <stdio.h>
char input[100];
int i, error;

int main()
{
    printf("Recursive descent parsing for grammar\n");
    printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n\n");
    gets(input);
    E();

    if (input[i] == '\0' && error == 0)
        printf("string is Accepted");
    else
        printf("String rejected");
}
E()
{
    T();
    Eds();
}
T()
{
    F();
    Tds();
}
Eds()
{
    if (input[i] == '+')
    {
        i++;
        E();
    }
}
Tds()
{
    if (input[i] == '*')
    {
        i++;
        T();
    }
}
F()
{
    if (input[i] == '(')
    {
        i++;
        E();
        i++;
    }
    else if (input[i] == 'i')
        i++;

    else
        error = 1;
}
