#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll = long long;

struct SinhVien{
	int MaSV;
	string Hoten;
	int Namsinh;
	string Gioitinh;
	float DTK;
	
};

struct Node{
	SinhVien infor;
	Node *next;
};

typedef Node* TRO;
TRO L;

string str;
//nhap thong tin cho sinh vien
void input(SinhVien &SV){
	cout << "---------------- Nhap Thong Tin Cho Sinh Vien ----------------" << endl;
	cout << "1. Nhap Ma Sinh Vien : ";
	cin >> SV.MaSV;
	cout << "2. Nhap Ho Ten Sinh Vien : ";
	cin.ignore(); getline(cin,SV.Hoten);
	cout << "3. Nhap Nam Sinh Sinh Vien : ";
	cin >> SV.Namsinh;
	cout << "4. Nhap Gioi Tinh Sinh Vien : ";
	cin.ignore(); getline(cin,SV.Gioitinh);
	cout << "5. Nhap Diem Tong Ket Sinh Vien : ";
	cin >> SV.DTK;
}

//Khoi tao danh sach rong
void create(TRO &L){
	L = NULL;
}

//kiem tra ds rong
int empty(TRO L){
	return L == NULL;
}

//them sinh vien vao cuoi danh sach
void add(TRO &L, SinhVien elem){
	TRO P,Q;
	P = new Node;
	P -> infor = elem;
	P -> next = NULL;
	if(L == NULL){
		L = P;
	}
	else {
		Q = L;
		while(Q -> next != NULL)
			Q = Q -> next;
		Q -> next =P;
	}
}

//tim chieu dai danh sach sinh vien
int length(TRO L){
	int cnt = 0;
	TRO Q = L;
	while(Q -> next != NULL){
		cnt++;
		Q = Q -> next;
	}
	return cnt;
}

//dua ra danh sach sinh vien da nhap
void showTitle(){
	cout << "                      ------------------ DANH SACH SINH VIEN ------------------" << endl;
	cout << fixed;
	cout << setw(15) << left << "MA SINH VIEN";
	cout << setw(30) << left << "HO TEN";
	cout << setw(15) << right << "NAM SINH";
	cout << setw(15) << right << "GIOI TINH";
	cout << setw(20) << right << "DIEM TONG KET";
	cout << endl;
}

void showData(SinhVien SV){
	cout << fixed;
	cout << setw(15) << left << SV.MaSV;
	cout << setw(30) << left << SV.Hoten;
	cout << setw(15) << right << SV.Namsinh;
	cout << setw(15) << right << SV.Gioitinh;
	cout << setw(20) << right << setprecision(3) << SV.DTK;
	cout << endl;
}
void showList(TRO L){
	TRO Q;
	if(!empty(L)){
		//show title
		showTitle();		
		//show data
		Q = L;
		while(Q != NULL){
			showData(Q -> infor);
			Q = Q -> next;
		}		
	}
	else {
		cout << "Danh sach sinh vien rong !" << endl;
	}	
}

//tao mot danh sach sinh vien
void input_List(TRO &L)
{
	TRO P, Q = NULL;
	SinhVien elem;
	char tieptuc;

	create(L);

	do
	{
		input(elem);
		P = new Node;
		P -> infor = elem;
		P -> next = NULL;
		if (L == NULL)
		{
			L = P;
		}
		else
		{
			Q->next = P;
		}

		Q = P;
		cout << "- Chu y : Co tiep tuc nhap hay khong ? (C/K): ";
		cin >> tieptuc;
	} while (toupper(tieptuc) == 'C');
}

//tim kiem thong qua ma sinh vien
TRO search(TRO L, int masv)
{
	TRO Q = L;
	while(Q != NULL && Q->infor.MaSV != masv)
		Q = Q->next;
	return Q;
}

//sap xep danh sach sinh vien theo diem
void SortByDTK(TRO &a){
	for(TRO p = a; p->next != NULL; p = p->next){
		TRO min = p;
		for(TRO q = p->next; q != NULL; q = q->next){
			if(q->infor.DTK < min->infor.DTK){
				min = q;
			}
		}
		SinhVien tmp = min->infor;
		min->infor = p->infor;
		p->infor = tmp;
	}
}

