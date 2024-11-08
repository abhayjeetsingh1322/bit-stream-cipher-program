/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY. */

/*Description: This program takes a string as input, and generates elementary
level ciphertext, based on the key provided by the user.*/

/* Author: Abhayjeet Singh */

#include <stdio.h>

int main()
{
    //Defining an array that will hold 201 characters
	char message[201] = {'\0'};
    
    //Last char is intialized to '\n', 201 - 1 = 200 characters total
	message[200] = '\n';
    
    #ifdef PROMPT
	printf("Enter the text to be encrypted (hit Enter to end): ");
    #endif
    
    //While loop to get characters until max length or '\n' entered
	int i = 0;
	char letter = '\0';
	while (i < 200 && letter != '\n')
	{
    	letter = getchar();
    	message[i] = letter;
    	i++;
	}
	
	//New counter variable used for '\n', moved out PROMPT construct
	int endlCounter = 0;
	
    #ifdef PROMPT
	printf("\nYour text is: ");
    
    //While loop to print all in ASCII characters until '\n' is reached
	i = 0;
	while(message[i] != '\n')
	{
    	printf("%c", message[i]);
    	i++;
	}
    
	printf("\n\nYour text in hexadecimal is: \n");
	
    //While loop to print all in hexadecimal until '\n' is reached
	i = 0;
	while(message[i] != '\n')
	{
    	printf("%02X ", message[i]);
    	
    	//If statements to check and print '\n'
    	if(endlCounter == 9)
    	{
        	printf("\n");
        	endlCounter = -1; //Resetting counter
    	}
    	i++;
    	endlCounter++;
	}
    
	printf("\n\nEnter the 4-bit key: ");
    #endif
    
    //Defining a new array of string of 8-bits
	char keyPattern[8] = {'\0'};
	letter = '\0';
	
	//For loop to get 4-bits key pattern
	for (i = 0; i < 4; i++)
	{
    	letter = getchar();
    	keyPattern[i] = letter;
    	//Copying 4-bits to the next 4-bits
    	keyPattern[i+4] = letter;
	}
    
    //Defining key variable, 0000 0000
	unsigned char key = 0;
	
	//Defining one variable for comparing, 0000 0001
	unsigned char one = 1;
    
    //For loop to manipulate key to match 8-bits
	for (i = 0; i < 8; i++)
	{
	    //If key pattern is 1 then OR-ing the key with one
    	if(keyPattern[i] == '1')
    	{
    	key = key | one;
    	}
    	
    	//If not last bit then shift left
    	if (i != 7)
    	{
        	key = key << 1;
    	}
	}
    
    #ifdef PROMPT
	printf("\nYour hex ciphertext:\n");
    #endif
    
    //While loop to print all in hexa ciphertext until '\n' is reached
	i = 0;
	endlCounter = 0;
	while(message[i] != '\n')
	{
	    //Printing after XOR-ing the key with ASCII character
    	printf("%02X ", message[i] ^ key);
	
    #ifdef PROMPT    	
    	//If statements to check and print '\n'
    	if(endlCounter == 9)
    	{
        	printf("\n");
        	endlCounter = -1; //Resetting counter
    	}
    #endif
	
    	i++;
    	endlCounter++;
	}
	
	printf("\n");
    
	return 0;
}
