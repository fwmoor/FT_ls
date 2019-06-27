#include <stdio.h>
#include <dirent.h>

int main(void)
{
    struct dirent *de;
    DIR *dr = opendir(".");

    if (dr == NULL)
    {
        printf("Could not open current directory" );
        return 0;
    }
    while ((de = readdir(dr)) != NULL)
        printf("%s\t", de->d_name);
    printf("\n");
    closedir(dr);
    return 0;
}
