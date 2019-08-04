
/***********************************************************************/
/* Student Name: Panagiotis Goulas, Student ID: 886001                 */
/* Assignment 1: Subject: Engineering Computation - Comp20005          */
/* Time and Date Submitted: 9:45 - 30/4/2018                           */
/*                        Programming is Fun                           */
/***********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


#define NEW_LINE        '\n'
#define THOUSAND        1000
#define THOUSAND_DEC    1000.0
#define FOURHUNDRED     400
#define HUNDRED         100
#define HUNDRED_DEC     100.0
#define FOUR            4
#define SECOND          2

/* Used lecturer's code for the following constants, till FEB_MONTH */
#define JAN             1
#define FEB             2
#define MAR             3
#define APR             4
#define MAY             5
#define JUN             6
#define JUL             7
#define AUG             8
#define SEP             9
#define OCT             10
#define NOV             11
#define DEC             12

#define STD_MONTH       30
#define LNG_MONTH       31
#define FEB_MONTH       28

#define DAYS_OF_YEAR    365
#define MAX_DATA        10000

#define NGPRS           3
#define SUNDAY          1
#define MONDAY          2
#define TUESDAY         3
#define WEDNESDAY       4
#define THURSDAY        5
#define FRIDAY          6
#define SATURDAY        7




/***********************  Function Prototypes ***************************/
int mygetchar();
void print_stage1(int YYYY[],int MM[],int DD[],int DAYCOUNT[],int counter3);
int read_stage1(int YYYY[],int MM[],int DD[],int DAY[],int DAYCOUNT[]);
int leap_year(int year);
int between_years(int year1, int year2);
void calculate_days(int YYYY[], int MM[], int DD[], int counter3);
int days_left(int YYYY[],int MM[],int DD[],int condition,int counter3);
int days_of_month(int month, int year);
void stage3(int YYYY[], int MM[], int DD[], int DAYCOUNT[], int counter3);
void stage4(int YYYY[],int MM[],int DD[],int DAY[],int DAYCOUNT[],int counter3,
			int Groups[], int Mon[], int Tue[], int Wed[], int Thu[],int Fri[],
			int Sat[], int Sun[], int Mon_count[], int Tue_count[],
			int Wed_count[], int Thu_count[], int Fri_count[], int Sat_count[],
			int Sun_count[]);
void stage4_partb(int Mon[], int Tue[], int Wed[], int Thu[], int Fri[],
				  int Sat[], int Sun[], int Mon_count[], int Tue_count[],
				  int Wed_count[],int Thu_count[], int Fri_count[],
				  int Sat_count[], int Sun_count[]);
void print_stage4a(int counter, int start_day, int start_month, int start_year,
			       int DD[], int MM[], int YYYY[], int Groups[], int i);
void initialize_arrays(int Sun[], int Mon[], int Tue[], int Wed[], int Thu[],
					   int Fri[], int Sat[]);

/* in this version -> changed array names into more meaningful names,        */
/* last version that was submitted was working perfectly                     */
/* declaring arrays in main                                                  */
int
main (int argc, char *argv[]) {
int YYYY[MAX_DATA],MM[MAX_DATA],DD[MAX_DATA], DAY[MAX_DATA],DAYCOUNT[MAX_DATA],
	counter3 =0, Groups[NGPRS], Mon[NGPRS], Tue[NGPRS], Wed[NGPRS], Thu[NGPRS],
	Fri[NGPRS], Sat[NGPRS], Sun[NGPRS], Mon_count[NGPRS], Tue_count[NGPRS],
	Wed_count[NGPRS], Thu_count[NGPRS], Fri_count[NGPRS], Sat_count[NGPRS],
	Sun_count[NGPRS];
 	

/****************************** Stage 1 *********************************/

	counter3=read_stage1(YYYY, MM, DD, DAY, DAYCOUNT);
 	print_stage1(YYYY, MM, DD, DAYCOUNT, counter3);
 	
/****************************** Stage 2 *********************************/

 	calculate_days(YYYY, MM, DD, counter3);
 	
/****************************** Stage 3 *********************************/

 	stage3(YYYY, MM, DD, DAYCOUNT, counter3);
 	
/****************************** Stage 4 *********************************/

 	stage4(YYYY,MM,DD,DAY,DAYCOUNT,counter3,Groups,Mon,Tue,Wed, Thu, Fri, Sat,
 		   Sun, Mon_count, Tue_count, Wed_count, Thu_count, Fri_count,
 		   Sat_count, Sun_count);
 	
 	stage4_partb(Mon, Tue, Wed, Thu, Fri, Sat, Sun, Mon_count, Tue_count,
 		         Wed_count, Thu_count, Fri_count, Sat_count, Sun_count);

 	return 0;
}

