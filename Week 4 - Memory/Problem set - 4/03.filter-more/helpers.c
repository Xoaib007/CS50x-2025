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


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE edgedImage[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            float gxRed = 0, gxGreen = 0, gxBlue = 0;
            float gyRed = 0, gyGreen = 0, gyBlue = 0;


            int gxElement[] = {-1, 0, 1, -2, 0, 2, -1, 0 , 1};
            int gyElement[] = {-1, -2, -1, 0, 0, 0, 1, 2 , 1};

            int index = 0;

            for (int dRow = -1; dRow <= 1; dRow++)
            {
                for (int dCol = -1; dCol <= 1; dCol++)
                {
                    int neighborRow = row + dRow;
                    int neighborCol = col + dCol;

                    // Check if neighbor is within image bounds
                    if (neighborRow >= 0 && neighborRow < height && neighborCol >= 0 && neighborCol < width)
                    {
                        gxRed += image[neighborRow][neighborCol].rgbtRed * gxElement[index];
                        gxGreen += image[neighborRow][neighborCol].rgbtGreen * gxElement[index];
                        gxBlue += image[neighborRow][neighborCol].rgbtBlue * gxElement[index];

                        gyRed += image[neighborRow][neighborCol].rgbtRed * gyElement[index];
                        gyGreen += image[neighborRow][neighborCol].rgbtGreen * gyElement[index];
                        gyBlue += image[neighborRow][neighborCol].rgbtBlue * gyElement[index];
                    }
                    index++;
                }
            }

            int red = round(sqrt(gxRed * gxRed + gyRed * gyRed));
            if (red > 255) red = 255;
            edgedImage[row][col].rgbtRed = red;

            int green = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            if (green > 255) green = 255;
            edgedImage[row][col].rgbtGreen = green;

            int blue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            if (blue > 255) blue = 255;
            edgedImage[row][col].rgbtBlue = blue;

        }
    }

    // Copy blurred values back to original image
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = edgedImage[row][col];
        }
    }
}
