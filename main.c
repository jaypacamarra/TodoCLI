#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE  *fp, *fpw;
    fp = fopen("test.txt", "w");

    fprintf(fp, "1. [ ] Take out the trash\n");
    fprintf(fp, "2. [X] Do the laundry\n");
    fprintf(fp, "3. [X] Finish the exam cheat sheet\n");
    fclose(fp);

    // delete item 2
    fp  = fopen("test.txt", "r");
    fpw = fopen(".temp.txt", "w");

    char buffer[100];
    while(fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        if (buffer[0] != '2')
        {
            fprintf(fpw, "%s", buffer);
        }
    }

    fclose(fpw);
    fclose(fp);

    rename(".temp.txt","test.txt");

    return 0;
}
