#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;

void run_with_timer() {
  clock_t start_time, end_time;
  start_time = clock();

/*---Write code to time here---*/


  
/*-----------------------------*/
  end_time = clock();
  double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
  cout << "Execution Time: " << fixed << time_taken << setprecision(5);
  cout << " sec" << endl;
}
