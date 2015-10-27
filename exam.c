#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
char chn;
void displayscore()
 {
	 char name[20];
	 float s;
	 FILE *f;
	 
	 f=fopen("score.txt","r");
	 fscanf(f,"%s%f",&name,&s);
	 printf("\n\n\t\t ");
	 printf("\n\n\t\t %s has secured the Highest Score %.2f",name,s);
	 printf("\n\n\t\t ");
	 fclose(f);
	 
 }
void help()
 {
	 
	 printf("\n\n\n\tThis game is very easy to play. You'll be asked some general");
	 printf("\n\n\tknowledge questions and the right answer is to be chosen among");
	 printf("\n\n\tthe four options provided. Your score will be calculated at the");
	 printf("\n\n\tend. Remember that the more quicker you give answer the more");
	 printf("\n\n\tscore you will secure. Your score will be calculated and displayed");
	 printf("\n\n\tat the end and displayed. If you secure highest score, your score");
	 printf("\n\n\twill be recorded. So BEST OF LUCK.");
 }
void writescore(float score, char plnm[20])
 {
	 float sc;
	 char nm[20];
	 FILE *f;
	
	 f=fopen("score.txt","r");
	 fscanf(f,"%s%f",&nm,&sc);
	 if (score>=sc)
	  { sc=score;
	    fclose(f);
	    f=fopen("score.txt","w");
	    fprintf(f,"%s\n%.2f",plnm,sc);
	    fclose(f);
	  }
 }
