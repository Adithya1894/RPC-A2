struct a2_echo{

	char input[100];

};

program Morampudi_a2{

	version a2Vers{
	
	a2_echo Echo(a2_echo)=1;
	
	}=1;
}=0x456456;
