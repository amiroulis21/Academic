#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int n = 10;
int a[n];
int i;
void sort();


int main() {
//This program generates an array of random 
//integers and sorts the array from least to greatest
//Written in C++ by Andrew Miroulis
//2/24/23

    srand(time(0)); //srand() and rand() functions were retrieved from geeksforgeeks.org
    cout << "Initial array values: ";
    for(i = 0; i < n; i++) {
	a[i] = rand();
	cout << a[i] << " ";
	 
    }
   cout << "\n\n";
    sort();
    cout << "Sorted array values: ";
    for(i = 0; i < n; i++) {
	cout << a[i] << " ";
    } 
}

int j;
void move();

void sort() {
//This function iterates through the array
//and checks if the element at index j is
//greater than the element at index j + 1
//If true, then the move() function is called
//Written in C++ by Andrew Miroulis
//2/24/23

    for(j = 0; j < n - 1; j++) {
	if(a[j] > a[j + 1]) {
	    move();
	}
    }
    
}
int temp;
int k;
void findkay();

void move() {
//This function moves the element at index
//j + 1 to the left of all other elements 
//greater than it
//It calls the findkay() function to
//help accomplish this task
//Written in C++ by Andrew Miroulis
//2/24/23
    
    temp = a[j + 1];
    a[j + 1] = a[j];
    findkay();
    a[k] = temp;

}

int sw;

void findkay() {
//This function moves all elements that are
//greater than temp to the right of it
//Written in C++ by Andrew Miroulis
//2/24/23
   
    k = j;
    sw = 0;
    while(k > 0 && sw == 0) {
	if(a[k - 1] > temp) {
	    a[k] = a[k - 1];
	    k = k - 1;
	}
	else {
	    sw = 1;
	}
    }
}

