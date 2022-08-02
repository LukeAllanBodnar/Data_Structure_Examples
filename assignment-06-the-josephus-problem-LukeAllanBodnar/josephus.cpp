#include "josephus.h"
using namespace std;

/*//////////////////////////////////////////////////////////////////////////////////
//                                                                               ///
//      Name: Luke Allan Bodnar                                                  ///
//      ZID:  Z1808328                                                           ///
//      CSCI: 340                                                                ///
//                                                                               ///
//    I certify that this is my own work and where appropriate an extension      ///
//    of the starter code provided for the assignment.                           ///
*///////////////////////////////////////////////////////////////////////////////////

int main() {

	args josephus;
	list<string> People;
	int z, i = 0, cnt = 0;
	list<string>::iterator p;

	init_vals(People, josephus);   //creates the value that goes into arg
	print_list(People, cnt);	   //prints out the intial list of people 

	while (People.size() > 1)
	{
	
		z = (i + (josephus.M-1))%People.size();	    //int for the next M postion
		i = z;										//keeps track were last deletion took place 
	
		p = People.begin();							//to always postion p at the start
		advance(p, z);								// advance to the next postion for deletion 
		People.erase(p);
		++cnt;

		if (cnt%josephus.K==0)  // prints out values every Kth deletion 
		{
			print_list(People, cnt);
		}
	}
	print_list(People, cnt); //prints out the last value 
	return 0;
}

void init_vals(list<string>& People, args& josephus) {

	ifstream inFile;
	inFile.open("josephus.d");
	inFile >> josephus.N >> josephus.M >> josephus.K;

	cout << "Number of people? " << josephus.N << endl;
	cout << "Index for elimination? " << josephus.M << endl;
	cout << "Index for printing? " << josephus.K << endl;
	cout << endl;

	People.resize(josephus.N);

	for (auto k : People)
	{
		generate( People.begin(), People.end(), SEQ(josephus.N));
	}

}

void print_list(const list<string>& People, const unsigned& cnt) {
	
	int count = 0;

	if (cnt == 0) {    //prints the correct begging statments 
		cout << "Initial group of people" << endl;
	}
	else {
		cout << "After eliminating " << cnt << "th person" << endl;
	}
	cout << "----------------------------" << endl;

	for (list<string>::const_iterator it=People.begin(); it != People.end(); ++it) {

		if (count%NO_ITEMS==0 && count != 0) {
			cout << endl;
			count == 0;
		}

		cout << *it << " ";

		++count;
	}
	cout << endl;
	cout << endl;
}