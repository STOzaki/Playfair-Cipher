#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int* search(char let0, char let1, char grid[5][5]){
  int* locations = malloc(sizeof(int) * 4);
  for(int i = 0; i < 5; i++){ // goes through each row
    for(int j = 0; j < 5; j++){ // goes through each colum
      if(grid[j][i] == let0){
        locations[0] = j;
        locations[1] = i;
      }
      if(grid[j][i] == let1){
        locations[2] = j;
        locations[3] = i;
      }
    }
  }
  return locations;
}

char* encrypt(char char1, char char2, char grid[5][5]){
  int* location = search(char1,char2,grid);
  char* flip = malloc(sizeof(char) * 2);
  if(location[0] == location[2]){ // if they are on the same column
    // shift down
    if(location[1] == 4){ // if the letter is at the bottom
      location[1] = 0; // move to the top
    } else {
    location[1] = location[1] + 1;
  } // else
    if(location[3] == 4){ // if the letter is at the bottom
      location[3] = 0; // move to the top
    } else {
      location[3] = location[3] + 1;
    } // else

  } else if(location[1] == location[3]){ // if the are on the same row
    // shift right
    if(location[0] == 4){ // if the letter is at the bottom
      location[0] = 0; // move to the top
    } else {
    location[0] = location[0] + 1;
  } // else
    if(location[2] == 4){ // if the letter is at the bottom
      location[2] = 0; // move to the top
    } else {
      location[2] = location[2] + 1;
    }
  } else { // flip char1 and char2
    int tem = location[0]; // temporarily store location[0]
    // the code below simply switches columns
    location[0] = location[2];
    location[2] = tem;
  } // else
  flip[0] = grid[location[0]][location[1]];
  flip[1] = grid[location[2]][location[3]];
  free(location);
  return flip;
}

void listing(char grid[5][5]){ // this was used to debug by iterating throught the matrix
  for(int i = 0; i < 5; i++){
    for(int j = 0 ; j < 5; j++){
      printf("%c\n", grid[j][i]);
    } // for (j)
  } // for (i)
} // listing


int main(int argc, char **argv){
  char c;
  char grid [5][5];
  char left[26];
  int counter = 0; // counts how many letters
  int i = 0; // column
  int j = 0; // row
  char letter = 'A';
  while(counter != 25){ // creating a matrix with all letters except J
    if(letter!= 74){
      if(counter % 5 == 0 && counter != 0){ // once we reach the end of the row, start on a new row
        j++;
        i = 0;
      } else {
        if(counter != 0){
          i++;
        } // if
      } // else
        grid[i][j] = letter;
        letter++;
        counter++;
    } else {
      letter++;
    } // else
  }// while
int count = 0;
char* el = malloc(sizeof(char) * 2);
char* result;
FILE *fp = fopen("encrypted.txt","w+");
while(scanf("%c", &c) != EOF){
    if(count % 2 == 1 && count != 0){
      el[1] = c;
      result = encrypt(el[0],el[1],grid);
      fprintf(fp,"%c", result[0]);
      fprintf(fp,"%c", result[1]);
    } else {
      el[0] = c;
    } // else
    count++;
} // while
free(el);
free(result);
fclose(fp);
} // main
