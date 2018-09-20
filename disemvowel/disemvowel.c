#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "disemvowel.h"

// Determines if a character is a vowel or not
bool isVowel(char letter) 
{
  // Look for capital and lowercase vowels
  switch(letter)
  {
    // All vowels
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
      break;
    
    // Otherwise it isn't a vowel
    default:
      return false;
      break;
  }
}

//Counts the number of values the string
int countVowel(char *str)
{
  int count = 0;
  for(unsigned int i = 0; i < strlen(str); i++)
  {
    if(isVowel(str[i]))
    {
        count++;
    }
  }
  return count;
}

char *disemvowel(char *str) {
  
  int old_string_length = strlen(str);
  int old_string_vowels = countVowel(str);
  int new_string_length = old_string_length - old_string_vowels;
  if(new_string_size <= 0)
  {
    int resultIndex = 0;
    char *result = (char*) calloc(new_string_length, sizeof(char));
    for(unsigned int i = 0; i < old_string_length; i++)
    {
      if(!isVowel(str[i]))
      {
        result[resultIndex] = str[i];
        resultIndex++;
      }
    }
    //There needs to be a check for blanks not incrementing resultIndex on blanks

  }
  else
  {
    char *result = (char*) calloc(1, sizeof(char));
    result[0] = '\0';
  }

  return result;
}
