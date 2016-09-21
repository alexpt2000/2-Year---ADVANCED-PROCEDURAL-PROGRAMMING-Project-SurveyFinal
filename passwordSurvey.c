#include <stdio.h>
#include <conio.h>
#include "functions.h"

/**
 @desc passwordSurvey - verify access by username and password storage into the file password.txt

 @param Don't take any param
 @return void - Don't have return
*/

void passwordSurvey()
{
	char password[7], usrname[7], ch;
	char chechUser[7];
	char checkPassword[7];
	int i, pass;
	int sentinel = 0;

	FILE* myFile; /// Pointer to file with sales

	/// Open up the file with the password
	myFile = fopen("password.txt", "r");

	
	/*
	This logo was created with ASCI code
	*/

	//********************* Print My logo *********************
	printf("   _____                                       \n");
	printf("  / ____|                                      \n");
	printf(" | (___    _   _   _ __  __   __   ___   _   _ \n");
	printf("  \\___ \\  | | | | | '__| \\ \\ / /  / _ \\ | | | |\n");
	printf("  ____) | | |_| | | |     \\ V /  |  __/ | |_| |\n");
	printf(" |_____/   \\__,_| |_|      \\_/    \\___|  \\__, |\n");
	printf("  _                                       __/ |\n");
	printf(" | |                                     |___/ \n");
	printf(" | |__    _   _                                \n");
	printf(" | '_ \\  | | | |                               \n");
	printf(" | |_) | | |_| |                               \n");
	printf(" |_.__/   \\__, |                               \n");
	printf("           __/ |                               \n");
	printf("          |___/                                \n");
	printf("             _                                 \n");
	printf("     /\\     | |                                \n");
	printf("    /  \\    | |   ___  __  __                  \n");
	printf("   / /\\ \\   | |  / _ \\ \\ \\/ /                  \n");
	printf("  / ____ \\  | | |  __/  >  <                   \n");
	printf(" /_/    \\_\\ |_|  \\___| /_/\\_\\  				   \n");
	printf(" \n");
	//********************* End Print My logo *********************


	/// If file cannot be accessed
	if (myFile == NULL)
	{
		printf("The file pasword don't exist...\n\n");
		system("pause");
		exit(0);
	}
	else
	{
		for (pass = 0; pass < 3; pass++)
		{
			myFile = fopen("password.txt", "r");

			printf("Enter User name...: ");
			gets(usrname);
			printf("Enter the password: ");

			// Loop 6 times represents 1 loop for each char password
			for (i = 0; i < 6; i++)
			{
				ch = getch();
				password[i] = ch;
				ch = '*';
				printf("%c", ch);
			}

			password[i] = '\0';

			/* while not end of file */
			while (!feof(myFile))
			{
				// scan into the file each line for user name and pawssword
				fscanf(myFile, "%s%s%", chechUser, checkPassword);

				// compare username and password
				if (strcmp(chechUser, usrname) == 0 && strcmp(checkPassword, password) == 0) {
					pass = 3;
					sentinel = 1;
				}

			} /* end while */


			if (sentinel == 0) // condition for wrong password
			{
				printf("\n\nWrong username or password, try again...\n\n");
				fclose(myFile);
			}

			fclose(myFile); /* fclose closes the file */
		}

		fclose(myFile); /* fclose closes the file */

		if (sentinel == 0) // condition for wrong password
		{
			printf("You can't try more than 3 times...\n\n");
			system("pause");
			exit(0);
		}

	} /* end else */

	system("cls"); // clear the screen
}
