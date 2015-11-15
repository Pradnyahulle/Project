#include <stdio.h> 
#include <stdlib.h>
#include <string.h>  

int student()
{
    FILE *fp, *ft; /* file pointers */
	int ch;
	char an;
    /* structure that represent a studentloyee */
    struct student
    {
	char name[40]; 		
	int age; 		
	float percent; 		
    };

    struct student e; 		
    char studentname[40]; 		
    long int recsize; 		
   /* open the file in binary read and write mode
    * if the file student.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    fp = fopen("student.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("student.DAT","wb+");
	if(fp == NULL)
	{
            printf("Connot open file");
            exit(1);
        }
    }

    /* sizeo of each record i.e. size of structure variable e */
    recsize = sizeof(e);

    /*infinite loop continues untile the break statement encounter */
    while(1)
    {
	printf("\n1. Add Record\n"); 

	printf("\n2. List Records\n"); 

	printf("\n3. Modify Records\n"); 

	printf("\n4. Delete Records\n"); 

	printf("\n5. Exit\n"); 

	printf("\nYour Choice: \n");  
	fflush(stdin);            
	scanf("%d",&ch);
	switch(ch)
	{
            case 1:  
               
                fseek(fp,0,SEEK_END);
		an='y';
		{ 
                    printf("\nEnter name: ");
                    scanf("%s",e.name);
                    printf("\nEnter age: ");
                    scanf("%d", &e.age);
                    printf("\nEnter Percentage of student: ");
                    scanf("%f", &e.percent);
                    fwrite(&e,recsize,1,fp); 
                }
                break;
            case 2:
    			rewind(fp); /* this moves file cursor to start of the file */
			while(fread(&e,recsize,1,fp)==1)
			{ /* read the file and fetch the record one record per fetch */
		            printf("\n\t%s \t%d \t%.2f",e.name,e.age,e.percent); 
			    printf("\n\t*******************************"); 	
			
		        }
                break;

            case 3: 
		an='y';
		while(an == 'y')
		{
                    printf("Enter the student name to modify: ");
                    scanf("%s", studentname);
                    rewind(fp);
		    while(fread(&e,recsize,1,fp)==1)
		    { 
			/* fetch all record from file */
			if(strcmp(e.name,studentname) == 0)
			{ 
			   /* if entered name matches with that in file */
                            printf("\nEnter new name,age and percent: ");
                            scanf("%s%d%f",e.name,&e.age,&e.percent);
                            fseek(fp,-recsize,SEEK_CUR); /* move the cursor 1 step back from current position */
                            fwrite(&e,recsize,1,fp); /* override the record */
                            break;
                        }
                    }
                    printf("\nModify another record(y/n)");
                    fflush(stdin);
			scanf("%c",&an);
                }
                break;
            case 4:
                an= 'y';
                while(an == 'y'){
                    printf("\nEnter name of student to delete: ");
                    scanf("%s",studentname);
                    ft = fopen("Tstudent.dat","wb");  /* create a intermediate file for tstudentorary storage */
                    rewind(fp); /* move record to starting of file */
                    while(fread(&e,recsize,1,fp) == 1){ /* read all records from file */
                        if(strcmp(e.name,studentname) != 0){ /* if the entered record match */
                            fwrite(&e,recsize,1,ft); /* move all records except the one that is to be deleted to tstudent file */
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("student.DAT"); /* remove the orginal file */
                    rename("Tstudent.dat","student.DAT"); /* rename the tstudent file to original file name */
                    fp = fopen("student.DAT", "rb+");
                    fflush(stdin);
		    scanf("%c",&an);
                }
                break;
            case 5:
                fclose(fp);  
		choise(); 
        }
	printf("\n-----------------------------------------------\n");
    }
    
}

