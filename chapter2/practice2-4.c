#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int filedes;

    // 명령행 인자로 파일 이름 확인
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *workfile = argv[1]; // 파일 이름을 명령행 인자로 설정

    // 새 파일 생성 (확인용)
    filedes = open("./junk2", 0644);

    // 작업 파일 열기
    if ((filedes = open(workfile, O_RDONLY)) == -1) {
        printf("Couldn't open %s\n", workfile);
        exit(1);
    }

    printf("open success!\n");
    close(filedes); // 열린 파일 닫기
    exit(0);
}
