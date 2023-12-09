#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

// Number of bytes in a block
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    // Open input file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        fclose(infile);
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];

    int i = 0;
    char file[8];
    sprintf(file, "%03i.jpg", i);
    FILE *outfile;

    while (fread(&buffer, sizeof(BYTE), BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        // ensure infile is (likely) a JPEG
        if (buffer[0] == 0XFF && buffer[1] == 0XD8 && buffer[2] == 0XFF && (buffer[3] & 0XF0) == 0XE0)
        {
            // First Block
            if (i == 0)
            {
                outfile = fopen(file, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outfile);
                i++;
            }
            // The other Blocks
            else
            {
                fclose(outfile);
                sprintf(file, "%03i.jpg", i);
                outfile = fopen(file, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outfile);
                i++;
            }
        }
        else if (i == 0)
        {
            i = i + 1 - 1;
        }
        else
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outfile);
        }
    }

    // Close files
    fclose(infile);
    fclose(outfile);

    return 0;
}