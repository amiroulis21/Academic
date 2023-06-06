// Andrew Miroulis

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <cmath>

using namespace std;


long baseTen(string, int);
string convert(int, int, char[]);

int main(int argc, char* argv[]) {
    ifstream f(argv[1]);
    string line;
    int n;
    string token;
    int lineno = 1;;
    char alphanum[36];
    char temp = 'a';
    for(int i = 0; i < 36; i++) {
	if (i < 10)  {
	    alphanum[i] = i + 48;
	}
	else {
	    alphanum[i] = temp + i - 10;
	}
    }

    while(getline(f, line)) {
	while(line[0] == '@') {
	getline(f, line);
	lineno++;

	}
	
        stringstream ss(line);
	if (ss >> n){

	cout << lineno << ": ";
        //cout << n << " ";
	ss >> token;
	long bTen = baseTen(token, n);
	ss >> n;
	cout << convert(bTen, n, alphanum) << "\n";
	
	}

	lineno++;
    }

   
    
   
}

long baseTen(string s, int base) {
    long sum = 0;
    for(int i = 0; i < s.length(); i++) {
	if (s[i] <= 57) {
	    sum += (s[i] - 48) * pow(base, s.length() - i - 1);
	    
	}
	else {
	    sum += (tolower(s[i]) - 87) * pow(base, s.length() - i - 1);

	}
    }
    return sum;
    
}

string convert(int deci, int base, char alphanum[]) {
    string sum = "";
     do {
	sum = alphanum[deci % base] + sum; 
	deci = deci / base;

    } while(deci != 0);
	return sum;
	
}
