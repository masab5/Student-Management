#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/*
	Variables
filename: students_database.txt
temporary pointer: db_reader
struct type: student
main pointer: student_db
temp file: temp_db
temp file pointer: ftemp and temp_fp
*/

typedef struct student
{
	char name[21];
	int roll;
	char section[7];
	char fathers_name[21];
	char mothers_name[21];
	char address[51];
	int semester;
	char department[4];
	char mobile[20];
	char email[51];
	int number_of_courses;
	struct result
	{
		char cc[7];
		double cgpa;
	} result[100];
	double average_cgpa;
} student;

void edit_db()
{
	printf("\n-----------------------------\n");
	printf("      Editing Database      \n");
	printf("-----------------------------\n");
	int flag=0,roll,choice,element_number = 1, i,edit_choice,j,k,result_flag=0;
	double total=0;
	char temp_course[7];

	student db_reader;
	FILE *fp; 
	FILE *temp_fp;
	fp = fopen("students_database.txt","r");
	temp_fp = fopen("temp_db.txt", "w");

	printf("Enter roll of the student: ");
	scanf("%d", &roll);
	clean_stdin();
	while(fread(&db_reader,sizeof(student),1,fp))
	{
		if(db_reader.roll == roll) //if the roll is matched, display that part of the db
		{
			flag = 1;
			printf("\n-------------\n");
			printf("    Found    \n");
			printf("-------------\n");

			printf("\n[%d]\n", element_number);
			printf("Name: %s\n", db_reader.name);
			printf("Roll: %d\n", db_reader.roll);
			printf("Section: %s\n", db_reader.section);
			printf("Father's Name: %s\n", db_reader.fathers_name);
			printf("Mother's Name: %s\n", db_reader.mothers_name);
			printf("Address: %s\n", db_reader.address);
			printf("Mobile: %s\n", db_reader.mobile);
			printf("Email: %s\n", db_reader.email);
			printf("Department: %s\n", db_reader.department);
			printf("Semester: %d\n", db_reader.semester);
			printf("Result: \n");
			printf("------------------------\n");
			printf("| Course Code |  CGPA  |\n");
			printf("------------------------\n");
			for(i=0; i<db_reader.number_of_courses; i++)
			{
				printf("|    %s   |  %.2lf  |\n", db_reader.result[i].cc, db_reader.result[i].cgpa);
				printf("------------------------\n");
			}
			printf("|   Average   |  %.2lf  |\n",db_reader.average_cgpa);
			printf("------------------------\n");
			element_number++;
			printf("\nWhat do you want to edit here?\n");
			printf("1. Name\n");
			printf("2. Roll\n");
			printf("3. Section\n");
			printf("4. Father's name\n");
			printf("5. Mother's name\n");
			printf("6. Address\n");
			printf("7. Mobile\n");
			printf("8. Email\n");
			printf("9. Department\n");
			printf("10. Semester\n");
			printf("11. Result\n");

			printf("Select your option: ");
			scanf("%d", &edit_choice);
			clean_stdin();

			if(edit_choice == 1)
			{
				printf("Enter new name: ");
				fgets(db_reader.name, 21, stdin);
				if(db_reader.name[strlen(db_reader.name) - 1] == '\n') db_reader.name[strlen(db_reader.name) - 1] = '\0';
			}
			else if(edit_choice == 2)
			{
				printf("Enter new roll: ");
				scanf("%d", &db_reader.roll);
				clean_stdin();
			}
			else if(edit_choice == 3)
			{
				printf("Enter new section: ");
				fgets(db_reader.section, 7, stdin);
				if(db_reader.section[strlen(db_reader.section) - 1] == '\n') db_reader.section[strlen(db_reader.section) - 1] = '\0';
			}
			else if(edit_choice == 4)
			{
				printf("Enter father's name: ");
				fgets(db_reader.fathers_name, 21, stdin);
				if(db_reader.fathers_name[strlen(db_reader.fathers_name) - 1] == '\n') db_reader.fathers_name[strlen(db_reader.fathers_name) - 1] = '\0';
			}
			else if(edit_choice == 5)
			{
				printf("Enter mother's name: ");
				fgets(db_reader.mothers_name, 21, stdin);
				if(db_reader.mothers_name[strlen(db_reader.mothers_name) - 1] == '\n') db_reader.mothers_name[strlen(db_reader.mothers_name) - 1] = '\0';
			}
			else if(edit_choice == 6)
			{
				printf("Enter new address: ");
				fgets(db_reader.address, 51, stdin);
				if(db_reader.address[strlen(db_reader.address) - 1] == '\n') db_reader.address[strlen(db_reader.address) - 1] = '\0';
			}
			else if(edit_choice == 7)
			{
				printf("Enter new mobile number: ");
				fgets(db_reader.mobile, 20, stdin);
				if(db_reader.mobile[strlen(db_reader.mobile) - 1] == '\n') db_reader.mobile[strlen(db_reader.mobile) - 1] = '\0';
			}
			else if(edit_choice == 8)
			{
				printf("Enter new email: ");
				fgets(db_reader.email, 51, stdin);
				if(db_reader.email[strlen(db_reader.email) - 1] == '\n') db_reader.email[strlen(db_reader.email) - 1] = '\0';
			}
			else if(edit_choice == 9)
			{
				printf("Enter department: ");
				fgets(db_reader.department, 4, stdin);
				if(db_reader.email[strlen(db_reader.department) - 1] == '\n') db_reader.department[strlen(db_reader.department) - 1] = '\0';
			}
			else if(edit_choice == 10)
			{
				printf("Enter new semester: ");
				scanf("%d", &db_reader.semester);
				clean_stdin();
			}
			else if(edit_choice == 11)
			{
				printf("Enter the course code of the course you want to edit: ");
				fgets(temp_course, 7, stdin);
				if(temp_course[strlen(temp_course) - 1] == '\n') temp_course[strlen(temp_course) - 1] = '\0';
				for(j=0; j<db_reader.number_of_courses; j++)
				{
					if(strcmp(db_reader.result[j].cc,temp_course) == 0)
					{
						result_flag = 1;

						clean_stdin();
						printf("Re-enter the course code: ");
						fgets(db_reader.result[j].cc, 7, stdin);

						printf("Enter the obtained CGPA: ");
						scanf("%lf", &db_reader.result[j].cgpa);
						clean_stdin();

						for(k=0;k<db_reader.number_of_courses;k++)
						{
							total+=db_reader.result[k].cgpa;
						}
						db_reader.average_cgpa = total/db_reader.number_of_courses;
					}
				}
				if(result_flag == 0)
				{
					printf("\nCourse not found\n");
				}
			}
			fwrite(&db_reader, sizeof(student), 1, temp_fp); //write to temp file.
		}
		else fwrite(&db_reader, sizeof(student), 1, temp_fp); //write to temp.
	}

	fclose(fp);
	fclose(temp_fp);

	if(flag == 0)
	{
		printf("\n-------------\n");
		printf("  Not Found  \n");
		printf("-------------\n");
	}
	else
	{
		fp = fopen("students_database.txt", "w");
		temp_fp = fopen("temp_db.txt", "r");

		while(fread(&db_reader, sizeof(student), 1, temp_fp))
		{
			fwrite(&db_reader, sizeof(student), 1, fp);
		}

		fclose(fp);
		fclose(temp_fp);
	}
}

