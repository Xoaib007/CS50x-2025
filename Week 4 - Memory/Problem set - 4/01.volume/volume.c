// Modifies the volume of an audio file
// This program takes in three command-line arguments: an input .wav file, an output .wav file, and a scaling factor. 
// It adjusts the volume of the audio data in the input file by multiplying each sample by the given factor 
// and writes the modified data to the output file while preserving the .wav file header.

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
        return 1; // Exit with error if incorrect number of arguments is provided
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1; // Exit with error if input file cannot be opened
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        fclose(input); // Ensure input file is closed before exiting
        return 1; // Exit with error if output file cannot be opened
    }

    float factor = atof(argv[3]); // Convert the scaling factor from string to float

    // Copy header from input file to output file
    uint8_t buffer[HEADER_SIZE]; // Buffer to store the header
    fread(buffer, sizeof(uint8_t), HEADER_SIZE, input); // Read header from input file
    fwrite(buffer, sizeof(uint8_t), HEADER_SIZE, output); // Write header to output file

    // Determine the size of the audio data in the file
    fseek(input, 0, SEEK_END); // Move to the end of the file
    long fileSize = ftell(input); // Get the total size of the file in bytes
    fseek(input, HEADER_SIZE, SEEK_SET); // Move back to the position after the header

    long dataBytes = fileSize - HEADER_SIZE; // Calculate data size excluding header
    long numSamples = dataBytes / sizeof(int16_t); // Determine the number of audio samples

    // Allocate memory for audio samples
    int16_t *buffer2 = malloc(numSamples * sizeof(int16_t));
    if (buffer2 == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(input);
        fclose(output);
        return 1; // Exit if memory allocation fails
    }

    // Read audio samples into buffer
    fread(buffer2, sizeof(int16_t), numSamples, input);

    // Adjust the volume of each audio sample
    for (long i = 0; i < numSamples; i++)
    {
        buffer2[i] = buffer2[i] * factor; // Scale sample by the factor
    }

    // Write modified samples to the output file
    fwrite(buffer2, sizeof(int16_t), numSamples, output);

    // Free allocated memory and close files
    free(buffer2);
    fclose(input);
    fclose(output);
    return 0; // Exit successfully
}

/*
Summary:
This code modifies the volume of an audio file in .wav format. It takes three command-line arguments:
1. Input file name
2. Output file name
3. Scaling factor for the volume.

The program first validates the number of arguments and opens the input and output files. It reads the 44-byte
header from the input file and writes it to the output file to preserve file structure. It calculates the number
of audio samples in the file and dynamically allocates memory to store them. Each audio sample is scaled by the
given factor to adjust its volume. The modified samples are then written to the output file. Finally, the allocated
memory is freed, and both files are closed. Errors during file operations or memory allocation are handled gracefully.
*/
