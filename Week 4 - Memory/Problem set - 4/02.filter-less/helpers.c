#include <math.h>
#include "helpers.h"

// Convert image to grayscale

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0f;
            int roundedAverage = (int) round(average);

            image[i][j].rgbtRed = roundedAverage;
            image[i][j].rgbtGreen = roundedAverage;
            image[i][j].rgbtBlue = roundedAverage;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            if (sepiaRed > 255) sepiaRed = 255;

            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            if (sepiaGreen > 255) sepiaGreen = 255;

            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            if (sepiaBlue > 255) sepiaBlue = 255;

            image[i][j].rgbtRed = (int) round(sepiaRed);
            image[i][j].rgbtGreen = (int) round(sepiaGreen);
            image[i][j].rgbtBlue = (int) round(sepiaBlue);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurredImage[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            int validPixelCount = 0;

            for (int dRow = -1; dRow <= 1; dRow++)
            {
                for (int dCol = -1; dCol <= 1; dCol++)
                {
                    int neighborRow = row + dRow;
                    int neighborCol = col + dCol;

                    // Check if neighbor is within image bounds
                    if (neighborRow >= 0 && neighborRow < height && neighborCol >= 0 && neighborCol < width)
                    {
                        totalRed += image[neighborRow][neighborCol].rgbtRed;
                        totalGreen += image[neighborRow][neighborCol].rgbtGreen;
                        totalBlue += image[neighborRow][neighborCol].rgbtBlue;
                        validPixelCount++;
                    }
                }
            }

            blurredImage[row][col].rgbtRed = round((float) totalRed / validPixelCount);
            blurredImage[row][col].rgbtGreen = round((float) totalGreen / validPixelCount);
            blurredImage[row][col].rgbtBlue = round((float) totalBlue / validPixelCount);
        }
    }

    // Copy blurred values back to original image
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = blurredImage[row][col];
        }
    }
}
