/**
@desc struc and function
@param 
@return 
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "arrayVariables.h"

//Struct
typedef struct {
	int age;
}age_t;

typedef struct {
	int income;
}income_t;

typedef struct {
	int exercise;
}exercise_t;

typedef struct {
	int alcohol;
}alcohol_t;

typedef struct {
	int cigarettes;
}cigarettes_t;

//Struct book take struct date
struct listElement {
	int pps;
	char firstName[40];
	char secondName[40];
	char address[40];
	char email[40];
	int Gender;
	age_t age;
	income_t income;
	exercise_t exercise;
	alcohol_t alcohol;
	cigarettes_t cigarettes;

	struct listElement *next;
};


// Declare functions
void openSurvey(struct listElement** head);
void saveSurvey(struct listElement* head);
void passwordSurvey();
void reportSurvey(struct listElement* head);
void addElement(struct listElement** head);
void addElement_AtStart(struct listElement** head, int pps);
void fillData(struct listElement* head, int PPS);
int verifyId(struct listElement* head, int PPSVerify);
int verifyPosition(struct listElement* head, int pps);
void displayElements(struct listElement* head);
void detailsElements(struct listElement* head);
void updateElements(struct listElement** head);
void addTemplatesSurveys(struct listElement** head);
void deleteElement(struct listElement** head);
void deleteElementFirst(struct listElement** head);
void printDetailsDelete(struct listElement* head);
void displayStatistics(struct listElement* head, int op);
void statisticsSurvey(struct listElement* head);