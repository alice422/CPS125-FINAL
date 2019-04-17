 

#include<stdio.h>
const char names[6][9] = { "Superior", "Michigan", "Huron", "Erie", "Ontario", "St.Claire" };
int i = 0;
int j = 0;

void q1_q2(double lake[6][365]);
void q3(double lake[6][365]);
void q4(double lake[6][365]);
void q5(double lake[6][365]);
void q6(double lake[6][365]);
void monthDateFromDayNumber(int dayNum);

void q1_q2(double lake[6][365])
{

	/*Question 1*/
	
	
	double avg[6] = { 0, 0, 0, 0, 0, 0 };
	double totAvg;
	
	int cold = 0, warm = 0;
	
	printf("QUESTION 1\n");
	

	for (j = 0; j < 365; j++) {
		for ( i = 0; i < 6; i++) {

			avg[i] += (lake[i][j]/365);
		}

	}
	
	for (i = 0; i < 6; i++){
		printf("The average temperature of lake %s is %.2lf celsius.\n", names[i], avg[i]);
		
	}
	
	
	totAvg = (avg[0] + avg[1] + avg[2] + avg[3] + avg[4] + avg[5])/6;
	
	printf("\nThe average temperature of all the lakes is %.2lf celsius\n", totAvg);

	/*Question 2*/
	
	
	printf("\n\n\nQUESTION 2\n");
	
	for ( i = 0; i < 6; i++) {
		if (avg[i] > totAvg)
			printf("Lake %s has an above average temperature.\n", names[i], avg[i]);
		else
			printf("Lake %s has below average temperature.\n", names[i], avg[i]);

		if (avg[i] < avg[cold])
			cold = i;
		else if (avg[i] > avg[warm])
			warm = i;	

	}

	printf("\n\nLake %s is the coldest lake.\n", names[cold]);
	printf("Lake %s is the warmest lake.\n", names[warm]);

}


void q3(double lake[6][365])
{

	int warmest[6] = { 0, 0, 0, 0, 0, 0 };
	int coldest[6] = { 0, 0, 0, 0, 0, 0 };
	
	printf("\n\n\nQUESTION 3\n");
	

	for (j = 1; j < 365; j++) {

		for ( i = 0; i < 6; i++) {
			if (lake[i][j] > lake[i][warmest[i]])
				warmest[i] = j;
			else if (lake[i][j] < lake[i][coldest[i]])
				coldest[i] = j;
		}

	}
	
	
	
	for( i = 0; i < 6; i++){
		printf("Lake %s had it's warmest on", names[i]); monthDateFromDayNumber(warmest[i]+1); printf("with a temperature of %.2lf celsius.\n", lake[i][warmest[i]]);
	}
	
	printf("\n\n\n");
	
	for(i = 0; i < 6; i++){
		printf("Lake %s had it's coldest on", names[i]); monthDateFromDayNumber(coldest[i]+1); printf("with a temperature of %.2lf celsius.\n", lake[i][coldest[i]]);
	}

}


void q4 (double lake[6][365])
{

	int avg_warmest = 0;
	int avg_coldest = 0;
	
	double cur_avg_warm = 0;
	double cur_avg_cold = 0;
	double new_avg = 0;


	/*Question 4*/
	
	printf("\n\n\nQUESTION 4\n");
	
	for(i = 0; i < 6; i++){
		cur_avg_warm += lake[i][0]/6;
	}
	
	cur_avg_cold = cur_avg_warm;
	
	for(j = 1; j<365; j++){
	
		for(i = 0; i < 6; i++){
			new_avg += lake[i][j]/6;
		}
		
		if(new_avg > cur_avg_warm){
		 	avg_warmest = j;
		 	cur_avg_warm = new_avg;
		}
		 
		else if(new_avg < cur_avg_cold){
		 	avg_coldest = j;
		 	cur_avg_cold = new_avg;
		}
		
		new_avg = 0;
	
	}
	
	
	/*printf("On"); monthDateFromDayNumber(avg_warmest+1);	rintf("the warmest overall temperature occurred, which was %.2lf celsius", cur_avg_warm);*/
	printf("On"); monthDateFromDayNumber(avg_coldest+1); printf("the coldest overall temperature occurred, which was %.2lf celsius\n", cur_avg_cold);
	printf("On"); monthDateFromDayNumber(avg_warmest + 1); printf("the warmest overall temperature occurred, which was %.2lf celsius", cur_avg_warm);

}


