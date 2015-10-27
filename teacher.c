#include <stdio.h> 
#include <stdlib.h>
#include <string.h>  

int teacher()
{
    FILE *fp, *ft; /* file pointers */
	int ch;
	char an;
    
    struct Teacher
    {
	char name[40]; 	
	int age; 		
	float bs; 		
    };

    struct Teacher e; 		
    char Teachername[40]; 		
    long int recsize; 		
   /* open the file in binary read and write mode
    * if the file Teacher.DAT already exists then it open that file in read write mode
    * if the file doesn't exit it simply create a new copy
    */
    fp = fopen("Teacher.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("Teacher.DAT","wb+");
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
                    printf("\nEnter basic salary: ");
                    scanf("%f", &e.bs);

                    fwrite(&e,recsize,1,fp); 
                }
                break;
            case 2:
    			rewind(fp); /* this moves file cursor to start of the file */
			while(fread(&e,recsize,1,fp)==1)
			{ /* read the file and fetch the record one record per fetch */
		            printf("\n\t%s \t%d \t%.2f",e.name,e.age,e.bs); 
			    printf("\n\t*******************************"); 	
			
		        }
                break;

            case 3: 
		an='y';
		while(an == 'y')
		{
                    printf("Enter the Teacherloyee name to modify: ");
                    scanf("%s", Teachername);
                    rewind(fp);
		    while(fread(&e,recsize,1,fp)==1)
		    { 
			/* fetch all record from file */
			if(strcmp(e.name,Teachername) == 0)
			{ 
			   /* if entered name matches with that in file */
                            printf("\nEnter new name,age and bs: ");
                            scanf("%s%d%f",e.name,&e.age,&e.bs);
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
                    printf("\nEnter name of Teacher to delete: ");
                    scanf("%s",Teachername);
                    ft = fopen("TTeacher.dat","wb");  /* create a intermediate file for tTeacherorary storage */
                    rewind(fp); /* move record to starting of file */
                    while(fread(&e,recsize,1,fp) == 1){ /* read all records from file */
                        if(strcmp(e.name,Teachername) != 0){ /* if the entered record match */
                            fwrite(&e,recsize,1,ft); /* move all records except the one that is to be deleted to tTeacher file */
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("Teacher.DAT"); /* remove the orginal file */
                    rename("TTeacher.dat","Teacher.DAT"); /* rename the tTeacher file to original file name */
                    fp = fopen("Teacher.DAT", "rb+");
                    fflush(stdin);
		    scanf("%c",&an);
                }
                break;
            case 5:
                fclose(fp);  
               // exit(0);
		choise(); 
        }
	printf("\n-----------------------------------------------\n");
    }
    
}

