# RPC-A2
A MultiThreaded Client - Server Program using RPC
to Run the program, Clone the Project into your Machine  
To run this code, you need to have RPCBIND installed in you machine.   
if it is not installed, you can do so using the command "sudo apt -get install rpcbind"  

# Commands To start the Client and Server  
./print_server - to start the server    
./print_client server_host - to start the client    
Now you can use the application.  


# To Make any changes to the file and compile again  

If you make any changes to the Interface file which is print.x, you need to use the command rpcgen -a -M print.x  
This will generate the server files, server stubs, client files and client stubs and also a makeFile  
once the above files are generated use the command make -f Makefile.print to build the system.  

