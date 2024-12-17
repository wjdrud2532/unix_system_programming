#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


void main()
{
    off_t filesize_back;
    off_t filesize_fornt;

    int filedes;
    int count = 0;
    char buffer[1];

    //  open("ccc", O_WRONLY | O_CREAT | O_TRUNC, PERM)) == -1)
    if((filedes = open("aaa", O_RDONLY)) == -1)
        printf("파일이 열리지 않음\n");

    if((filesize_back = lseek(filedes, (off_t) 0, SEEK_END)) == -1)
        printf("lseek 에러\n");


    if(filesize_fornt = lseek(filedes, 0, SEEK_SET) == -1)
        printf("lseek set 에러\n");

    while(read(filedes, buffer, 1) > 0)
    {
        count ++;
    }

    printf("count is %d\n", count);
    printf("aa %d\n", filesize_back - filesize_fornt);

    return 0;
}

// 파일의 포인터를 움직이지 않고
// 시작과 끝의 크기를 계산하여 파일의 크기를 계산
//