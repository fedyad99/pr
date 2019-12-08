#include <iostream>
#include <vector>
using namespace std;

void factorization(int n) {
	vector<int> prost;
	int temp;
	while (n > 1) {
		for (int i = 2; i < n;) {
			if (n % i == 0) {
				prost.push_back(i);
				n = n / i;
			}
			else {
				i++;
			}
		}
		if (n > 1) {
			prost.push_back(n);
			break;
		}
	}

	for (int i = 0; i < prost.size(); i++) {
		cout << prost[i];
		temp = count(prost.begin(), prost.end(), prost[i]);
		if (temp != 1) {
			cout << "^" << temp;
			i += temp - 1;
			if (i != prost.size() - 1) cout << "*";
			continue;
		}
		else if (i != prost.size() - 1) cout << "*";
	}

	return;
}

int main(){
	int n;
	cin >> n;
	factorization(n);
	return 0;
}
