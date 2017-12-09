#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int main(int argc, char **argv){
  //takes in a string or a file and create a output that has the appropriate parameters to run the Play-fair Cipher on this string/file
  char c;
  char last = 0;
  int counter = 0;
  while(scanf("%c", &c) != EOF){
    if(c == 74){ // J or j, will convert to I
      c = 73;
    } // if
    if(last == c && last != 0){ // add X between duplicates
      counter++;
      printf("%c",'X');
    } // if
    last = c;
    printf("%c", c);
    counter++; // add for every letter
  } // while
  if(counter % 2 != 0){ //if there are an odd number of letters including Xs, then add an X
    printf("%c", 'X');
  } // if
} // main(int, char**)
