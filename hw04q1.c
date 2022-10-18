// Osman Servin
// State the IDE that you use: GCC
// GCC Command line to compile: gcc -g -Wall hw04q1.c -o output
// Execute: ./output

#include <stdio.h>
#include <string.h>


// Global Macro Values. They are used to define the size of 2D array of characters
#define NUM_STRINGS 4
#define STRING_LENGTH 50

// Forward Declarations
void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]);
void printStrings(char[NUM_STRINGS][STRING_LENGTH]);
void encryptStrings(char[NUM_STRINGS][STRING_LENGTH], int);
void decryptStrings(char[NUM_STRINGS][STRING_LENGTH], int); 
void reverseStrings(char strings[NUM_STRINGS][STRING_LENGTH]); 
char* reverseOneString(char s[STRING_LENGTH]); 
int isPalindrome(char s[STRING_LENGTH]);



// Use pointer 'ptr' to traverse the 2D array of characters variable 'strings' (input from user in main()) and set all characters in each
void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* ptr = &strings[0][0];

	// Enter the code below
	int rows, columns; // VARIABLES USED IN FOR LOOP

	for(rows = 0; rows < NUM_STRINGS; rows++) // GOES THROUGH THE ROWS IN THE 2D ARRAY
	{
		for(columns = 0; columns < STRING_LENGTH; columns++) // GOES THROUGH THE COLUMNS IN THE 2D ARRAY
		{
			*(ptr + rows * STRING_LENGTH + columns) = '\0'; // SETS THE CHARACTER AT THE POINTER ADDRESS EQUAL TO \0
		}
	}
} // END OF initializeStrings()



// Use pointer 'ptr' to traverse the 2D character array 'strings' and print each string.
// See the example outputs provided in the word document. Each string should be printed on a new line.
void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* ptr = &strings[0][0];

	// Enter the code below
	int row, column; // VARIABLES THAT WILL BE USED TO PRINT THE STRINGS

	for(row = 0; row < NUM_STRINGS; row++) // GOES THROUGH THE FIRST STRINGS
	{
		for(column = 0; column < STRING_LENGTH; column++) // GOES THROUGH THE STRING ITSELF AND INITIALIZES
		{
			printf("%c", *(ptr + row * STRING_LENGTH + column) ); // PRINTS THE CHARACTER IN STRINGS
		}
		printf("\n"); // GOES TO THE NEXT STRING OF CHARACTERS. USED FOR FORMATTING OUTPUT
	}

}




// Reverse the string s by using pointer.
// Use pointer 'ptr' and 'temp' char to swap 1st char with last, then 2nd char with (last-1) and so on..
// Finally return pointer 'ptr' which points to start of the reversed string.
// Hint: You might want to check if your logic works with even as well as odd length string.
//       You can write test code to print out the reversed string to check if your function works. (Don't include it in final submission)
char* reverseOneString(char s[STRING_LENGTH])
{
	char temp;  // not necessary to use this variable
	char* ptr = &s[0];  // pointer to start of string
	int len = strlen(s); // STORES THE LENGTH OF THE STRING

	// Enter the code below
	int index; // USED TO INCREMENT AND GO THROUGH THE STRING
	char* ptr2 = &s[len]; // USED TO STORE THE LAST CHARACTER OF THE STRING

	for(index = 1; index <= len / 2; index++) // RUNS FOR ONLY HALF THE LENGTH OF THE STRING
	{
		temp = *ptr; // temp STORES THE CHARACTER AT THE BEGINNING OF THE STRING 
		*ptr = *(ptr2 - index); // THE LEFT INDEX WILL STORE THE CHARACTER IN THE RIGHT INDEX
		*(ptr2 - index) = temp; // THE RIGHT INDEX STORES THE LEFT INDEX CHARACTER
		ptr++; // INCREMENT THE ADDRESS ptr IS POINTING TO
	}

	ptr = &s[0]; // REASSIGN THE ADDRESS AT THE BEGINNING OF THE 2D ARRAY TO ptr
	return ptr; // RETURN THE ADDRESS AT THE BEGINNING OF THE ARRAY

	// MANIPULATE MOVING TO NEXT ADDRESS LOCATION BY USING (ptr + n)
	// MAKE USE OF THE ORDER OF OPERATION

} // END OF reverseOneString()




// Reverse all the strings in 'strings[][]'
// For each string in 'strings', use the reverseOneString() to reverse it.
void reverseStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	// Enter the code below
	char* ptr = &strings[0][0]; // CHARACTER POINTER SO THAT WE CAN TRAVERSE THROUGH THE STRINGS
	int index; // USED TO HELP GO THROUGH THE STRINGS IN THE 2D ARRAY
	
	for(index = 0; index < NUM_STRINGS; index++) // RUNS FOR THE AMOUNT OF STRINGS STORED IN THE ARRAY
	{
		reverseOneString(ptr); // CALLS THE reverseOneString() AND PASSES THE ADDRESS IN ptr WHICH IS THE BEGINNING OF strings ARRAY

		while(*ptr != 0) // INCREMENTS THE ADDRESS IN POINTER
		{
			ptr++;
		}
		while(*ptr == 0) // INCREMENTS THE ADDRESS IN POINTER
		{
			ptr++;
		}
	}
} // END OF reverseStrings()




