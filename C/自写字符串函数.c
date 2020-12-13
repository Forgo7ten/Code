//自写strlen，strcmp，strcpy，strcat

int mystrlen(const char * s)
{
    int i = -1;
    while (s[++i]);
    return i;
}

int mystrcmp(const char* s1, const char* s2)
{
    int i=0;
    while (s1[i] == s2[i] && s1[i])
        i++;
    i = s1[i] - s2[i];
    return (i > 0) - (i < 0);//i<0返回-1，i>0返回1，i==0返回0
}

char * mystrcpy(char* s1, const char* s2)
{
    int i;
    for (i = 0; s2[i]; i++)
        s1[i] = s2[i];
    s1[i] = 0;
    return s1;
}

char * mystrcat(char* s1, const char* s2)
{
    int i = -1, j;
    while (s1[++i]);
    for (j = 0; s2[j]; j++)
        s1[i + j] = s2[j];
    s1[i + j] = 0;
    return s1;
}