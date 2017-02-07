# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);
void radix_sort2(char **,int,int);

int main()
{
  char **input;
  char ch=' ';
  int n,k,i,j;
  srand(time(NULL));
  scanf("%d",&n);
  scanf("%d",&k);
  input = (char **)malloc(n*sizeof(char *));
  for(i=0;i<n;i++)
    {
      input[i]=(char *)malloc((k+1)*sizeof(char));
      for(j=0;j<k;j++)
	input[i][j]=(rand()%95)+32;
      input[i][k]='\0';
    }

    for(i=0;i<n;i++)
    {
      printf("%s\n",input[i]);

    }

  radix_sort2(input,n,k);
  for(i=0;i<n;i++)
    {
      printf("%s\n",input[i]);
    }
  
  return 0;
}

void radix_sort(char **input,int n,int k)
{
  /* The function sorts the array input using radix sort
     Write the two versions of the radix sort here, one after another.
     To execute one of the version just comment out the other version.
   */

   // first function
    //printf("into radix");
   int count[100];
   char out[n][k+1];

   

   int i, j;
   for(i = 0; i < 100; i++){
     count[i] = 0;
   }
   for( i = k-1; i >= k-1 ; i--) {
     for(j = 0 ; j < n; j++) {
       count[input[j][i] - 32]++;
     }
     //printf("count calculated");
     for(j = 1 ; j < 100; j++) {
       count[j] += count[j-1];
     }
     
     printf("--------radix_sort1\n");
     for(j = n-1; j >= 0; j--){

       strcpy(out[count[input[j][i] - 32] - 1], input[j]);
       count[input[j][i] - 32]--; 
     }
     
     //printf("out initialised");
     for(j = 0; j < n; j++){
       strcpy(input[j], out[j]);
     }
   }
}

void radix_sort2(char **input,int n,int k)
{
  /* The function sorts the array input using radix sort
     Write the two versions of the radix sort here, one after another.
     To execute one of the version just comment out the other version.
   */

   // second function
    //printf("into radix");
   int count[100];
   char temp[k+1];

   

   int i, j;
   for(i = 0; i < 100; i++){
     count[i] = 0;
   }
   for( i = k-1; i >= k-1 ; i--) {
     for(j = 0 ; j < n; j++) {
       count[input[j][i] - 32]++;
     }
     //printf("count calculated");
     for(j = 1 ; j < 100; j++) {
       count[j] += count[j-1];
     }
     printf("--------radix_sort2\n");
     for(j = n-1; j >= 0; j--){
       strcpy(temp, input[count[input[j][i] - 32]-1]);
       strcpy(input[count[input[j][i] - 32]-1], input[j]);
       strcpy(input[j], temp);
       count[input[j][i] - 32]--; 
     }
     
   }
}

