/**
 @desc 
 Custom-surveys Ltd. currently performs surveys in Ireland and has requested you to develop
 a new survey program for them.
 This program will create a database which will store the details of all the surveys. In
 addition to storing all the survey data the application should allow survey statistics to be
 generated.
 Your program should create the database (which for your purpose will be implemented as a
 linked list) and be able to save, restore, retrieve, add, delete and update survey details.
 
 @author Alexander Souza G0037835@GMIT.IE

*/

// functions.h include all struct and #include lib
#include "functions.h" 

void main() {

	// open method passwordSurvey(), if password is not correct the program will be close 
	passwordSurvey();

	// creating struct
	struct listElement* top;
	int choice;
	top = NULL;

	// call method openSurvey(&top) and pass param &top to be load all storage data 
	// from the file survey.txt 
	openSurvey(&top);

	// Print the menu
	do {
		printf("\nSurvey - Please Enter your choice!\n");
		printf("-----------------------------------------------\n");
		printf("  1. Add a survey\n");
		printf("  2. Display all surveys to screen\n");
		printf("  3. Display Survey details\n");
		printf("  4. Update Survey\n");
		printf("  5. Delete Survey\n");
		printf("  6. Generate statistics\n");
		printf("  7. Print all surveys into a report file\n");
		printf(" -1. Exit!\n");
		printf("=> ");
		scanf("%d", &choice);
		printf("\n******************* Results *******************\n");

		// cleaner the screen after print the menu
		system("cls");

		if (choice != -1) {
			if (choice <= 0 || choice > 8) { // check numbers between 0 t0 5
				choice = 0;
				printf("Invalid choice - Just choice between 1 to 8.\n");
			}
		}

		//State conditions for choice
		switch (choice) {

		case(1) :
			//function To add an element
			addElement(&top);
			break;

		case(2) :
			//display all elements screen
			displayElements(top);
			break;

		case(3) :
			//Display details, base of PPS and Name
			detailsElements(top);
			break;


		case(4) :
			//function To update the survey
			updateElements(&top);
			break;

		case(5) :
			//function To delete survey
			deleteElement(&top);
			break;

		case(6) :
			//function To show statiscs screen
			statisticsSurvey(top);
			break;

		case(7) :
			//function To create report and export to the file
			reportSurvey(top);
			break;



		case(8) :
			//function to show the size list
			//addTemplatesSurveys(&top);
			break;
		}

	} while (choice != -1); // keep in loop until -1 to be press

	// after -1 (exit) be press the program will call function saveSurvey into a file survey.txt
	saveSurvey(top);
}






/**
@desc openSurvey - open the file Survey.txt and populate struct listElement** head with data
@param struct listElement** head
@return void - Don't have return
*/

void openSurvey(struct listElement** head)
{
	//variables
	int i = 0;
	int sentinel = 0;
	int numberofSurveys = 0;
	struct listElement *temp;
	struct listElement *newNode;

	FILE* myFile; /// Pointer to file 

	/// Open up the file with the Survey
	myFile = fopen("Surveys.txt", "r");

	/// If file cannot be accessed
	if (myFile == NULL)
	{
		//fclose(myFile);
	}


	else
	{
		// count number of records into the file
		char c;
		// Extract characters from file and store in character c
		for (c = getc(myFile); c != EOF; c = getc(myFile)) {
			if (c == '\n') {// Increment count if this character is newline
							
				numberofSurveys++;
			}
		}

		
		fclose(myFile);

		/// Open up the file with the Survey
		myFile = fopen("Surveys.txt", "r");

		for (i = 0; i < numberofSurveys; i++) // loop base numberofSurveys, records into the file
		{

			// the first value have to be take to be create the memory alocate
			if (sentinel == 0)
			{
				temp = *head; 

				// create a new memory alocate to receive data from file
				newNode = (struct listElement*)malloc(sizeof(struct listElement));

				fscanf(myFile, "%d %s %s %s %s %d %d %d %d %d %d", &newNode->pps, newNode->firstName, newNode->secondName, newNode->address, newNode->email, &newNode->Gender, &newNode->age.age, &newNode->income.income, &newNode->exercise.exercise, &newNode->alcohol.alcohol, &newNode->cigarettes.cigarettes);

				newNode->next = *head;
				*head = newNode; // transfer the address of newNode' to	'head'
				//free(newNode);
				sentinel = 1;
			}

			// condition for subsequents datas from the file
			else
			{
				temp = *head;

				while (temp->next != NULL)
				{
					temp = temp->next;
				}

				newNode = (struct listElement*)malloc(sizeof(struct listElement));

				fscanf(myFile, "%d %s %s %s %s %d %d %d %d %d %d", &newNode->pps, newNode->firstName, newNode->secondName, newNode->address, newNode->email, &newNode->Gender, &newNode->age.age, &newNode->income.income, &newNode->exercise.exercise, &newNode->alcohol.alcohol, &newNode->cigarettes.cigarettes);

				newNode->next = NULL;
				temp->next = newNode;
			}
		}
		fclose(myFile);
	}
}






/**
@desc saveSurvey - save the date into file Survey.txt after leave the program
@param struct listElement** head
@return void - Don't have return
*/

void saveSurvey(struct listElement* head)
{
	struct listElement *temp;
	int count = 0;
	temp = head;

	FILE* myFile; /// Pointer to file 

	// file to safe , declared whrite mode
	myFile = fopen("Surveys.txt", "w");

	// loop form each record into memory alocate
	while (temp != NULL)
	{
		// save line by line
		fprintf(myFile, "%d %s %s %s %s %d %d %d %d %d %d\n", temp->pps, temp->firstName, temp->secondName, temp->address, temp->email, temp->Gender, temp->age.age, temp->income.income, temp->exercise.exercise, temp->alcohol.alcohol, temp->cigarettes.cigarettes);

		temp = temp->next; // next record
	}

	//close the file
	fclose(myFile);
}