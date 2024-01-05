#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

// int main() 
// {
//     // Declare an output iterator for std::cout
//     std::ostream_iterator<int> output_itr(std::cout, " ");

    
//     // Use the output iterator to write values to std::cout
//     *output_itr = 1;
//     ++output_itr;
//     *output_itr = 2;
//     ++output_itr;
//     *output_itr = 3;

//     // Output a newline for better readability
//     std::cout << std::endl;

//     return 0;
// }

// int main() 
// {
//     // std::vector<int> arrVector = {5, 2, 8, 1, 9, 3};

//     //  std::list<int> arr = {5, 2, 8, 1, 9, 3};
//     //  std::list<int>::iterator it;
//     std::istream_iterator<int> input_itr(std::cin);
//     std::cout << *input_it << std::endl;
//     // it = arr.begin();
//     // while (it != arr.end())
//     // {
//     //     std::cout << *input_itr << std::endl;
//     //     it++;
//     // }

//     // std::cout << "\n\n";




// }

int main() {
    // Create a vector of integers
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // Create iterators for the beginning and end of the vector
    std::vector<int>::iterator beginIterator = myVector.begin();
    std::vector<int>::iterator endIterator = myVector.end();

    // Calculate the difference between the iterators
    std::vector<int>::difference_type difference = endIterator - beginIterator;

    // Print the difference
    std::cout << "Difference between iterators: " << difference << std::endl;

    return 0;
}
