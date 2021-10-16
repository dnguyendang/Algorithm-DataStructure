#include<iostream>
#include<vector>
using namespace std;

// thuat toan 

void printXU(vector<int> v){
	for (int i = 0; i < v.size(); i ++){
		cout << v[i] << " ";
	}
}

int main(){
	// bai toan toi uu so dong tien theo tong cho truoc;
	int sum;
	cout << "Select the amount of money you wanna convert: ";
	cin >> sum;
	// int *arr = new int[];
	vector<int> xu;

	// quy doi ra cac dong 1 2 5 
	while(sum > 0){
		if(sum >= 5){
			sum -= 5;
			xu.push_back(5);
		}
		else if(sum >= 2){
			sum -= 2;
			xu.push_back(2); 
		}
		else if(sum >= 1){
			sum -= 1;
			xu.push_back(1);
		}
	}
	cout << "So luong xu quy doi: " << xu.size() << endl;
	cout << "Bao gom: ";
	printXU(xu);

	return 0;
}