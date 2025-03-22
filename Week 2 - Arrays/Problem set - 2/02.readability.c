// readability.c
// This program calculates the readability grade of a given text based on the Coleman-Liau index.
// It counts the number of letters, words, and sentences in the text and computes the grade level.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Function prototypes
int count_letter(string text);
int count_word(string text);
int count_sentence(string text);
int calculate_grade(int letter, int word, int sentence);

int main(void)
{
    // Get input text from the user
    string text = get_string("Text: ");

    // Count letters, words, and sentences in the text
    int countLetter = count_letter(text);
    int countWord = count_word(text);
    int countSentence = count_sentence(text);

    // Calculate the readability grade
    int grade = calculate_grade(countLetter, countWord, countSentence);

    // Print the grade level
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

// Function to count the number of letters in the text
int count_letter(string text)
{
    int letter_count = 0;

    // Iterate through each character in the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if the character is a letter
        if (isalpha(text[i]))
        {
            letter_count++;
        };
    };

    return letter_count;
}

// Function to count the number of words in the text
int count_word(string text)
{
    int word_count = 0;

    // Iterate through each character in the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if the character is a space (indicating a new word)
        if (isspace(text[i]))
        {
            word_count++;
        };
    };

    // Add one to account for the last word
    return word_count + 1;
}

// Function to count the number of sentences in the text
int count_sentence(string text)
{
    int sentence_count = 0;

    // Iterate through each character in the text
    for (int i = 0; i < strlen(text); i++)
    {
        // Check if the character is a sentence-ending punctuation mark
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        };
    };

    // Ensure there is at least one sentence
    if(sentence_count != 0)
    {
        return sentence_count;
    }
    else
    {
        return 1;
    }
}

// Function to calculate the readability grade using the Coleman-Liau index
int calculate_grade(int letter, int word, int sentence)
{
    // Calculate the average number of letters and sentences per 100 words
    float L = (letter / (float)word) * 100;
    float S = (sentence / (float)word) * 100;

    // Compute the Coleman-Liau index
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    // Round the index to the nearest whole number to get the grade level
    int grade = round(index);

    return grade;
}
