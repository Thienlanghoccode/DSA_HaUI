#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

struct NhanVien{
	string hoDem;
	string ten;
	char gioiTinh;
	string maNhanVien;
	float heSoLuong;
};

struct Node{
	NhanVien infor;
	Node *next;
};

typedef Node* Tro;
Tro List;

//nhap thong tin nhan vien
void input(NhanVien &nv){
	cout << "----------------------	NHAP THONG TIN NHAN VIEN ----------------------" << endl;
	cout << "Nhap Ho Dem Nhan Vien: "; getline(cin, nv.hoDem);
	cout << "Nhap Ten Nhan Vien: "; getline(cin, nv.ten);
	cout << "Nhap Gioi Tinh Nhan Vien (M/F): "; cin >> nv.gioiTinh;cin.ignore();
	cout << "Nhap Ma Nhan Vien: "; getline(cin, nv.maNhanVien);
	cout << "Nhap He So Luong Nhan Vien: "; cin >> nv.heSoLuong ;cin.ignore();
}

//tao danh sach rong
void create_List(Tro &List){
	List = NULL;
}

//kiem tra ds rong
int empty(Tro List){
	return List == NULL;
}

//in tieu de
void showTitle(){
	cout << "------------------------- IN THONG TIN NHAN VIEN -------------------------" << endl;
	cout << setw(9) << left << "HO DEM" << "\t";
	cout << setw(10) << left  << "TEN NHAN VIEN" << "\t";
	cout << setw(4) << left << "GIOI TINH" << "\t";
	cout << setw(10) << left << "MA NHAN VIEN" << "\t";
	cout << setw(4) << left << "HE SO LUONG";
	cout << endl;
}

void showData(NhanVien NV){
	cout << setw(9) << left << NV.hoDem << "\t";
	cout << setw(10) << left  << NV.ten << "\t";
	cout << setw(8) << left << NV.gioiTinh << "\t";
	cout << setw(10) << left << NV.maNhanVien << "\t";
	cout << setw(4) << left << NV.heSoLuong;
	cout << endl;
}

void showList(Tro List){
	Tro Q;
	if(!empty(List)){
		//in tieu de
		showTitle();
		
		//in thong tin
		Q = List;
		while(Q != NULL) {
			showData(Q -> infor);
			Q = Q -> next;
		}
	} else {
		cout << "Danh sach nhan vien rong ! ";
		cout << endl;
	}
}

void input_List(Tro &List){
	Tro P,Q = NULL;
	NhanVien elem;
	char tieptuc;
	
	do {
	
		input(elem);
		P = new Node;
		P -> infor = elem;
		P -> next = NULL;
		if(List == NULL){
			List = P;
		} else {
			Q -> next = P;
		}
		Q = P;
		cout << "- Chu y : Co tiep tuc nhap hay khong ? (C/K): ";
		cin >> tieptuc;
		cin.ignore();
	} while(toupper(tieptuc) == 'C');
}


int main(){
	input_List(List);
	showList(List);
	
	return 0;
}
