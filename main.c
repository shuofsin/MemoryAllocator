#include "memalloc.c"
#include "stdio.h"

int testSimpleMemalloc() {
	int *new_int = memalloc(sizeof(int));
	memfree(new_int);
	return 1;
}

int main(void) {
	if (testSimpleMemalloc()) 
		printf("Simple test passed!\n");
	else
		printf("Simple test failed!\n");
	
	return 0;
} 
