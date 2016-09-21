
#include "functions.h"


/**
@desc statisticsSurvey - shows menu options for each case statistics
@param struct listElement** head
@return void - Don't have return
*/

char choice[2];
int i, j, sentinel, op;
int count = 0;

void statisticsSurvey(struct listElement* head)
{
	//Loop to get user choice.
	do
	{
		// Print Menu
		printf("\n-------------- Menu ----------------------------------------------\n");
		printf("   a. %% of people who smoke\n");
		printf("   b. %% of people who smoke less than 20 cigarettes per week\n");
		printf("   c. %% of people who smoke less than 40 cigarettes per week\n");
		printf("   d. %% of people who smoke greater than 40 cigarettes per week\n");
		printf("------------------------------------------------------------------\n");
		printf("   e. %% of people who never exercise\n");
		printf("   f. %% of people who exercise less than three times per week\n");
		printf("   g. %% of people who exercise less than five times per week\n");
		printf("   h. %% of people who exercise more than five times per week\n");
		printf("------------------------------------------------------------------\n");
		printf("   i. %% of people who do not consume alcohol\n");
		printf("   j. %% of people who consume less than 2 units of alcohol per week\n");
		printf("   k. %% of people who consume less than 4 units of alcohol per week\n");
		printf("   l. %% of people who consume more than 4 units of alcohol per week\n");
		printf("------------------------------------------------------------------\n");
		printf("   x. Exit\n");
		printf("==> ");
		scanf("%s", choice);

		system("cls");

		sentinel = 0;

		// for each option the program will pass to function displayStatistics(head, op) 
		// op = number will be pass to function, this value represents type menu select
		if (strcmp(choice, "a") == 0) {
			op = 1;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "b") == 0) {
			op = 2;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "c") == 0) {
			op = 3;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "d") == 0) {
			op = 4;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "e") == 0) {
			op = 5;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "f") == 0) {
			op = 6;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "g") == 0) {
			op = 7;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "h") == 0) {
			op = 8;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "i") == 0) {
			op = 9;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "j") == 0) {
			op = 10;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "k") == 0) {
			op = 11;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "l") == 0) {
			op = 12;
			displayStatistics(head, op);
		}

		if (strcmp(choice, "x") == 0) {
			return 0;
		}

	} while (choice != "x"); // diferent -1

} // end add statistics




  /**
  @desc displayStatistics - generates statistics acord of option select
  @param struct listElement** head
  @return void - Don't have return
  */
void displayStatistics(struct listElement* head, int op) {

	struct listElement *temp;
	int count = 1;
	temp = head;

	int countGender[2] = { 0, 0 };
	int countAge[5] = { 0, 0, 0, 0, 0 };
	int countIncome[7] = { 0, 0, 0, 0, 0, 0, 0 };

	int resultGender[2] = { 0, 0 };
	int resultAge[5] = { 0, 0, 0, 0, 0 };
	int resultIncome[7] = { 0, 0, 0, 0, 0, 0, 0 };

	sentinel = 0;
	count = 0;


	// loop all records into the memory temp
	while (temp != NULL)
	{
		// this state condition will takes diferents criterias, kind of people smoke and value takes from option
		// each line represents one condition

		if ((op == 1 && (temp->cigarettes.cigarettes >= 2 && temp->cigarettes.cigarettes <= 4)) ||
			(op == 2 && (temp->cigarettes.cigarettes == 2)) ||
			(op == 3 && (temp->cigarettes.cigarettes == 3)) ||
			(op == 4 && (temp->cigarettes.cigarettes == 4)) ||
			(op == 5 && (temp->exercise.exercise == 1)) ||
			(op == 6 && (temp->exercise.exercise == 2)) ||
			(op == 7 && (temp->exercise.exercise == 3)) ||
			(op == 8 && (temp->exercise.exercise == 4)) ||
			(op == 9 && (temp->alcohol.alcohol == 1)) ||
			(op == 10 && (temp->alcohol.alcohol == 2)) ||
			(op == 11 && (temp->alcohol.alcohol == 3)) ||
			(op == 12 && (temp->alcohol.alcohol == 4)))	{ // finsh if statemnt

			int age = temp->age.age;
			int income = temp->income.income;
			int gender = temp->Gender;
			countAge[age - 1] += 1;
			countIncome[income - 1] += 1;
			countGender[gender - 1] += 1;
			count++;
			sentinel = 1;
		}
		temp = temp->next; // get the next value
	}


	// if the value exist will take this condition
	if (sentinel == 1) {

		// loop count and get % Age
		for (i = 0; i < 5; i++)
		{
			resultAge[i] = (countAge[i] * 100) / count;
		}

		// loop count and get % Income
		for (i = 0; i < 7; i++)
		{
			resultIncome[i] = (countIncome[i] * 100) / count;
		}


		// loop count and get % Gender
		for (i = 0; i < 2; i++)
		{
			resultGender[i] = (countGender[i] * 100) / count;
		}



		//printing all results
		printf("\n------------------------------------------------------------------\n");
		printf(" Total %d %s\n", count, descStatistics[op - 1]);
		printf("------------------------------------------------------------------\n");
		for (i = 0; i < 5; i++)
		{
			printf(" Total %3d %% -%4d people - %s\n", resultAge[i], countAge[i], ageArray[i]);
		}

		printf("---------------------------------------------------\n");
		for (i = 0; i < 7; i++)
		{
			printf(" Total %3d %% -%4d income - %s \n", resultIncome[i], countIncome[i], incomeArray[i]);
		}

		printf("---------------------------------------------------\n");
		for (i = 0; i < 2; i++)
		{
			printf(" Total %3d %% -%4d gender - %s \n", resultGender[i], countGender[i], genderArray[i]);
		}
	}


	//if don't exist records for this statistics
	else
	{
		printf("\n------------------------------------------------------------------\n");
		printf(" No records for statistics for \n %s\n", descStatistics[op - 1]);
		printf("------------------------------------------------------------------\n");
	}
}