void delete_student()
{
	FILE *fp, *ftemp;
	fp = fopen("students_database.txt", "r");
	ftemp = fopen("temp_db.txt", "w");
	student db_reader;
	int roll,flag;

	printf("Enter roll of the student: ");
	scanf("%d", &roll);
	clean_stdin();

	while(fread(&db_reader,sizeof(student),1,fp))
	{
		if(db_reader.roll == roll) //if the roll is matched, display that part of the db
		{
			flag = 1;
		}
		else 
		{
			fwrite(&db_reader, sizeof(student), 1, ftemp);
		}
	}
	fclose(fp);
	fclose(ftemp);

	if(flag == 1)
	{
		printf("\n-------------\n");
		printf("    Found    \n");
		printf("-------------\n");
		fp = fopen("students_database.txt", "w");
		ftemp = fopen("temp_db.txt", "r");
		while(fread(&db_reader, sizeof(student), 1, ftemp))
		{
			fwrite(&db_reader, sizeof(student), 1, fp);
		}
		fclose(fp);
		fclose(ftemp);
	}
	else
	{
		printf("\n-------------\n");
		printf("  Not Found  \n");
		printf("-------------\n");
	}
}

int number_of_students_in_db()
{
	int n;
	FILE *fp;
	fp = fopen("students_database.txt", "r");

	fseek(fp, 0, SEEK_END);
	n = ftell(fp)/sizeof(student);

	fclose(fp);
	return(n);
}

