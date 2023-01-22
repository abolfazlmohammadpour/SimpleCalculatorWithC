#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, const char *argv[])
{
    unsigned char *NumberOne = ((unsigned char *)calloc(16, sizeof(unsigned char)));
    unsigned char *NumberTwo = ((unsigned char *)calloc(16, sizeof(unsigned char)));
    unsigned char *Operation = ((unsigned char *)calloc(1, sizeof(unsigned char)));

    puts("Welcome To Simple Calculator (Wrote By C Programming Language)");
    puts("In Windows Please Press (Ctrl+C)");
    puts("In Linux Please Press (Ctrl+C)");
    puts("In Mac Please Press (Command+C)");

    while (true)
    {
        // Get NumberOne Value From User
        while (true)
        {
            printf_s("%s", "Please Enter NumberOne : ");
            scanf_s("%s", NumberOne);

            if (strlen(NumberOne) > 16)
            {
                puts("Error : The Number Is So Larg.");
                continue;
            }

            bool IsNum = true;

            for (unsigned short int Counter = 0; Counter < strlen(NumberOne); Counter++)
            {
                if (!(isdigit((*(NumberOne + Counter)))))
                {
                    IsNum = false;
                    break;
                }
            }

            if (IsNum)
            {
                break;
            }
            else
            {
                puts("Error : Please Enter A Number (A Number Is Cantain (1234567890)). Please Try Again.");
                continue;
            }
        }

        // Get NumberTwo Value From User
        while (true)
        {
            printf_s("%s", "Please Enter NumberTwo : ");
            scanf_s("%s", NumberTwo);

            if (strlen(NumberTwo) > 16)
            {
                puts("Error : The Number Is So Larg.");
                continue;
            }

            bool IsNum = true;

            for (unsigned short int Counter = 0; Counter < strlen(NumberTwo); Counter++)
            {
                if (!(isdigit((*(NumberTwo + Counter)))))
                {
                    IsNum = false;
                    break;
                }
            }

            if (IsNum)
            {
                break;
            }
            else
            {
                puts("Error : Please Enter A Number (A Number Is Cantain (1234567890)). Please Try Again.");
                continue;
            }
        }

        // Get Operation From User
        while (true)
        {
            puts("1) Sum");
            puts("2) Subtraction");
            puts("3) Multiplication");
            puts("4) Divide");
            printf_s("%s", "Please Enter Number Of Operation : ");
            scanf("%s", Operation);

            if (strlen(Operation) > 1)
            {
                puts("Error : The Number Is So Larg.");
                continue;
            }

            bool IsNum = true;

            for (unsigned short int Counter = 0; Counter < strlen(Operation); Counter++)
            {
                if (!(isdigit((*(Operation + Counter)))))
                {
                    IsNum = false;
                    break;
                }
            }

            if (IsNum)
            {
                if ((atoi(Operation) < 1) || (atoi(Operation) > 4))
                {
                    puts("Error : The Selected Operation Not Valid. Please Try Again.");
                    continue;
                }
                else
                {
                    break;
                }
            }
            else
            {
                puts("Error : Please Enter A Number (A Number Is Cantain (1234567890)). Please Try Again.");
                continue;
            }
        }

        // Print Total Of User's Selected Operation
        switch (atoi(Operation))
        {
        case 1:
        {
            printf("%s%lld%c", "Sum Is : ", (atoll(NumberOne) + atoll(NumberTwo)), '\n');

            break;
        }
        case 2:
        {
            printf("%s%lld%c", "Subtraction Is : ", (atoll(NumberOne) - atoll(NumberTwo)), '\n');

            break;
        }
        case 3:
        {
            printf("%s%lld%c", "Multiplication Is : ", (atoll(NumberOne) * atoll(NumberTwo)), '\n');

            break;
        }
        case 4:
        {
            if (atoll(NumberTwo) == 0)
            {
                puts("Error : We Can't Divide A Number To Zero. Please Try Again.");
            }
            else
            {
                printf("%s%lld%c", "Divide Is : ", (atoll(NumberOne) / atoll(NumberTwo)), '\n');
            }

            break;
        }
        }
    }

    return 0;
}