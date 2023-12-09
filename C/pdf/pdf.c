#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid Usage!\n");
        return 1;
    }

    FILE *TEST = fopen(argv[1], "r");
    if (TEST == NULL)
    {
        printf("No such file found.\n");
        return 2;
    }

    uint8_t buffer[4];
    uint8_t signatur[] = {37, 80, 68, 70};

    fread(buffer, 1, 4, TEST);
    fclose(TEST);

    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signatur[i])
        {
            printf("Not a PDF!\n");
            return 0;
        }
    }
    printf("It's a PDF!\n");
}