#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *fileName;

    if (argc != 2)
    {
        fprintf(stderr, "usage: useupper file\n");
        exit(1);
    }

    fileName = argv[1];

    if (!freopen(fileName, "r", stdin))
    {
        fprintf(stderr, "could not redirect stdin from file %s\n", fileName);
    }

    execl("./upper", "upper", 0);

    perror("could not exec ./upper");

    exit(3);
}
