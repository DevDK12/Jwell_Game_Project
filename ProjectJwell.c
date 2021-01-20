/*
Make sure that your Compiler Supports conio.h header file as it includes keyboardHit function and getchar from Conio.h 
*/

#include <stdio.h>
#include <conio.h>
#define CHECKKEY _kbhit()

#include <stdlib.h>
#include <time.h>

//Function Declaration. U must declare all the function
void drawBoundary(int, int, int *, int *, int *);
void changeUserLocationOnButtonClick(int *, int *, char, int *, int *);

void drawBoundary(int x, int y, int *posX, int *posY, int *gameOver)
{ // Passing User Coordinate And JWEL Coordinate
	// Here I will be drawing the boundary using # character.

	int i, j, k;
	for (i = -1; i <= 10; i++)
	{
		for (j = -1; j <= 50; j++)
		{
			if (i == -1 || i == 10 || j == -1 || j == 50)
			{
				printf("#");
			}
			else
			{ //using empty space
				if (i == y && j == x)
				{
					printf("P");
					//checking by for loop that if all jwels are at origin or not
					for (k = 0; k < 4; k++)
					{
						if (posX[k] == x && posY[k] == y)
						{
							posX[k] = -1;
							posY[k] = -1;
							(*gameOver)++; // if we are here means we are able to collect the jwels hence incrementing gameOver.
						}				   //ending checker if
					}					   //ending checker loop
				}						   //end if
				else
				{
					if (posX[0] == j && posY[0] == i)
					{
						printf("a");
					}
					else if (posX[1] == j && posY[1] == i)
					{
						printf("b");
					}
					else if (posX[2] == j && posY[2] == i)
					{
						printf("c");
					}
					else if (posX[3] == j && posY[3] == i)
					{
						printf("d");
					}
					else
						printf(" ");
				} //end current if
			}
		}
		printf("\n");
	}
}

void changeUserLocationOnButtonClick(int *x, int *y, char keyPressed, int *noOfMoves, int *gameQuit)
{
	switch (keyPressed)
	{
	case 'w': // ASCII value of  UP Arrow Key
		if (*y != 0)
		{
			(*noOfMoves)++;
			(*y)--; // Changing y
		}
		break;
	case 'a': // ASCII value of  LEFT Arrow Key
		if (*x != 0)
		{
			(*noOfMoves)++;
			(*x)--; // Changing x
		}
		break;
	case 's': // ASCII value of  RIGHT Arrow Key
		if (*x != 49)
		{
			(*noOfMoves)++;
			(*x)++; // Changing x
		}
		break;
	case 'z': // ASCII value of  DOWN Arrow Key
		if (*y != 9)
		{
			(*noOfMoves)++;
			(*y)++; // Changing y
		}
		break;
	case 'q':
		*gameQuit = 1; // storing 1 to gameQuit variable indicate that user has quit the GAME
		break;
	}
}

int main()
{
	char choose = '0';
	do
	{
		system("cls");
		printf("\n############################################################\n");
		printf("\t\t\tJWELL GAME\n\n\n\n");
		printf("1.\t\t\tEnter game\n\n");
		printf("2.\t\t\tAbout ME\n\n");
		printf("3.\t\t\tInstructions\n\n");
		printf("4.\t\t\tQuit Game\n\n");
		printf("\n\n\t-->Please Read Instructions carefully<--");

		printf("\n\n\n############################################################\n");
		printf("\n---->Enter your selection <1-4> : ");
		scanf("%c", &choose);
		fflush(stdin);
		//	if(choose!=4)	system("cls");
		switch (choose)
		{
		case '1':
			system("cls");
			{							//Case 1 start
				int x = 0, y = 0;		// for user position
				char ch;				// to store the key Pressed
				int positionX[4] = {0}; // Jwel X Position
				int positionY[4] = {0}; // Jwel Y Position
				int randomNum, i = 0;
				int gameOver = 0, noOfMoves = 0, gameQuit = 0;

				srand(time(0)); 

				// Storing the random X Position For JWEL
				while (i < 4)
				{
					randomNum = rand() % 50;
					positionX[i] = randomNum;
					i++;
				}
				// Storing the random Y Position For JWEL
				i = 0;
				while (i < 4)
				{
					randomNum = rand() % 10;
					positionY[i] = randomNum;
					i++;
				}

				drawBoundary(x, y, positionX, positionY, &gameOver); // Function Call

				while (1)
				{
					if (_kbhit())
					{
						ch = getchar();
				    	system("cls"); 
					changeUserLocationOnButtonClick(&x, &y, ch, &noOfMoves, &gameQuit);
						if (gameQuit == 0)
						{ // if gameQuit is 1 means user has pressed 'q' key
							drawBoundary(x, y, positionX, positionY, &gameOver);
							if (gameOver == 4)
							{ // if gameOver value becomes 4 means we have collected all the jwels
								system("cls");
								printf("\n[][][][] Well Done [][][][]\n");
								printf("\nYou Collected All The Jwels!\n");
								printf("\nIt Took You %d Moves!\n", noOfMoves);
								printf("\n[][][][] Game Over [][][][]\n");
								break; // it will break infinite loop as we have won the game
							}
						}
						else
						{
							system("cls");
							printf("\nOh No! You Quit!!\n");
							printf("\nYou Collected %d Jwels!\n", gameOver);   // gameOver will give the number of jwel collected.
							printf("\nAfter %d Moves You Quit!\n", noOfMoves); // gives number of moves so for.
							printf("\n[][][][] Game Over [][][][]\n");
							break; //breaking the infinite loop
						}
					} //end kbhit if
				}// end while loop
	system("pause");		//	getch();
			} //Case 1 ended
			break;

		case '2':
			system("cls");
			printf("\n############################################################\n");
			printf("\nAuthor :\tDev Kumar Gupta\n\n\n");
			printf("About me :\tA passionate learner who is interested in-->\n\n");
			printf("\t\t1)C /C++ \n\n");
			printf("\t\t2)Python and Machine Learning\n\n");
			printf("\t\t3)Ethical Hacking \n\n");
			printf("\t\t4)IT \n\n");
			printf("\t\t5)Web Developmenf Front End\n\n\n");
			
			printf("\tThis Game is based on Concept of pointers and arrays\n\n\n");
			
			printf("\n############################################################\n");
			system("pause");
			break;

		case '3':
			system("cls");

			printf("\t\tINSTRUCTIONS\n\n\n");
			printf("1. \tUse key 'a' to move left\n\n");
			printf("2. \tUse key 's' to move right\n\n");
			printf("3. \tUse key 'w' to move up\n\n");
			printf("4. \tUse key 'z' to move down\n\n");
			printf("5. \tPress 'q' To Quit The Game Any Time\n\n");
			system("pause");
			break;

		case '4':
			printf("Thanks for playing Come back again");

		default:
			if (choose != '4')
				printf("\n\n =>\t-_- Enter Valid Options only!!!!\n\n");
			system("pause");
			break;

		} //switch end

	} while (choose != '4');

	return (0);
}