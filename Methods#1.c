#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int length(char text[]) // string length
{
	int i = 0;
	while(text[i] != '\0')
		i++;
	
	
	return i;
}


void findsubstring() // finding common substring
{

  char str[] = "String1 subString1 Strinstrnd subStr ing1subString";
  char sub[] = "subString";

  char *p1, *p2, *p3;
  int i=0,j=0,flag=0;

  p1 = str;
  p2 = sub;

  for(i = 0; i<length(str); i++)
  {
    if(*p1 == *p2)
      {
          p3 = p1;
          for(j = 0;j<length(sub);j++)
          {
            if(*p3 == *p2)
            {
              p3++;p2++;
            }
            else
              break;
          }
          p2 = sub;
          if(j == length(sub))
          {
             flag = 1;
            printf("\nSubstring found at index : %d\n",i);
          }
      }
    p1++;
  }
  
  if(flag==0)
  {
       printf("Substring NOT found");
  }

}



int getGCD(int a, int b) // greatest common divisor
{
    int i = 0 ;

    while(b!=0)
    {
        i = a % b;

        a =  b;

        b = i;

    }
    return a;

}



int getrand(int min, int max) // random number with linear distribution
{
    int range = max - min + 1;

    int num = (rand() % range) + min;

    return num;

}

double normaldist() // gaussian distribution
{
    double a,b,r,x1;

    a = 1.0 * rand() / (RAND_MAX * 1.0);

    b = 1.0 * rand() / (RAND_MAX * 1.0);

    r = sqrt(-2.0 * log(1-a));

    x1 = r * sin(2*M_PI*b);

    return x1;

}

int  getrandgau(int min, int max) // random number with gaussian distribution
{
    int range  = (max - min)+1;

    int rnd = (( (int) (normaldist()*100)+457) % range) + min;
    return rnd;
}



int search(char src[], char str[]) { // searching a string in a text
   int i, j, firstOcc;
   i = 0, j = 0;

   while (src[i] != '\0') {

      while (src[i] != str[0] && src[i] != '\0')
         i++;

      if (src[i] == '\0')
         return (-1);

      firstOcc = i;

      while (src[i] == str[j] && src[i] != '\0' && str[j] != '\0') {
         i++;
         j++;
      }

      if (str[j] == '\0')
         return (firstOcc);
      if (src[i] == '\0')
         return (-1);

      i = firstOcc + 1;
      j = 0;
   }
}





char charAt(char text[],int point) // spesific character  a point
{
	return  text[point];
}


void reverse(char text[]) // reverse string
{
	int i = length(text);
	while(i>=0)
	{
		printf("%c",text[i]);
		i--;	
	}
		
}


void split(char *text,int start,int finish) //split a string with range
{
	char newtext[100];
	int j = 0;
	int i = 0;
	for(i = start; i<finish;i++)
	{
		newtext[j] = text[i];
		j++;
	}
	
	
	for(i = 0; i < length(text);i++)
		text[i] = newtext[i];
		
		
		
}

void copy(char *text,char *newtext) //copy a strig to another
{
	int i = 0;

	for(i = 0; i < length(newtext);i++)
		text[i] = newtext[i];
			
	text[length(newtext)] = '\0';
		
}

void upper(char *text) // turn into uppercase
{
	int i=0;
	
	for(i=0; i < length(text);i++)
	 	if(text[i] >=97 && text[i] <=122)
	 		text[i] = text[i] - 32;
		
}


void lower(char *text) // turn into lowercase
{
	int i=0; 
	for(i=0; i < length(text);i++)
	 	if(text[i] >=65 && text[i] <=90)
	 		text[i] = text[i] + 32;
		
}

float natof(char *x) //ascii to float
{
	float m=1;
	float s=0;
	int i = 0;
	int f=0;
	
	for(i = length(x)-1;i>=0;i--)
		if(x[i] == '.') f = 1;
		else if (f==1)
		{
			s+=m*(x[i]-48);
			m*=10;
		}
	
	m=1;f=0;
	
	for(i=0;i<length(x);i++)
	{
		if(x[i]=='.') f=1;
		else if(f==1)
		{
			m/=10.;
			s+=m*(x[i]-48);	
		}

	}

	return s;
}


void swap(char *text, char *text2) //swapping 2 string
{
	char c[100];
	int i=0;
	
	for(i=0;i <=length(text2);i++)
   	c[i] = text2[i];


   for(i=0;i <=length(text);i++)
   	text2[i] = text[i];

   for(i=0;i <=length(c);i++)
   	text[i] = c[i];



}


int power(int a, int b) // a^b;
{
	int ret=1;
	int i=0;
	for(i=0;i<b;i++)
     	ret = ret  *  a;


    return ret;

}


int natoi(char *x) // ascii to integer
{
	int a = 0;
	int i=0;
   for(i=0;i<length(x);i++)
   		a = a + (power(10,(length(x)-i-1)) * (x[i]-48));

    return a;

}

int main()
{
	char text[] = "erkan berk";
	char text2[] = "deneme";
	char text3[] = "123";
	char text4[] = "123.567";
	
	printf("Text: %s",text);
	printf("\nLength: %d",length(text));
	printf("\nReverse:"); reverse(text);
	printf("\nChar at 6: %c",charAt(text,6)); ;
	
	split(text,2,5);printf("\nSplit 2 to 5: %s",text);
	
	copy(text,text2);printf("\nAfter copy our Text: %s",text);
	
	upper(text);printf("\nAfter upper our Text: %s",text);
	lower(text);printf("\nAfter lower our Text: %s",text);

	printf("\nInteger value of: %d",natoi(text3)); 
	printf("\nFloat value of: %f",natof(text4)); 
	
	printf("\n5^2 is: %d",power(5,2));
	
	return 0;	


}
