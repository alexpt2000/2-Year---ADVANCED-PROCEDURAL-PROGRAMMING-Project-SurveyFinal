/**
@desc deleteElement - function To delete an element
@param struct listElement** head
@return void - Don't have return
*/

#include "functions.h"


void deleteElement(struct listElement** head)
{
	int position, i, count=1;
	int search;

	struct listElement* temp;
	struct listElement* oldTemp;

	// if *head is empty will show the msg (No survey to delete)
	if (*head == NULL) {
		printf("\nNo survey to delete\n");
	}

	//if exist records
	else {
		//do {

		// Request number PPS to be delete
		printf("Please enter the PPS..: ");
		scanf("%d", &search);

		temp = *head;

		// looking for value PPS number
		while (temp != NULL)
		{
			// if exist
			if (temp->pps == search) {
				position = count; // will storage the position
			}
			count++;
			temp = temp->next; // next record
		}


		temp = (struct listElement*)malloc(sizeof(struct listElement));
		oldTemp = (struct listElement*)malloc(sizeof(struct listElement));
		temp = *head;

		// exeption case, if value is in first position
		if (position == 1) {
			deleteElementFirst(head); 
		}

		// if position is grater than 1
		else {

			// will realocate rest  values to fit deleted position
			for (i = 0; i < position - 1; i++) {
				oldTemp = temp;
				temp = temp->next;
			}

			// take realocate values
			oldTemp->next = temp->next;
			
			// pass temp, represents the delete value
			printDetailsDelete(temp);

			// delelete temp
			free(temp);
		}
	}
}





/**
@desc deleteElementFirst - function To delete first  element head
@param struct listElement** head
@return void - Don't have return
*/

void deleteElementFirst(struct listElement** head)
{
	struct listElement *temp;
	struct listElement *old_temp;


	// if *head is empty will show the msg(No survey to delete)
	if (*head == NULL) {
		printf("\nNothing to delete\n");
	}

	// if exist records
	else {


		temp = (struct nolistElementde*)malloc(sizeof(struct listElement));
		temp = *head;
		*head = temp->next;

		// pass temp, represents the delete value
		printDetailsDelete(temp);

		free(temp);
	}
}






/**
@desc printDetailsDelete - function To show  element deleted
@param struct listElement** tempOld
@return void - Don't have return
*/
void printDetailsDelete(struct listElement* tempOld)
{
	struct listElement *temp;

	temp = tempOld;


	// printing information   Personal Data  and  Survey Data

	printf("\nDeleting \n");
	printf("---------------- Personal Data ---------------------------------\n");
	printf("PPS Number..: %d\n", temp->pps);
	printf("First Name..: %s\n", temp->firstName);
	printf("Second Name.: %s\n", temp->secondName);
	printf("Address.....: %s\n", temp->address);
	printf("Email.......: %s\n", temp->email);
	printf("Gender.......: %s\n", &genderArray[temp->Gender - 1][0]);

	printf("---------------- Survey Data ----------------\n");
	printf("Age Bracket................: %s\n", &ageArray[temp->age.age - 1][0]);
	printf("Income Bracket.............: %s\n", &incomeArray[temp->income.income - 1][0]);
	printf("Often do Exercise per week.: %s\n", &exerciseArray[temp->exercise.exercise - 1][0]);
	printf("Alcohol consume per week...: %s\n", &alcoholArray[temp->alcohol.alcohol - 1][0]);
	printf("Cigarettes Smoked per week.: %s\n", &cigarettesArray[temp->cigarettes.cigarettes - 1][0]);

}