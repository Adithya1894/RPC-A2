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

program Morampudi_a2{

	version a2Vers{
	
	a2_echo Echo(a2_echo)=1;
	a2_sort Sort(a2_sort list)=2;
	a2_path Path(void)=3;
	a2_file_check File_Check(a2_file_check files)=4;
	}=1;
}=0x456456;
