/*
1. Iterate through each region with index intialized to 0
2 Iterate through each dog with another index intialized to 0
3. Ask the user to enter pounds of truffles found
4. Record user input
5. Add the data to the running total of the current dog
6. Add the data to the running total of the current region
7. Add the data to the running total of all truffles
8. Increment dog index by 1
9. Test to see if dog index is less than 4
    9a. If true, go to step 3
    9b. If false, go to step 10
10. Increment region index by 1
11. Test to see if region index is less than 3
    11a. If true, go to step 3
    11b. If false, go to step 12
12. Iterate through data in running total of each region 
    with an index intialized to 0
13. Display the total pounds of truffle found in the current region
14. Increment index by 1
15. Test if index is less than 3
    15a. If true, go to step 13
    15b. If false, go to step 16
16. Iterate through data in running total of each dog
17. Display the total pounds of truffle found by the current dog
18. Increment index by 1
19. Test if index is less than 4
    19a. If true, go to step 17
    19b. If false, go to step 20
20. Display running total of pounds of truffle found
21. Terminate
*/




#include <stdio.h>

int main(void) {

    double poundsOfTruffles[3][4];
    double poundsPerDog[4] = {0.0, 0.0, 0.0, 0.0};
    double poundsPerRegion[3] = {0.0, 0.0, 0.0};
    double grandTotal = 0.0;
    int i = 0;
    int j = 0;
//1. Iterate through each region with index intialized to 0
    for(i = 0; i < 3; i++) {

    //2 Iterate through each dog with another index intialized to 0
	for(j = 0; j < 4; j++) {
	
	//3. Ask the user to enter pounds of truffles found
	    printf("Enter pounds of truffles found ");
	    printf("in region #%d by dog #%d: ", i + 1, j + 1);

	//4. Record user input
	    scanf("%lf", &poundsOfTruffles[i][j]);

	//5. Add the data to the running total of the current dog
	    poundsPerDog[j] += poundsOfTruffles[i][j];

	//6. Add the data to the running total of the current region
	    poundsPerRegion[i] += poundsOfTruffles[i][j];

	//7. Add the data to the running total of all truffles
	    grandTotal += poundsOfTruffles[i][j];
	
	//8. Increment dog index by 1

	//9. Test to see if dog index is less than 4
	    //9a. If true, go to step 3
	    //9b. If false, go to step 10
	}

    //10. Increment region index by 1

    //11. Test to see if region index is less than 3
	//11a. If true, go to step 3
	//11b. If false, go to step 12
    }

    printf("\n");
    
//12. Iterate through data in running total of each region 
    //with an index intialized to 0
    for(i = 0; i < 3; i++) {

    //13. Display the total pounds of truffle found in the current region
	printf("Region #%d: %.1lf lbs", i + 1, poundsPerRegion[i]);
	if (i < 2) {
	    printf(", ");
	}

    //14. Increment index by 1

    //15. Test if index is less than 3
	//15a. If true, go to step 13
	//15b. If false, go to step 16
    }
    printf("\n");

//16. Iterate through data in running total of each dog
    //with an index initialized to 0
    for(i = 0; i < 4; i++) {

    //17. Display the total pounds of truffle found by the current dog
	printf("Dog #%d: %.1lf lbs", i + 1, poundsPerDog[i]);
	if (i < 3) {
	    printf(", ");
	}

    //18. Increment index by 1

    //19. Test if index is less than 4
	//19a. If true, go to step 17
	//19b. If false, go to step 20
    }
    printf("\n");
    
//20. Display running total of pounds of truffle found
    printf("Grand total: %.1lf lbs", grandTotal);

//21. Terminate
    return 0;
}
