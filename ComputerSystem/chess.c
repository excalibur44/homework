#include <stdio.h>
#include <iostream>

char R1[36], R6;
int R2, R3, R4, R5;

void wrong() { printf("Invalid move. Try again.\n"); }

void insert()
{
IF1:
	if(R4 == 0)
		printf("Player 1, choose a column:");
	else
		printf("Player 2, choose a column:");
	std::cin >> R6;
	if (R6 >= '0' && R6 <= '6')
	{
		R2 = (int)R6 - 48;
		R2 += 29;
		for (R3 = 0; R3 < 6; R3++)
		{
			if (R1[R2] == '-')
			{
				if(R4 == 0)
					R1[R2] = 'O';
				else
					R1[R2] = 'X';
				return;
			}
			R2 -= 6;
		}
		goto IF2;
	}
	else
IF2:	wrong();
	//getchar();
	goto IF1;
}

void output()
{
	for (R3 = 0, R4 = 6; R3 < 36; R3++)
	{
		printf("%c ", R1[R3]);
		if (R4 == 1)
		{
			printf("\n");
			R4 = 6;
		}
		else
			R4--;
	}
    return;
}

void start()
{
	for (R3 = 0; R3 < 36; R3++)
	{
		R1[R3] = '-';
	}
    return;
}

void judge()
{
	//'-'
	for (R3 = 0, R4 = 0; R3 < 3; R3++)
	{
		if (R1[R4 + 0] == '-' ||
			R1[R4 + 0] - R1[R4 + 1] ||
			R1[R4 + 1] - R1[R4 + 2] ||
			R1[R4 + 2] - R1[R4 + 3])
		{
			R4 += 1;
			if (R4 % 3 == 0)
			{
				R4 += 3;
				R3 = -1;
			}
			if (R4 > 35)
				R3 = 3; //break;
		}
        else
        {
            if (R1[R4] == 'O')
                printf("Player 1 Wins.\n");
            else
                printf("Player 2 Wins.\n");
			R2 = 0;
            return;
        }
	}
	//'|'
	for (R3 = 0; R3 < 18; R3++)
	{
		if (R1[R3 + 00] == '-' ||
			R1[R3 + 00] - R1[R3 + 06] ||
			R1[R3 + 06] - R1[R3 + 12] ||
			R1[R3 + 12] - R1[R3 + 18])
			;
        else
        {
            if (R1[R3] == 'O')
                printf("Player 1 Wins.\n");
            else
                printf("Player 2 Wins.\n");
			R2 = 0;
            return;
        }
	}
	//'/'
	for (R3 = 0, R4 = 3; R3 < 3; R3++)
	{
		if (R1[R4 + 0] == '-' ||
			R1[R4 + 0] - R1[R4 + 5] ||
			R1[R4 + 5] - R1[R4 + 10] ||
			R1[R4 + 10] - R1[R4 + 15])
		{
			R4 += 1;
			if (R4 % 3 == 0)
			{
				R4 += 3;
				R3 = -1;
			}
			if (R4 > 17)
				R3 = 3; //break;
		}
        else
        {
            if (R1[R4] == 'O')
                printf("Player 1 Wins.\n");
            else
                printf("Player 2 Wins.\n");
			R2 = 0;
            return;
        }
	}
	//'\'
	for (R3 = 0, R4 = 0; R3 < 3; R3++)
	{
		if (R1[R4 + 0] == '-' ||
			R1[R4 + 0] - R1[R4 + 7] ||
			R1[R4 + 7] - R1[R4 + 14] ||
			R1[R4 + 14] - R1[R4 + 21])
		{
			R4 += 1;
			if (R4 % 3 == 0)
			{
				R4 += 3;
				R3 = -1;
			}
			if (R4 > 14)
				R3 = 3; //break;
		}
        else
        {
            if (R1[R4] == 'O')
                printf("Player 1 Wins.\n");
            else
                printf("Player 2 Wins.\n");
			R2 = 0;
            return;
        }
	}
	//FULL?
	for (R3 = 0; R3 < 36; R3++)
        if (R1[R3] == '-')
        {
            R2 = 3;
            return;
        }
	printf("Tie Game.\n");
    return;
}

int main()
{
	start();
	output();
start:
	R4 = 0;
	insert();
	output();
	judge();
	if (R2 == 0)
		return 0;
	
	R4 = 1;
	insert();
	output();
	judge();
	if (R2 == 0)
		return 0;
	
	goto start;
}
