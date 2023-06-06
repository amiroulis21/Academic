/*
ALGORITHM
1. Populate a 100-row and 1000-column 2D array of integers from
   a file named GHP15.dat (sent via email... you should store
   GHP15.dat into the same folder/directory that holds your .c
   files)... the 2D array is composed of the following characters:
   0   1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18
2. Find the number of horizontal triples (three of the same integer
   in a row... example: 7  5  5  5  12
   Note - the following should be interpreted a 3 horizontal triples:
   3  5  5  5  5  5  2

ADD ALGORITHM STEPS HERE... ADD YOUR STEPS AS SUB-STEPS OF STEP 2
2. Test to see if row is less than or equal to 99
   A. If true
      1. Set column equal to 0
      2. Test to see if column is less than or equal to 997
         AA. If true
            1. Test to see if the value that is in the current row and
             column is equal to the numbers in the next two columns
               AAA. If true
                  1. Add one to the total of horizontal triples
                  2. Go to step 2/A/2/AA/2
               BBB. If false, go to next step
            2. Add one to column
            3. Go to step 2/A/2
         BB. If false
            1. Go to step 2/A/3
      3. Add one to row
      4. Go to step 2
    B. If false
      1. Set columns equal to 0
      2. Go to step 3
3. Find the number of vertical triples (three of the same integer
   in a column... example: 4
                                             7
                                             7
                                             7
                                             0
   Note - the following should be interpreted a 3 vertical triples:
   5
   4
   4
   4
   4
   4
   16

ADD ALGORITHM STEPS HERE... ADD YOUR STEPS AS SUB-STEPS OF STEP 3
3. Test to see if column is less than or equal to 999
   A. If true
      1. Set row equal to 0
      2. Test to see if row is less than or equal to 97
         AA. If true
            1. Test to see if the value that is in the current row and
            column is equal to the number in the next two rows
               AAA. If true
                  1. Add one to the total of vertical triples
                  2. Go to step 3/A/2/AA/2
               BBB. If false, go to next step
            2. Add one to row
            3. Go to step 3/A/2
         BB. If false
            1. Go to step 3/A/3
       3. Add one to column
       4. Go to step 3
   B. If false
      1. Go to step 4
4. Display the number of horizontal triples.
5. Display the number of vertical triples.
6. Terminate

YOU WILL KNOW THAT YOUR PROGRAM WORKS CORRECTLY WHEN YOUR PROGRAM
PRODUCES 281 FOR HORIZONTAL TRIPLES AND 250 FOR VERTICAL TRIPLES.

*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void populate(int[][1000], int, int, FILE*);
int h_trips(int[][1000], int, int, int);
int v_trips(int[][1000], int ,int, int);
void results(int, int);

int main( void )
{
     //DO NOT CHANGE - Local variables declared below
     FILE  *  read_ptr = NULL ;
     read_ptr = fopen( "GHP15.dat" , "r" ) ;
     int int_array[100][1000] = { 0 } ;
     int row = 0 , col = 0 ;
     int h_triples = 0;
     int v_triples = 0;
 
     //1. Populate a 100-row and 1000-column 2D array of integers from
     //a file named GHP15.dat (sent via email... you should store
     //GHP15.dat into the same folder/directory that holds your .c
     //files)... the 2D array is composed of the following integers ONLY:
     //  0   1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18

     populate(int_array, row, col, read_ptr);

 //2. Test to see if row is less than or equal to 99
    
        //A. If true
           //1. Set column equal to 0
           //2. Test to see if column is less than or equal to 997
           
              //AA. If true
                 //1. Test to see if the value that is in the current row and
                 //column is equal to the numbers in the next two columns
                
                    //AAA. If true
                       //1. Add one to the total of horizontal triples
                       
                       //2. Go to step 2/A/2/AA/2
                    //BBB. If false, go to next step
                 
                 //2. Add one to column
                 //3. Go to step 2/A/2
              //BB. If false
                  //1. Go to step 2/A/3
           
           //3. Add one to row
           //4. Go to step 2
     
        //B. If false
           //1. Set columns equal to 0
           //2. Go to step 3
     h_triples = h_trips(int_array, row, col, h_triples);

 //3. Test to see if column is less than or equal to 999
    
     
        //A. If true
           //1. Set row equal to 0
           //2. Test to see if row is less than or equal to 97
           
              //AA. If true
                 //1. Test to see if the value that is in the current row and
                 //column is equal to the number in the next two rows
               
                    //AAA. If true
                       //1. Add one to the total of vertical triples
                      
                       //2. Go to step 3/A/2/AA/2
                    //BBB. If false, go to next step
                 
                 //2. Add one to row
                 //3. Go to step 3/A/2
              //BB. If false
                 //1. Go to step 3/A/3
           
           //3. Add one to column
           //4. Go to step 3
     
        //B. If false
           //1. Go to step 4
     v_triples = v_trips(int_array, row, col, v_triples);

  //4. Display the number of horizontal triples.
  //5. Display the number of vertical triples.
     results(h_triples, v_triples);

     //6. Terminate
     return 0 ;
}

void populate(int array[][1000], int row, int col, FILE *read_ptr) {
    for ( row = 0 ; row < 100 ; row = row + 1 ) {
    
	for ( col = 0 ; col < 1000 ; col = col + 1 ) {
           
               fscanf( read_ptr , "%d" , &array[row][col] )  ;
        }
    }

    fclose( read_ptr ) ;

}

int h_trips(int array[][1000], int row, int col, int h_triples) {
    for (row = 0; row <= 99; ++row)
     {
       
           for (col = 0; col <= 997; ++col)
           {
            
                 if (array[row][col] == array[row][col+1] &&
                     array[row][col] == array[row][col+2])
                 {
                 
                       ++ h_triples;
                 } 
           }
     }
    return h_triples;
 
}

int v_trips(int array[][1000], int row, int col, int v_triples) {
    for (col = 0; col <= 999; ++col)
     {
        
           for (row = 0; row <= 97; ++row)
           {
             
                 if (array[row][col] == array[row+1][col] &&
                     array[row][col] == array[row+2][col])
                 {
               
                       ++ v_triples;

                 }     
           }   
     }
        
  return v_triples;
 
}

void results(int htrips, int vtrips) {

     printf( "\n\nHorizontal triples: %d \n " , htrips ) ;
     printf( "\n\nVertical triples:   %d \n " , vtrips ) ;

}
