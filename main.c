/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 17:36:00 by nsterk        #+#    #+#                 */
/*   Updated: 2020/12/22 10:33:13 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

void	putPic(char **pic, int x, int y)
{
	int i = 0;
	int x_axis;
	int y_axis;

	if (y < 0)
	{
		while (y < 0)
		{
			printf("\n");
			y++;
		}

	}
	else
		while (y)
		{
			printf("\n");
			y--;
		}
	while (pic[i])
	{
		x_axis = x;
		while (x_axis)
		{
			printf(" ");
			x_axis--;
		}
		printf("%s\n", pic[i]);
		i++;
	}
}

void setColour(colour)
{
	if (colour == 0)
		printf("\e[0;38;5;88m");
	else if (colour == 1)
		printf("\e[0;38;5;125m");
	else if (colour == 2)
		printf("\e[0;38;5;162m");
	else if (colour == 3)
		printf("\e[0;38;5;199m");
	else if (colour == 4)
		printf("\e[0;38;5;128m");
	else if (colour == 5)
		printf("\e[0;38;5;93m");
	else if (colour == 6)
		printf("\e[0;38;5;62m");
	else if (colour == 7)
		printf("\e[0;38;5;27m");
	else if (colour == 8)
		printf("\e[0;38;5;25m");
	else if (colour == 9)
		printf("\e[0;38;5;23m");
	else if (colour == 10)
		printf("\e[0;38;5;22m");
}

int		changeColour(int colour)
{
	if (colour < 10)
		colour++;
	else
		colour = 0;
	return (colour);
}

int	main(void)
{
	char	**pic;
	int		x = 2;
	int		y = 3;
	int		timer = 25;
	int		colour = 0;
	                               
	pic[0] = " #####     ####    #####     ####   ";
	pic[1] = "##   ##   ##  ##  ##   ##   ##  ##  ";
	pic[2] = "    ###  ##   ##      ###  ##   ##  ";
	pic[3] = "   ###   ##   ##     ###   ##   ##  ";
	pic[4] = "  ##     ##   ##    ##     ##   ##  ";
	pic[5] = " ##      ##  ##    ##      ##  ##   ";
	pic[6] = "#######   ####    #######   ####    ";
	pic[7] = NULL;

	while (timer)
	{
		while (x < 120)//change to 150 if fullscreen? (on my mac)
		{
			printf("\e[1;1H\e[2J");
			setColour(colour);
			putPic(pic, x, y);
			usleep(67000);
			if (y > 40)
			{
				y = -y;
				colour = changeColour(colour);
			}
			else if (!y)
				colour = changeColour(colour);
			x++;
			y++;
		}
		colour = changeColour(colour);
		while (x > 5)
		{
			printf("\e[1;1H\e[2J");
			setColour(colour);
			putPic(pic, x, y);
			usleep(67000);
			if (y > 40)
			{
				y = -y;
				colour = changeColour(colour);
			}
			else if (!y)
				colour = changeColour(colour);
			y++;
			x--;
		}
		colour = changeColour(colour);
		timer--;
	}
	printf("\e[0m");
	return (0);
}
