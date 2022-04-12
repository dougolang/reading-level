//Determine the grade level needed to comprehend the text input
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int count_sentences(string text);
int count_letters(string text);
int count_words(string text);
int main()

{
     string usertext = get_string("Text: ");
     int numLetters = count_letters(usertext);
     int numWords = count_words(usertext);
     int numSentences = count_sentences(usertext);
     double s = (float)numSentences / numWords * 100.00000;
     double l = (float)numLetters / numWords * 100.00000;
     double index = (.05880 * l) - (.29600 * s) - 15.80000;
     int graderounded = round(index);
     
     if (graderounded < 1)
        {
            printf("Before Grade 1\n");
        }
      else if (graderounded > 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
        printf("Grade %d\n", graderounded);
        }
}
    //function to count letters of get_string
int count_letters(string text)
{
    int len = strlen(text);
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++;   
        }
    }
    return count;
}

    //function to count words of get_string
int count_words(string text)
{
    int len = strlen(text);
    int count = 1;

    for (int i = 0; i < len; i++)
    {
        if (isspace(text[i]))
        {
            count++;   
        }
    }
    return count;
}

    //function to count sentences based on . ! ? chars
int count_sentences(string text)
{
    int len = strlen(text);
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;   
        }
    }
    return count;
}