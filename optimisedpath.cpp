#include<stdio.h>
#include<stdlib.h>

int lines;
int machines;
int check, check1=1;
int oppath[100]; //optimized path
int time[100][100];

int flag=0;

void display(int e1[], int e2[], int **w1, int ***w2)
{
	int i,j,k;
	printf("1. The entry time for each of the line:\n\n");
	for (i=0; i<lines; i++)
	{
		printf("Line %d: ", i+1);
		printf("%d", e1[i]);
		printf("\n");
	}
	printf("\n2. The time taken to process the product in each machine:\n\n");
	for(i=0; i<lines; i++)
	{
		printf("Line %d\n", i+1);
		for(j=0; j<machines; j++)
		{
			printf("	Machine %d: ", j+1);
			printf("%d", w1[i][j]);
			printf("\n");
		}
	}
	printf("\n3. The time taken to travel from a machine in one level to the machines in the other level:\n\n");
	for(i=0; i<lines; i++)
	{
		for(j=0; j<machines-1; j++)
		{
			printf("The time taken to travel from Machine %d of Line %d to: \n", j+1, i+1);
			for(k=0; k<lines; k++)
			{
				printf("Machine %d of line %d: ", j+2, k+1);
				printf("%d", w2[i][j][k]);
				printf("\n");
			}
		}
	}
	printf("\n4. The exit time for each of the line: \n\n");
	for(i=0; i<lines; i++)
	{
		printf("Line %d: ", i+1);
		printf("%d", e2[i]);
		printf("\n");
	}
	printf("\n");
	printf("Press any key to Continue...");
	getch();
	system("cls");
}


void process(int e1[], int e2[], int **w1, int ***w2)
{
	int path[lines][machines-1];
	int i,j,k,t1,minpath,tmin;
	char x;
	for(i=0; i<lines; i++)
	{
		time[i][0]=e1[i]+w1[i][0];
	}
	for(i=0; i<machines; i++)
	{
		for(j=0; j<lines; j++)
		{
			tmin=time[0][i]+w1[j][i+1]+w2[0][i][j];
			minpath=1;
			for(k=0; k<lines; k++)
			{
				if(tmin>time[k][i]+w1[j][i+1]+w2[k][i][j])
				{
					tmin=time[k][i]+w1[j][i+1]+w2[k][i][j];
					minpath=k-1;
				}
			}
			time[j][i+1]=tmin;
			path[j][i]=minpath;
		}
	}
	
	for(i=0; i<lines; i++)
	{
		time[i][machines]=time[i][machines-1]+e2[i];
	}
	int min=time[0][machines];
	int bestendline=1;
	for(i=1; i<lines; i++)
	{
		if(min>time[i][machines])
		{
			min=time[i][machines];
			bestendline=i+1;
		}
	}
	
	if(check1!=0)
	{
		printf("The least time required for a product to be made is : %d\n\n", time[bestendline-1][machines]);
		check1=1;
	}
	
	oppath[machines-1]=bestendline;
	int temp=oppath[machines-1]-1;
	for(i=machines-2; i>=0; i--)
	{
		oppath[i]=path[temp][i];
		temp=oppath[i]-1;
	}
	
	if(check1!=0)
	{
		for(i=0; i<machines; i++)
		{
			printf("%d.) Machine %d of Line %d\n", i+1, i+1, oppath[i]);
		}
		printf("\n\n");
		printf("Press any key to return to the HOME page... ");
		getch();
		system("cls");
		check1=1;
	}
}

void display1(int e1[], int e2[], int **w1, int ***w2)
{
	check1=0;
	process(e1,e2,w1,w2);
	check1=1;
	int n,i;
	printf("Enter the machine number for which the optimized path and time is to be displayed:\n");
	scanf("%d", &n);
	if(n>machines)
	{
		printf("The number exceeds the total number of machines.\n");
		printf("Displaying the output for n=total number of machines!\n");
		n=machines;
	}
	printf("The least time required to reach and operate in machine %d is:", n);
	int bestendline;
	bestendline=oppath[n-1];
	printf("%d\n", time[bestendline-1][n-1]);
	for(i=0; i<n; i++)
	{
		printf("%d.) Machine %d of Line %d\n", i+1, i+1, oppath[i]);
	}
	printf("\n");
	printf("Press any key to Continue...");
	getch();
	system("cls");
}

int inputchoice(int count, int ch1)
{
	int ch;
	char x;
	if(count<4)
	{
		printf("\nWhat do you want to input?? \n");
		printf("1. The time taken to process the product in each machine \n");
		printf("2. The entry time for each of the line \n");
		printf("3. The exit time for each of the line \n");
		printf("4. The time taken to travel from a machine in one level to the machine in the other level\n");
		printf("5. To reset all the inputs\n");
		printf("6. To start over\n\n");
		printf("Enter the choice: ");
		scanf("%d", &ch);
		printf("\n");
		return ch;
	}
	else
	{
		printf("You have entered data successfully...");
		printf("\n\n");
		printf("Double ENTER to calculate the optimised path... ");
		getch();
		scanf("%c", &x);
		system("cls");
		return 5;
	}
}

