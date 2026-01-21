#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int main(){
	
	char code,carwash;
	int liter;
	float price,gasPrice,carwashPrice,totalPrice;
	
	printf("Today's gas price...\n");
	printf("------------------------------------\n");
	printf("%3s   %-12s  %8s\n","Code","Type","Price");
	printf("------------------------------------\n");
	printf("%3s   %-12s  %8s\n","A","Gasohol 95","36.35");
	printf("%3s   %-12s  %8s\n","B","Gasohol 91","35.98");
	printf("%3s   %-12s  %8s\n","C","Gasohol E20","34.24");
	printf("%3s   %-12s  %8s\n","D","Gasohol E85","33.99");
	printf("%3s   %-12s  %8s\n","E","Hi Disel","32.94");
	printf("------------------------------------\n");
	
	printf("Enter Gas Code:");
	scanf("%c", &code);
	
	printf("Enter Number of liters:");
	scanf("%d", &liter);
	getchar();
	
	printf("Wash the car(Y)or not(N):");	
	scanf("%c", &carwash);
	
	switch(code){
		case 'A' : price = 36.35; break;
		case 'B' : price = 35.98; break;
		case 'C' : price = 34.24; break;
		case 'D' : price = 33.99; break;
		case 'E' : price = 32.94; break;
		default  : price = 0;
				   printf("invalid Input\n\n");	
	}
	
	gasPrice=liter*price;
	
	if(gasPrice>=1000&&carwash=='Y'){
    carwashPrice=150;}
	else if(gasPrice<=1000&&carwash=='Y'){
	carwashPrice=250;}
	else{
		carwashPrice=0;
	}
	
	totalPrice=gasPrice+carwashPrice;  
	
	printf("%60s","****************************************************\n");
	printf("%8s""%52s","*","*\n");
	printf("%8s %35s %15s","*","Gas-N-Clean Service Station","*\n");
	printf("%8s""%52s","*","*\n");
	printf("%60s","****************************************************\n\n");
	
	printf("%-30s : %20d %2s\n","Amount of gasoline purchased",liter,"liters");
	printf("%-30s : %20.2f %2s\n\n","Price per liter",price,"bath.");	
	printf("%-30s   %20.2f %2s\n","Total gasoline cost",gasPrice,"baht.");
	printf("%-30s   %20.2f %2s\n","Car wash cost",carwashPrice,"baht.");
	printf("%70s","------------------------------\n");
	printf("%30s   %20.2f %2s\n","Total due",totalPrice,"baht.");

return 0;
}
