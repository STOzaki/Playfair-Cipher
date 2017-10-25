#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int* search(char let0, char let1, char grid[5][5]){ // finds the row and column of 2 chars
  int* locations = malloc(sizeof(int) * 4);
  for(int i = 0; i < 5; i++){ // goes through each row
    for(int j = 0; j < 5; j++){ // goes through each colum
      if(grid[j][i] == let0){
        locations[0] = j; // column of let0
        locations[1] = i; // row of let0
      }
      if(grid[j][i] == let1){
        locations[2] = j; // column of let1
        locations[3] = i; // row of let1
      }
    }
  }
  return locations;
}

char* decrypt(char char1, char char2, char grid[5][5]){ // runs the playfair cipher on char1 and char2 using the key grid
  int* location = search(char1,char2,grid); // finds the locations of char1 and char2
  char* flip = malloc(sizeof(char) * 2);
  if(location[0] == location[2]){ // if they are on the same column
    // shift up
    if(location[1] == 0){ // if the letter is at the top
      location[1] = 4; // move it to the bottom
    } else { // otherwise
    location[1] = location[1] - 1; // move up
    } // else
    if(location[3] == 0){ // if char1 is located on the top of the matrix
      location[3] = 4; // put at the bottom
    } else {
      location[3] = location[3] - 1;
    } // else

  } else if(location[1] == location[3]){ // if they are on the same row
    // shift left
    if(location[0] == 0){ // if it to the edge of matrix
      location[0] = 4;
    } else {
    location[0] = location[0] - 1;
  } // else
    if(location[2] == 0){
      location[2] = 4;
    } else {
      location[2] = location[2] - 1;
    }
  } else { // flip char1 and char2
    int tem = location[0]; // temporarily store location[0]
    location[0] = location[2];
    location[2] = tem; // give location[2] location[0]'s value
  } // else
  flip[0] = grid[location[0]][location[1]];
  flip[1] = grid[location[2]][location[3]];
  free(location);
  return flip;
}

void listing(char grid[5][5]){
  for(int i = 0; i < 5; i++){
    for(int j = 0 ; j < 5; j++){
      printf("%c\n", grid[j][i]);
    } // for (j)
  } // for (i)
}


int main(int argc, char **argv){
  char c;
  char grid [5][5];
  char left[26];
  int counter = 0; // counts how many letters
  int i = 0; // column
  int j = 0; // row
  char letter = 'A';
  while(counter != 25){ // generates an matrix with every letter except J
    if(letter!= 74){ // if the letter is J, then skip over it
      if(counter % 5 == 0 && counter != 0){
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
FILE *fp = fopen("decrypted.txt","w+");
while(scanf("%c", &c) != EOF){
    if(count % 2 == 1 && count != 0){ // if you have a pair
      el[1] = c;
      result = decrypt(el[0],el[1],grid); // use the playfair cipher
      fprintf(fp,"%c", result[0]); // write to file the first decrypted letter
      fprintf(fp,"%c", result[1]); // write to file the second decrypted letter
    } else {
      el[0] = c;
    } // else
    count++;
} // while
free(el);
free(result);
fclose(fp);
} // main
