#include <stdio.h>
#include <sys/stat.h>
#include "file_utils.h"

/************************************************************************
 *File_Utilities is a C file that reads other files and writes said file
 *It is the implementation file to file_utils.h and uses pointers to
 *pass values and information to the heap to dynamically allocate memory.
 *
 * @author James Lund
 * @version September2018
 ************************************************************************/

/*************************************************************************
 *Function reads contents of an inputted file using memory from the heap
 *and putting each character from the file into an array.
 *
 *@param pointer and pointer to a pointer
 ************************************************************************/
 int read_file(char* filename, char **buffer){
  //These next three lines of code find out the size of a file
  struct stat st;
  stat(filename, &st);
  int size = st.st_size;

  char ch;
  //Manually allocating memory in the heap to read our inputted file
  char* readFile = (char*)malloc(size * sizeof(char));
  FILE *file = fopen(filename, "r");

  //loop reads every character of the inputted file until the end
  int i =0;
  while (!feof(file)){
    fscanf(file, "%c", &ch);
    readFile[i] = ch;
    printf("%c", readFile[i]);
    i++;
  }
  *buffer = readFile;
  return size;
}

/**************************************************************************
 *Function writes contents read from read_file() to a new file "output.txt"
 *
 *@param pointers and integer size
 ************************************************************************/
int write_file(char* filename, char *buffer, int size){
  FILE *out = fopen(filename, "w");
  //loop adds each character from the file into an array, then prints the array
  for(int i =0; i< size; i++){
    //buffer is the array that contains the contents of the file from read()
    fprintf(out, "%c",buffer[i]);
  }
  fclose(out);
  return 0;
}