void add_new_students()
{
	int number_of_students;
	printf("\n-------------------------------\n");
	printf("   Adding new students in DB   \n");
	printf("-------------------------------\n");
	printf("Number of students to be added: ");
	scanf("%d", &number_of_students);
	clean_stdin();
	FILE* fp;
	student* student_db = (student*) malloc(number_of_students * sizeof(student));
	fp = fopen("students_database.txt", "a");

	int i,j,k;
	double total;

	for(i=0; i<number_of_students; i++)
	{
		total=0;
		printf("\nEnter the name of student no.%d: ", i+1);
		fgets(student_db[i].name, 21, stdin);
		if(student_db[i].name[strlen(student_db[i].name)-1] == '\n') student_db[i].name[strlen(student_db[i].name)-1] = '\0';

		printf("Enter roll of the student no.%d: ", i+1);
		scanf("%d", &student_db[i].roll);
		clean_stdin();

		printf("Enter the section of student no.%d: ", i+1);
		fgets(student_db[i].section, 7, stdin);
		if(student_db[i].section[strlen(student_db[i].section)-1] == '\n') student_db[i].section[strlen(student_db[i].section)-1] = '\0';

		printf("Enter father's name of student no.%d: ", i+1);
		fgets(student_db[i].fathers_name, 21, stdin);
		if(student_db[i].fathers_name[strlen(student_db[i].fathers_name)-1] == '\n') student_db[i].fathers_name[strlen(student_db[i].fathers_name)-1] = '\0';

		printf("Enter mother's name of student no.%d: ", i+1);
		fgets(student_db[i].mothers_name, 21, stdin);
		if(student_db[i].mothers_name[strlen(student_db[i].mothers_name)-1] == '\n') student_db[i].mothers_name[strlen(student_db[i].mothers_name)-1] = '\0';

		printf("Enter address of student no.%d: ", i+1);
		fgets(student_db[i].address, 51, stdin);
		if(student_db[i].address[strlen(student_db[i].address)-1] == '\n') student_db[i].address[strlen(student_db[i].address)-1] = '\0';

		printf("Enter mobile number of student no.%d: ", i+1);
		fgets(student_db[i].mobile, 20, stdin);
		if(student_db[i].mobile[strlen(student_db[i].mobile)-1] == '\n') student_db[i].mobile[strlen(student_db[i].mobile)-1] = '\0';

		printf("Enter the email address of student no.%d: ", i+1);
		fgets(student_db[i].email, 51, stdin);
		if(student_db[i].email[strlen(student_db[i].email)-1] == '\n') student_db[i].email[strlen(student_db[i].email)-1] = '\0';

		printf("Enter department of student no.%d: ", i+1);
		fgets(student_db[i].department, 4, stdin);
		if(student_db[i].department[strlen(student_db[i].department)-1] == '\n') student_db[i].department[strlen(student_db[i].department)-1] = '\0';

		printf("Enter semester of student no.%d: ", i+1);
		scanf("%d", &student_db[i].semester);
		clean_stdin();

		printf("Number of courses taken by student no.%d: ", i+1);
		scanf("%d", &student_db[i].number_of_courses);
		clean_stdin();

		printf("\nTaking result of student no.%d\n", i+1);
		for(j=0; j<student_db[i].number_of_courses; j++)
		{
			printf("Enter course code #%d: ", j+1);
			fgets(student_db[i].result[j].cc, 7, stdin);
			
			printf("Enter obtained CGPA in course #%d: ", j+1);
			scanf("%lf", &student_db[i].result[j].cgpa);
			total+=student_db[i].result[j].cgpa;
			clean_stdin();
		}
		student_db[i].average_cgpa = total/(double) student_db[i].number_of_courses;
		fwrite(&student_db[i], sizeof(student), 1, fp);
	}
	fclose(fp);
	free(student_db);
}

