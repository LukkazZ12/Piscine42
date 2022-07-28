/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucade-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:04:57 by lucade-s          #+#    #+#             */
/*   Updated: 2022/07/17 21:04:57 by lucade-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
    char    c;
    int     i;
    int     j;
    int     k;
	int     n;
    int     s_r;
    int     s_c;
    int     views[16];
    int     sky_scrapers[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    
    if (argc != 2)
        return (1);
    n = 0;
    while (argv[1][n] != '\0')
        n++;
    if (n != 31)
    return (1);
    i = 0;
    j = 0;
    while (i < n)
    {
        if (argv[1][i] == ' ')
        {
            i++;
            continue;
        }
        views[j] = argv[1][i] - '0';
        i++;
        j++;
    }
	i = 0;
    while(i < 16)
    {
       if (views[i] == 4)
        {
            if (i <= 3)
            {
                j = 0;
                while(j <= 3)
                {             
                    sky_scrapers[j][i] = j + 1;
                    j++;
                }
            }
            else if (i <= 7)
            {
                j = 0;
                while(j <= 3)
                {
                    sky_scrapers[j][i - 4] = 4 - j;
                    j++;
                }
            }
            else if (i <= 11)
            {
                j = 0;
                while(j <= 3)
                {
                    sky_scrapers[i - 8][j] = j + 1;
                    j++;
                }
            }
            else
            {
                j = 0;
                while(j <= 3)
                {
                    sky_scrapers[i - 12][j] = 4 - j;
                    j++;
                }
            }
        }
        else if (views[i] == 1)
        {
            if (i <= 3)
            {
                sky_scrapers[0][i] = 4;
                if (views[i + 4] == 2)
                    sky_scrapers[3][i] = 3;
            }
            else if (i <= 7)
            {
                sky_scrapers[3][i - 4] = 4;
                if (views[i - 4] == 2)
                    sky_scrapers[0][i - 4] = 3;
            }
            else if (i <= 11)
            {
                sky_scrapers[i - 8][0] = 4;
                if (views[i + 4] == 2)
                    sky_scrapers[i - 8][3] = 3;
            }
            else
            {
                sky_scrapers[i - 12][3] = 4;
                if (views[i - 4] == 2)
                    sky_scrapers[i - 12][0] = 3;
            }
        }
        else if (views[i] == 2)
        {
            if (i <= 3)
            {
                if (views[i + 4] == 3)
                    sky_scrapers[1][i] = 4;
                if (i != 0 && i != 3 && views[i + 4] == 2)
                {
                    if (views[i + 8] == 2 && views[i + 12] == 2)
                    {
                        if (i == 1)
                            sky_scrapers[1][1] = 4;
                        else
                            sky_scrapers[2][2] = 4;
                    }
                    else if (i == 1 && views[i + 9] == 2 && views[i + 13] == 2)
                            sky_scrapers[2][1] = 4;
                    else if (i == 2 && views[i + 7] == 2 && views[i + 11] == 2)
                        sky_scrapers[1][2] = 4;
                }
            }
            else if (i <= 7)
            {
                if (views[i - 4] == 3)
                    sky_scrapers[2][i - 4] = 4;
            }
            else if (i <= 11)
            {
                if (views[i + 4] == 3)
                    sky_scrapers[i - 8][1] = 4;
            }
            else
                if (views[i - 4] == 3)
                    sky_scrapers[i - 12][2] = 4;
        }
        i++;
    }
    i = 0;
    while (i <= 3)
    {
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][1] == 3)
        {
            if (sky_scrapers[i][2] == 0)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][2] == 3)
        {
            if (sky_scrapers[i][1] == 0)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
        }
        if (sky_scrapers[i][0] == 3 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 3 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][2] == 1)
        {
            if (views[i + 8] == 1 && views[i + 12] == 3)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 1 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][3] = 3;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][1] == 1)
        {
            if (views[i + 8] == 3 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][0] = 3;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        if (sky_scrapers[0][j] == 4 && sky_scrapers[1][j] == 3)
        {
            if (sky_scrapers[2][j] == 0)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[2][j] == 3)
        {
            if (sky_scrapers[1][j] == 0)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
        }
        if (sky_scrapers[0][j] == 3 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 3 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[i] == 3 && views[i + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 4 && sky_scrapers[2][j] == 1)
        {
            if (views[j] == 1 && views[j + 4] == 3)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 1 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[3][j] = 3;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[1][j] == 1)
        {
            if (views[j] == 3 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[0][j] = 3;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        j = 0;
        s_r = 0;
        while (j <= 3)
        {   
            s_r = s_r + sky_scrapers[i][j];
            j++;
        }
        j = 0;
        while (j <= 3)
        {
            k = s_r - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[i][0] != 3 && sky_scrapers[i][1] != 3 && sky_scrapers[i][2] != 3 && sky_scrapers[i][3] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            j++;
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        i = 0;
        s_c = 0;
        while (i <= 3)
        {
            s_c = s_c + sky_scrapers[i][j];
            i++;
        }
        i = 0;
        while (i <= 3)
        {
            k = s_c - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[0][j] != 3 && sky_scrapers[1][j] != 3 && sky_scrapers[2][j] != 3 && sky_scrapers[3][j] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            i++;
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][1] == 3)
        {
            if (sky_scrapers[i][2] == 0)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][2] == 3)
        {
            if (sky_scrapers[i][1] == 0)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
        }
        if (sky_scrapers[i][0] == 3 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 3 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][2] == 1)
        {
            if (views[i + 8] == 1 && views[i + 12] == 3)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 1 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][3] = 3;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][1] == 1)
        {
            if (views[i + 8] == 3 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][0] = 3;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        if (sky_scrapers[0][j] == 4 && sky_scrapers[1][j] == 3)
        {
            if (sky_scrapers[2][j] == 0)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[2][j] == 3)
        {
            if (sky_scrapers[1][j] == 0)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
        }
        if (sky_scrapers[0][j] == 3 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 3 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[i] == 3 && views[i + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 4 && sky_scrapers[2][j] == 1)
        {
            if (views[j] == 1 && views[j + 4] == 3)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 1 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[3][j] = 3;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[1][j] == 1)
        {
            if (views[j] == 3 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[0][j] = 3;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        j = 0;
        s_r = 0;
        while (j <= 3)
        {   
            s_r = s_r + sky_scrapers[i][j];
            j++;
        }
        j = 0;
        while (j <= 3)
        {
            k = s_r - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[i][0] != 3 && sky_scrapers[i][1] != 3 && sky_scrapers[i][2] != 3 && sky_scrapers[i][3] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            j++;
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        i = 0;
        s_c = 0;
        while (i <= 3)
        {
            s_c = s_c + sky_scrapers[i][j];
            i++;
        }
        i = 0;
        while (i <= 3)
        {
            k = s_c - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[0][j] != 3 && sky_scrapers[1][j] != 3 && sky_scrapers[2][j] != 3 && sky_scrapers[3][j] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            i++;
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][1] == 3)
        {
            if (sky_scrapers[i][2] == 0)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][2] == 3)
        {
            if (sky_scrapers[i][1] == 0)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
        }
        if (sky_scrapers[i][0] == 3 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 3 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][2] == 1)
        {
            if (views[i + 8] == 1 && views[i + 12] == 3)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 1 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][3] = 3;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][1] == 1)
        {
            if (views[i + 8] == 3 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][0] = 3;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        if (sky_scrapers[0][j] == 4 && sky_scrapers[1][j] == 3)
        {
            if (sky_scrapers[2][j] == 0)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[2][j] == 3)
        {
            if (sky_scrapers[1][j] == 0)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
        }
        if (sky_scrapers[0][j] == 3 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 3 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[i] == 3 && views[i + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 4 && sky_scrapers[2][j] == 1)
        {
            if (views[j] == 1 && views[j + 4] == 3)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 1 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[3][j] = 3;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[1][j] == 1)
        {
            if (views[j] == 3 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[0][j] = 3;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        j = 0;
        s_r = 0;
        while (j <= 3)
        {   
            s_r = s_r + sky_scrapers[i][j];
            j++;
        }
        j = 0;
        while (j <= 3)
        {
            k = s_r - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[i][0] != 3 && sky_scrapers[i][1] != 3 && sky_scrapers[i][2] != 3 && sky_scrapers[i][3] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            j++;
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        i = 0;
        s_c = 0;
        while (i <= 3)
        {
            s_c = s_c + sky_scrapers[i][j];
            i++;
        }
        i = 0;
        while (i <= 3)
        {
            k = s_c - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[0][j] != 3 && sky_scrapers[1][j] != 3 && sky_scrapers[2][j] != 3 && sky_scrapers[3][j] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            i++;
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][1] == 3)
        {
            if (sky_scrapers[i][2] == 0)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][2] == 3)
        {
            if (sky_scrapers[i][1] == 0)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
        }
        if (sky_scrapers[i][0] == 3 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 3 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][2] == 1)
        {
            if (views[i + 8] == 1 && views[i + 12] == 3)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 1 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][3] = 3;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][1] == 1)
        {
            if (views[i + 8] == 3 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][0] = 3;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        if (sky_scrapers[0][j] == 4 && sky_scrapers[1][j] == 3)
        {
            if (sky_scrapers[2][j] == 0)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[2][j] == 3)
        {
            if (sky_scrapers[1][j] == 0)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
        }
        if (sky_scrapers[0][j] == 3 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 3 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[i] == 3 && views[i + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 4 && sky_scrapers[2][j] == 1)
        {
            if (views[j] == 1 && views[j + 4] == 3)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 1 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[3][j] = 3;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[1][j] == 1)
        {
            if (views[j] == 3 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[0][j] = 3;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        j = 0;
        s_r = 0;
        while (j <= 3)
        {   
            s_r = s_r + sky_scrapers[i][j];
            j++;
        }
        j = 0;
        while (j <= 3)
        {
            k = s_r - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[i][0] != 3 && sky_scrapers[i][1] != 3 && sky_scrapers[i][2] != 3 && sky_scrapers[i][3] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            j++;
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        i = 0;
        s_c = 0;
        while (i <= 3)
        {
            s_c = s_c + sky_scrapers[i][j];
            i++;
        }
        i = 0;
        while (i <= 3)
        {
            k = s_c - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[0][j] != 3 && sky_scrapers[1][j] != 3 && sky_scrapers[2][j] != 3 && sky_scrapers[3][j] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            i++;
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][1] == 3)
        {
            if (sky_scrapers[i][2] == 0)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][2] == 3)
        {
            if (sky_scrapers[i][1] == 0)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
        }
        if (sky_scrapers[i][0] == 3 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 3 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][2] == 1)
        {
            if (views[i + 8] == 1 && views[i + 12] == 3)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 1 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][3] = 3;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][1] == 1)
        {
            if (views[i + 8] == 3 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][0] = 3;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        if (sky_scrapers[0][j] == 4 && sky_scrapers[1][j] == 3)
        {
            if (sky_scrapers[2][j] == 0)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[2][j] == 3)
        {
            if (sky_scrapers[1][j] == 0)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
        }
        if (sky_scrapers[0][j] == 3 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 3 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[i] == 3 && views[i + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 4 && sky_scrapers[2][j] == 1)
        {
            if (views[j] == 1 && views[j + 4] == 3)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 1 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[3][j] = 3;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[1][j] == 1)
        {
            if (views[j] == 3 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[0][j] = 3;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        j = 0;
        s_r = 0;
        while (j <= 3)
        {   
            s_r = s_r + sky_scrapers[i][j];
            j++;
        }
        j = 0;
        while (j <= 3)
        {
            k = s_r - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[i][0] != 3 && sky_scrapers[i][1] != 3 && sky_scrapers[i][2] != 3 && sky_scrapers[i][3] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            j++;
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        i = 0;
        s_c = 0;
        while (i <= 3)
        {
            s_c = s_c + sky_scrapers[i][j];
            i++;
        }
        i = 0;
        while (i <= 3)
        {
            k = s_c - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[0][j] != 3 && sky_scrapers[1][j] != 3 && sky_scrapers[2][j] != 3 && sky_scrapers[3][j] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            i++;
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][1] == 3)
        {
            if (sky_scrapers[i][2] == 0)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][2] == 3)
        {
            if (sky_scrapers[i][1] == 0)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
        }
        if (sky_scrapers[i][0] == 3 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 3 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        if (sky_scrapers[i][0] == 4 && sky_scrapers[i][2] == 1)
        {
            if (views[i + 8] == 1 && views[i + 12] == 3)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][3] = 2;
            }
            else if (views[i + 8] == 1 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 2;
                sky_scrapers[i][3] = 3;
            }
        }
        if (sky_scrapers[i][3] == 4 && sky_scrapers[i][1] == 1)
        {
            if (views[i + 8] == 3 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][0] = 2;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 1)
            {
                sky_scrapers[i][2] = 2;
                sky_scrapers[i][0] = 3;
            }
        }
        if (sky_scrapers[i][0] == 2 && sky_scrapers[i][1] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][2] = 1;
                sky_scrapers[i][3] = 3;
            }
            else if (views[i + 8] == 2 && views[i + 12] == 3)
            {
                sky_scrapers[i][2] = 3;
                sky_scrapers[i][3] = 1;
            }
        }
        if (sky_scrapers[i][3] == 2 && sky_scrapers[i][2] == 4)
        {
            if (views[i + 8] == 2 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 1;
                sky_scrapers[i][0] = 3;
            }
            else if (views[i + 8] == 3 && views[i + 12] == 2)
            {
                sky_scrapers[i][1] = 3;
                sky_scrapers[i][0] = 1;
            }
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        if (sky_scrapers[0][j] == 4 && sky_scrapers[1][j] == 3)
        {
            if (sky_scrapers[2][j] == 0)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[2][j] == 3)
        {
            if (sky_scrapers[1][j] == 0)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
        }
        if (sky_scrapers[0][j] == 3 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 3 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[i] == 3 && views[i + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        if (sky_scrapers[0][j] == 4 && sky_scrapers[2][j] == 1)
        {
            if (views[j] == 1 && views[j + 4] == 3)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[3][j] = 2;
            }
            else if (views[j] == 1 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 2;
                sky_scrapers[3][j] = 3;
            }
        }
        if (sky_scrapers[3][j] == 4 && sky_scrapers[1][j] == 1)
        {
            if (views[j] == 3 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[0][j] = 2;
            }
            else if (views[j] == 2 && views[j + 4] == 1)
            {
                sky_scrapers[2][j] = 2;
                sky_scrapers[0][j] = 3;
            }
        }
        if (sky_scrapers[0][j] == 2 && sky_scrapers[1][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[2][j] = 1;
                sky_scrapers[3][j] = 3;
            }
            else if (views[j] == 2 && views[j + 4] == 3)
            {
                sky_scrapers[2][j] = 3;
                sky_scrapers[3][j] = 1;
            }
        }
        if (sky_scrapers[3][j] == 2 && sky_scrapers[2][j] == 4)
        {
            if (views[j] == 2 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 1;
                sky_scrapers[0][j] = 3;
            }
            else if (views[j] == 3 && views[j + 4] == 2)
            {
                sky_scrapers[1][j] = 3;
                sky_scrapers[0][j] = 1;
            }
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        j = 0;
        s_r = 0;
        while (j <= 3)
        {   
            s_r = s_r + sky_scrapers[i][j];
            j++;
        }
        j = 0;
        while (j <= 3)
        {
            k = s_r - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[i][0] != 3 && sky_scrapers[i][1] != 3 && sky_scrapers[i][2] != 3 && sky_scrapers[i][3] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            j++;
        }
        i++;
    }
    j = 0;
    while (j <= 3)
    {
        i = 0;
        s_c = 0;
        while (i <= 3)
        {
            s_c = s_c + sky_scrapers[i][j];
            i++;
        }
        i = 0;
        while (i <= 3)
        {
            k = s_c - sky_scrapers[i][j];
            if (sky_scrapers[i][j] == 0)
            {
                if (k == 7 && sky_scrapers[0][j] != 3 && sky_scrapers[1][j] != 3 && sky_scrapers[2][j] != 3 && sky_scrapers[3][j] != 3)
                    sky_scrapers[i][j] = 3;
                else if (k == 8)
                    sky_scrapers[i][j] = 2;
                else if (k == 9)
                    sky_scrapers[i][j] = 1;
            }
            i++;
        }
        j++;
    }
    i = 0;
    while (i <= 3)
    {
        j = 0;
        while (j <= 3)
        {
            c = sky_scrapers[i][j] + '0';
            write(1, &c, 1);
            if (j != 3)
                write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
	return (0);
}    
