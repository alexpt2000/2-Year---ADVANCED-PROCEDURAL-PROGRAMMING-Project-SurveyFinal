/**
@desc displayElements - function To print all the elements to the screen
@param struct listElement** head
@return void - Don't have return
*/

#include "functions.h"


void displayElements(struct listElement* head) {
	struct listElement *temp;
	int count = 1;
	temp = head;

	// loop all records into the memory temp
	while (temp != NULL)
	{

		// print the values from the node
		printf("\nSurvey n. %d \n", count);
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
	
		count++; // count each recort

		temp = temp->next; // set temp to take the  next value
	}
}