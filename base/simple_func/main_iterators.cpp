#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> A = {10,13,15,22,8};

    // iterator 1
    for (std::vector<int>::iterator i = A.begin(); i != A.end(); ++i)
        std::cout << *i << ' ';

    // iterator 2
    for (auto i = A.begin(); i != A.end(); ++i)
        std::cout << *i << ' ';

    // iterator 3
    for (auto i : A)
        std::cout << i << ' ';


    return 0;
}

// istream_iterator example
#include <iostream>     // std::cin, std::cout
#include <iterator>     // std::istream_iterator

int main () {
  double value1, value2;
  std::cout << "Please, insert two values: ";

  std::istream_iterator<double> eos;              // end-of-stream iterator
  std::istream_iterator<double> iit (std::cin);   // stdin iterator

  if (iit!=eos) value1=*iit;

  ++iit;
  if (iit!=eos) value2=*iit;

  std::cout << value1 << "*" << value2 << "=" << (value1*value2) << '\n';

  return 0;
}

// ostream_iterator example
#include <iostream>     // std::cout
#include <iterator>     // std::ostream_iterator
#include <vector>       // std::vector
#include <algorithm>    // std::copy

int main () {
  std::vector<int> myvector;
  for (int i=1; i<10; ++i) myvector.push_back(i*10);

  std::ostream_iterator<int> out_it (std::cout,", ");
  std::copy ( myvector.begin(), myvector.end(), out_it );
  return 0;
}