/* used Alistair's code to bypass the first 2 lines */
int
mygetchar() {
	int c;
	while ((c=getchar())=='\r') {
	}
	return c;
}
/* bypasses the first 2 lines with getchar as instructed and then inputs the */
/* data in the arrays appropriatelly                                         */
int
read_stage1(int YYYY[],int MM[],int DD[],int DAY[],int DAYCOUNT[]) {
 	int counter1=0,num1=0,num2=0,num3=0,num4=0,num5=0, month=0, counter2=0;
 	char ch;
 	
 	while (counter1 <= 1) {
 		ch = mygetchar();
 		if (ch == NEW_LINE) {
 			counter1++;
 		}		
 	}
 	
 	while(scanf("%d%d%d%d%d\n", &num1, &num2, &num3, &num4, &num5) == 5) {
 		YYYY[counter2] = num1;
 		MM[counter2] = num2;
 		DD[counter2] = num3;
 		DAY[counter2] = num4;
 		DAYCOUNT[counter2] = num5;
 		month = num2;
 		counter2++;
 	}
 	return counter2;	
}

/* prints out the output for stage 1 */
void
print_stage1(int YYYY[],int MM[],int DD[],int DAYCOUNT[], int counter3) {
  	printf("\nS1: total data lines = %d days\n", counter3);
   	printf("S1: first data line  = ");
   	printf("%02d/%02d/%d, ", DD[0], MM[0], YYYY[0]);
   	printf("%d people counted\n", DAYCOUNT[0]);
   	printf("S1: last data line   = ");
   	printf("%02d/%02d/%d, ", DD[counter3-1], MM[counter3-1], YYYY[counter3-1
]);
   	printf("%d people counted\n", DAYCOUNT[counter3-1]);
}

/* check if year is leap year , and if it is return 1. if not return 0 */
/* used Alistair's code as well                                        */
int
leap_year(int year) {
  if (year % FOUR == 0 && (year%HUNDRED!=0 || year%FOURHUNDRED==0)) {  
    return 1;
  } else {
    return 0;
  }
}

/* calculate days between years (year1 + 1) and (year2 - 1)            */
/* example: if year1 = 2009, year2 = 2018, then it calculates the days */
/* between 2010 and 2017 */
int
between_years(int year1, int year2) {
	int between_days = 0, between = 0, count = 0;
 	between = year2 - year1;
 	
 	while (count <= between) {
 		between_days += DAYS_OF_YEAR + leap_year(year1 + count);
 		count++;
 	}
 	return between_days;
}

/* calculates the remaining days of year1 - condition == 0                   */
/* calculates the days passed of year2 - condition == 1                      */
/* calculates the days if we only have 1 year,                               */
/* example: 2009,condition == SECOND                                         */
void
calculate_days(int YYYY[], int MM[], int DD[], int counter3) {
	int days=0, year1=0, year2=0, condition = 0, days_year1 = 0;
	double coverage = 0.0;
	
	year1 = YYYY[0];
	year2 = YYYY[counter3-1];
	
	if ((year2-year1)>=SECOND) {
		days += between_years((year1+1),(year2-1));
	}
	if (year2-year1==0) {
		condition = SECOND;
	}
	days += days_left(YYYY, MM, DD, condition, counter3);
	
	if ((year2-year1)==0) {
		days_year1 = days;
		days=0;
	}
	
	condition = 1;
	days += days_left(YYYY, MM, DD, condition, counter3);
	
	if ((year2-year1)==0) {
		days = (days+1) - days_year1;
	}
	
	printf("\nS2: range spanned    = %d days\n", days);
	if ((year2-year1)==0) {
			days--;
	}
	coverage = HUNDRED_DEC * (((counter3-1)*1.0) / days);
	printf("S2: coverage ratio   = %.1f%%\n\n", coverage);
}

/* calculates days left for year1, and days passed year2              */
/* calculates only days of 2009 between 2 days if we only have 1 year */
int
days_left(int YYYY[], int MM[], int DD[],int condition, int counter3) {
	int year=0,mm=0,day=0, days_left=0;
	
	year = YYYY[0];
	mm = MM[0];
	day = DD[0];
	
	if (condition == 1) {
		year = YYYY[counter3-1];
		mm = MM[counter3-1];
		day = DD[counter3-1];
	}
	
	mm--;
	while (mm > 0) {
		days_left += days_of_month(mm, year);
		mm--;
	}
	
	if (condition == 0) {
		if ((days_left-1)>0) {
			days_left += (day-1);
		}
	} else {
		days_left += day;	
	}
	if (condition == 0) {
		days_left = (DAYS_OF_YEAR - days_left);
	} 
	
	return days_left;
}

