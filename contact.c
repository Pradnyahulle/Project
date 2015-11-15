/*****************************************************************************
 * Copyright (C) Pradnya D.Hulle hullepd14.comp@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>   
struct contact
{
	long ph;
	char name[20],add[20],email[30];
}list; 
char query[20],name[20];
//char exit[20];
FILE *fp, *ft;
int i,n,ch,l,found; 
int contact()
{    
	main://system("cls");    /* ************Main menu ***********************  */
	printf("\n\t **** Welcome to a0 contact Manager ****");
	printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new   Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit  a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");
	printf("Enter the choice:");
	scanf("%d",&ch); 
	switch(ch)
	{
		case 0:printf("\n\n\t\tAre you sure u want to exit?");
			break;
			/* *********************add new contacts************  */
		case 1: //system("cls");
			fp=fopen("contact.dll","a");
			for (;;)
			{ 
				fflush(stdin);
				printf("To exit type exit/EXIt  NAME:");
				scanf("%s",&list.name);
				if(strcmp(list.name,"exit") == 0 || strcmp(list.name,"EXIT")==0)
				{
					break;
				}
				//if(strcmp (list.name , o) == 0) 
				//break;
				fflush(stdin);
				printf("Phone:");
				scanf("%ld",&list.ph);
				fflush(stdin);
				printf("address:");
				scanf("%s",&list.add);
				fflush(stdin);
				printf("email address:");
				scanf("%s",&list.email);
				gets(list.email);
				fflush(stdin);
				printf("\n");
				fwrite(&list,sizeof(list),1,fp);
			}
			fclose(fp);
			break; 
			/* *********************list of contacts*************************  */
		case 2://system("cls");
			printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t==== ============================\n\nName\t\tPhone No\t    Address\t\tE-mail ad.\n=== ==============================================================\n\n"); 
			for(i=97;i<=122;i=i+1)
			{ 
				fp=fopen("contact.dll","r");
				fflush(stdin);
				found=0;
				while(fread(&list,sizeof(list),1,fp)==1)
				{
					if(list.name[0]==i || list.name[0]==i-32)
					{
					printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t\n",list.name,list.ph,list.add,list.email);
					found++;
					}
				}
				if(found!=0)
				{
					printf("=========================================================== [%c]- (%d)\n\n",i-32,found);
					//getch();
				}
				fclose(fp); 
			} 
			break;   
			/* *******************search contacts**********************  */
			case 3://system("cls");
				do
				{
					found=0;
					printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of  contact to search:");
					fflush(stdin);
					scanf("%s",&query);
					l=strlen(query);
					fp=fopen("contact.dll","r"); 
					//system("cls");
					printf("\n\n..::Search result for '%s' \n====================================== ==========\n",query);
					while(fread(&list,sizeof(list),1,fp)==1)
					{
						for(i=0;i<=l;i++)
						name[i]=list.name[i];
						name[l]='\0';
						if(strcmp(name,query)==0)
						{
							printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email address: %s \n",list.name,list.ph,list.add,list.email);
							found++;
							if (found%4==0)
							{
								printf("..::Press any key to continue...");
								//getch();
							}
						}
					} 
					if(found==0)
					printf("\n..::No match found!");
					else
					printf("\n..::%d match(s) found!",found);
					fclose(fp);
					printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");
					scanf("%d",&ch);
				}while(ch==1);
				break;  
				/* *********************edit contacts************************/
				case 4://system("cls");
					fp=fopen("contact.dll","r");
					ft=fopen("temp.dat","w");
					fflush(stdin);
					printf("..::Edit contact\n===============================\n\n\t..::Enter the  name of contactedit:");
					scanf("%s",name);
					while(fread(&list,sizeof(list),1,fp)==1) {
						if(strcmp(name,list.name)!=0)
						fwrite(&list,sizeof(list),1,ft);
					}
				fflush(stdin);
				printf("\n\n..::Editing '%s'\n\n",name);
				printf("..::Name(Use identical):");
				scanf("%s",&list.name);fflush(stdin);
				printf("..::Phone:");
				scanf("%ld",&list.ph);
				fflush(stdin);
				printf("..::address:");
				scanf("%s",&list.add);
				fflush(stdin);
				printf("..::email address:");
				scanf("%s",&list.email);
				gets(list.email);
				printf("\n");
				fwrite(&list,sizeof(list),1,ft);
				fclose(fp);
				fclose(ft);
				remove("contact.dll");
				rename("temp.dat","contact.dll");
				break;  
				/* ********************delete contacts**********************/
				case 5:/*system("cls");*/
					fflush(stdin);
					printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter  the name of contact to delete:");
					scanf("%s",&name);
					fp=fopen("contact.dll","r");
					ft=fopen("temp.dat","w");
					while(fread(&list,sizeof(list),1,fp)!=0)
					if (strcmp(name,list.name)!=0)
					fwrite(&list,sizeof(list),1,ft);
					fclose(fp);
					fclose(ft);
					remove("contact.dll");
					rename("temp.dat","contact.dll");
					break; 
				default:printf("Invalid choice");
					break;
	}  
			printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
			scanf("%d",&ch);
			switch (ch){
			case 1:goto main;  
			case 0:choise(); 
			default:printf("Invalid choice");
			break;
			} 
return 0;
}  



















