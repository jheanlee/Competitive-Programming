#include <ctime>
#include <iostream>
#include <iomanip>

void run_with_timer() {
  clock_t start_time, end_time;
  start_time = clock();

/*---Write code to time here---*/


  
/*-----------------------------*/
  end_time = clock();
  double time_taken = double(end_time - start_time) / double(CLOCKS_PER_SEC);
  std::cout << "Execution Time: " << std::fixed << time_taken << std::setprecision(5);
  std::cout << " sec" << '\n';
}