void exam() {
	     int countq,countr;
	     int r,i;
	     int pa;
	     int nq[6];
	     int w;
	     int opt;
	     float score;
	     int choice;
	     char ch1[10];
	     char playername[20];
	     time_t initialtime,finaltime;
	     
	     mainhome:
	    
	do {
	     puts("\n\t\t WELCOME TO I.Q. TEST PROGRAM\n\n") ;
	     puts("\n\t\t-------------------------------");
	     puts("\n\t\t Enter 1 to start game       ");
	    // puts("\n\t\t Enter 2 to view high score  ");
	     puts("\n\t\t Enter 2 for help            ");
	     puts("\n\t\t Enter 3 to quit             ");
	     printf("\n\t\t-------------------------------\n\n\t\t  ");
	     
	     scanf("%d",&choice);
	    // choice=toupper(choice);
	     if (choice==4)
		{
			displayscore();
			goto mainhome;
		}
	     else if (choice==3)
	 		//exit(1);
			choise();
	     else if (choice==2)
             {
			 help();
	 		goto mainhome;
	     }
	    else if(choice==1)
           		    

		     printf("\n\n\n\t\t\tEnter your name...");
		     printf("\n\t\t\t(only one word)\n\n\t\t\t");
		     scanf("%s", playername);
		     home:
		   
		     initialtime=time(NULL);
		     countq=countr=0;
		     i=1;
		     start:
		     srand ( time(NULL) );
		     r=rand()%23+1;
		     nq[i]=r;
		     for (w=0;w<i;w++)
		 if (nq[w]==r) goto start;

		     switch(r)
		  {
		  	case 1:
		  		printf("\n\nWhat is the maximum no. of asymptotes of the curve x^4+2x+6=0?");
		  		printf("\n\n1.4\t2.3\n\n3.none\t4.infinite\n\n");
		  		countq++;
				scanf("%d", &opt);
			  if (opt == 1) {
			  	 printf("\n\nCorrect!!!");
				 countr++;
				 break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 1.4");
				break;
		 	 }

		  case 2:
			  printf("\n\n\nHow many points are possible in a compound pendulum about which");
			  printf("time period is same?");
			  printf("\n\n1.4\t2.2\n\n3.none\t4.infinite\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 1) {
			   	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else
				printf("\n\nWrong!!! The correct answer is 1.4");
			  break;

		  case 3:
			  printf("\n\n\nWho was the first US President?");
			  printf("\n\n1.Richard Nikson\t2.Abraham Linkon\n\n3.John F. Kennedy\t4.George Washington\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 4)
			   {
				printf("\n\nCorrect!!!");
				countr++; 
				break;
			   }
			  else {
				printf("\n\nWrong!!! The correct answer is 4.George Washington");
				break;
			   }

		  case 4:
			  printf("\n\n\nWho was awarded the 'Man of the Tournament' of ICC WORLD CUP 2007?");
			  printf("\n\n1.Glen Magrath\t2.Mahela Jawardan\n\n3.Mathew Hayden\t4.Sachin Tendulkar\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 1) {
			   	printf("\n\nCorrect!!!");
				countr++; 
			   	break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 1.Glen Magrath");
				break;
			  }
		  case 5:
			  printf("\n\n\nWhich country won the Fifa World Cup 1998?");
			  printf("\n\n1.France\t2.Brazil\n\n3.Italy\t4.England\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 1){
			   	printf("\n\nCorrect!!!");countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 1.France");
				break;
			  }
		  case 6:
			  printf("\n\n\nWhich syllabe is stressed in the word 'democracy'?");
			  printf("\n\n1.1st\t2.2nd\n\n3.3rd\t4.4th\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 2 ){
			   	printf("\n\nCorrect!!!");
				countr++; 
			   	break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 2.2nd");
				break;
			  }
		  case 7:
			  printf("\n\n\nWhich country was the winner of Cricket World Cup 1987?");
			  printf("\n\n1.West Indies\t2.India\n\n3.Australia\t4.England\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 3){
			   	 printf("\n\nCorrect!!!");
				 countr++; 
				 break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 3.Australia");
				break;
			  }
		  case 8:
			  printf("\n\n\nWhat is the height of Mount everest in feet?");
			  printf("\n\n1.8648\t2.6648\n\n3.8884\t4.8848\n\n");
			  countq++;
			   scanf("%d", &opt);
			  if (opt == 4){
			  	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 4.8848");
				break;
			  }
		  case 9:
			  printf("\n\n\nWhat is the capital of Denmark?");
			  printf("\n\n1.Copenhagen\t2.Helsinki\n\n3.Rome\t\t4.Madrid\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 1) {
			   	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 1.Copenhagen");
				break;
			  }
		  case 10:
			  printf("\n\n\nWhich syllabe is stressed in the word 'instanteneous'?");
			  printf("\n\n1.1st\t2.2nd\n\n3.3rd\t4.4th\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 3){
			  	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 3.3rd");
				break;
			  }
		  case 11:
			  printf("\n\n\nWho was the only player to score 6 successive sixes in an over?");
			  printf("\n\n1.Adam Gilchrist\t2.M.S.Dhoni\n\n3.Herschel Gibbs\t4.Sanath Jayasurya\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 3){
			  	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 3.Herschel Gibbs");
				break;
			}
		  case 12:
			  printf("\n\n\nWho was the only player to take 4 successive wickets?");
			  printf("\n\n1.Malinga Bandara\t2.Lasith Malinga\n\n3.Bret Lee\t4.Murali Daran\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 2) {
			   	printf("\n\nCorrect!!!");
				countr++; 
				break;
			   }
			  else{
				printf("\n\nWrong!!! The correct answer is 2.Lasith Malinga");
				break;
			  }
		  case 13:
			  printf("\n\n\nWhich country is hosting the Fifa World Cup 2010?");
			  printf("\n\n1.South Africa\t2.Italy\n\n3.Argentina\t4.Spain\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 1) {
			   	printf("\n\nCorrect!!!");
			   	countr++;
				 break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 1.South Africa");
				break;
			  }

		  case 14:
			  printf("\n\n\nWho is the author of 'Pulpasa Cafe'?");
			  printf("\n\n1.Narayan Wagle\t2.Lal Gopal Subedi\n\n3.B.P. Koirala\t4.Khagendra Sangraula\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 1) {
			   	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 1.Narayan Wagle");
				break;
			  }
		  case 15:
			  printf("\n\n\nWhich country is Maria Sarapova from?");
			  printf("\n\n1.Russia\t2.Switzerland\n\n3.Argentina\t4.Spain\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 1){
			   	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 1.Russia");
				break;
			  }

		  case 16:
			  printf("\n\n\nWho was awarded the youngest player award in Fifa World Cup 2006?");
			  printf("\n\n1.Wayne Rooney\t2.Lucas Podolski\n\n3.Lionel Messi\t4.Christiano Ronaldo\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 2) {
			  	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 2.Lucas Podolski");
				break;
			  }
			  
		  case 17:
			  printf("\n\n\nWhat is the smallest district of Nepal?");
			  printf("\n\n1.Lalitpur\t2.Karnali\n\n3.Bhaktapur\t4.Gulmi\n\n");
			  countq++;
			   scanf("%d", &opt);
			  if (opt == 3) {
			   	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 3.Bhaktapur");
				break;
			  }
		  case 18:
			  printf("\n\n\nWhat is the headquarter of Western Development Region?");
			  printf("\n\n1.Dhankuta\t2.Kathmandu\n\n3.Dhangadhi\t4.Pokhara\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 4) {
			   	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 4.Pokhara");
				break;
			  }

		  case 19:
			  printf("\n\n\nWhich place is called 'The Cherrapunji of Nepal'?");
			  printf("\n\n1.Dharan\t2.Kathmandu\n\n3.Pokhara\t4.Butwal\n\n");
			  countq++;
			   scanf("%d", &opt);
			  if (opt == 3){
				printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 3.Pokhara");
				break;
			 }

		  case 20:
			  printf("\n\n\nWhich city is known at 'The City of Seven Hills'?");
			  printf("\n\n1.Rome\t2.Vactican City\n\n3.Madrid\t4.Berlin\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 1) {
			   	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else {
				printf("\n\nWrong!!! The correct answer is 1.Rome");
				break;
			  }

		  case 21:
			  printf("\n\n\nWho was the F1 racing champion of 2006?");
			  printf("\n\n1.Louis Hamilton\t2.Felipe Massa\n\n3.Fernando Alonso\t4.Michael Schumaker\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 3) {
			   	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 3.Fernanda Alonso");
				break;
			  }
		  case 22:
			  printf("\n\n\nWho won the Women Australian Open 2007?");
			  printf("\n\n1.Martina Hingis\t2.Maria Sarapova\n\n3.Kim Clijster\t4.Serena Williams\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 4) {
			   	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else{
				printf("\n\nWrong!!! The correct answer is 4.Serena Williams");
				break;
			}

		  case 23:
			  printf("\n\n\nName the country where there no mosquito is found?");
			  printf("\n\n1.Germany\t2.Spain\n\n3.Japan\t4.France\n\n");
			  countq++;
			  scanf("%d", &opt);
			  if (opt == 4) {
			   	printf("\n\nCorrect!!!");
				countr++; 
				break;
			  }
			  else
				{
				printf("\n\nWrong!!! The correct answer is 4.France");
				break;
				}

		 }
		//printf("Do u Want to continue (Y/N):-");
                //scanf("%c", &chn);
		}while(chn=='Y' || chn == 'y');
	i++;
	if (i<=5) 
		goto start;
	 finaltime=time(NULL);
	 score=(float)countr/countq*100-difftime(finaltime,initialtime)/3;
	 if (score<0) 
		score=0;
	 printf("\n\n\nYour Score: %.2f",score);
	 if (score==100) 
		printf("\n\nEXCELLENT!!! KEEP IT UP");
	 else if (score>=80 && score<100) 
		printf("\n\nVERY GOOD!!");
	 else if (score>=60 &&score<80) 
		printf("\n\nGOOD! BUT YOU NEED TO KNOW MORE.");
	 else if (score>=40 && score<60) 
		printf("\n\nSATISFACTORY RESULT, BUT THIS MUCH IS MUCH SUFFICIENT.");
	 else 
		printf("\n\nYOU ARE VERY POOR IN G.K.,WORK HARD");
	 puts("\n\nNEXT PLAY?(1 (yes) / 2 (NO) )");
	 int d;
	 scanf("%d", &d);
	 if (d == 1) {
	  	goto home;
	 }
	  if(d==2)
	  {
	  	//writescore(score,playername);
	  	goto mainhome;
	  }
	/* else 
	 {
	 	printf("\n\n\t\t  Enter the right key\n\n\t\t  ");
	 	goto mainhome;
	 }*/
	
	 
}
