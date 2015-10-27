#include <stdio.h>
#include <stdlib.h>
void choise();
void main () {
	choise();
	
}
void choise() {
	int ch;
	while(1) {
		printf("*********** ENTER YOUR CHOISE ***********\n");
		printf("1. About Teacher \n");
		printf("2. About student \n");
		printf("3. Play a GENERAL KNOWLEDGE game\n");
		printf("4. Contact managment\n");
		printf("5. Exit\n");
		scanf("%d", &ch);
		switch (ch) {
			case 1: teacher();
				break;
			case 2: student();
				break;
			case 3: exam();
				break;
			case 4: contact();
				break;
			case 5: exit(1);
			default: printf("\n Enter correct choise");
		}
	}
}
			
	
