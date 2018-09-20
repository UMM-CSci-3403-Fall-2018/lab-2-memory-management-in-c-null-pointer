#include <stdlib.h>

#include <string.h>
#include "disemvowel.h"

bool isVowel(char letter) {
  if(letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' ||
     letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ){
    return true;
  }
  else {
    return false;
  }
}

int countVowel(char *str) {
  int count = 0;
  for(unsigned int i = 0; i < strlen(str); i++){
    if(isVowel(str[i])){
        count++;
    }
  }
  return count;
}


char *disemvowel(char *str) {
  char *result = (char*) calloc(strlen(str) - countVowel(str), sizeof(char));
  int resultIndex = 0;
  for(unsigned int i = 0; i < strlen(str); i++){
	if(!isVowel(str[i])){
		result[resultIndex] += str[i];
		resultIndex++;
	}
  }
  result[resultIndex] = '\0';
  return result;
}
