#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

char bombdetector[100][100];
int direction[100][100], bombplace[100][100];

void board()
{
	int i,j;
	system("cls");
	
	printf("\n\n\t\t\t\t-----------------\n");
    printf("\t\t\t\t---MINESWEEPER---\n");
    printf("\t\t\t\t-----------------\n");
	printf("       ");
	for(j=0; j<10; j++)
		{
    		printf("_____  "); 
    		if(j==9)
    		{
				printf("\n");
			}
		}
		
	for(i=0; i<10; i++)
	{
		printf("      |");
		for(j=0; j<10; j++)
		{
			if(direction[i][j] != 1000 && direction[i][j] < 10) /* if the number not 1000, it will print the direction based on its value (0-9) */
			{
				printf("  %d  | ", direction[i][j]);
    		}
    		
    		else if(direction[i][j] != 1000 && direction[i][j] < 100) /* if the number not 1000, it will print the direction based on its value (10-99) */
			{
				printf("  %d | ", direction[i][j]);
    		}
    		
    		else if(direction[i][j] != 1000 && direction[i][j] < 1000) /* if the number not 1000, it will print the direction based on its value (100) */
			{
				printf(" %d | ", direction[i][j]);
    		}
    		
    		else
    		{
    			printf("  %c  | ", bombdetector[i][j]); /* if the coordinate changes into 10000, it will print into bombdetector */
			}
		}
		printf("\n");
		printf("       ");
		for(j=0; j<10; j++)
		{
    		printf("_____  ");
    		if(j==9)
    		{
				printf("\n");
			}
		}
	}
}

int checkboard(int choice)
{
	char a;
	int i,j,k=0,aman=0;
	for(i=0; i<10; i++) /* There are 2 loops bcs its multi dimentional */
	{
		for(j=0; j<10; j++)
		{
			
			if(direction[i][j] == choice) /* if our choice is the same like the directional then proceed to next step */
			{
				if(bombplace[i][j] == 1) /* Finding the bomb in the coordinate that we choose, this if used to if there is a bomb*/
				{
					bombdetector[i][j] = 'X';
					return 0;
				}
				
				else /* if there is no bomb */
				{
					direction[i][j] = 1000; /* There are will be no same coordinate bcs change to 1000 */
					bombdetector[i][j] = ' ';
					k=1;
				}
			}
			if(k == 1) /* Next if is to find if there is a bomb near the coordinate */
			{
			a='`';/* to show the hint ex:(a,b,c,d) */
			
				/*Cek Atas Kiri*/
				
				if(bombplace[i-1][j-1] == 1)
				{
					a++;
				}
				
				/*Cek Atas*/
				if(bombplace[i-1][j] == 1)
				{
					a++;
				}
				
				/*Cek Atas Kanan*/
				if(bombplace[i-1][j+1] == 1)
				{
					a++;
				}
				
				/*Cek Kiri*/
				if(bombplace[i][j-1] == 1)
				{
					a++;
				}
				
				/*Cek Kanan*/
				if(bombplace[i][j+1] == 1)
				{
					a++;	
				}
				
				/*Cek Bawah Kiri*/
				if(bombplace[i+1][j-1] == 1)
				{
					a++;
				}
				
				/*Cek Bawah*/
				if(bombplace[i+1][j] == 1)
				{
					a++;
				}
				
				/*Cek Bawah Kanan*/
				if(bombplace[i+1][j+1] == 1)
				{
					a++;
				}
				if(a=='`') /* if there are no bombs around the coordinate it will stay at " " */
				{
					a=' '; /*  */
				}
				bombdetector[i][j] = a;
			 k=0;	
			}
			k=0;
			
		}
	}
	
	
	
	/*Cek win*/
	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
		{
			if(direction[i][j] == 1000)
			{
				aman++;
			}
		}
	}
	
	if(aman == 88)
	{
		return 1;
	}
	
	return -1;
}