/* calculates the days of its month - used Alistair's code from lectures */
int
days_of_month(int mm, int year) {
	int month_days = 0;
	
	if (mm == FEB) {
		month_days += (FEB_MONTH + leap_year(year));
	} else if (mm==SEP||mm==APR||mm==JUN||mm==NOV) {
		month_days += STD_MONTH;
	} else
		month_days += LNG_MONTH;
	return month_days;
}

/* goes through each month and sums up the passengers and then prints them  */
/* out appropriately                                                        */
void
stage3(int YYYY[], int MM[], int DD[], int DAYCOUNT[], int counter3) {
	int month_count = 0, i = 0, month = 0, month_pedest = 0, year = 0,days_m=0;
	month = MM[0];
	year = YYYY[0];
	for (i=0; i<=counter3; i++) {
		if (month != MM[i]) {
			days_m= days_of_month(month, year);
			printf("S3: %02d/%d %2d/%02d days covered, ",
				month,year,month_count,days_m);
			printf("average count =  %4.1fk\n",
				(month_pedest/(month_count*THOUSAND_DEC)));
			month = MM[i];
			month_count = 1;
			year = YYYY[i];
			month_pedest = DAYCOUNT[i];
		} else {
			month_pedest += DAYCOUNT[i];
			month_count++;
		}	
	}
	printf("\n");
}
/* calculates stage 4 and prints it out                                      */
/* Part a)                                                                   */
/* the method we use here is to divide the total lines by NGPRS and take the */
/* integer part of it. Then take the remainder of that division. So we form  */
/* (number of total lines) / NGPRS groups and we add 1 in each group starting*/
/* from the last one upwards. then we go through our data and we search from */
/* from what date till what date we have the specific group's number of data */
/* records.                                                                  */

void
stage4(int YYYY[],int MM[], int DD[], int DAY[], int DAYCOUNT[],int counter3,
	   int Groups[],int Mon[], int Tue[], int Wed[], int Thu[], int Fri[], 
	   int Sat[],int Sun[], int Mon_count[], int Tue_count[], int Wed_count[],
	   int Thu_count[], int Fri_count[], int Sat_count[], int Sun_count[]) {
	
	int start_year=0, start_month=0, start_day=0,group_remainder=0,
		group_number=0, counter=0, i = 0, line_counter=1;
 	
	group_number = counter3 / NGPRS;
	group_remainder = counter3 % NGPRS;
	
	counter = (NGPRS-1);
	
	
	while (counter >= 0) {
		Groups[counter] = group_number;
		if (group_remainder > 0) {
			Groups[counter] += 1;
			group_remainder -= 1;
		}
		counter -= 1;
	}
	
	counter = 0;
	initialize_arrays(Sun, Mon, Tue, Wed, Thu, Fri, Sat);
	for (i=0; i<= (counter3-1); i++) {
		
		if (i==0) {
			start_day = DD[i];
			start_month = MM[i];
			start_year = YYYY[i];
		}
		/* these are used for stage4 part b)                              */
		/* if day is sunday == 2 for example sum up the passengers number */
		if (DAY[i] == SUNDAY) {
			Sun[counter] += DAYCOUNT[i];
			Sun_count[counter] += 1;
		}
		if (DAY[i] == MONDAY) {
			Mon[counter] += DAYCOUNT[i];
			Mon_count[counter] += 1; 
		}
		if (DAY[i] == TUESDAY) {
			Tue[counter] += DAYCOUNT[i];
			Tue_count[counter] += 1;
		}
		if (DAY[i] == WEDNESDAY) {
			Wed[counter] += DAYCOUNT[i];
			Wed_count[counter] += 1;
		}
		if (DAY[i] == THURSDAY) {
			Thu[counter] += DAYCOUNT[i];
			Thu_count[counter] += 1;
		}
		if (DAY[i] == FRIDAY) {
			Fri[counter] += DAYCOUNT[i];
			Fri_count[counter] += 1;
		}
		if (DAY[i] == SATURDAY) {
			Sat[counter] += DAYCOUNT[i];
			Sat_count[counter] += 1;
		}

		if (line_counter == Groups[counter]) {
			print_stage4a(counter, start_day, start_month, start_year, DD, MM,
						  YYYY, Groups, i);
			
			if (counter < NGPRS) {
				counter += 1;
			}
			line_counter=0;
			if (i < (counter3-1)) {
				start_day = DD[i+1];
				start_month = MM[i+1];
				start_year = YYYY[i+1];
			}
		}
		line_counter += 1;
	}
	printf("\n");
	
}