void input(int e1[], int e2[], int **w1, int ***w2)
{
	int flag=0, flag1=0, flag2=0, flag3=0;
	char x;
	int i,j,k;
	int ch=0;
	int count=0;
	ch=inputchoice(count,ch);
	while(count<4)
	{
		switch(ch)
		{
			case 1:
				if(flag==1)
				{
					printf("You have already input this data!\n");
				}
				else
				{
					flag=1;
					count=count+1;
					printf("========================================================================================================================\n\n");
					for(i=0; i<lines; i++)
					{
						printf("Lines %d\n", i+1);
						for(j=0; j<machines; j++)
						{
							printf("	Machine %d: ", j+1);
							scanf("%d", &w1[i][j]);
							printf("\n");
						}
					}
				}
				printf("\n");
				printf("Press any key to Continue...");
				getch();
				scanf("%c", &x);
				system("cls");
				ch=inputchoice(count,ch);
				break;
			
		case 2:
				if(flag1==1)
				{
					printf("You have already input this data!\n");
				}
				else
				{
					flag1=1;
					count=count+1;
					printf("========================================================================================================================\n\n");
					for(i=0; i<lines; i++)
					{
						printf("Line %d:", i+1);
						scanf("%d", &e1[i]);
						printf("\n\n");
					}
				}
				printf("\n");
				printf("Press any key to Continue...");
				getch();
				scanf("%c", &x);
				system("cls");
				ch=inputchoice(count,ch);
				break;
		case 3:
				if(flag2==1)
				{
					printf("You have already input this data!\n");
				}
				else
				{
					flag2=1;
					count=count+1;
					printf("========================================================================================================================\n\n");
					for(i=0; i<lines; i++)
					{
						printf("Line %d:", i+1);
						scanf("%d", &e2[i]);
						printf("\n\n");
					}
				}
				printf("\n");
				printf("Press any key to Continue...");
				getch();
				scanf("%c", &x);
				system("cls");
				ch=inputchoice(count,ch);
				break;
		case 4:
				if(flag3==1)
				{
					printf("You have already input this data!\n");
				}
				else
				{
					flag3=1;
					count=count+1;
					printf("========================================================================================================================\n\n");
					for(i=0; i<lines; i++)
					{
						for(j=0; j<machines-1; j++)
						{
							printf("The time taken to travel from Machine %d of Line %d to: \n", j+1, i+1);
							for(k=0; k<lines; k++)
							{
								printf("Machine %d of line %d: \n", j+2, k+1);
								scanf("%d", &w2[i][j][k]);
							}
						}
					}
				}
				printf("\n");
				printf("Press any key to Continue...");
				getch();
				scanf("%c", &x);
				system("cls");
				ch=inputchoice(count,ch);
				break;
		case 5:
				flag=0;
				flag1=0;
				flag2=0;
				flag3=0;
				count=0;
				check=0;
				printf("\n");
				printf("The values haven been reset!\n\n");
				printf("Press any key to Continue...");
				getch();
				scanf("%c", &x);
				system("cls");
				ch=inputchoice(count,ch);
				break;
		case 6:
				system("cls");
				count=0;
				check=0;
				main();
				break;
		default:
				printf("Invalid input\n");
				printf("Press any key to Try again...");
				getch();
				scanf("%c", &x);
				system("cls");
				ch=inputchoice(count,ch);
				break;
		}
	}
	check=count;
}

int main()
{
	int c=0, ch;
	printf("\t\t\tHere we go!!\n\n");
	char x;
	printf("\tFirst enter the number of lines and machines in your factory...\n");
	printf("\tThe number of lines: ");
	scanf("%d", &lines);
	printf("\tThe number of machines in each line:");
	scanf("%d", &machines);
	printf("\n\n");
	printf("Press any key to Continue... ");
	getch();
	scanf("%c", &x);
	system("cls");
	int i,j,k;
	int e1[lines];
	int e2[lines];
	
	int *w1[lines];
	for (i=0; i<lines; i++)
	{
		w1[i]= (int *)malloc(machines* sizeof(int));			
	}
	
	int ***w2= (int***)malloc(lines *sizeof(int**));
	for(i=0; i<lines; i++)
	{
		w2[i]=(int**)malloc(machines*sizeof(int*));
		for(j=0; j<machines; j++)
		{
			w2[i][j]=(int*)malloc(machines* sizeof(int));	
		}
	}
	again:
	printf("                             HOME PAGE:\n");
	printf("\nPress 1 to Input the data");
	printf("\t\t\t\t(PLEASE INPUT THE DATA FIRST!!! IF DONE, IGNORE THIS MESSAGE)");
	printf("\nPress 2 to Input Menu");
	printf("\nPress 3 to Display the input data");
	printf("\nPress 4 to Process and Display the most optimised path");
	printf("\nPress 5 to END the program");
	printf("\n\nEnter the choice:");
	scanf("%d", &ch);
	system("cls");
	switch(ch)
	{
		case 1:
			input(e1,e2,w1,w2);
			process(e1,e2,w1,w2);
			goto again;
			break;
		case 2:
			input(e1,e2,w1,w2);
			goto again;
			break;
		case 3:
			display(e1,e2,w1,w2);
			goto again;
			break;
		case 4:
			process(e1,e2,w1,w2);
			goto again;
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("\nWRONG CHOICE!!!");
			break;	
	}
	return 0;
}

