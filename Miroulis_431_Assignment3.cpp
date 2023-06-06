#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void pattern(string, string, string);

int main() {
//This program accepts user input of a sequence of characters
//and generates a pattern of concentric squares using each character
//Written in C++
//Written by Andrew Miroulis
//3/31/23

string word;
string start = "";
string end = "";


cout << "Type in any sequence of characters(no spaces in between): ";
cin >> word;


pattern(word, start, end);


}
void pattern(string word, string start, string end) {
//The function prints each line of the concentric square pattern
//by recursively calling itself. The 'start' and 'end' string
//variables store the portions of each line that are not repeating
//characters. The 'temp' string variable is used to formulate
//the correct sequence of characters for each line.
//'start' and 'end' are then updated.
//'ssword' is set to be all characters in 'word' except for the last.
//'ssword', 'start', and 'end' are passed into the recursive call
//The base case is when the length of 'word' = 1
//Written in C++
//Written by Andrew Miroulis
//3/31/23

int len = word.length();
if(len == 1) {
cout << start << word << end << "\n";
}
else{
string temp = start;
    for(int i = 0; i < 2 * len - 1; i++) {
	  temp += word[len - 1];	
    }
    temp += end;
    cout << temp;
    cout << "\n";

    start += word[len - 1];
    end = word[len - 1] + end;

    string ssword;
    for(int i = 0; i < len - 1; i++) {
        ssword += word[i];
    }

    pattern(ssword, start, end); 
 
    cout << temp + "\n";


}

}

