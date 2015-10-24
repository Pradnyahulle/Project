project : exam.o student.o main.o
	  cc exam.o student.o main.o -o project
main.o : main.c
	 cc -c main.c
exam.o : exam.c
	 cc -c exam.c
student.o : student.c
	 cc -c student.c

