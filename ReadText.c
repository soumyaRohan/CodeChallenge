#include <stdio.h>
#include <string.h>

#define LENGTH 20


FILE *f;
char str[100],strv[100],strd[100];
  char stcmp[100];
  char grid[4][4] = {{'a','b','a','c'},{'b','c','r','g'},{'d','j','e','b'},{'o','h','l','r'}};
  int i,j,flag = 0;


void Search(FILE *f,char str[])
{
     rewind(f);
    while(fgets(stcmp,40,f)!=NULL)
    {
        while(str[i] == stcmp[i]&& (i<4))
        {
            i++;
        }

        if(4<=i)
        {
             for(j=0;stcmp[j]!='\0';j++)
            {
                printf("%c",stcmp[j]);
            }
        i=0;
        }
    }
}


int main()
{

  f = fopen("words.txt" , "r");

  if(f == NULL){
    perror("Error opening file");
    return(-1);
  }
  else
{

// this loop print the given 4*4 Grid
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%c\t",grid[i][j]);
        }
        printf("\n");
    }

// Horizontal search
    for(i=0;i<1;i++)
    {
        for(j=0;j<4;j++)
        {
            str[j] = grid[i][j];
        }
    }
 printf("\n%s",str);
 printf("Words Listed for Horizontal Search:\n");
 Search(f,str);


 // Vertical search
    for(i=0;i<4;i++)
    {
        for(j=0;j<1;j++)
        {
            strv[i] = grid[i][j];
        }
    }
printf("\n%s",strv);
printf("\nWords Listed for vertical Search:\n");
Search(f,strv);


// Diagonal search
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i==j)
            {
                 strd[i] = grid[i][j];
            }
        }
    }
    printf("\n%s",strd);
 printf("\nWords Listed for diagonal Search:\n");
Search(f,strd);

}
    fclose(f);

  return(0);
}

