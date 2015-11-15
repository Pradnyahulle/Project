project : exam.o student.o main.o teacher.o
	  cc exam.o student.o main.o contact.o teacher.o -o project
main.o : main.c
	 cc -c main.c
exam.o : exam.c
	 cc -c exam.c
student.o : student.c
	 cc -c student.c
contact.o : contact.c 
	  cc -c contact.c
teacher.o : teacher.c
	cc -c teacher.c