void create_student_database()
{
	int number_of_students;
	printf("\n-------------------------------\n");
	printf("   Creating Student Database   \n");
	printf("-------------------------------\n");
	printf("Number of students to be added: ");
	scanf("%d", &number_of_students);
	clean_stdin();
	FILE* fp;
	student* student_db = (student*) malloc(number_of_students * sizeof(student));
	fp = fopen("students_database.txt", "w");

	int i,j,k;
	double total;

	for(i=0; i<number_of_students; i++)
	{
		total = 0;
		printf("\nEnter the name of student no.%d: ", i+1);
		fgets(student_db[i].name, 21, stdin);
		if(student_db[i].name[strlen(student_db[i].name)-1] == '\n') student_db[i].name[strlen(student_db[i].name)-1] = '\0';

		printf("Enter roll of the student no.%d: ", i+1);
		scanf("%d", &student_db[i].roll);
		clean_stdin();

		printf("Enter the section of student no.%d: ", i+1);
		fgets(student_db[i].section, 7, stdin);
		if(student_db[i].section[strlen(student_db[i].section)-1] == '\n') student_db[i].section[strlen(student_db[i].section)-1] = '\0';

		printf("Enter father's name of student no.%d: ", i+1);
		fgets(student_db[i].fathers_name, 21, stdin);
		if(student_db[i].fathers_name[strlen(student_db[i].fathers_name)-1] == '\n') student_db[i].fathers_name[strlen(student_db[i].fathers_name)-1] = '\0';

		printf("Enter mother's name of student no.%d: ", i+1);
		fgets(student_db[i].mothers_name, 21, stdin);
		if(student_db[i].mothers_name[strlen(student_db[i].mothers_name)-1] == '\n') student_db[i].mothers_name[strlen(student_db[i].mothers_name)-1] = '\0';

		printf("Enter address of student no.%d: ", i+1);
		fgets(student_db[i].address, 51, stdin);
		if(student_db[i].address[strlen(student_db[i].address)-1] == '\n') student_db[i].address[strlen(student_db[i].address)-1] = '\0';

		printf("Enter mobile number of student no.%d: ", i+1);
		fgets(student_db[i].mobile, 20, stdin);
		if(student_db[i].mobile[strlen(student_db[i].mobile)-1] == '\n') student_db[i].mobile[strlen(student_db[i].mobile)-1] = '\0';

		printf("Enter the email address of student no.%d: ", i+1);
		fgets(student_db[i].email, 51, stdin);
		if(student_db[i].email[strlen(student_db[i].email)-1] == '\n') student_db[i].email[strlen(student_db[i].email)-1] = '\0';

		printf("Enter department of student no.%d: ", i+1);
		fgets(student_db[i].department, 4, stdin);
		if(student_db[i].department[strlen(student_db[i].department)-1] == '\n') student_db[i].department[strlen(student_db[i].department)-1] = '\0';

		printf("Enter semester of student no.%d: ", i+1);
		scanf("%d", &student_db[i].semester);
		clean_stdin();

		printf("Number of courses taken by student no.%d: ", i+1);
		scanf("%d", &student_db[i].number_of_courses);
		clean_stdin();

		printf("\nTaking result of student no.%d\n", i+1);
		for(j=0; j<student_db[i].number_of_courses; j++)
		{
			printf("Enter course code #%d: ", j+1);
			fgets(student_db[i].result[j].cc, 7, stdin);
			
			printf("Enter obtained CGPA in course #%d: ", j+1);
			scanf("%lf", &student_db[i].result[j].cgpa);
			total += student_db[i].result[j].cgpa;
			clean_stdin();
		}
		student_db[i].average_cgpa = total/(double) student_db[i].number_of_courses;
		fwrite(&student_db[i], sizeof(student), 1, fp);
	}
	fclose(fp);
	free(student_db);
}

void display()
{
	student db_reader;
	FILE *fp;
	fp = fopen("students_database.txt","r");
	int element_number = 1;
	int i;
	printf("\n---------------------------------\n");
	printf("   Displaying Student Database   \n");
	printf("---------------------------------\n");
	printf("Number of students: %d\n", number_of_students_in_db());
	while(fread(&db_reader,sizeof(student),1,fp))
	{
		printf("\n[%d]\n", element_number);
		printf("Name: %s\n", db_reader.name);
		printf("Roll: %d\n", db_reader.roll);
		printf("Section: %s\n", db_reader.section);
		printf("Father's Name: %s\n", db_reader.fathers_name);
		printf("Mother's Name: %s\n", db_reader.mothers_name);
		printf("Address: %s\n", db_reader.address);
		printf("Mobile: %s\n", db_reader.mobile);
		printf("Email: %s\n", db_reader.email);
		printf("Department: %s\n", db_reader.department);
		printf("Semester: %d\n", db_reader.semester);
		printf("Result: \n");
		printf("------------------------\n");
		printf("| Course Code |  CGPA  |\n");
		printf("------------------------\n");
		for(i=0; i<db_reader.number_of_courses; i++)
		{
			printf("|    %s   |  %.2lf  |\n", db_reader.result[i].cc, db_reader.result[i].cgpa);
			printf("------------------------\n");
		}
		printf("|   Average   |  %.2lf  |\n",db_reader.average_cgpa);
		printf("------------------------\n");
		element_number++;
	}
	fclose(fp);
}

