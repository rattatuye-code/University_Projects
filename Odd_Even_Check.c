//Phurin reabroi
//68040233136
#include<stdio.h>
int main(){
	
	int num=1 ,odd=0,even=0;
	
	printf("***** Check Odd/Even Number *****\n");
	while(num !=0){
	 printf("Enter integer number =>");
	 scanf(" %d", &num);
	 
	  if(num % 2!=0){
 	   odd = odd+1;
        }else{
 	      even = even+1;
         }
    }
	 printf("-----------------------------\n");
	 printf("%11s | %15s\n","Type","Number");
	 printf("-----------------------------\n");
	 printf("%6s  | %12d\n","Odd number",odd);
	 printf("%6s | %12d\n","Even number",even-1);
	 printf("-----------------------------\n");
return 0;
}
