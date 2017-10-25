#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

/*int inArray(int val, int *arr){
    int i;
    for (i=0; i < 26; i++) {
        if (arr[i] == val)
            return TRUE;
    }
    return FALSE;
}
*/

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
    if(location[1] == 4){
      location[1] = 0;
    } else {
    location[1] = location[1] + 1;
  } // else
    if(location[3] == 4){
      location[3] = 0;
    } else {
      location[3] = location[3] + 1;
    } // else

  } else if(location[1] == location[3]){
    // shift right
    if(location[0] == 4){
      location[0] = 0;
    } else {
    location[0] = location[0] + 1;
  } // else
    if(location[2] == 4){
      location[2] = 0;
    } else {
      location[2] = location[2] + 1;
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
  while(counter != 25){ // trying not to use two for loops, even though it is the same speed
    if(letter!= 74){
      if(counter % 5 == 0 && counter != 0){
        j++;
        i = 0;
      } else {
        if(counter != 0){
          i++;
        } // if
      } // else
        grid[i][j] = letter;
        //printf("%c\n", grid[i][j]);
        letter++;
        counter++;
    } else {
      letter++;
    } // else
  }// while
int count = 0;
//char* da = encrypt('T','Y',grid);
char* el = malloc(sizeof(char) * 2);
char* result;
FILE *fp = fopen("encrypted.txt","w+");
while(scanf("%c", &c) != EOF){
  //if(c != 32 && c != 10){ // if you type space it will stop the program.
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

  /*left[counter] = letter;
  letter++;
  printf("%c\n",left[counter]);
  counter++;
  */

/*if(inArray(,*left) == 1){
  printf("We found it!!");
}*/

/* maybe if I had more time
while(count != 0){
  int num = 97+(rand()%26);
  //printf("%d\n",num);
  if(letter != 106){ // if a is equal to
    //if()
  }
  letter++;
  count--;
}
*/
} // main
