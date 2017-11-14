struct a2_echo{

	char input[100];

};

struct a2_sort{
	
	int count;
	int list[100];
	int sorted_list[100];	

};

struct a2_path{
	char pwd[100];

};

struct a2_file_check{
	
	char files[100];
	
};

struct a2_matrix_mul{


	int first[100];
	int second[100];
	int row_first;
	int col_first;
	int row_second;
	int col_second;

};

program Morampudi_a2{

	version a2Vers{
	
	a2_echo Echo(a2_echo)=1;
	a2_sort Sort(a2_sort list)=2;
	a2_path Path(void)=3;
	a2_file_check File_Check(a2_file_check files)=4;
	a2_matrix_mul Matrix_mul(a2_matrix_mul matrix)=5;
	}=1;
}=0x456456;