// Use pointer 'ptr' to traverse the 2D character array 'strings' and encrypt each string in 2 step as follows- 
// 1) Reverse the strings. Hint: Use 'reverseStrings()' for this step.
// 2) Shift the characters forward by the integer value of 'key'.
// If the string is "hello" and key = 2, reversing will get you "olleh" and adding key to it will result in "qnnfj".
// Once the value of 'key' gets larger, you will extend past alphabetical characters and reach non-alphabetical characters. Thats ok.
void encryptStrings(char strings[NUM_STRINGS][STRING_LENGTH], int key)
{
	char* ptr = &strings[0][0];
	// Enter the code below
	int index = 0; // USED TO GO THROUGH THE STRING AND ARRAY

	reverseStrings(strings); // CALLS THE reverseStrings() FUNCTION AND PASSES THE ARRAY OF STRINGS TO IT		

	while(index < NUM_STRINGS * STRING_LENGTH) // RUNS UNTIL THE END OF ARRAY OR NULL TERMINATOR
	{
		*(ptr + index) += key; // INCREMENTS THE ADDRESS IN ptr BY INDEX AND ADDS key TO THE ASCII VALUE IN THE ADDRESS 
		index++; // INCREMENT INDEX BT 1
	}
} // END OF encryptStings()




// HINT: This should be very similiar to the encryption function defined above in encryptStrings().
// Use pointer 'ptr' to traverse the 2D character array 'strings' and decrypt each string in 2 step as follows- 
// 1) Shift the characters backward by the integer value of 'key'.
// 2) Reverse the strings. Hint: Use 'reverseStrings()' for this step.
void decryptStrings(char strings[NUM_STRINGS][STRING_LENGTH], int key)
{
	char* ptr = &strings[0][0];
	// Enter the code below
	int index = 0; // USED TO GO THROUGH THE STRING AND ARRAY 

	while(index < NUM_STRINGS * STRING_LENGTH) // RUNS UNTIL THE END OF ARRAY
	{
		*(ptr + index) -= key;
		index++;
	}
	reverseStrings(strings); // CALLS reverseStrings() AND PASSES THE ARRAY TO THE FUNCTION

} // END OF decryptStrings()




// Return 1 if string s is palindrome. Or, return 0 if string is not palindrome.
// A palindrome is a sequence of characters which when reversed, is the same sequence of characters.
// Palindrome string examples: rotor, noon, madam...
// Parse through the string to check if 1st char==last char, 2nd char == (last-1) char, and so on.. 
int isPalindrome(char s[STRING_LENGTH])
{
	char* ptr = s;
	int len = strlen(s);
		
	// Enter the code below
	int index, palindrome; // USED TO STORE VALUES
	char* ptr2 = &s[len]; // USED TO POINT TO THE END OF THE STRING 

	for(index = 1; index <= len / 2; index++) // RUNS FOR HALF THE STRING LENGTH
	{
		if( *ptr == *(ptr2 - index) ) // IF THE FIRST AND LAST INDEX ARE THE SAME DO THE FOLLOWING
		{	
			ptr++; // INCREMENT THE POINTER
			palindrome = 1; // SET palindrome EQUAL TO 1
		}
		else // IF THE CHARACTERS ARENT THE SAME EXIT LOOP
		{	
			index = (len / 2) + 1; // index IS SET TO THE FOLLOWING IN ORDER TO EXIT LOOP
			palindrome = 0; // palindrome EQUALS 0 AND THEREFORE FALSE
		}
	}	
	return palindrome; // RETURNS THE VALUE USED TO DETERMINE IF TRUE OR FALSE

} // END OF isPalindrome()




int main()
{
	char strings[NUM_STRINGS][STRING_LENGTH]; // will store four strings each with a max length of 34
	int i, key;
	char input[STRING_LENGTH];

	printf("CSE240 HW4: Pointers\n\n");
	initializeStrings(strings);

	for (i = 0; i < NUM_STRINGS; i++)
	{
		printf("Enter a string: ");				// prompt for string
		fgets(input, sizeof(input), stdin);		// store input string
		input[strlen(input) - 1] = '\0';		// convert trailing '\n' char to '\0' (null terminator)
		strcpy(strings[i], input);				// copy input to 2D strings array
	}

	printf("\nEnter a key value for encryption: "); // prompt for integer key
	scanf("%d", &key);

	encryptStrings(strings, key);
	printf("\nEncrypted Strings:\n");
	printStrings(strings);
	decryptStrings(strings, key);
	printf("\nDecrypted Strings:\n");
	printStrings(strings);

	getchar();									// flush out newline '\n' char

	printf("Checking for palindrome. Enter a string: ");				// prompt for string
	fgets(input, sizeof(input), stdin);		// store input string
	input[strlen(input) - 1] = '\0';		// convert trailing '\n' char to '\0' (null terminator)

	if (isPalindrome(input))
		printf("\nThe string is a palindrome!");
	else
		printf("\nThe string is NOT a palindrome!");

	getchar();									// keep VS console open
	return 0;
}
