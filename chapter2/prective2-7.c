#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFSIZE 512
#define PERM 0644

// copyfile : name1의 내용을 name2에 작성 

int copyfile(int name1, int name2)
{
 
    int infile, outfile;
    ssize_t nread;
    char buffer[BUFSIZE];

    while ((nread = read(name1, buffer, BUFSIZE)) > 0)
    {
        if (write(name2, buffer, nread) < nread)
        {
            close(infile);
            close(outfile);
            return (-3);
        }
    }

    close(infile);
    close(outfile);

    if (nread == -1)
        return (-4);
    else
        return 0;
}

int main(int argc, char *argv[]) 
{

    int filediscrip1, filediscrip2;

    // if ((filediscrip1 = open("aaa", O_RDONLY)) == -1)
    if ((filediscrip1 = open(argv[1], O_RDONLY)) == -1)
    {
        printf("error in opening aaa\n");
        exit(1);
    }

    // if ((filediscrip2 = open("ccc", O_WRONLY | O_CREAT | O_TRUNC, PERM)) == -1)
    if ((filediscrip2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, PERM)) == -1)
    {
        printf("error in opening aaa\n");
        exit(1);
    }

    copyfile(filediscrip1, filediscrip2);

    return 0;
}