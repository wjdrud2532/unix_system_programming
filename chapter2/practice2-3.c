#include <stdlib.h>
#include <fcntl.h>

char *workfile="junk";

main()
{
	int filedes;

    filedes = creat("./junk2", 0644);

	if((filedes = open (workfile, O_TRUNC)) == -1)
	{
		printf("Couldn't open %s\n", workfile);
		exit(1);
	}

	printf("open success!\n");
	exit(0);
}
