#include <stdio.h>
#include <stdlib.h>

//function that reads in text file with 12 monthly sales numbers
float* read_sales(char *file_name){
	float* monthly_sales = (float*)malloc(sizeof(float) * 12);
	FILE *fp = fopen(file_name, "r");
	for(int i =0; i < 12; ++i){
		fscanf(fp, "%f\n", &monthly_sales[i]);
	}
	return monthly_sales;
}

//function to prints out and calculate six-month moving averages 
int moving_avg(char *calendar[], float *sales){
	printf("\nSix-Month Moving Average Report: \n");
	int begin = 0, end = 5;
	float total = 0;
	
	while(begin < 7){
		printf("%-8s\t- %-8s\t\t", calendar[begin], calendar[end]);
		for(int i = begin; i <= end; i++){
			total += sales[i];
		}
		float average = total / 6;
		printf("$%.2f\n", average);
		begin++;
		end++;
		total = 0;
	}
	return 0;
}

//function to print out sales summary with minimum, maximum, and average of the monthly sales. 
int sales_summary(float *sales){
	double total, average, min, max;
	
	total = 0.0;
	min = sales[0];
	max = sales[0];
	for (int i = 0; i < 12; i++) {
		total += sales[i];
		if (sales[i] < min) {
			min = sales[i];
		}
		if (sales[i] > max) {
			max = sales[i];
		}
	}
	average = total / 12;
	
	printf("\nSales Summary\n");
	printf("Minimum: $%.2f\n", min);
	printf("Maximum: $%.2f\n", max);
	printf("Average: $%.2f\n", average);
	
	return 0;
}

// function to print out sales report 
int sales_report(char *calendar[], float *sales){
	printf("Months\t\tSales\n");
	for(int i = 0; i < 12; ++i){
		printf("%-8s\t$%.2f\n", calendar[i], sales[i]);
	}
	return 0;
}

// function to print out monthly sales report from highest to lowest 
int monthly_sales_report(char *calendar[], float *sales){
	printf("\nSales Report (Highest to Lowest):\nMonth\t\tSales\n");
	int max_idx = 0;
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			if(sales[j] > sales[max_idx]){
				max_idx = j;
			}
		}
		printf("%-8s\t$%.2f\n", calendar[max_idx], sales[max_idx]);
		sales[max_idx] = 0;
	}
	return 0;
}

//main function that calls all functions to print out final tabular sales report and sales summary report
int main(){
	//reads in input.txt file with 12 monthly sales numbers 
	float* sales = read_sales("input.txt");
	
	//creates array containing months of the year that will be printed out in report 
	char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	
	printf("Monthly Sales Report for 2022:\n");
	
	//calls all functions to generate final report 
	sales_report(month, sales);
	sales_summary(sales);
	moving_avg(month, sales);
	monthly_sales_report(month, sales);
	return 0;
}