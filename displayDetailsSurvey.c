/**
@desc detailsElements - function To print survey detail select by PPS on screen
@param struct listElement** head
@return void - Don't have return
*/

#include "functions.h"

void detailsElements(struct listElement *head) {
	char *search[40];;
	int sentinel = 0;
	struct listElement *temp;
	
	temp = head;

	// get PPS or first name 
	printf("Please enter the PPS or First Name..: ");
	scanf("%s", search);


	// loop all records into the memory temp
	while (temp != NULL)
	{
		
		// I used atoi to convert strinto to int my search
		if (strcmp(temp->firstName, search) == 0 || temp->pps == atoi(search))
		{
			// print the values from the node
			printf("---------------- Personal Data ---------------------------------\n");
			printf("PPS Number..: %d\n", temp->pps);
			printf("First Name..: %s\n", temp->firstName);
			printf("Second Name.: %s\n", temp->secondName);
			printf("Address.....: %s\n", temp->address);
			printf("Email.......: %s\n", temp->email);
			printf("Gender......: %s\n", &genderArray[temp->Gender - 1][0]);

			printf("---------------- Survey Data ----------------\n");
			printf("Age Bracket................: %s\n", &ageArray[temp->age.age - 1][0]);
			printf("Income Bracket.............: %s\n", &incomeArray[temp->income.income - 1][0]);
			printf("Often do Exercise per week.: %s\n", &exerciseArray[temp->exercise.exercise - 1][0]);
			printf("Alcohol consume per week...: %s\n", &alcoholArray[temp->alcohol.alcohol - 1][0]);
			printf("Cigarettes Smoked per week.: %s\n", &cigarettesArray[temp->cigarettes.cigarettes - 1][0]);

			sentinel = 1; // set sentinel to 1 to jump the next condition not show msg (The record %s is not the list)
		}
		temp = temp->next; // set temp to take the  next value
	}

	// if sentinel remains 0, record don't exist
	if (sentinel == 0) {
		printf("\n The record %s is not the list.\n", search);
	}
}