#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <algorithm>

using namespace std;

// using a regular function for sort()
bool mycmp(const int &a, const int &b) {
	return b < a;
}

int main() {
    vector<int> v1;


    for (int i = 10; i != 0; --i) {
	v1.push_back(i);
    }

    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // this works because operator<() has been provided for integer type
    // for other types, you need to overload this operator yourself, or
    // provide a function object, or you can use lambda function
    sort(v1.begin(), v1.end());
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // using regular function, note this will result in decreasing order
    sort(v1.begin(), v1.end(), mycmp);
    copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return(EXIT_SUCCESS);
}
