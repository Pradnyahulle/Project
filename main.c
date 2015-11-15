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
		printf("\n1. About Teacher \n");
		printf("\n2. About student \n");
		printf("\n3. Play a GENERAL KNOWLEDGE game\n");
		printf("\n4. Contact managment\n");
		printf("\n5. Exit\n");
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
			
	
