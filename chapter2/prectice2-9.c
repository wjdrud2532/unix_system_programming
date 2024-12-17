#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define NAMELENGTH 41

char namebuf[NAMELENGTH];   // 이름을 보관할 버퍼
int infile = -1;            // 파일 기술자를 보관할 것

char * getoccupier(int roomno)
{
    off_t offset;
    ssize_t nread;

    // 파일을 처음으로 개방

    if(infile == -1 && (infile = open("residents", O_RDONLY)) == -1)
    {
        return (NULL);  // 파일 개방 실패
    }

    offset = (roomno - 1) * NAMELENGTH;
}