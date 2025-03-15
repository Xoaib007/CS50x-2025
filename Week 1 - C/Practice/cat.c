// Use of function and loop (including input validation using do-while)
#include <cs50.h> 
#include <stdio.h> 

void meow(int n); 

int main(void) 
{ 
  int n;
  do
  {
    n = get_int("Number: "); 
  }
  while (n < 1)
    
  meow(n); 
} 

void meow(int times) 
{ 
  for (int i = 0; i < times; i++) 
  { 
    printf("meow\n"); 
  } 
}
