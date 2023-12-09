#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
// Functions prototype
int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        fclose(infile);
        printf("Could not open file.\n");
        return 1;
    }

    // Read header
    WAVHEADER HEADER;
    fread(&HEADER, HEADER_SIZE, 1, infile);

    // Use check_format to ensure WAV format
    if (check_format(HEADER) != 0)
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Open output file for writing
    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL)
    {
        fclose(outfile);
        printf("Could not open file.\n");
        return 1;
    }

    // Write header to file
    fwrite(&HEADER, HEADER_SIZE, 1, outfile);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(HEADER);

    // Moving the cursor
    long x = ftell(infile);
    int n = 2 * block_size;
    fseek(infile, (-block_size), SEEK_END);
    long y = ftell(infile);

    // Creating the Buffers
    DWORD *buffer4 = malloc(sizeof(DWORD));
    WORD *buffer2 = malloc(sizeof(WORD));
    BYTE *buffer1 = malloc(sizeof(BYTE));

    // Writing reversed audio to file
    if (block_size == 4)
    {
        while (y >= x)
        {
            fread(buffer4, block_size, 1, infile);
            fwrite(buffer4, block_size, 1, outfile);
            fseek(infile, (-n), SEEK_CUR);
            y = ftell(infile);
        }
    }
    else if (block_size == 2)
    {
        while (y >= x)
        {
            fread(buffer2, block_size, 1, infile);
            fwrite(buffer2, block_size, 1, outfile);
            fseek(infile, (-n), SEEK_CUR);
            y = ftell(infile);
        }
    }
    else
    {
        while (y >= x)
        {
            fread(buffer1, block_size, 1, infile);
            fwrite(buffer1, block_size, 1, outfile);
            fseek(infile, (-n), SEEK_CUR);
            y = ftell(infile);
        }
    }

    // Free the Buffers
    free(buffer4);
    free(buffer2);
    free(buffer1);

    // Close files
    fclose(infile);
    fclose(outfile);

    return 0;
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 0X57 && header.format[1] == 0X41 && header.format[2] == 0X56 && header.format[3] == 0X45)
    {
        return 0;
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    return header.numChannels * (header.bitsPerSample / 8);
}