void q5(double lake[6][365]){

	double summer_avg[6] = { 0, 0, 0, 0, 0, 0 };
	double warmer = 100;
	int current = 0;
	int order[6] = {3, 5, 4, 1, 2, 0};
	
	/*Question 5*/
	
	printf("\n\n\nQUESTION 5\n");

	for (j = 171; j <= 264; j++) {
		for (i = 0; i < 6; i++) {
			summer_avg[i] += (lake[i][j]/94);
		}

	}
	
	
	for(i = 0; i < 6; i++){	   
		printf("Lake %s has a summer average temperature of %.2lf celsius\n", names[order[i]], summer_avg[order[i]]);
	}

}


void q6(double lake[6][365])
{

	double winter_avg[6] = { 0, 0, 0, 0, 0, 0 };
	double warmer = 100;
	int current = 0;
	int order[6] = {4, 1, 0, 2, 3, 5}; 
	
	printf("\n\n\nQUESTION 6\n");

	/*Question 6*/
	for (j = 0; (j >= 0 && j <= 78) || (j >= 354 && j <= 364); j++) {
		for (i = 0; i < 6; i++) {
			winter_avg[i] += (lake[i][j]/90);
			if(j == 79) j=353;
		}

	}
	
	
		
	for(i = 0; i < 6; i++){
		printf("Lake %s has a winter average temperature of %.2lf celsius\n", names[order[i]], winter_avg[order[i]]);
	}


}


void q7_q8(double lake[6][365])
{

	int swim[6] = { 0, 0, 0, 0, 0, 0 };
	int frozen[6] = { 0, 0, 0, 0, 0, 0 };

	/*Question 7 and 8*/
	
	printf("\n\n\nQUESTION 7\n");
	
	for(j = 0; j < 365; j++){
		for(i = 0; i < 6; i++){
			if(lake[i][j] > 20) swim[i]++;
			else if (lake[i][j] < 0) frozen[i]++;
			
		}
		
	}
	
	
	for(i = 0; i < 6; i++){
		printf("Lake %s is safe to swim in for %d days \n", names[i], swim[i]);
	}
	
	printf("\n\n\nQUESTION 8\n");
	
	for(i = 0; i < 6; i++){
		printf("Lake %s is frozen for %d days.\n", names[i], frozen[i]);
	}

}




int main(void)
{
	/*initializing lake names*/
	/*const char names[6][9] = { "Superior", "Michigan", "Huron", "Erie", "Ontario", "St.Claire" };*/

	double lake[6][365];
	double trash;
	
	
	
	
	
	
	FILE *in;
	
	in = fopen("lakeData.txt", "r");


	for (j = 0; j < 365; j++) {
	
		fscanf(in, "%lf", &trash);
		fscanf(in, "%lf", &trash);
		
		for ( i = 0; i < 6; i++) {

			fscanf(in, "%lf", &lake[i][j]);
		}

	}
	
	
	
	q1_q2(lake);
	q3(lake);
	q4(lake);
	q5(lake);
	q6(lake);
	q7_q8(lake);
	
	
	
	

	
	
	
	fclose(in);

	return 0;
}


void monthDateFromDayNumber(int dayNum)
{
	int day;

	if (dayNum <= 31)  /*Days can start  from 1*/
	{
		/*date falls in january*/
		printf(" January %d ", dayNum);
	}
	else if (dayNum <= 59)  /*Because 2017 was not a leap year.*/
	{
		/*date falls in February*/
		printf(" February %d ", dayNum - 31);
	}
	else if (dayNum <= 90) 
	{
		/*date falls in March*/
		printf(" March %d ", dayNum - 59);
	}
	else if (dayNum <= 120)
	{
		/*date falls in April*/
		printf(" April %d ", dayNum - 90);
	}
	else if (dayNum <= 151) 
	{
		/*date falls in May*/
		printf(" May %d ", dayNum - 120);
	}
	else if (dayNum <= 181)
	{
		/*date falls in June*/ 
		printf(" June %d ", dayNum - 151);
	}
	else if (dayNum <= 212)
	{
		/*date falls in July*/
		printf(" July %d ", dayNum - 181);
	}
	else if (dayNum <= 243)
	{
		/*date falls in August*/
		printf(" August %d ", dayNum - 212);
	}
	else if (dayNum <= 273)
	{
		/*date falls in September*/ 
		printf(" September %d ", dayNum - 243);
	}
	else if (dayNum <= 304)
	{
		/*date falls in October*/
		printf(" October %d ", dayNum - 273);
	}
	else if (dayNum <= 334)
	{
		/*date falls in November*/
		printf(" November %d ", dayNum - 304);
	}
	else if (dayNum <= 365)
	{
		/*date falls in December*/ 
		printf(" December %d ", dayNum - 334);
	}
	else
	{
		printf(" Wrong day number. Year 2017 do not have %d days", dayNum);
	}
}

