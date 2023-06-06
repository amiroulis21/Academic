#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char firstName[20];
    char lastName[20];
    int testScores[4];
} student;

void copyArray(student[], student[]);
void printByLastName(student[]);
void printLowToHighScores(student[]);
void printHighToLowScores(student[]);
char DisplayMenu();
double averageScore(student);

void main() {
    FILE *readptr = NULL;
    student s[15];
    int i = 0;
    char answer;

    readptr = fopen("legends.dat", "r");
    for(i = 0; i < 15; i++) {
	fscanf(readptr, "%s", &s[i].firstName);
	fscanf(readptr, "%s", &s[i].lastName);
	fscanf(readptr, "%d", &s[i].testScores[0]);
	fscanf(readptr, "%d", &s[i].testScores[1]);
	fscanf(readptr, "%d", &s[i].testScores[2]);
	fscanf(readptr, "%d", &s[i].testScores[3]);

    }
    answer = DisplayMenu();
    while(answer == '1' || answer == '2' || answer == '3') {
	if (answer == '1') {
	    printByLastName(s);
	}
	else if (answer == '2') {
	    printLowToHighScores(s);
	}
	else if (answer == '3') {
	    printHighToLowScores(s);
	}
	
	answer = DisplayMenu();

    }


}
void copyArray(student a1[], student a2[]) {
    for(int i = 0; i < 15; i++) {
	a2[i] = a1[i];
    }
}

void printByLastName(student s[]) {
    student temp[15];
    student tempo;
    copyArray(s, temp);
    int nameIndex = 0;
    int i = 0;
    int j = 0;
    for(i = 0; i < 15; i++) {
	for(j = 0; j < 14 - i; j++) {
	    while(temp[j].lastName[nameIndex] == temp[j + 1].lastName[nameIndex]) {
		nameIndex++;
	    }
	    if(temp[j].lastName[nameIndex] > temp[j + 1].lastName[nameIndex]) {
	        tempo = temp[j];
	        temp[j] = temp[j + 1];
	        temp[j + 1] = tempo;
	    }
	    nameIndex = 0;
	}
	
    }

    for(i = 0; i < 15; i++) {
	printf("%s ", temp[i].firstName);
	printf("%s\t\t", temp[i].lastName);
	printf("%.2lf\n", averageScore(temp[i]));
    }
    printf("\n");

}

void printLowToHighScores(student s[]) {
    student temp[15];
    student tempo;
    copyArray(s, temp);
    int i = 0;
    int j = 0;
    for(i = 0; i < 15; i++) {
	for(j = 0; j < 14 - i; j++) {
	    if(averageScore(temp[j]) > averageScore(temp[j + 1])) {
		tempo = temp[j];
		temp[j] = temp[j + 1];
		temp[j + 1] = tempo;
	    }
	}
    }
     for(i = 0; i < 15; i++) {
	printf("%s ", temp[i].firstName);
	printf("%s\t\t", temp[i].lastName);
	printf("%.2lf\n", averageScore(temp[i]));
    }
    printf("\n");
 

}

void printHighToLowScores(student s[]) {
student temp[15];
    student tempo;
    copyArray(s, temp);
    int i = 0;
    int j = 0;
    for(i = 14; i >= 0; i--) {
	for(j = 14; j > 0; j--) {
	    if(averageScore(temp[j]) > averageScore(temp[j - 1])) {
		tempo = temp[j];
		temp[j] = temp[j - 1];
		temp[j - 1] = tempo;
	    }
	}
    }
     for(i = 0; i < 15; i++) {
	printf("%s ", temp[i].firstName);
	printf("%s\t\t", temp[i].lastName);
	printf("%.2lf\n", averageScore(temp[i]));
    }
    printf("\n");
 

}

char DisplayMenu() {
    char answer;
    printf("1. List first name, last name, and test score average to the screen\n");
    printf("by last name in alphabetical order\n");
    printf("2. List first name, last name, and test score average to the screen\n");
    printf("by test score average in ascending order\n");
    printf("3. List first name, last name, and test score average to the screen\n");
    printf("by test score average in descending order\n");
    printf("4. Quit\n\nPlease make your selection: ");

    scanf("%c", &answer);
    printf("\n");
    return answer;

}

double averageScore(student s) {
    return (s.testScores[0] + s.testScores[1] + s.testScores[2] + s.testScores[3]) / 4.0;

}



