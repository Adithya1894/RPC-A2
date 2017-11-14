/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "print.h"
#include "unistd.h"
#include "errno.h"
#include "stdio.h"
bool_t
echo_1_svc(a2_echo *argp, a2_echo *result, struct svc_req *rqstp)
{
	bool_t retval;

	printf("Echo function called \n");
	printf("This is the input from the user: %s",argp->input);
	printf("\n");
	strcpy(result->input, argp->input);
	retval =1;
	return retval;
	/*
	 * insert server code here
	 */

}

bool_t
sort_1_svc(a2_sort *argp, a2_sort *result, struct svc_req *rqstp)
{
	printf("Sort function is called\n");
	bool_t retval;
	int count = argp->count; 
	int list_items;
	int items[100];
	int i;
	int j;
	int value; 
	/*I am using insertion sort to sort the values of the list */
	for(i =0; i < count; i++)
	{
		list_items = argp->list[i];
		items[i] = list_items;		
	}
	result->count = count;	
	for(i = 1;i <count; i++ )
	{
		value = items[i];
		j = i -1;
		
	while(j >= 0 && items[j] > value)
		{
 		
		items[j+1] = items[j];
		j = j -1;
		}
		items[j+1] =value; 

	
	
	}
	/*passing the sorted output to the client*/
	for(i = 0; i < count; i++)
	{
	result->sorted_list[i] =items[i];
	}
	/*
	 * insert server code here
	 */
	retval = 1;
	return retval;
}

bool_t
path_1_svc(void *argp, a2_path *result, struct svc_req *rqstp)
{	
	printf("Path function is called");
	bool_t retval;
	char cwd[100];
	/*getcwd is used here to get the current working directory, inbuilt function in c*/
	getcwd(cwd,sizeof(cwd));
       	strcpy(result->pwd, cwd);
	/*
	 * insert server code here
	 */
	retval = 1;
	return retval;
}

bool_t
file_check_1_svc(a2_file_check *argp, a2_file_check *result, struct svc_req *rqstp)
{
	bool_t retval;
	char empty[10] = "Not Found";
	int arr[10][10]; 
	/*using the inbuilt access function present in c I am checking if a file is available*/
    if( access( argp->files, F_OK ) != -1 ) {
    	strcpy(result->files, argp->files);
    	
	} else {
    		strcpy(result->files, empty);
	}
	
	
	
	
	
	/*
	 * insert server code here
	 */
	retval = 1;
	return retval;
}


bool_t
matrix_mul_1_svc(a2_matrix_mul *argp, a2_matrix_mul *result, struct svc_req *rqstp)
{
	bool_t retval;
	
	int row1,i,j;
	int col1;
	int row2;
	int col2;
	int z,k,l = 0;
	int first[100][100];
	int second[100][100];
	int result[100][100] = 0;
	int serialized_result[100];
	/*Assigning local variables values from the values which has been passed by the client*/
	row1 = argp->row_first;
	col1 = argp->col_first;
	row2 = argp->row_second;
	col2 = argp->col_second;
	
	/*DeSerializing the first Array values and storing it in first Matrix*/
	for(i = 0; i < row1; i++)
	{
		for(j = 0; j < col1; j++)
		{
			first[i][j] = argp->first[k];
			k++;
			
		}
	}
	/*Deserializing the second Array values and storing it in the Matrix 2*/ 
	for(i = 0; i < row2; i++)
	{
		for(j = 0; j < col2; j++)
		{
			second[i][j] = argp->second[z];
			z++;
		
		}
	}
	
	/*Multiplication code for Matrices*/	
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < row1; j++)
        {
        
            for (k = 0; k < row1; k++)
                result[i][j] += mat1[i][k]*mat2[k][j];
        }
    }

	/*Serializing the output in the form of an array to send it to the client*/
		
	 
	for(i = 0; i < row1; i++)
		{
			for(j = 0; j < col1; j++)
			{
				serialized_result[l] = result[i][j];
				result->result[l] = serialized_result[l];
				l++;
			}
		}
		result->row_first = row1;	
	
	retval =1;
	return retval;
}

int
morampudi_a2_1_freeresult (SVCXPRT *transp, xdrproc_t xdr_result, caddr_t result)
{
	xdr_free (xdr_result, result);

	/*
	 * Insert additional freeing code here, if needed
	 */

	return 1;
}