//liet ke danh sach sinh vien co dtk cao nhat
double findListMaxDTK(TRO L){
	double res = 0;
	TRO Q = L;
	while(Q != NULL ){
		if(Q -> infor.DTK >= res){
			res = Q -> infor.DTK;
			Q = Q -> next;
		}
	}
	return res;
}

int main(){
	create(L);
	bool tmp = true;
	while(tmp){
		cout << "-----------------------------------------------MENU----------------------------------------------------" << endl;
		cout << "1. TAO MOT DANH SACH SINH VIEN MOI ." << endl;
		cout << "2. THEM MOT SINH VIEN VAO CUOI DANH SACH SINH VIEN ." << endl;
		cout << "3. HIEN THI TOAN BO THONG TIN SINH VIEN ." << endl;
		cout << "4. TIM KIEM THONG TIN SINH VIEN BANG MA SINH VIEN ." << endl;
		cout << "5. SAP XEP DANH SACH SINH VIEN THEO DIEM TONG KET ." << endl;
		cout << "6. LIET KE DANH SACH SINH VIEN CO DIEM TONG KET CAO NHAT ." << endl;
		cout << "7. Thoat !" << endl;
		cout << "-------------------------------------------------------------------------------------------------------" << endl;
		cout << "Xin hay nhap lua chon : ";
		int lc; cin >> lc;
		cout << endl;
		switch(lc){
			case 1 :
				{
					cout << endl;
					input_List(L);
					cout << endl;
					break;
				}
			case 2 :
				{
					cout << endl;
					SinhVien sv;
					input(sv);
					add(L,sv);
					cout << endl;
					break;
				}
			case 3 :
				{
					cout << endl;
					showList(L);
					cout << endl;
					break;
				}
			case 4 :
				{
					cout << endl;
					int Ma;
					cout << "HAY NHAP VAO MA SINH VIEN CAN TIM : "; cin >> Ma;
					TRO Q = search(L, Ma);
					if(Q == NULL){
						cout << "KHONG CO MA SINH VIEN " << Ma << " TRONG DANH SACH !";
					} else {
						cout << "THONG TIN CUA SINH VIEN CO MA " << Ma << " LA :" << endl;
						cout << setw(15) << left << "MA SINH VIEN";
						cout << setw(30) << left << "HO TEN";
						cout << setw(15) << right << "NAM SINH";
						cout << setw(15) << right << "GIOI TINH";
						cout << setw(20) << right << "DIEM TONG KET";
						cout << endl;
						showData(Q -> infor);
					}
					cout << endl;
					break;
				}
			case 5 :
				{
					cout << endl;
					int len = length(L);
					if(len == 0){
						cout <<"DANH SACH RONG, KHONG THE SAP XEP !";
						cout << endl;
						break;
					} else {
						SortByDTK(L);
						cout << "HAY NHAP 3 DE HIEN THI DANH SACH SAU KHI SAP XEP !" << endl;
						break;
					}
				}
			case 6 :
				{
					cout << endl;
					int len = length(L);
					if(len == 0){
						cout <<"DANH SACH RONG, KHONG THE TIM KIEM !";
						cout << endl;
						break;
					} else {
						TRO Q = L;
						double res = findListMaxDTK(L);
						cout << "                      ------------------ DANH SACH SINH VIEN CO DIEM TONG KET CAO NHAT  ------------------" << endl;
						cout << fixed;
						cout << setw(15) << left << "MA SINH VIEN";
						cout << setw(30) << left << "HO TEN";
						cout << setw(15) << right << "NAM SINH";
						cout << setw(15) << right << "GIOI TINH";
						cout << setw(20) << right << "DIEM TONG KET";
						cout << endl;
						while(Q != NULL){
							if(Q -> infor.DTK == res){
								showData(Q -> infor);
							}
							Q = Q -> next;
						}
						cout << endl;
						break;
					}
				}
			case 7 :
				{
					cout << "BAN DA THOAT CHUONG TRINH !" << endl;
					tmp = false;
					break;
				}
			default :
				{
					cout << "BAN DA NHAP SAI, XIN VUI LONG NHAP LAI DUNG THEO MENU !" << endl;
				}
		}
	}
	return 0;
}
