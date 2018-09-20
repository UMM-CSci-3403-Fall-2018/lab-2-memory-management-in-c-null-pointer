#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char *argv[]) {
  char *line;
  int size;
  
  size = 100;
  line = (char*) calloc (size + 1, sizeof(char));

  // fgets reads a line from stdin (usually the keyboard)
  // and returns it in the buffer passed as the first argument
  // (line here). If there's no more input to read from, it
  // returns NULL.
  while (fgets(line, size, stdin) != NULL) {
    // This crazy line removes the '\n' at the end of the input line.
    // Without it, nothing will ever be a palindrome, unless it happens
    // to somehow start with a '\n'.
    line[strcspn(line, "\n")] = '\0';


    // We need to free the memory from the palindrome call after printing since we no longer need it.
    // To do this we will assign it a variable to free after the print statement is finished.
    char *palin = palindrome(line);
    printf("Is the string <%s> a palindrome? %s\n", line, palin);
    
    // Palin is no longer needed, as we printed it out, so we free it.
    free(palin);
  }

  free(line);
}
