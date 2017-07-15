#include <string.h>
#include <stdio.h>

void insert();
void search();
void rsearch();

int main()
{
	int ch, opt;
	xy:
	printf("1. Scan WWID and Code\n2. Search\n3. Do a reverse search\nEnter option: ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: insert();
			break;
		case 2: search();
			break;
		case 3: rsearch();
			break;
		default: printf("Bye Bye\n");
			break;
	}
	printf("Continue?(1/0)\n");
	scanf("%d", &opt);
	if(opt == 1)
		goto xy;
	else if(opt == 0)
		return 0;
}

void insert()
{
	FILE *fptr;
        char wwid[100];
        char code[100];	

	fptr = fopen("emp.txt", "a+");

        fclose(fptr);
        fptr = fopen("emp.txt", "a+");
        if(fptr == NULL)
        {
		printf("No file exists\n");
                return;
        }
        printf("Enter WWID:\n");
        scanf("%s", wwid);
        fprintf(fptr,"%s\t\t", wwid);

        printf("Enter product ID:\n");
        scanf("%s", code);
        fprintf(fptr, "%s\n", code);

        fclose(fptr);
}

void search()
{
	printf("Enter the WWID you want to search\n");
        char swwid[100];
        scanf("%s", swwid);
        char buf[100];
        FILE *fp=fopen("emp.txt", "r");
        char *p;
        while(fgets(buf,100,fp))
        {
        	p=strstr(buf, swwid);
                if(p!=NULL)
                {
                	printf("%s", p);
                }
        }
}

void rsearch()
{
	printf("Enter the Code you want to search\n");
	char scode[100];
	scanf("%s", scode);
	char buf[100];
	FILE *fp=fopen("emp.txt", "r");
	char *p;
	while(fgets(buf,100, fp))
	{
		p=strstr(buf, scode);
		if(p!=NULL)
		{
			printf("%s", p);
		}
	}
}
