// This program takes user input for a name and a phone number, 
// then appends the data to a file called "phonebook.csv". 
// The program ensures the file can be opened and handles potential errors if it cannot.

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open the file "phonebook.csv" in append mode to add new entries
    FILE *file = fopen("phonebook.csv", "a"); // "a" mode appends data to the file
    if (file == NULL) // Check if the file was successfully opened
    {
        return 1; // Return 1 to indicate error if the file couldn't be opened
    }

    // Prompt the user to input a name
    char *name = get_string("Name: ");
    // Prompt the user to input a phone number
    char *number = get_string("Number: ");

    // Write the name and number to the file in CSV format
    fprintf(file, "%s,%s\n", name, number);

    // Close the file to ensure data is saved and resources are freed
    fclose(file);
}
