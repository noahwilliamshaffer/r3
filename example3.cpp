#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <algorithm>

using namespace std;
bool isEven(int a) {
    if (a % 2 == 0)
	return true;
    else
	return false;
}


int main() {
    vector<int> v1;


    for (int i = 10; i != 0; --i) {
	v1.push_back(i);
    }

    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // randomize the values in vector
    // need to check again for details to make sure we are doing the
    // right thing for this; but for time being, just use random_shuffle.
    random_shuffle(v1.begin(), v1.end());

    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    // this works because operator<() has been provided for integer type
    // for other types, you need to overload this operator yourself, or
    // provide a function object, or you can use lambda function
    auto itr = max_element(v1.begin(), v1.end());
    cout << "max value: " << *itr << endl;

    // delete the largest value
    v1.erase(itr);

    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // using lambda function to determine largest even value
    itr = max_element(v1.begin(), v1.end(), [](const int &a, const int &b){
	    if (isEven(a) && isEven(b)) {
		return (a < b);
	    } else
		return false;
	}
	);

    cout << "max even value: " << *itr << endl;
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


    return(EXIT_SUCCESS);
}
