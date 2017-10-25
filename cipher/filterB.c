#include <stdio.h>

#define FALSE 0
#define TRUE 1

int isLowercaseLetter(char c){
  if('a' <= c && c <= 'z'){
    return TRUE;
  } // if
  else {
    return FALSE;
  } // else
} // isLowercaseLetter(char)

int LowertoUpper(char c){
  c = c - 32;
}

int main(int argc, char **argv){
  char c;
  while(scanf("%c", &c) != EOF){
    if(isLowercaseLetter(c)){
      c = LowertoUpper(c);
      printf("%c", c);
    } // if Lower
    else{
      printf("%c",c);
    } // else
  } // while
} // main(int, char**)
