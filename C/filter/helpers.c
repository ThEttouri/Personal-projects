#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loping through rows
    for (int i = 0; i < height; i++)
    {
        // Loping through pixels
        for (int j = 0; j < width; j++)
        {
            int x = 0;
            if (image[i][j].rgbtBlue == image[i][j].rgbtGreen && image[i][j].rgbtBlue == image[i][j].rgbtRed &&
                image[i][j].rgbtGreen == image[i][j].rgbtRed)
            {
                x++;
            }
            else
            {
                int avg = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
                image[i][j].rgbtBlue = avg;
                image[i][j].rgbtGreen = avg;
                image[i][j].rgbtRed = avg;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loping through rows
    for (int i = 0; i < height; i++)
    {
        int width1 = width;
        if (width % 2 == 0)
        {
            int w = width / 2;
            // Loping through pixels
            for (int j = 0; j < w; j++)
            {
                RGBTRIPLE temp = {0, 0, 0};
                temp = image[i][j];
                image[i][j] = image[i][width1 - 1];
                image[i][width1 - 1] = temp;
                width1--;
            }
        }
        else
        {
            int wi = (width - 1) / 2;
            // Loping through pixels
            for (int j = 0; j < wi; j++)
            {
                RGBTRIPLE temp = {0, 0, 0};
                temp = image[i][j];
                image[i][j] = image[i][width1 - 1];
                image[i][width1 - 1] = temp;
                width1--;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    // Loping through rows
    for (int i = 0; i < height; i++)
    {
        // Loping through pixels
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loping through rows
    for (int i = 0; i < height; i++)
    {
        // Loping through pixels
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE avg = {0, 0, 0};
            // First pixel of first row
            if (i == 0 && j == 0)
            {
                avg.rgbtRed = round(
                                  (copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 4.00);
                avg.rgbtGreen = round(
                                    (copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) /
                                    4.00);
                avg.rgbtBlue = round(
                                   (copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 4.00);

                image[i][j].rgbtRed = avg.rgbtRed;
                image[i][j].rgbtGreen = avg.rgbtGreen;
                image[i][j].rgbtBlue = avg.rgbtBlue;
            }
            // First row
            else if (i == 0 && (j > 0 && j < (width - 1)))
            {
                avg.rgbtRed = round((copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                                     copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) /
                                    6.00);
                avg.rgbtGreen = round((copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                       copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) /
                                      6.00);
                avg.rgbtBlue = round((copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                      copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) /
                                     6.00);

                image[i][j].rgbtRed = avg.rgbtRed;
                image[i][j].rgbtGreen = avg.rgbtGreen;
                image[i][j].rgbtBlue = avg.rgbtBlue;
            }
            // Last pixel of first row
            else if (i == 0 && j == (width - 1))
            {
                avg.rgbtRed = round(
                                  (copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) / 4.00);
                avg.rgbtGreen = round(
                                    (copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) /
                                    4.00);
                avg.rgbtBlue = round(
                                   (copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) / 4.00);

                image[i][j].rgbtRed = avg.rgbtRed;
                image[i][j].rgbtGreen = avg.rgbtGreen;
                image[i][j].rgbtBlue = avg.rgbtBlue;
            }
            // First colomn
            else if ((i > 0 && i < (height - 1)) && j == 0)
            {
                avg.rgbtRed = round((copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j].rgbtRed +
                                     copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) /
                                    6.00);
                avg.rgbtGreen = round((copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen +
                                       copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) /
                                      6.00);
                avg.rgbtBlue = round((copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j].rgbtBlue +
                                      copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) /
                                     6.00);

                image[i][j].rgbtRed = avg.rgbtRed;
                image[i][j].rgbtGreen = avg.rgbtGreen;
                image[i][j].rgbtBlue = avg.rgbtBlue;
            }
            // Middle pixels
            else if ((i > 0 && i < (height - 1)) && (j > 0 && j < (width - 1)))
            {
                avg.rgbtRed = round((copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed +
                                     copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                                     copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) /
                                    9.00);
                avg.rgbtGreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                                       copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                       copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) /
                                      9.00);
                avg.rgbtBlue = round((copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
                                      copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                      copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) /
                                     9.00);

                image[i][j].rgbtRed = avg.rgbtRed;
                image[i][j].rgbtGreen = avg.rgbtGreen;
                image[i][j].rgbtBlue = avg.rgbtBlue;
            }
            // Last colomn
            else if ((i > 0 && i < (height - 1)) && j == (width - 1))
            {
                avg.rgbtRed = round((copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed +
                                     copy[i][j].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) /
                                    6.00);
                avg.rgbtGreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
                                       copy[i][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) /
                                      6.00);
                avg.rgbtBlue = round((copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
                                      copy[i][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) /
                                     6.00);

                image[i][j].rgbtRed = avg.rgbtRed;
                image[i][j].rgbtGreen = avg.rgbtGreen;
                image[i][j].rgbtBlue = avg.rgbtBlue;
            }
            // First pixel of last row
            else if (i == (height - 1) && j == 0)
            {
                avg.rgbtRed = round(
                                  (copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed) / 4.00);
                avg.rgbtGreen = round(
                                    (copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen) /
                                    4.00);
                avg.rgbtBlue = round(
                                   (copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue) / 4.00);

                image[i][j].rgbtRed = avg.rgbtRed;
                image[i][j].rgbtGreen = avg.rgbtGreen;
                image[i][j].rgbtBlue = avg.rgbtBlue;
            }
            // Last row
            else if (i == (height - 1) && (j > 0 && j < (width - 1)))
            {
                avg.rgbtRed = round((copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed +
                                     copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed) /
                                    6.00);
                avg.rgbtGreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                                       copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen) /
                                      6.00);
                avg.rgbtBlue = round((copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
                                      copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue) /
                                     6.00);

                image[i][j].rgbtRed = avg.rgbtRed;
                image[i][j].rgbtGreen = avg.rgbtGreen;
                image[i][j].rgbtBlue = avg.rgbtBlue;
            }
            // Last pixel of last row
            else if (i == (height - 1) && j == (width - 1))
            {
                avg.rgbtRed = round(
                                  (copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed) / 4.00);
                avg.rgbtGreen = round(
                                    (copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen) /
                                    4.00);
                avg.rgbtBlue = round(
                                   (copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue) / 4.00);

                image[i][j].rgbtRed = avg.rgbtRed;
                image[i][j].rgbtGreen = avg.rgbtGreen;
                image[i][j].rgbtBlue = avg.rgbtBlue;
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    // Loping through rows
    for (int i = 0; i < height; i++)
    {
        // Loping through pixels
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Loping through rows
    for (int i = 0; i < height; i++)
    {
        // Loping through pixels
        for (int j = 0; j < width; j++)
        {
            int Gx[] = {0, 0, 0};
            int Gy[] = {0, 0, 0};
            int temp[] = {0, 0, 0};
            // First pixel of first row
            if (i == 0 && j == 0)
            {
                // Computing the Gx
                Gx[0] = ((copy[i][j + 1].rgbtRed * 2) + copy[i + 1][j + 1].rgbtRed);
                Gx[1] = ((copy[i][j + 1].rgbtGreen * 2) + copy[i + 1][j + 1].rgbtGreen);
                Gx[2] = ((copy[i][j + 1].rgbtBlue * 2) + copy[i + 1][j + 1].rgbtBlue);

                // Computing the Gy
                Gy[0] = ((copy[i + 1][j].rgbtRed * 2) + copy[i + 1][j + 1].rgbtRed);
                Gy[1] = ((copy[i + 1][j].rgbtGreen * 2) + copy[i + 1][j + 1].rgbtGreen);
                Gy[2] = ((copy[i + 1][j].rgbtBlue * 2) + copy[i + 1][j + 1].rgbtBlue);

                // Calculating the channels
                temp[0] = round(sqrt((Gx[0] * Gx[0]) + (Gy[0] * Gy[0])));
                if (temp[0] >= 255)
                {
                    temp[0] = 255;
                }

                temp[1] = round(sqrt((Gx[1] * Gx[1]) + (Gy[1] * Gy[1])));
                if (temp[1] >= 255)
                {
                    temp[1] = 255;
                }

                temp[2] = round(sqrt((Gx[2] * Gx[2]) + (Gy[2] * Gy[2])));
                if (temp[2] >= 255)
                {
                    temp[2] = 255;
                }

                image[i][j].rgbtRed = temp[0];
                image[i][j].rgbtGreen = temp[1];
                image[i][j].rgbtBlue = temp[2];
            }
            // First row
            else if (i == 0 && (j > 0 && j < (width - 1)))
            {
                // Computing the Gx
                Gx[0] = ((copy[i][j - 1].rgbtRed * (-2)) + (copy[i][j + 1].rgbtRed * 2) + (copy[i + 1][j - 1].rgbtRed * (-1)) +
                         copy[i + 1][j + 1].rgbtRed);
                Gx[1] = ((copy[i][j - 1].rgbtGreen * (-2)) + (copy[i][j + 1].rgbtGreen * 2) +
                         (copy[i + 1][j - 1].rgbtGreen * (-1)) + copy[i + 1][j + 1].rgbtGreen);
                Gx[2] = ((copy[i][j - 1].rgbtBlue * (-2)) + (copy[i][j + 1].rgbtBlue * 2) + (copy[i + 1][j - 1].rgbtBlue * (-1)) +
                         copy[i + 1][j + 1].rgbtBlue);

                // Computing the Gy
                Gy[0] = (copy[i + 1][j - 1].rgbtRed + (copy[i + 1][j].rgbtRed * 2) + copy[i + 1][j + 1].rgbtRed);
                Gy[1] = (copy[i + 1][j - 1].rgbtGreen + (copy[i + 1][j].rgbtGreen * 2) + copy[i + 1][j + 1].rgbtGreen);
                Gy[2] = (copy[i + 1][j - 1].rgbtBlue + (copy[i + 1][j].rgbtBlue * 2) + copy[i + 1][j + 1].rgbtBlue);

                // Calculating the channels
                temp[0] = round(sqrt((Gx[0] * Gx[0]) + (Gy[0] * Gy[0])));
                if (temp[0] >= 255)
                {
                    temp[0] = 255;
                }

                temp[1] = round(sqrt((Gx[1] * Gx[1]) + (Gy[1] * Gy[1])));
                if (temp[1] >= 255)
                {
                    temp[1] = 255;
                }

                temp[2] = round(sqrt((Gx[2] * Gx[2]) + (Gy[2] * Gy[2])));
                if (temp[2] >= 255)
                {
                    temp[2] = 255;
                }

                image[i][j].rgbtRed = temp[0];
                image[i][j].rgbtGreen = temp[1];
                image[i][j].rgbtBlue = temp[2];
            }
            // Last pixel of first row
            else if (i == 0 && j == (width - 1))
            {
                // Computing the Gx
                Gx[0] = ((copy[i][j - 1].rgbtRed * (-2)) + (copy[i + 1][j - 1].rgbtRed * (-1)));
                Gx[1] = ((copy[i][j - 1].rgbtGreen * (-2)) + (copy[i + 1][j - 1].rgbtGreen * (-1)));
                Gx[2] = ((copy[i][j - 1].rgbtBlue * (-2)) + (copy[i + 1][j - 1].rgbtBlue * (-1)));

                // Computing the Gy
                Gy[0] = (copy[i + 1][j - 1].rgbtRed + (copy[i + 1][j].rgbtRed * 2));
                Gy[1] = (copy[i + 1][j - 1].rgbtGreen + (copy[i + 1][j].rgbtGreen * 2));
                Gy[2] = (copy[i + 1][j - 1].rgbtBlue + (copy[i + 1][j].rgbtBlue * 2));

                // Calculating the channels
                temp[0] = round(sqrt((Gx[0] * Gx[0]) + (Gy[0] * Gy[0])));
                if (temp[0] >= 255)
                {
                    temp[0] = 255;
                }

                temp[1] = round(sqrt((Gx[1] * Gx[1]) + (Gy[1] * Gy[1])));
                if (temp[1] >= 255)
                {
                    temp[1] = 255;
                }

                temp[2] = round(sqrt((Gx[2] * Gx[2]) + (Gy[2] * Gy[2])));
                if (temp[2] >= 255)
                {
                    temp[2] = 255;
                }

                image[i][j].rgbtRed = temp[0];
                image[i][j].rgbtGreen = temp[1];
                image[i][j].rgbtBlue = temp[2];
            }
            // First colomn
            else if ((i > 0 && i < (height - 1)) && j == 0)
            {
                // Computing the Gx
                Gx[0] = (copy[i - 1][j + 1].rgbtRed + (copy[i][j + 1].rgbtRed * 2) + copy[i + 1][j + 1].rgbtRed);
                Gx[1] = (copy[i - 1][j + 1].rgbtGreen + (copy[i][j + 1].rgbtGreen * 2) + copy[i + 1][j + 1].rgbtGreen);
                Gx[2] = (copy[i - 1][j + 1].rgbtBlue + (copy[i][j + 1].rgbtBlue * 2) + copy[i + 1][j + 1].rgbtBlue);

                // Computing the Gy
                Gy[0] = ((copy[i - 1][j].rgbtRed * (-2)) + (copy[i - 1][j + 1].rgbtRed * (-1)) + (copy[i + 1][j].rgbtRed * 2) +
                         copy[i + 1][j + 1].rgbtRed);
                Gy[1] = ((copy[i - 1][j].rgbtGreen * (-2)) + (copy[i - 1][j + 1].rgbtGreen * (-1)) +
                         (copy[i + 1][j].rgbtGreen * 2) + copy[i + 1][j + 1].rgbtGreen);
                Gy[2] = ((copy[i - 1][j].rgbtBlue * (-2)) + (copy[i - 1][j + 1].rgbtBlue * (-1)) + (copy[i + 1][j].rgbtBlue * 2) +
                         copy[i + 1][j + 1].rgbtBlue);

                // Calculating the channels
                temp[0] = round(sqrt((Gx[0] * Gx[0]) + (Gy[0] * Gy[0])));
                if (temp[0] >= 255)
                {
                    temp[0] = 255;
                }

                temp[1] = round(sqrt((Gx[1] * Gx[1]) + (Gy[1] * Gy[1])));
                if (temp[1] >= 255)
                {
                    temp[1] = 255;
                }

                temp[2] = round(sqrt((Gx[2] * Gx[2]) + (Gy[2] * Gy[2])));
                if (temp[2] >= 255)
                {
                    temp[2] = 255;
                }

                image[i][j].rgbtRed = temp[0];
                image[i][j].rgbtGreen = temp[1];
                image[i][j].rgbtBlue = temp[2];
            }
            // Middle pixels
            else if ((i > 0 && i < (height - 1)) && (j > 0 && j < (width - 1)))
            {
                // Computing the Gx
                Gx[0] = ((copy[i - 1][j - 1].rgbtRed * (-1)) + copy[i - 1][j + 1].rgbtRed + (copy[i][j - 1].rgbtRed * (-2)) +
                         (copy[i][j + 1].rgbtRed * 2) + (copy[i + 1][j - 1].rgbtRed * (-1)) + copy[i + 1][j + 1].rgbtRed);
                Gx[1] = ((copy[i - 1][j - 1].rgbtGreen * (-1)) + copy[i - 1][j + 1].rgbtGreen + (copy[i][j - 1].rgbtGreen * (-2)) +
                         (copy[i][j + 1].rgbtGreen * 2) + (copy[i + 1][j - 1].rgbtGreen * (-1)) + copy[i + 1][j + 1].rgbtGreen);
                Gx[2] = ((copy[i - 1][j - 1].rgbtBlue * (-1)) + copy[i - 1][j + 1].rgbtBlue + (copy[i][j - 1].rgbtBlue * (-2)) +
                         (copy[i][j + 1].rgbtBlue * 2) + (copy[i + 1][j - 1].rgbtBlue * (-1)) + copy[i + 1][j + 1].rgbtBlue);

                // Computing the Gy
                Gy[0] =
                    ((copy[i - 1][j - 1].rgbtRed * (-1)) + (copy[i - 1][j].rgbtRed * (-2)) + (copy[i - 1][j + 1].rgbtRed * (-1)) +
                     copy[i + 1][j - 1].rgbtRed + (copy[i + 1][j].rgbtRed * 2) + copy[i + 1][j + 1].rgbtRed);
                Gy[1] = ((copy[i - 1][j - 1].rgbtGreen * (-1)) + (copy[i - 1][j].rgbtGreen * (-2)) +
                         (copy[i - 1][j + 1].rgbtGreen * (-1)) + copy[i + 1][j - 1].rgbtGreen + (copy[i + 1][j].rgbtGreen * 2) +
                         copy[i + 1][j + 1].rgbtGreen);
                Gy[2] = ((copy[i - 1][j - 1].rgbtBlue * (-1)) + (copy[i - 1][j].rgbtBlue * (-2)) +
                         (copy[i - 1][j + 1].rgbtBlue * (-1)) + copy[i + 1][j - 1].rgbtBlue + (copy[i + 1][j].rgbtBlue * 2) +
                         copy[i + 1][j + 1].rgbtBlue);

                // Calculating the channels
                temp[0] = round(sqrt((Gx[0] * Gx[0]) + (Gy[0] * Gy[0])));
                if (temp[0] >= 255)
                {
                    temp[0] = 255;
                }

                temp[1] = round(sqrt((Gx[1] * Gx[1]) + (Gy[1] * Gy[1])));
                if (temp[1] >= 255)
                {
                    temp[1] = 255;
                }

                temp[2] = round(sqrt((Gx[2] * Gx[2]) + (Gy[2] * Gy[2])));
                if (temp[2] >= 255)
                {
                    temp[2] = 255;
                }

                image[i][j].rgbtRed = temp[0];
                image[i][j].rgbtGreen = temp[1];
                image[i][j].rgbtBlue = temp[2];
            }
            // Last colomn
            else if ((i > 0 && i < (height - 1)) && j == (width - 1))
            {
                // Computing the Gx
                Gx[0] =
                    ((copy[i - 1][j - 1].rgbtRed * (-1)) + (copy[i][j - 1].rgbtRed * (-2)) + (copy[i + 1][j - 1].rgbtRed * (-1)));
                Gx[1] = ((copy[i - 1][j - 1].rgbtGreen * (-1)) + (copy[i][j - 1].rgbtGreen * (-2)) +
                         (copy[i + 1][j - 1].rgbtGreen * (-1)));
                Gx[2] = ((copy[i - 1][j - 1].rgbtBlue * (-1)) + (copy[i][j - 1].rgbtBlue * (-2)) +
                         (copy[i + 1][j - 1].rgbtBlue * (-1)));

                // Computing the Gy
                Gy[0] = ((copy[i - 1][j - 1].rgbtRed * (-1)) + (copy[i - 1][j].rgbtRed * (-2)) + copy[i + 1][j - 1].rgbtRed +
                         (copy[i + 1][j].rgbtRed * 2));
                Gy[1] = ((copy[i - 1][j - 1].rgbtGreen * (-1)) + (copy[i - 1][j].rgbtGreen * (-2)) + copy[i + 1][j - 1].rgbtGreen +
                         (copy[i + 1][j].rgbtGreen * 2));
                Gy[2] = ((copy[i - 1][j - 1].rgbtBlue * (-1)) + (copy[i - 1][j].rgbtBlue * (-2)) + copy[i + 1][j - 1].rgbtBlue +
                         (copy[i + 1][j].rgbtBlue * 2));

                // Calculating the channels
                temp[0] = round(sqrt((Gx[0] * Gx[0]) + (Gy[0] * Gy[0])));
                if (temp[0] >= 255)
                {
                    temp[0] = 255;
                }

                temp[1] = round(sqrt((Gx[1] * Gx[1]) + (Gy[1] * Gy[1])));
                if (temp[1] >= 255)
                {
                    temp[1] = 255;
                }

                temp[2] = round(sqrt((Gx[2] * Gx[2]) + (Gy[2] * Gy[2])));
                if (temp[2] >= 255)
                {
                    temp[2] = 255;
                }

                image[i][j].rgbtRed = temp[0];
                image[i][j].rgbtGreen = temp[1];
                image[i][j].rgbtBlue = temp[2];
            }
            // First pixel of last row
            else if (i == (height - 1) && j == 0)
            {
                // Computing the Gx
                Gx[0] = (copy[i - 1][j + 1].rgbtRed + (copy[i][j + 1].rgbtRed * 2));
                Gx[1] = (copy[i - 1][j + 1].rgbtGreen + (copy[i][j + 1].rgbtGreen * 2));
                Gx[2] = (copy[i - 1][j + 1].rgbtBlue + (copy[i][j + 1].rgbtBlue * 2));

                // Computing the Gy
                Gy[0] = ((copy[i - 1][j].rgbtRed * (-2)) + (copy[i - 1][j + 1].rgbtRed * (-1)));
                Gy[1] = ((copy[i - 1][j].rgbtGreen * (-2)) + (copy[i - 1][j + 1].rgbtGreen * (-1)));
                Gy[2] = ((copy[i - 1][j].rgbtBlue * (-2)) + (copy[i - 1][j + 1].rgbtBlue * (-1)));

                // Calculating the channels
                temp[0] = round(sqrt((Gx[0] * Gx[0]) + (Gy[0] * Gy[0])));
                if (temp[0] >= 255)
                {
                    temp[0] = 255;
                }

                temp[1] = round(sqrt((Gx[1] * Gx[1]) + (Gy[1] * Gy[1])));
                if (temp[1] >= 255)
                {
                    temp[1] = 255;
                }

                temp[2] = round(sqrt((Gx[2] * Gx[2]) + (Gy[2] * Gy[2])));
                if (temp[2] >= 255)
                {
                    temp[2] = 255;
                }

                image[i][j].rgbtRed = temp[0];
                image[i][j].rgbtGreen = temp[1];
                image[i][j].rgbtBlue = temp[2];
            }
            // Last row
            else if (i == (height - 1) && (j > 0 && j < (width - 1)))
            {
                // Computing the Gx
                Gx[0] = ((copy[i - 1][j - 1].rgbtRed * (-1)) + copy[i - 1][j + 1].rgbtRed + (copy[i][j - 1].rgbtRed * (-2)) +
                         (copy[i][j + 1].rgbtRed * 2));
                Gx[1] = ((copy[i - 1][j - 1].rgbtGreen * (-1)) + copy[i - 1][j + 1].rgbtGreen + (copy[i][j - 1].rgbtGreen * (-2)) +
                         (copy[i][j + 1].rgbtGreen * 2));
                Gx[2] = ((copy[i - 1][j - 1].rgbtBlue * (-1)) + copy[i - 1][j + 1].rgbtBlue + (copy[i][j - 1].rgbtBlue * (-2)) +
                         (copy[i][j + 1].rgbtBlue * 2));

                // Computing the Gy
                Gy[0] =
                    ((copy[i - 1][j - 1].rgbtRed * (-1)) + (copy[i - 1][j].rgbtRed * (-2)) + (copy[i - 1][j + 1].rgbtRed * (-1)));
                Gy[1] = ((copy[i - 1][j - 1].rgbtGreen * (-1)) + (copy[i - 1][j].rgbtGreen * (-2)) +
                         (copy[i - 1][j + 1].rgbtGreen * (-1)));
                Gy[2] = ((copy[i - 1][j - 1].rgbtBlue * (-1)) + (copy[i - 1][j].rgbtBlue * (-2)) +
                         (copy[i - 1][j + 1].rgbtBlue * (-1)));

                // Calculating the channels
                temp[0] = round(sqrt((Gx[0] * Gx[0]) + (Gy[0] * Gy[0])));
                if (temp[0] >= 255)
                {
                    temp[0] = 255;
                }

                temp[1] = round(sqrt((Gx[1] * Gx[1]) + (Gy[1] * Gy[1])));
                if (temp[1] >= 255)
                {
                    temp[1] = 255;
                }

                temp[2] = round(sqrt((Gx[2] * Gx[2]) + (Gy[2] * Gy[2])));
                if (temp[2] >= 255)
                {
                    temp[2] = 255;
                }

                image[i][j].rgbtRed = temp[0];
                image[i][j].rgbtGreen = temp[1];
                image[i][j].rgbtBlue = temp[2];
            }
            // Last pixel of last row
            else if (i == (height - 1) && j == (width - 1))
            {
                // Computing the Gx
                Gx[0] = ((copy[i - 1][j - 1].rgbtRed * (-1)) + (copy[i][j - 1].rgbtRed * (-2)));
                Gx[1] = ((copy[i - 1][j - 1].rgbtGreen * (-1)) + (copy[i][j - 1].rgbtGreen * (-2)));
                Gx[2] = ((copy[i - 1][j - 1].rgbtBlue * (-1)) + (copy[i][j - 1].rgbtBlue * (-2)));

                // Computing the Gy
                Gy[0] = ((copy[i - 1][j - 1].rgbtRed * (-1)) + (copy[i - 1][j].rgbtRed * (-2)));
                Gy[1] = ((copy[i - 1][j - 1].rgbtGreen * (-1)) + (copy[i - 1][j].rgbtGreen * (-2)));
                Gy[2] = ((copy[i - 1][j - 1].rgbtBlue * (-1)) + (copy[i - 1][j].rgbtBlue * (-2)));

                // Calculating the channels
                temp[0] = round(sqrt((Gx[0] * Gx[0]) + (Gy[0] * Gy[0])));
                if (temp[0] >= 255)
                {
                    temp[0] = 255;
                }

                temp[1] = round(sqrt((Gx[1] * Gx[1]) + (Gy[1] * Gy[1])));
                if (temp[1] >= 255)
                {
                    temp[1] = 255;
                }

                temp[2] = round(sqrt((Gx[2] * Gx[2]) + (Gy[2] * Gy[2])));
                if (temp[2] >= 255)
                {
                    temp[2] = 255;
                }

                image[i][j].rgbtRed = temp[0];
                image[i][j].rgbtGreen = temp[1];
                image[i][j].rgbtBlue = temp[2];
            }
        }
    }
    return;
}