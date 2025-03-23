#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
    string email;
}
person;

int main(void)
{
    // person people[3];

    // people[0].name = "John";
    // people[1].name = "John";
    // people[2].name = "John";

    // people[0] = {"John", "39-3486925084", "john@email.com"};
    // people[1] = {"David","39-3486925085", "david@email.com" };
    // people[2] = {"Muller", "39-3486925086","muller@email.com" };

    person people[] = {
        {"John", "39-3486925084", "john@email.com"},
        {"David","39-3486925085", "david@email.com" },
        {"Muller", "39-3486925086","muller@email.com" }
    };

    string name[] = {"John", "David", "Muller"};
    string number[] = {"39-3486925084","39-3486925085","39-3486925086"};
    string email[] = {"john@email.com","david@email.com","muller@email.com"};

    string searchName = get_string("Search name: ");

    for(int i = 0 ; i < 3; i++)
    {
        if(strcmp(people[i].name,searchName) == 0)
        {
            printf("Number: %s \nEmail: %s \n", people[i].number, people[i].email);
            return 0;
        }
    }
    printf("Sorry, this person doesnt exist in your contact-book. \n");

}
