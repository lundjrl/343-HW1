#include <sys/stat.h>
#include <stdio.h>
#include "file_utils.h"


/************************************************************
 *Function will reverse the contents of an input file and 
 *use functions within file_utils.h to print the input file
 *backwards into an output file.
 *
 *
 *@author James Lund
 *@version September2018
 ***********************************************************/
int main(int argc, char ** argv){
	char* input = argv[1]; //filename
	char* output = argv[2];
	
	char* buffer;
	int size =0;
	//Setting size to equal the size of our inputted file
	size = read_file(input, &buffer);
	//allocating memory for our array
	char* backwards = (char*)malloc(size * sizeof(char));
	for (int i =0; i< size; i++){
	  //array starts backwards and works towards the start
	  backwards[size-1 -i] = buffer[i];
	}
	
	//passing output file, reversed file (backwards) and size of file
	write_file(output, backwards, size);

	//Freeing up memory we barrowed
	free(buffer);
	free(backwards);
	return 0;
} 
	
