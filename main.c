#include "memalloc.c"
#include "stdio.h"

void testSimpleMemalloc() {
	printf("--Simple Memalloc Test Start--\n");
	int *new_int = memalloc(sizeof(int));
	if (sizeof(*new_int) == sizeof(int)) {
		printf("Simple Memalloc Test Passed!\n");
	} else {
		printf("Simple Memalloc Test Failed!\n");
	}
	memfree(new_int);
	printf("--Simple Memalloc Test End--\n");
}

void testContalloc() {
	printf("--Contalloc Test Start--\n");
	int *new_array = contalloc(sizeof(int), 10);
	int num_elements = 0;
	for (int i = 0; i < 10; i++) {
		new_array[i] = i;
		num_elements++;
	}
	if (num_elements == 10) {
		printf("Contalloc Test Passed!\n");
	} else {
		printf("Contalloc Test Failed!\n");
	}
	memfree(new_array);
	printf("--Contalloc Test End--\n");
}

void testResizealloc() {
	printf("--Resizealloc Test Start--\n");
	int *new_int = memalloc(sizeof(int));
	double *new_double = resizealloc(new_int, sizeof(double));
	new_int = NULL;
	if (sizeof(*new_double) == sizeof(double)) {
		printf("Resizealloc Test Passed!\n");
	} else {
		printf("Resizealloc Test Failed!\n");
	}
	memfree(new_double);
	printf("--Resizealloc Test End--\n");
}

int main(void) {
	testSimpleMemalloc();
	testContalloc();
	testResizealloc();
	return 0;
} 