void search()
{
	printf("\n-----------------------------\n");
	printf("      Searching Student      \n");
	printf("-----------------------------\n");
	int flag=0,roll,choice,element_number = 1, i;
	char name[21];
	printf("\nSearch by:\n1. Roll\n2. Name\n: ");
	scanf("%d", &choice);
	clean_stdin();

	student db_reader;
	FILE *fp;
	fp = fopen("students_database.txt","r");

	if(choice == 1) //user wants to search by roll
	{
		printf("Enter roll of the student: ");
		scanf("%d", &roll);
		clean_stdin();
		while(fread(&db_reader,sizeof(student),1,fp))
		{
			if(db_reader.roll == roll) //if the roll is matched, display that part of the db
			{
				flag = 1;
				printf("\n-------------\n");
				printf("    Found    \n");
				printf("-------------\n");

				printf("\n[%d]\n", element_number);
				printf("Name: %s\n", db_reader.name);
				printf("Roll: %d\n", db_reader.roll);
				printf("Section: %s\n", db_reader.section);
				printf("Father's Name: %s\n", db_reader.fathers_name);
				printf("Mother's Name: %s\n", db_reader.mothers_name);
				printf("Address: %s\n", db_reader.address);
				printf("Mobile: %s\n", db_reader.mobile);
				printf("Email: %s\n", db_reader.email);
				printf("Department: %s\n", db_reader.department);
				printf("Semester: %d\n", db_reader.semester);
				printf("Result: \n");
				printf("------------------------\n");
				printf("| Course Code |  CGPA  |\n");
				printf("------------------------\n");
				for(i=0; i<db_reader.number_of_courses; i++)
				{
					printf("|    %s   |  %.2lf  |\n", db_reader.result[i].cc, db_reader.result[i].cgpa);
					printf("------------------------\n");
				}
				printf("|   Average   |  %.2lf  |\n",db_reader.average_cgpa);
				printf("------------------------\n");
				element_number++;
			}
		}
	}
	else if(choice == 2) //user wants to search by name
	{
		printf("Enter name of the student: ");
		fgets(name, 21, stdin);
		if(name[strlen(name) - 1] == '\n') name[strlen(name) - 1] = '\0';
		while(fread(&db_reader,sizeof(student),1,fp))
		{
			if(strcmp(db_reader.name, name) == 0) //if string is found, display that part of the db. 
			{
				flag = 1;
				printf("\n-------------\n");
				printf("    Found    \n");
				printf("-------------\n");

				printf("\n[%d]\n", element_number);
				printf("Name: %s\n", db_reader.name);
				printf("Roll: %d\n", db_reader.roll);
				printf("Section: %s\n", db_reader.section);
				printf("Father's Name: %s\n", db_reader.fathers_name);
				printf("Mother's Name: %s\n", db_reader.mothers_name);
				printf("Address: %s\n", db_reader.address);
				printf("Mobile: %s\n", db_reader.mobile);
				printf("Email: %s\n", db_reader.email);
				printf("Department: %s\n", db_reader.department);
				printf("Semester: %d\n", db_reader.semester);
				printf("Result: \n");
				printf("------------------------\n");
				printf("| Course Code |  CGPA  |\n");
				printf("------------------------\n");
				for(i=0; i<db_reader.number_of_courses; i++)
				{
					printf("|    %s   |  %.2lf  |\n", db_reader.result[i].cc, db_reader.result[i].cgpa);
					printf("------------------------\n");
				}
				printf("|   Average   |  %.2lf  |\n",db_reader.average_cgpa);
				printf("------------------------\n");
				element_number++;
			}
		}
	}
	if(flag == 0)
	{
		printf("\n-------------\n");
		printf("  Not Found  \n");
		printf("-------------\n");
	}
	fclose(fp);
}

int main()
{
	int choice;

	while(1)
	{
			printf("\n--------------------------------\n");
			printf("|      Student Management      |\n");
			printf("--------------------------------\n");
			printf("\n1. Create student database\n");
			printf("2. Display student database\n");
			printf("3. Add more students to the database\n");
			printf("4. Delete a student from database\n");
			printf("5. Search a student\n");
			printf("6. Edit Students Database\n");
			printf("0. Exit\n");
			printf("\nSelect your option: ");
			scanf("%d", &choice);
			if(choice == 0) break;
			 switch(choice)
			  {
				case 1:
						create_student_database();
						break;
				case 2:
						display();
						break;
				case 3:
						add_new_students();
						break;
				case 4:
						delete_student();
						break;
				case 5:
						search();
						break;
				case 6:
						edit_db();
						break;
				}
			}
	return 0;
}
