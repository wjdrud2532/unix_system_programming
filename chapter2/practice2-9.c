#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define NAMELENGTH 41

char namebuf[NAMELENGTH]; // 이름을 보관할 버퍼
int infile = -1;          // 파일 기술자를 보관할 것

char *getoccupier(int roomno)
{
    off_t offset;
    ssize_t nread;

    // 파일을 처음으로 개방

    if (infile == -1 && (infile = open("residents", O_RDONLY)) == -1)
    {
        return (NULL); // 파일 개방 실패
    }

    offset = (roomno - 1) * NAMELENGTH;

    // 방의 위치를 찾아 투숙객의 이름을 읽는다
    if (lseek(infile, offset, SEEK_SET) == -1)
        return (NULL);

    if ((nread = read(infile, namebuf, NAMELENGTH)) <= 0)
        return (NULL);

    // 개행문자를 널 종결자로 태체하여 하나의 스트링을 생성
    namebuf[nread - 1] = '\0';
    return (namebuf);
}

#define NROOMS 10

main()
{
    int j;
    char * getoccupier (int), *p;

    // for()
}