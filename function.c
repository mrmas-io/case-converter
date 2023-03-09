//
// Created by mrmas.io on 3.03.2023.
//

#ifndef CASE_CONVERTER_FUNCTION_H
#define CASE_CONVERTER_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define BUFFSIZE 4096
#define CTRLKEY(key) ((key) & 0x1f)
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__MINGW64__)
#include <windows.h>
#include <conio.h>
#else
#include <unistd.h>
#include <termios.h>
int getch()
{//getch function for unix system.
    struct termios old_tio, new_tio;
    int c;

    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    c = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    return c;
}
#endif

void Sentence_case();
void lower_case();
void UPPER_CASE();
void Capitalized_Case();
void aLtErNaTiNg_cAsE();
void InVeRsE_CaSe();

bool isuppercase(char ch)
{
    if(ch >= 65 && ch <= 90)
    {
        return true;
    }
    else{
        return false;
    }
}
bool islowercase(char ch)
{
    if(ch >= 97 && ch <= 122)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isalphabet(char ch)
{
    if ((ch <= 65 && ch >= 90) || (ch <= 97 && ch >= 122))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isalphanum(char ch)
{
    if ((ch <= 65 && ch >= 90) || (ch <= 97 && ch >= 122) || (ch <= 48 && ch >= 57))
    {
        return true;
    }
    else
    {
        return false;
    }    
}
char tolowercase(char ch)
{
    if(ch >= 65 && ch <= 90)
    {
        ch += 32;
    }
    return ch;
}
char touppercase(char ch)
{
    if(ch >= 97 && ch <= 122)
    {
        ch -= 32;
    }
    return ch;
}
#endif //CASE_CONVERTER_FUNCTION_H