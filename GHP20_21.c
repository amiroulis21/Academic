/*
Algorithm:
    1. In the main ( ), open the cars.dat file in the read mode and confirm
        you have properly opened the file.
    2. In the main ( ), read the entire contents of the cars.dat file into the
       inventory array.    
    3. In the main ( ), close the cars.dat file
    4. Call function_1( ), which will process the contents of the
        inventory array by sorting the inventory array to place all the cars
        in ascending order according to their price.
    5. Call function_2( ), which will save (write) the sorted inventory
        array to a file named output.dat
    6. Terminate

  ALGORITHM FOR function_1( ):

    BUBBLE SORT ALGORITHM:
    1. Create an index (i) to keep track of the iterations of inventory
    2. Check if i is less than the size of inventory
        If true, go to step 2a
        If false, go to step 3
	2a. Create an index (j) to keep track of the elements in inventory
	2b. Check if j is less than inventory size - 1 - i
	    If true, go to step 2bi
	    If false, go to step 2c
	    2bi. Check if price of element at index j in inventory
	         is greater than price of next element
		    If true, go to step 2bi1
		    If false, go to step 2bii
		2bi1. Record the data of the element after the current element
			in a separate location
		2bi2. Assign the value of the current element to the next element
		2bi3. Retrieve the old value of the next element and assign it to
	              the current element
	    2bii. Increment j by 1
	    2biii. Go back to step 2b
	2c. Increment i by 1
	2d. Go back to step 2
    3. Terminate

   ALGORITHM FOR function_2( ):

    1. Open output.dat file in write mode
    2. Create an index (i) to keep track of elements in inventory
    3. Check if i is less than the size of inventory
    	If true, go to step 3a
	If false, go to step 4
	3a. Write the contents of the current element onto output.dat
	3b. Increment i by 1
	3c. Go back to step 3
    4. Terminate
*/

#include <stdio.h>
#include <stdlib.h>

typedef  struct  cars {
    char  make [ 20 ];
    char  model [ 20 ];
    char  color  [ 15 ];
    int  year;
    double price;
                      }  cars; 


//Provide the prototype for your PCFs below:

void function_1(cars[]);
void function_2(cars[], FILE*);


int main (void)
{
    //Local variables declared... add additional variables as required
    cars  inventory [ 25 ];
    FILE * readptr = NULL;
    FILE * writeptr = NULL;
    int i = 0;

     //1. Open the cars.dat file in the read mode and confirm
    //     you have properly opened the file.
	readptr = fopen("cars.dat", "r");

     //2. Read the entire contents of the cars.dat file into the
     //    inventory array.    
	for(i = 0; i < 25; i++) {
	    fscanf(readptr, "%s", &inventory[i].make);
	    fscanf(readptr, "%s", &inventory[i].model);
	    fscanf(readptr, "%s", &inventory[i].color);
	    fscanf(readptr, "%d", &inventory[i].year);
	    fscanf(readptr, "%lf", &inventory[i].price);
	    
	}    

     //3. Close the cars.dat file
	fclose(readptr);


     //4. Call function_1( ), which will process the contents of the
     //    inventory array by sorting the inventory array to place all the cars
     //     in ascending order according to their price.
	function_1(inventory);


    //5. Call function_2( ), which will save (write) the sorted inventory
    //    array to a file named output.dat
	function_2(inventory, writeptr);
 

    //6. Terminate
    return 0 ;
}

//Provide the definition for your PCFs below:

void function_1(cars inventory[]) {
    cars temp;

    //BUBBLE SORT ALGORITHM:

    //1. Create an index (i) to keep track of the iterations of inventory
    //2. Check if i is less than the size of inventory
    	//If true, go to step 2a
	//If false, go to step 3
    for(int i = 0; i < 25; i++){
	
	//2a. Create an index (j) to keep track of the elements in inventory
	//2b. Check if j is less than inventory size - 1 - i;
	    //If true, go to step 2bi
	    //If false, go to step 2c
	for(int j = 0; j < 24 - i; j++){

	    //2bi. Check if price of element at index j in inventory
	    //     is greater than price of next element
		//If true, go to step 2bi1
		//If false, go to step 2bii
	    if(inventory[j].price > inventory[j + 1].price) {
		
		//2bi1. Record the data of the element after the current element
		//	in a separate location
		temp = inventory[j + 1];

		//2bi2. Assign the value of the current element to the next element
		inventory[j + 1] = inventory[j];

		//2bi3. Retrieve the old value of the next element and assign it to
		// the current element
		inventory[j] = temp;
	    }
		
	    //2bii. Increment j by 1
	    //2biii. Go back to step 2b
        }

	//2c. Increment i by 1
	//2d. Go back to step 2
    }

    //3. Terminate
}

void function_2(cars inventory[], FILE *writeptr) {

    //1. Open output.dat file in write mode
   writeptr = fopen("output.dat", "w");

    //2. Create an index (i) to keep track of elements in inventory
    //3. Check if i is less than the size of inventory
    	//If true, go to step 3a
	//If false, go to step 4
	for(int i = 0; i < 25; i++) {

	//3a. Write the contents of the current element onto output.dat
	    fprintf(writeptr, "%s %s %s %d %.2lf\n", inventory[i].make, 
inventory[i].model, inventory[i].color, inventory[i].year, inventory[i].price);

	//3b. Increment i by 1
	//3c. Go back to step 3
	}
    
    //4. Terminate

}
  
