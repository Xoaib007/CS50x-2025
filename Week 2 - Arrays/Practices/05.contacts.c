#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name: ");
    long number = get_long("Number: ");
    int age = get_int("Age: ");

    printf("Are you sure you want to submit\nName: %s\nNumber: %li\nAge: %i", name, number, age);
}