void bombDisplay()
{
	int i,j;
	system("cls");
	printf("       ");
	for(j=0; j<10; j++)
		{
    		printf("_____  "); 
    		if(j==9)
    		{
				printf("\n");
			}
		}
		
	for(i=0; i<10; i++)
	{
		printf("      |");
		for(j=0; j<10; j++)
		{
			if(bombplace[i][j] == 1)
    			printf("  X  | "); /* Display Bomb*/
    			
    		else
    		printf("     | ");
		}
		printf("\n");
		printf("       ");
		for(j=0; j<10; j++)
		{
    		printf("_____  ");
    		if(j==9)
    		{
				printf("\n");
			}
		}
	}
}
int main()
{
	int x=0, i, j, k, init=1, randomNum, choice, win, difficulty, breaker=0;
	while (x==0)
	{
		printf("\n\n\t\t\t\t-----------------\n");
    	printf("\t\t\t\t---MINESWEEPER---\n");
    	printf("\t\t\t\t-----------------\n");
		printf ("HELLO THERE.... Welcome to the best minesweeper game of all time\n");
		printf ("PLEASE STAY AWAY FROM MINES IF YOU WANT TO WIN THE GAME\n");		
		printf("1. Easy (12 bombs)\n2. Medium (24 bombs)\n3. Hard (36 bombs)\n");
		printf("please select a difficulty:");
		scanf("%d", &difficulty);
		
		if(difficulty==1||difficulty==2||difficulty==3)
		{
			x++;
		}
		else
		{
			printf("you should enter a number between 1-3!");
			system("pause");
		}
	}
	/*init*/
	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
		{
			direction[i][j] = init;
			bombdetector[i][j] = '0';
			bombplace[i][j] = 0;
			init++;
		}
	}
	
	srand(time(NULL));
	if (difficulty==1)
	{
	
	for(i=0; i<12; i++)
	{
		/*init bomb*/
		randomNum=rand()%100;
		if(randomNum==0)
		{
			randomNum++;
		}
		
		/*place bomb*/
		for(k=0; k<10; k++)
	{
		for(j=0; j<10; j++)
		{
			if(direction[k][j] == randomNum)
			{
				if(bombplace[k][j] == 1)
				{
					breaker = 1;
					break;
				}
				else
				{
					bombplace[k][j] = 1;
				}
			}
		}
		if(breaker == 1)
		{
			breaker = 0;
			i--;
			break;
		}
	}
	}
}
	else if(difficulty==2)
	{
		for(i=0; i<24; i++)
	{
		/*init bomb*/
		randomNum=rand()%100;
		if(randomNum==0)
		{
			randomNum++;
		}
		
		/*place bomb*/
		for(k=0; k<10; k++)
	{
		for(j=0; j<10; j++)
		{
			if(direction[k][j] == randomNum)
			{
				if(bombplace[k][j] == 1)
				{
					breaker = 1;
					break;
				}
				else
				{
					bombplace[k][j] = 1;
				}
			}
		}
		if(breaker == 1)
		{
			breaker = 0;
			i--;
			break;
		}
	}
	}
	}
	else if(difficulty == 3)
	{
		for(i=0; i<36; i++)
	{
		/*init bomb*/
		randomNum=rand()%100;
		if(randomNum==0)
		{
			randomNum++;
		}
		
		/*place bomb*/
		for(k=0; k<10; k++)
	{
		for(j=0; j<10; j++)
		{
			if(direction[k][j] == randomNum)
			{
				if(bombplace[k][j] == 1)
				{
					breaker = 1;
					break;
				}
				else
				{
					bombplace[k][j] = 1;
				}
			}
		}
		if(breaker == 1)
		{
			breaker = 0;
			i--;
			break;
		}
	}
	}
	}
	board();
	do
	{
	back:
	system("cls");
	board();	
	printf ("HINT : a there are 1 bomb around\n");
	printf ("       b there are 2 bombs around\n");
	printf ("       c there are 3 bombs around etc.\n");
	printf ("input 0 to display bombs");
	printf("\n\nPlease input one of the number above: \n");
	scanf(" %d", &choice);
	if(choice<0 || choice>100)
	{
		printf("Invalid Input!");
		getch();
		system("cls");
		goto back;
	}
	else if(choice==0)
	{	
		bombDisplay();
		system("pause");
		goto back;
	}
	
	
	win = checkboard(choice);
	
	}while(win == -1);
	board();
	if(win==1)
	{
	
		printf ("You win the game!!!!!!!!!! ");
		
		
	}
	else
	{
		bombDisplay();
 
		printf("\n    _.-^^---....,,-- \n");
		printf("_--                  --_\n");
		printf("<                        >)\n");
		printf("<     BOOOOOOOMMMMM      >)\n");
		printf("|                         |\n");
		printf("   ```--. . , ; .--'''\n");
		printf("	| |   |       \n");
		printf("	| |   |             \n");
		printf("	| |   |  \n");
		printf("     .-=||  | |=-.\n");
		printf("     `-=#$%&%$#=-' \n");
		printf("	| ;  :| \n");
		printf("_____.,-#%&$@%#&#~,._____\n");
		printf("\nYOU LOSE!, you just stepped on the bomb\n\n");
	}
	system("pause");
	return 0;
}
