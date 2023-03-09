#include "function.c"

int main()//(int argc, char const *argv[])
{
    int choice;
    printf("\t\t \t \t CASE CONVERTER \n");
    
    printf("\n \t 1. Sentence case    \t 2. lower case       \t 3. UPPER CASE \n");
    printf("\n \t 4. Capitalized Case \t 5. aLtErNaTiNg cAsE \t 6. InVeRsE CaSe\n");
    
    printf("\n >> Select an option : ");
    
    menu:
    switch (getch())
    {
    case '1':
        Sentence_case();
        break;
    case '2':
        lower_case();
        break;
    case '3':
        UPPER_CASE();
        break;
    case '4':
        Capitalized_Case();
        break;
    case '5':
        aLtErNaTiNg_cAsE();
        break;
    case '6':
        InVeRsE_CaSe();
        break;
    case CTRLKEY('c'):
        exit(0);
    default:
        goto menu;
    }
    return 0;
}

void Sentence_case()
{
    char string[BUFFSIZE];
    int index = 0;

    printf("\n\n ~> Enter string to convert to Uppercase : ");
    fgets(string, BUFFSIZE, stdin);
    string[strcspn(string, "\n")] = '\0';

    if (islowercase(string[index]))
    {
        string[index] = touppercase(string[index]);
    }
    index += 1;
    while(string[index] != '\0')
    {
        if (isuppercase(string[index]))
        {
            string[index] = tolowercase(string[index]);
        }
        index += 1;
    }
    printf("\n ~> %s", string);
}

void lower_case()
{
    char string[BUFFSIZE];
    int index = 0;

    printf("\n ~> Enter string to convert to lowercase : ");
    fgets(string, BUFFSIZE, stdin);
    string[strcspn(string, "\n")] = '\0';

    while(string[index] != '\0')
    {
        if (isuppercase(string[index]))
        {
            string[index] = tolowercase(string[index]);
        }
        index += 1;
    }
    printf("\n ~> %s", string);
}

void UPPER_CASE()
{
    char string[BUFFSIZE];
    int index = 0;

    printf("\n ~> Enter string to convert to UPPERCASE : ");
    fgets(string, BUFFSIZE, stdin);
    string[strcspn(string, "\n")] = '\0';

    while(string[index] != '\0')
    {
        if (islowercase(string[index]))
        {
            string[index] = touppercase(string[index]);
        }
        index += 1;
    }
    printf("\n ~> %s", string);
}

void Capitalized_Case()
{
    char string[BUFFSIZE];
    int index = 0;

    printf("\n ~> Enter string to capitalize the cases : ");
    fgets(string, BUFFSIZE, stdin);
    string[strcspn(string, "\n")] = '\0';

    if (islowercase(string[index]))
    {
        string[index] = touppercase(string[index]);
    }
    index++;

    while(string[index] != '\0')
    {
        if (string[index - 1] == ' ' && islowercase(string[index]))
        {
            string[index] = touppercase(string[index]);
        }
        else
        {
            string[index] = tolowercase(string[index]);
        }
        index++;
    }
    printf("\n ~> %s", string);
}

void aLtErNaTiNg_cAsE()
{
    char string[BUFFSIZE];
    int index = 0;

    printf("\n\n ~> Enter string to convert to aLtErNaTiNg CaSe : ");
    fgets(string, BUFFSIZE, stdin);
    string[strcspn(string, "\n")] = '\0';

    while(string[index] != '\0')
    {
        if(string[index] == ' ')
        {
            index += 1;
            continue;
        }
        if (index % 2 == 0)
        {
            string[index] = tolowercase(string[index]);
        }
        else
        {
            string[index] = touppercase(string[index]);
        }
        index += 1;
    }
    printf("\n ~> %s", string);
}

void InVeRsE_CaSe()
{
    char string[BUFFSIZE];
    int index = 0;

    printf("\n\n ~> Enter string to Invert the case : ");
    fgets(string, BUFFSIZE, stdin);
    string[strcspn(string, "\n")] = '\0';

    while(string[index] != '\0')
    {
        if (isuppercase(string[index]))
        {
            string[index] = tolowercase(string[index]);
        }
        else
        {
            string[index] = touppercase(string[index]);
        }
        index += 1;
    }
    printf("\n ~> %s", string);
}