/* print out the output of stage 4 part a) */
void
print_stage4a(int counter, int start_day, int start_month, int start_year,
			  int DD[], int MM[], int YYYY[], int Groups[], int i) {
	
	printf("S4: group %d data, ", counter);
	printf("%02d/%02d/%d to ", start_day, start_month, start_year);
	printf("%02d/%02d/%d, ", DD[i], MM[i], YYYY[i]);
	printf("%d data records\n", Groups[counter]);

}

/* initialize arrays. always a good idea to initialize variables and arrays */
/* like Alistair always says: "Better initialize your variables >1 than     */
/* not initializing them at all and forgeting about them !!                 */
void 
initialize_arrays(int Sun[], int Mon[], int Tue[], int Wed[], int Thu[],
					   int Fri[], int Sat[]) {

	int counter = 0;
	
	for (counter = 0; counter < NGPRS; counter++) {
		Sun[counter] = 0;
		Mon[counter] = 0;
		Tue[counter] = 0;
		Wed[counter] = 0;
		Thu[counter] = 0;
		Fri[counter] = 0;
		Sat[counter] = 0;
		Sun[counter] = 0;
	}
}

/* prints out the output of stage 4 part b. basically we pass the arrays     */
/* into the function and we print appropriately. Although creating here      */
/* another function to automate further the procedure might be tempting we   */
/* opt not to do so as gain - loss is around the same                        */
/* we use round() function to round the results and get the asterisks (*)    */
void
stage4_partb(int Mon[], int Tue[], int Wed[], int Thu[], int Fri[], int Sat[],
	   int Sun[], int Mon_count[], int Tue_count[], int Wed_count[],
	   int Thu_count[], int Fri_count[], int Sat_count[], int Sun_count[]) {
	
	int i = 0, j = 0;
	double result = 0.0;
	
	for (i=0; i<NGPRS; i++) {
		result = Sun[i]/(Sun_count[i]*THOUSAND_DEC);
		printf("S4: Sun, g%d = %4.1fk",i, result);
		printf(" |");
		for(j=1;j<=(round(result));j++) {
				printf("*");
		}
		printf("\n");
	}
	printf("\n");
	
	for (i=0; i<NGPRS; i++) {
		result = Mon[i]/(Mon_count[i]*THOUSAND_DEC);
		printf("S4: Mon, g%d = %4.1fk",i, result);
		printf(" |");
		for(j=1;j<=(round(result));j++) {
				printf("*");
		}
		printf("\n");
	}
	printf("\n");
	
	for (i=0; i<NGPRS; i++) {
		result = Tue[i]/(Tue_count[i]*THOUSAND_DEC);
		printf("S4: Tue, g%d = %4.1fk",i, result);
		printf(" |");
		for(j=1;j<=(round(result));j++) {
				printf("*");
		}
		printf("\n");
	}
	printf("\n");
	
	for (i=0; i<NGPRS; i++) {
		result = Wed[i]/(Wed_count[i]*THOUSAND_DEC);
		printf("S4: Wed, g%d = %4.1fk",i, result);
		printf(" |");
		for(j=1;j<=(round(result));j++) {
				printf("*");
		}
		printf("\n");
	}
	printf("\n");
	
	for (i=0; i<NGPRS; i++) {
		result = Thu[i]/(Thu_count[i]*THOUSAND_DEC);
		printf("S4: Thu, g%d = %4.1fk",i, result);
		printf(" |");
		for(j=1;j<=(round(result));j++) {
				printf("*");
		}
		printf("\n");
	}
	printf("\n");
	
	for (i=0; i<NGPRS; i++) {
		result = Fri[i]/(Fri_count[i]*THOUSAND_DEC);
		printf("S4: Fri, g%d = %4.1fk",i, result);
		printf(" |");
		for(j=1;j<=(round(result));j++) {
				printf("*");
		}
		printf("\n");
	}
	printf("\n");
	
	for (i=0; i<NGPRS; i++) {
		result = Sat[i]/(Sat_count[i]*THOUSAND_DEC);
		printf("S4: Sat, g%d = %4.1fk",i, result);
		printf(" |");
		for(j=1;j<=(round(result));j++) {
				printf("*");
		}
		printf("\n");
	}
	printf("\n");	
}

/***********************************************************************/
/*             Thank you for going through my program                  */
/*                        Have a Nice Day!                             */
/*                                =)                                   */
/***********************************************************************/

/*                        Programming is Fun                           */
