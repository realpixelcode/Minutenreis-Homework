/**
 * @file magicsquare.c
 * @author Dirk Broßwick ( dirk.brosswick@uni-jena.de )
 * prerequisite: "sudo apt-get install build-essential"
 * build: "gcc magicsquare.c -o magicsquare"
 * @version 0.1
 * @date 2022-01-11
 * @note Happy new Year Easteregg!
 * @copyright Copyright (c) 2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PASSED "\033[0;32mpass\033[0m"
#define FAILED "\033[0;31mfail\033[0m"
#define ASSERT(test, message, ...)                                                         \
    do                                                                                     \
    {                                                                                      \
        if (!(test))                                                                       \
        {                                                                                  \
            printf("[A] %s (line:%d) " message "\r\n", __FILE__, __LINE__, ##__VA_ARGS__); \
            exit(EXIT_FAILURE);                                                            \
        }                                                                                  \
    } while (0)

int *genMagicSquare(int size);
bool checkMagicSquare(int *square, int size);

int main(int argc, char *argv[])
{
    int size = 0;
    int *square = NULL;

    printf("Geben Sie die Seitenlaenge des gewuenschten magischen Quadrates an > ");
    scanf("%d", &size);
    /**
     * generate magic square
     */
    square = genMagicSquare(size);
    /**
     * check magic square
     */
    if (checkMagicSquare(square, size))
    {
        printf("magisches Quadrat ist richtig\r\n");
    }
    else
    {
        printf("magisches Quadrat enthält Fehler\r\n");
    }
    /**
     * manipulate the magic square with a zero in the middle and check it
     */
    printf("manipuliere magisches Quadrat ... \r\n");
    square[size / 2 + size / 2 * size] = 0;
    if (checkMagicSquare(square, size))
    {
        printf("magisches Quadrat ist richtig\r\n");
    }
    else
    {
        printf("magisches Quadrat enthält Fehler\r\n");
    }
    /**
     * free allocated memory
     */
    free(square);

    return (EXIT_SUCCESS);
}

/**
 * @brief generate a magic square
 *
 * @param size      size of the mqgic sqaure
 * @return NULL if failed or a valid pointer to the magic square
 */
int *genMagicSquare(int size)
{
    int *square = NULL;                 /** @brief pointer to the allocated square */
    int x = size / 2, y = size / 2 + 1; /** @brief current x and y coordinate, preset is one down in the middle */
    int runner = 1;                     /** @brief current number to write in die square field */
    /**
     * check for a odd size and if allocation was successfull
     */
    ASSERT((size % 2) != 0, "please set a odd magic square size");
    ASSERT(square = (int *)calloc(size * size, sizeof(int)), "square calloc failed");
    /**
     * run the magic square generator
     */
    while (runner <= size * size)
    {
        /**
         * limit the size if we are out of border and wrapp it
         */
        x = x % size;
        y = y % size;
        /**
         * check if the field was NOT free and move
         * or write the field with the next number
         */
        if (square[x + y * size])
        {
            /**
             * move one down and left
             */
            y += 1;
            x -= 1;
            /**
             * special case when x was negative
             */
            if (x < 0)
            {
                x = size - 1;
            }
        }
        else
        {
            /**
             * write the current field with the current number
             * increment x, y and number
             */
            square[x++ + y++ * size] = runner++;
        }
    }

    return (square);
}

/**
 * @brief check if a magic square is valid
 *
 * @param square        pointer to a magic square
 * @param size          size of the magic square
 * @return true         if valid
 * @return false        if not valid
 */
bool checkMagicSquare(int *square, int size)
{
    int retval = 0;
    int checksum = 0;
    int referenz = 0;

    /**
     * https://de.wikipedia.org/wiki/Magisches_Quadrat
     */
    referenz = ((size * size * size) + size) / 2;

    for (int x = 0; x < size; x++)
    {
        checksum += *(square + (size * ((size - 1) - x)) + x);
        printf("\t");
    }
    printf("%s\r\n", checksum == referenz ? PASSED : FAILED);
    checksum == referenz ? retval++ : retval;

    for (int y = 0; y < size; y++)
    {
        checksum = 0;
        for (int x = 0; x < size; x++)
        {
            checksum += *(square + y * size + x);
            printf("%d\t", *(square + y * size + x));
        }
        printf("%s\r\n", checksum == referenz ? PASSED : FAILED);
        checksum == referenz ? retval++ : retval;
    }

    for (int x = 0; x < size; x++)
    {
        checksum = 0;
        for (int y = 0; y < size; y++)
        {
            checksum += *(square + y * size + x);
        }
        printf("%s\t", checksum == referenz ? PASSED : FAILED);
        checksum == referenz ? retval++ : retval;
    }

    checksum = 0;
    for (int x = 0; x < size; x++)
    {
        checksum += *(square + x * size + x);
    }
    printf("%s\r\n", checksum == referenz ? PASSED : FAILED);
    checksum == referenz ? retval++ : retval;

    return (retval == (size * 2 + 2) ? true : false);
}