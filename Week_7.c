#include <stdio.h>
#include <string.h>
void main()
{
    char input[7] = "ccdd$", m[8][6][3] = {" ", "c", "d", "$", "S", "C",
                                           "0", "s3", "s4", "_", "1", "2",
                                           "1", "_", "_", "ac", "_", "_",
                                           "2", "s3", "s4", "_", "_", "5",
                                           "3", "s3", "s4", "_", "_", "8",
                                           "4", "r3", "r3", "r3", "_", "_",
                                           "5", "_", "_", "r1", "_", "_",
                                           "8", "r2", "r2", "r2", "_", "_"};

    char stack[10], action[5];
    char rp[5];
    char x, a, rx, ra, ch;
    int i, inp = 0, top = 0, xp, ap, rxp, rap, count = 0;
    stack[top] = '0';
    do
    {
        a = input[inp];
        x = stack[top];
        for (i = 0; i < 6; i++)
        {
            if (a == m[0][i][0])
            {
                ap = i;
                break;
            }
        }
        for (i = 0; i < 8; i++)
        {
            if (x == m[i][0][0])
            {
                xp = i;
                break;
            }
        }
        for (i = 0; i < 2; i++)
        {
            action[i] = m[xp][ap][i];
        }
        action[i] = '\0';
        if (action[0] == 'a')
        {
            printf("\n");
            for (i = 0; i <= top; i++)
            {
                printf("%c", stack[i]);
            }
            printf("\t");
            for (i = inp; i < 6; i++)
            {
                printf("%c", input[i]);
            }
            printf("\t%s", action);
            break;
        }
        else if (action[0] == '_')
        {
            printf("rejected");
            break;
        }
        else if (action[0] == 's')
        {

            printf("\n");
            for (i = 0; i <= top; i++)
                printf("%c", stack[i]);
            printf("\t");
            for (i = inp; i < 6; i++)
                printf("%c", input[i]);
            printf("\t%s", action);
            top++;
            stack[top] = input[inp];
            inp++;
            top++;
            stack[top] = action[1];
        }
        else if (action[0] == 'r')
        {
            printf("\n");
            for (i = 0; i <= top; i++)
                printf("%c", stack[i]);
            printf("\t");
            for (i = inp; i < 6; i++)
                printf("%c", input[i]);
            printf("\t%s", action);
            ch = action[1];
            switch (ch)
            {
            case '1':
                strcpy(rp, "S->CC");
                break;
            case '2':
                strcpy(rp, "C->cC ");
                break;
            case '3':
                strcpy(rp, "C->d");
                break;
            default:
                printf("product not found");
            }
            printf("**%s**", rp);
            for (i = 3; rp[i] != '\0'; i++)
            {
                count++;
            }
            for (i = 1; i <= count * 2; i++)
            {
                stack[top] = ' ';
                top--;
            }
            top++;
            stack[top] = rp[0];
            strcpy(rp, " ");
            count = 0;
            ra = stack[top];
            rx = stack[top - 1];
            for (i = 0; i < 6; i++)
            {
                if (ra == m[0][i][0])
                {
                    rap = i;

                    break;
                }
            }
            for (i = 0; i < 8; i++)
            {
                if (rx == m[i][0][0])
                {
                    rxp = i;
                    break;
                }
            }
            top++;
            stack[top] = m[rxp][rap][0];
        }
    } while (!(strcmp(action, "ac") == 0));
    // printf("\n%c",input[inp]);
    if ((input[inp] == '$') && (strcmp(action, "ac") == 0))
    {
        printf("\naccepted");
    }
    else
    {
        printf("\nnot accepted");
    }
}
