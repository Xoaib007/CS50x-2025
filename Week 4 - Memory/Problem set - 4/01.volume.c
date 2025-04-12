// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t buffer[HEADER_SIZE];

    fread(buffer, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(buffer, sizeof(uint8_t), HEADER_SIZE, output);

    // TODO: Read samples from input file and write updated data to output file
    fseek(input, 0, SEEK_END);
    long fileSize = ftell(input); // total size in bytes
    fseek(input, HEADER_SIZE, SEEK_SET); // go back to just after the header

    long dataBytes = fileSize - HEADER_SIZE;

    long numSamples = dataBytes / sizeof(int16_t);
    int16_t *buffer2 = malloc(numSamples * sizeof(int16_t));
    if (buffer2 == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    fread(buffer2, sizeof(int16_t), numSamples, input);

    for (long i = 0; i < numSamples; i++)
    {
        buffer2[i] = buffer2[i] * factor;
    }

    fwrite(buffer2, sizeof(int16_t), numSamples, output);

    free(buffer2);

    // Close files
    fclose(input);
    fclose(output);
}
