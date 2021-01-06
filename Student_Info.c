
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Function Name :
// Input 	 :
// Output 	 :
// Description   : Case Study For Student Database System
//
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	int Roll_No;
	char Name[20];
	char Address[50];
	int No_Of_Sub;
	int *Marks;
}Student,*PStudent;

void Accept(PStudent);
void Average(PStudent, int);
void Display(PStudent, int);

int main()
{
	int iSCnt = 0, i = 0;
	PStudent sPtr = NULL;

	printf("\n Enter Number of Students : ");
	scanf("%d",&iSCnt);

	sPtr = (PStudent)malloc(sizeof(Student) * iSCnt);

	printf("\n Enter Information of Students : ");

	for(i = 0; i < iSCnt; i++)
	{
		printf("\n Student No : %d -> \n ",i+1);
		Accept(&sPtr[i]);
	}

	Display(sPtr,iSCnt);
	Average(sPtr,iSCnt);

	return 0;
}

void Accept(PStudent P)
{
	int i = 0;

	printf("\n Enter Roll Number : ");
	scanf("%d",&P->Roll_No);

	printf("\n Enter Name : ");
	scanf("%s",&P->Name);

	printf("\n Enter Address : ");
	scanf("%s",&P->Address);

	printf("\n Enter Number Of Subjects : ");
	scanf("%d",&P->No_Of_Sub);

	P->Marks = (int*)malloc(sizeof(int) * (P->No_Of_Sub));

	printf("\n Enter Marks : ");

	for(i = 0; i < (P->No_Of_Sub); i++)
	{
		printf("\n\t Subject Number %d = ",i+1);
		scanf("%d",&(P->Marks[i]));
	}
}

void Average(PStudent vPtr,int sCnt)
{
	int i, j, Sum, Avg, MaxAvg;
	char T_name[20];
	i = j = Sum = Avg = MaxAvg = 0;

	for(i = 0; i < sCnt; i++)
	{
		for(j = 0; j < vPtr[i].No_Of_Sub; j++)		// vPtr[i].No_Of_Sub
		{
			Sum = Sum + vPtr[i].Marks[j];		// vPtr[i].Marks[j]
		}
		Avg = Sum / vPtr[i].No_Of_Sub;			// vPtr[i].No_Of_Sub
		if(Avg > MaxAvg)
		{
			MaxAvg = Avg;
			strcpy(T_name,vPtr[i].Name);		// vPtr[i].Name
		}
		Sum = Avg = 0;
	}
	printf("\n===================================================\n");
	printf("\n\n  Name & Average Marks Of Student Who Has Highest Average Marks is :");
	printf("\n\t  Student Name : %s \t Average Marks : %d",T_name,MaxAvg);
    printf("\n===================================================\n");
}

void Display(PStudent vPtr,int sCnt)
{
	int i = 0, j = 0;

	printf("\n Information Of All Students is As Follows : \n\n");

	for(i = 0; i < sCnt; i++)
	{
        printf("\n===================================================\n");
		printf("\n%d",i);

		printf("\n  Student Roll Number : %d.",vPtr[i].Roll_No);

		printf("\n  Student Name	: %s.",vPtr[i].Name);

		printf("\n  Student Address 	: %s.",vPtr[i].Address);

		printf("\n  Student Number Of Subjects : %d.",vPtr[i].No_Of_Sub);

		printf("\n  Student Marks of Every Subject are :\n");

		for(j= 0; j < vPtr[i].No_Of_Sub; j++)
		{
			printf("\n\t  Subject %d = %d.",j+1, vPtr[i].Marks[j]);
		}
        printf("\n===================================================\n");
    }
}
