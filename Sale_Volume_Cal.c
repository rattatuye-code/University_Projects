#include<stdio.h>


int main(){
	
	float sale[5];
	float sum,percent;
	
	
	printf("Input sale volume of saleperson....\n");
	for(int i=0;i<5;i++)
	{
	 printf("No. %d ==>",i+1);
	 scanf("%f", &sale[i]);
	 sum = sum + sale[i];
	}
	printf("------------------------------\n");
	printf("Total sale volume : %.2f\n\n",sum);
	printf("++++ Sale Report ++++\n\n");
	printf("------------------------------\n");
	printf("|  %5s  |  %10s     |\n","No.","Volume");
	printf("------------------------------\n");
	
	for(int i=0;i<5;i++)
	{		
			percent=(sale[i]/sum)*100;
			printf("|  %5d  |  %10.2f (%5.2f%%) |\n",i+1,sale[i],percent);
	}
	
	

	

	return 0;
}
