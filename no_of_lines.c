#include <stdio.h>
int main()
{
    FILE *file;
    int LOC = 1;
    char filename[100];
    char ch;
    char last_ch = '\n';
    int comment_lines = 0;
    int blank_lines = 0;
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File not found.\n");
        return -1;
    }
    while ((ch = fgetc(file)) != EOF)
    {
        if(ch == '\n' && last_ch != '\n')
        {
            LOC++;
        }
        last_ch = ch;
        if (ch == '/')
        {
            if ((ch = fgetc(file)) == '/')
            {
                comment_lines++;
            }
        }
    }
    fclose(file);
    printf("No. of lines: %d\n", LOC - (comment_lines));
    return 0;
}