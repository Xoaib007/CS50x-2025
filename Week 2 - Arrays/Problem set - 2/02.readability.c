#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int count_letter(string text);
int count_word(string text);
int count_sentence(string text);
int calculate_grade(int letter, int word, int sentence);

int main(void)
{
    string text = get_string("Text: ");

    int countLetter = count_letter(text);
    int countWord = count_word(text);
    int countSentence = count_sentence(text);

    int grade = calculate_grade(countLetter, countWord, countSentence);

    if(grade >= 1 && grade <= 16)
    {
        printf("Grade %i\n", grade);
    }
    else if(grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if(grade < 1)
    {
        printf("Before Grade 1\n");
    }
}

int count_letter(string text)
{
    int letter_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        };
    };

    return letter_count;
}

int count_word(string text)
{
    int word_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            word_count++;
        };
    };

    return word_count + 1;
}

int count_sentence(string text)
{
    int sentence_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        };
    };

    if(sentence_count != 0)
    {
        return sentence_count;
    }
    else
    {
        return 1;
    }
}

int calculate_grade(int letter, int word, int sentence)
{
    float L = (letter / (float)word) * 100;
    float S = (sentence / (float)word) * 100;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    int grade = round(index);

    return grade;
}
