#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int valid = 1;
    int found = 0;
    printf("Enter your input String: ");
    scanf("%99s", str);
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        if (str[i] != 'a' && str[i] != 'b')
        {
            valid = 0;
            break;
        }
    }
    if (!valid)
    {
        printf("The given string is invalid because it contains characters other than 'a' and 'b'.");
        return 0;
    }
    int i = 0;
    while (i < length)
    {
        while (i < length && str[i] == 'a')
        {
            i++;
        }
        if (i < length - 1 && str[i] == 'b' && str[i + 1] == 'b')
        {
            found++;
            i += 2;
        }
        else
        {
            if (i < length && str[i] == 'b')
            {
                valid = 0;
                break;
            }
            i++;
        }
    }
    if (found == 1 && valid)
    {
        printf("\nValid String\n");
    }
    else
    {
        printf("\nInvalid String\n");
    }

    return 0;
}
