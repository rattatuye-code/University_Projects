#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int main(){
	char code,customer[20];
	int qty;
	float price,rate,discount,sumPrice,netPrice;
	
	printf("Enter customer type(B:Business/P:Private==>)");
	scanf(" %c", &code);
	
	printf("Enter unit price of product==>");
	scanf("%f", &price);
	
	printf("Enter number of product==>");
	scanf("%d", &qty);
	
	if(code == 'B'||code == 'b'){
		
		strcpy(customer,"Business");
		
		if(qty<10) rate = 0.10;
		else       rate = 0.15;
	}
	else if(code == 'P'||code == 'p'){
		
	    strcpy(customer,"Business");
		rate = 0.05;	
	}
	else{
		strcpy(customer,"Unknown");
		rate = 0.0;
	}
	
	sumPrice = qty*price;
	discount = sumPrice*rate;
	netPrice = sumPrice-discount;
	
	printf("-------------------------------------------------\n");
	printf("%-20s %4s %10s %15s \n","Customer type","Price","QTY","Discount rate");
	printf("-------------------------------------------------\n");
	printf("%-20s %4.2f %10d %15.2f \n",customer,price,qty,discount);
	printf("-------------------------------------------------\n");
	printf("Sumprice : %-10.2f \n",sumPrice);
	printf("Discount : %-10.2f \n",discount);
	printf("Netprice : %-10.2f \n",netPrice);
	
	return 0;
