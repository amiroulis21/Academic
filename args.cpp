// Andrew Miroulis

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) { //argc = argument counter, argv = argument vector
    ifstream f(argv[1]);

    int num;
    int sum;
    int min;
    int lineno = 1;
    string line;
    while(getline(f, line)) {
	min = 0;
	sum = 0;
	int count[21] = {0};
	cout << lineno;
	lineno++;
	stringstream ss(line);
	ss >> min;
	sum += min;
	count[min + 10]++;
	while(ss >> num) {
	    sum += num;
	    if(num < min) {
		min = num;
	    }
	    count[num + 10]++;

    	}
	int maxfreq = 0;
	int tally = 0;
	for(int i = 0; i < 21; i++) {
	    if(count[i] >= tally) {
		tally = count[i];
		maxfreq = i - 10;
	    }
	}
	cout << " " << sum;
	cout << " " << min;
	cout << " " << maxfreq;
	cout << endl;
    }

    f.close();

    return EXIT_SUCCESS;
}