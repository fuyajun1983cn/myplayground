#include <iostream>
#include <sstream>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

/* Distribution */

int main ()  {
	// engine only provides a source of randomness
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine e(seed);
   // How to get a random number between 0 and 5?
   //  e()%6  
	//    -- Bad quality of randomness
	//    -- Can only provide uniform distribution

	std::uniform_int_distribution<int> distr(0,5);  // range: [0,5]  -- both 1 and 5 are included
													// default param: [0, INT_MAX]
	cout << " int_distribution: " << endl; 
    for (int i=0; i<30; i++) {
        cout << distr(e) << " ";
    }


	cout << "\n\n real_distribution: " << endl;

	std::uniform_real_distribution<double> distrReal(0,5);  // half open: [1, 5)  -- 1 is included, 5 is not.
														// default param: [0, 1)
    for (int i=0; i<30; i++) {
        cout << distrReal(e) << " ";
    }

	cout << " poisson_distribution: " << endl; 
	std::poisson_distribution<int> distrP(1.0);  //  mean (double) 
    for (int i=0; i<30; i++) {
        cout << distrP(e) << " ";
    }
	cout << endl;	

	cout << " normal_distribution: " << endl; 
	std::normal_distribution<double> distrN(10.0, 3.0);  // mean and standard deviation
	vector<int> v(20);
    for (int i=0; i<800; i++) {
        int num = distrN(e); // convert double to int
		if (num >= 0 && num < 20)
			v[num]++;   // E.g., v[10] records number of times 10 appeared
    }
	for (int i=0; i<20; i++) {
		cout << i << ": " << std::string(v[i], '*') << endl;
	}
	cout << endl;

	// Stop using rand()%n; 
}

#if 0
/* More examples */
void printRandom(std::default_random_engine e) {
  for (int i=0; i<10; i++) 
    cout << e() << " ";
  cout << endl;
}


template <typename T>
void printArray(T arr) {
  for (auto v:arr) {
    cout << v << " ";
  }
  cout << endl;
}

int main ()
{
  std::default_random_engine eng;
  printRandom(eng);

  std::default_random_engine eng2;
  printRandom(eng2);

  unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
  std::default_random_engine e3(seed);
  printRandom(e3);

  eng.seed();  // reset engine to initial state
  eng.seed(109); // set engine to a state according to seed 109

  eng2.seed(109);
  if (eng == eng2)   // will return true
    cout << "eng and eng2 have the same state" << endl;


  cout << "\n\n Shuffling:" << endl;
  int arr[] = {1,2,3,4,5,6,7,8,9};
  vector<int> dd(arr, arr+9);
  printArray(dd);

  vector<int> d =  {1,2,3,4,5,6,7,8,9};
  std::shuffle(d.begin(), d.end(), std::default_random_engine());
  printArray(d);
  std::shuffle(d.begin(), d.end(), std::default_random_engine());  // same order
  printArray(d);
	
  std::shuffle(d.begin(), d.end(), eng);
  printArray(d);
  std::shuffle(d.begin(), d.end(), eng);  // different order
  printArray(d);
}
#endif

#if 0

int main()
{
  std::default_random_engine eng;
  cout << "Min: " << eng.min() << endl; 
  cout << "Max: " << eng.max() << endl;

  cout << eng() << endl;  // Generate one random value
  cout << eng() << endl;  // Generate second random value

  std::stringstream state;
  state << eng;  // Save the state

  cout << eng() << endl;  // Generate one random value
  cout << eng() << endl;  // Generate second random value

  state >> eng;  // Restore the state
  cout << eng() << endl;  // Generate one random value
  cout << eng() << endl;  // Generate second random value
}
#endif
