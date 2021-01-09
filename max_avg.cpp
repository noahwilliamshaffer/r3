#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;
int main() {
	float value;
	vector<float> v;
	float max;
	float avg;

	while (cin >> value) {
		if (value == 0) 
			break;
		else
			v.push_back(value);
	}

	if (v.empty()) {
		cout << "No input values" << endl;
	} else {
		max = avg = v[0];
		for (const auto & x: v) {
			if (max < x)
				max = x;
			avg += x;
		}
		/* using index operator
		for (size_t i = 1; i < v.size(); ++i) {
			if (max < v[i])
			   max = v[i];
			avg += v[i];	
		}
		*/

		/* another way: using range-based for loop
		for (const auto & x: v) {
			if (max < x)
				max = x;
			avg += x;
		}
		*/

		/* another way: using iterator
		for (auto itr = v.begin(); itr != v.end(); ++itr) {
			if (max < *itr)
				max = *itr;
			avg += *itr;
		}
		*/
		cout << "Maximum value = " << max << endl;
		cout << "Average value = " << avg/v.size() << endl;
	}

	return(EXIT_SUCCESS);
}
