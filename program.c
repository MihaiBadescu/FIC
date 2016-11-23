#include<string.h>
#include<stdlib.h>
#include<stdio.h>


int total,c1,c2,c3,c4;
char transfer_date[20][20]={"movl"};
char aritmetice[20][20]={"addl","subl","imull"};
char salt[20][20]={"jmp","cmpl","jle"};
char altele[20][20]={};
int n1=1,n2=3,n3=3,n4=0;


int contor1(char *linie){
  int i;
  for(i=0;i<n1;i++)
  {
    if(strstr(linie,transfer_date[i])!=NULL)
    {
      return 1;
    }
  }
  return 0;
}

int contor2(char *linie){
  int i;
  for(i=0;i<n2;i++)
  {
    if(strstr(linie,aritmetice[i])!=NULL)
    {
      return 1;
    }
  }
  return 0;
}

int contor3(char *linie){
  int i;
  for(i=0;i<n3;i++)
  {
    if(strstr(linie,salt[i])!=NULL)
    {
      return 1;
    }
  }
  return 0;
}

int contor4(char *linie){
  int i;
  for(i=0;i<n4;i++)
  {
    if(strstr(linie,altele[i])!=NULL)
    {
      return 1;
    }
  }
  return 0;
}


int main(){
  FILE *f;
  char *linie,*sir;
  int i;
  
  sir = malloc (100 * sizeof (char));
  f=fopen("L3-3.s","rt");
  
  while(!feof(f))
  {
    
    linie=fgets(sir,100,f);
    
    if(linie!=NULL)
    {
      if(contor1(linie))
      {
	c1++;
	total++;
	continue;
      }
      if(contor2(linie))
      {
	c2++;
	total++;
	continue;
      }
      if(contor3(linie))
      {
	c3++;
	total++;
	continue;
      }
      if(contor4(linie))
      {
	c4++;
	total++;
	continue;
      }
    }
    
  }
  printf("\nNumarul total de instructiuni : %d\n",total);
  printf("Instructiuni transfer date    : %d\n",c1);
  printf("Instructiuni aritmetice       : %d\n",c2);
  printf("Instructiuni de salt          : %d\n",c3);
  printf("Alte instructiuni	      : %d\n",c4);
  fclose(f);
}
