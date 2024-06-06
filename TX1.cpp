#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

//cau 1
int A(int m, int n){
	if(m == 0) return n + 1;
	if(n == 0) return A(m - 1, 1);
	return A(m - 1, A(m, n - 1));
}

//cau 2 : sap xep

//sap xep noi boi
void bubble_Sort(int arr[], int n){
	for(int i = 1; i < n ; i++){
		cout << "Buoc " << i << " sap xep day thanh : " << endl;
		for(int j = n - 1; j >= i; j--){
			if(arr[j] < arr[j - 1]){
				swap(arr[j], arr[j - 1]);
			}
		}
		for(int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

//sap xep chon
void selection_Sort(int arr[], int n){
	for(int i = 0; i < n - 1; i++){
		cout << "Buoc " << i + 1 << " sap xep day thanh : " << endl;
		int min = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[min])
				min = j;
		}
		swap(arr[i], arr[min]);
		for(int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}



//sap xep chen
void insert_Sort(int arr[], int n){
	for(int i = 1; i < n; i++){
		cout << "Buoc " << i << " sap xep day thanh : " << endl;
		int tmp = arr[i];
		int j = i - 1;
		while(j > -1 && arr[j] > tmp){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
		for(int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}


int main(){
	//cout << A(1,2) << endl;
	int arr[] = {10, 15, 5 , 35, -15, -25, 30};
	insert_Sort(arr,7);
	
	
	return 0;
}
