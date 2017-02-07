# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

struct stat{
  int item;
  int lenLong;
  float avgComp;
  float stdDev;
};

struct node{
  char* data ;
  struct node* next;
};

struct stat hash_ETH(char **, int);
struct stat hash_cpp(char **, int);
struct stat hash_cc1(char **, int);

void insert(struct node** start, char* val) {
  struct  node* newNode = ( struct node*) malloc(sizeof(struct node));
  //printf("just came\n");
  newNode->data = val;
  newNode->next = NULL;
  //printf("just came2\n");
  struct node* begin = *start;

  while(begin->next != NULL){
    begin = begin->next;
  }
  //printf("just came3\n");
  //printf("going out\n");
  begin->next = newNode;
}

int main()
{
  char **input;
  struct stat hash_stat;
  int n,k,i,j;
  srand(time(NULL));
  n=1632;
  k=5;
  input = (char **)malloc(n*sizeof(char *));
  for(i=0;i<n;i++)
    {
      input[i]=(char *)malloc((k+1)*sizeof(char));
      for(j=0;j<k;j++)
	input[i][j]=(rand()%95)+32;
      input[i][k]='\0';
    }
  printf("ETH\n");
  for(i=1040;i<=1050;i++)
    {
      hash_stat = hash_ETH(input,i);
      
      printf("%d,  %f,  %f\n",i,hash_stat.avgComp,hash_stat.stdDev);
    }
  printf("GNU-cc1\n");
  for(i=1040;i<=1050;i++)
    {
      hash_stat = hash_cc1(input,i);
      printf("%d,  %f,  %f\n",i,hash_stat.avgComp,hash_stat.stdDev);
    }
  printf("GNU-cpp\n");
  for(i=1040;i<=1050;i++)
    {
      hash_stat = hash_cpp(input,i);
      printf("%d,  %f,  %f\n",i,hash_stat.avgComp,hash_stat.stdDev);
    }
  
  return 0;
}

struct stat hash_ETH(char **input,int tablesize)
{
  struct stat hash_stat;

  /* write the program to perform ETH on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */

  int hashTable[tablesize];
  struct node* hashList[tablesize];
  int i,k;
  //hashTable[0] = 1;
  int temp[5];
  int n = 1632;
  for(i = 0; i < tablesize; i++){
    hashTable[i] = 0;
  }
  for(i = 0; i < tablesize; i++){
    hashList[i] = (struct node*)malloc(sizeof(struct node));
    hashList[i]->next = NULL;
  }
  int pos[n];
  for(i = 0; i < n; i++){
    pos[i] = 0;
  }
  //printf("hash calc starting \n");
  for(i = 0; i < n; i++) {
    temp[0] = 1;
    for(k = 1; k <= 4; k++) {
      temp[k] = input[i][k] * ((temp[k-1]%257)+1);
    }
    

    int H = temp[4] % tablesize;
    //printf("inserting in ll");
    insert(&hashList[H], input[i]);

    hashTable[H]++;
    pos[i] = hashTable[H];
  }
  //printf("hash calculated\n");
  hash_stat.item = n;


  int max = -1;
  for(i = 0; i < tablesize; i++){
    if(max < hashTable[i])
      max = hashTable[i];
  }

  hash_stat.lenLong = max;

  int comp = 0;
  for(i = 0; i < n; i++){
    comp += (pos[i]);
  }
  hash_stat.avgComp =(float)comp/n;

  int sumofsq = 0;
  for(i = 0; i < n; i++){
    sumofsq += (pos[i]*pos[i]);
  }

  hash_stat.stdDev = sqrt(((float)sumofsq/n) - (hash_stat.avgComp * hash_stat.avgComp));

  //printf("moving out of etf \n");
  
  return hash_stat;
}

 struct stat hash_cpp(char **input,int tablesize)
{
  struct stat hash_stat;

  /* write the program to perform GNU-cpp on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
  int hashTable[tablesize];
  struct node* hashList[tablesize];
  int i,k,j;
  //hashTable[0] = 1;
  int temp[5];
  int n = 1632;
  for(i = 0; i < tablesize; i++){
    hashTable[i] = 0;
  }
  for(i = 0; i < tablesize; i++){
    hashList[i] = (struct node*)malloc(sizeof(struct node));
    hashList[i]->next = NULL;
  }
  int pos[n];
  for(i = 0; i < n; i++){
    pos[i] = 0;
  }
  for(i = 0; i < n; i++) {
    temp[0] = 0;
    for(k = 1; k <= 4; k++) {
      temp[k] = 4*temp[k-1] + input[i][k];
    }
    //printf("her1e\n");
    int val = 0;
    for(j =0; j < 31; j++){
      val = val | ((1 << j)&temp[4]);
    }
    //printf("here\n");
    int H = val % tablesize;
    insert(&hashList[H], input[i]);
    hashTable[H]++;
    pos[i] = hashTable[H];
  }

  hash_stat.item = n;


  int max = -1;
  for(i = 0; i < tablesize; i++){
    if(max < hashTable[i])
      max = hashTable[i];
  }

  hash_stat.lenLong = max;

  int comp = 0;
  for(i = 0; i < n; i++){
    comp += (pos[i]);
  }
  hash_stat.avgComp =(float)comp/n;

  int sumofsq = 0;
  for(i = 0; i < n; i++){
    sumofsq += (pos[i]*pos[i]);
  }

  hash_stat.stdDev = sqrt(((float)sumofsq/n) - (hash_stat.avgComp * hash_stat.avgComp));

  
  return hash_stat;
}

struct stat hash_cc1(char **input,int tablesize)
{
  struct stat hash_stat;

  /* write the program to perform GNU-cc1 on the given input and given hash table size.
     collect statistics as specified in the question and store it in the structure hash_stat
  */
    int hashTable[tablesize];
    struct node* hashList[tablesize];
  int i,k,j;
  //hashTable[0] = 1;
  int temp[5];
  int n = 1632;
  for(i = 0; i < tablesize; i++){
    hashTable[i] = 0;
  }
  for(i = 0; i < tablesize; i++){
    hashList[i] = (struct node*)malloc(sizeof(struct node));
    hashList[i]->next = NULL;
  }
  int pos[n];
  for(i = 0; i < n; i++){
    pos[i] = 0;
  }
  for(i = 0; i < n; i++) {
    temp[0] = n;
    for(k = 1; k <= 4; k++) {
      temp[k] = 613*temp[k-1] + input[i][k];
    }
    int val = 0;
    for(j =0; j <= 30; j++){
      val = val | ((1LL << j)&temp[4]);
    }
    int H = val % tablesize;
    insert(&hashList[H], input[i]);
    hashTable[H]++;
    pos[i] = hashTable[H];
  }

  hash_stat.item = n;


  int max = -1;
  for(i = 0; i < tablesize; i++){
    if(max < hashTable[i])
      max = hashTable[i];
  }

  hash_stat.lenLong = max;

  int comp = 0;
  for(i = 0; i < n; i++){
    comp += (pos[i]);
  }
  hash_stat.avgComp =(float)comp/n;

  int sumofsq = 0;
  for(i = 0; i < n; i++){
    sumofsq += (pos[i]*pos[i]);
  }

  hash_stat.stdDev = sqrt(((float)sumofsq/n) - (hash_stat.avgComp * hash_stat.avgComp));

  
  return hash_stat;
}
