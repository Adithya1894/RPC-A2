# 1 RPC-A2
A MultiThreaded Client - Server Program using RPC
to Run the program, Clone the Project into your Machine  
To run this code, you need to have RPCBIND installed in you machine.   
if it is not installed, you can do so using the command "sudo apt -get install rpcbind"  

# 2 Commands To start the Client and Server 
go to the directory where the client and server files are located(In this case it is the root folder)  

./print_server - to start the server    
./print_client server_host - to start the client    

Now you can use the application.  


# 3 To Make any changes to the files and compile again  

if Interface file(print.x) is Changed use:  

rpcgen -a -M print.x - this will generate the server stubs, client stubs, server, client files and Makefile 
 
 
once the above files are generated use the command:  

make -f Makefile.print

now your client and server files will be ready in the root folder.

follow step 2 to run the client and server. 
