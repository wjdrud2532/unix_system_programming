#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 512

main()
{
    char buffer[BUFSIZE];
    int filedes;
    ssize_t nread;
    long total = 0;

    long word_start = 0;
    long count_word = 0;

    long count_line = 1;

    if ((filedes = open("aaa", O_RDONLY)) == -1)
    {
        printf("error in opening aaa\n");
        exit(1);
    }

    while ((nread = read(filedes, buffer, BUFSIZE)) > 0)
    {
        total += nread;

        for (int i = 0; i < nread; i++)
        {
            char tempChar = buffer[i];

            if (tempChar == '\n')
                count_line++;

            if (isspace(tempChar))
            {
                if (word_start)
                {
                    count_word++;
                    word_start = 0;
                }
            }
            else
            {
                word_start = 1;
            }
        }
    }

    if (word_start)
    {
        count_word++;
    }

    printf("total chars in aaa : %ld\n", total);
    printf("count line in aaa : %ld\n", count_line);
    printf("count word in aaa : %ld\n", count_word);
    exit(0);
}