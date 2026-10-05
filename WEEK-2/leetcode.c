#include <stdio.h>
#include <string.h>

char* rev(char* s, char ch)
{
    int len = strlen(s);
    char s1[len];
    char s2[len + 1];

    int top1 = -1;
    int top2 = -1;

    int key = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] != ch)
        {
            s1[++top1] = s[i];
        }
        else
        {
            s1[++top1] = s[i];
            key = i;

            while (top2 < key)
            {
                top2++;
                s2[top2] = s1[top1];
                top1--;
            }

            key++;

            while (top2 < len - 1 && key < len)
            {
                top2++;
                s2[top2] = s[key];
                key++;
            }

            break;
        }
    }

    s2[top2 + 1] = '\0';

    strcpy(s, s2);

    return s;
}

int main()
{
    char ch;
    char s[100];

    printf("string:");
    scanf("%99s", s);

    printf("char:");
    scanf(" %c", &ch);

    printf("result is %s", rev(s, ch));

    return 0;
}