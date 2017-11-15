/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "print.h"

void
input_list_values(a2_sort *formal_list)
{
	int count;
	int list_item;
	int i;
	printf("enter the number of elements: \n");
	scanf("%d", &count);
	formal_list->count = count;
	printf("enter the list elements: \n");
		for(i = 0; i < count; i++)
		{	
		printf("\n enter the list[%d] element: \n", i+1);
		scanf("%d", &list_item);
		formal_list->list[i] = list_item;
		}
		

}

void
input_array_values(a2_matrix_mul *formal_array)
{
	int row1;
	int col1;
	int row2;
	int col2;
	int formal_first[100];
	int formal_second[100];
	int i,j;
	int z ,k = 0;
	printf("\n Enter the number of rows of first array: \n");
	scanf("%d", &row1);
	formal_array->row_first = row1;
	printf("\n Enter the number of columns of first array: \n");
	scanf("%d", &col1);
	formal_array->col_first = col1;
	for(i = 0; i < row1; i++)
	{
		for(j = 0; j < col1; j++)
		{
			printf("Enter the array_element: \n");
			scanf("%d", &formal_first[z]);
			formal_array->first[z] = formal_first[z];		
			z++;
		}
	}
	
	printf("\n Enter the number of rows of second array: \n");
	scanf("%d", &row2);
	formal_array->row_second = row2;
	printf("\n Enter the number of columns of second array: \n");
	scanf("%d", &col2);
	formal_array->col_second = col2;
	for(i = 0; i < row2; i++)
	{
		for(j = 0; j < col2; j++)
		{
			printf("Enter the array_element: \n");
			scanf("%d", &formal_second[k]);
			formal_array->second[k] = formal_second[k];
			k++;
		}
	}
	
	for(i = 0; i < row1*col1; i++)
	{
	
		printf("%d\t", formal_first[i]);
		printf("%d\t", formal_second[i]);
	}
}


void
morampudi_a2_1(char *host)
{
	CLIENT *clnt;
	enum clnt_stat retval_1;
	a2_echo result_1;
	a2_echo  echo_1_arg;
	a2_sort *formal_sorted_list;
	int formal_count;
	enum clnt_stat retval_2;
	a2_sort result_2;
	a2_sort  sort_1_arg;
	int list_count;
	enum clnt_stat retval_3;
	a2_path result_3;
	char *path_1_arg;
	int i;
	int count1;
	char entered_input[100];
	enum clnt_stat retval_4;
	a2_file_check result_4;
	a2_file_check  file_check_1_arg;
	char file_name[100];
	enum clnt_stat retval_5;
	a2_matrix_mul result_5;
	a2_matrix_mul  matrix_mul_1_arg;
	int result_matrix[100][100];
	a2_matrix_mul *formal_result;
	int row;
	int j;
	int z = 0;
	
#ifndef	DEBUG
	clnt = clnt_create (host, Morampudi_a2, a2Vers, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

do
{	
	printf("\n");
	printf("Please choose an option: \n");
	printf("1. Echo the Input\n");
	printf("2. Sort the list\n");
	printf("3. Output the Present working directory\n");
	printf("4. Check if a file is available\n");
	printf("5. Matrix Multiplication\n");
	printf("6. Exit\n");
	scanf("%d", &i);

     
     
	switch(i)
	{	
	

	case 1:
	
	printf("\n");
	printf("enter the input: \n");
	scanf("%s", &entered_input);
	strcpy(echo_1_arg.input, entered_input);
	retval_1 = echo_1(&echo_1_arg, &result_1, clnt);
	if (retval_1 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	else{
	printf("\n");
	printf("This is the result: %s \n", result_1.input);
	}
	break;

		
	case 2:
	input_list_values(&sort_1_arg);
	retval_2 = sort_1(&sort_1_arg, &result_2, clnt);
	if (retval_2 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	else{
	printf("Sorted List: \n");
	formal_sorted_list = &result_2;
	formal_count = formal_sorted_list->count;
	for(i = 0; i < formal_count; i++)
	{

	printf("\n : %d \n", formal_sorted_list->sorted_list[i]);

	}
	
	
	
	}
	break;
	
	
	case 3:
	retval_3 = path_1((void*)&path_1_arg, &result_3, clnt);
	if (retval_3 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	else
	{
	
	printf("This is the working directory: %s \n\n", result_3.pwd);
	printf("\n");
	
	}
	break;
	
	case 4:
	printf("\nEnter the Filename:\n");
	scanf("%s", &file_name);
	strcpy(file_check_1_arg.files, file_name);	
	retval_4 = file_check_1(&file_check_1_arg, &result_4, clnt);
	if (retval_4 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	else{
	
	printf("Requested file:  %s\n", result_4.files);
	}
	break;
	
	case 5:
	printf("Matrix Multiplication\n");
	input_array_values(&matrix_mul_1_arg);
	retval_5 = matrix_mul_1(&matrix_mul_1_arg, &result_5, clnt);
	if (retval_5 != RPC_SUCCESS) {
		clnt_perror (clnt, "call failed");
	}
	else{
	printf("Multiplied Result: \n");
	formal_result = &result_5;
	row = formal_result->row_first;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < row; j++)
		{

		result_matrix[i][j] = formal_result->multiplied[z];
		z++;
		}
	}
	printf("Result Matrix is: \n");
	for(i = 0; i < row; i++ )
	{
		for(j = 0; j < row; j++)
		{
		
		
		printf("%d\t", result_matrix[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
	}
	
	
	/*closing brace for switch case, this comment is for Developers readability*/
	}
}  
while(i!=6);
	


   
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	morampudi_a2_1 (host);
exit (0);
}
