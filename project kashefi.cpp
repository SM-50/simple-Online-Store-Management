#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
///////////////////////////////////////////
// استراکت محصول
struct mahsol {
	string name;
	float price;
	int mojodi;
	int id;
};

// تابع اضافه کردن محصول (با استفاده از ارایه )
void addmahsol(mahsol a[], int &count) {
	if (count < 100) {
		// بررسی شرط ایا تعداد محصولات مغازه پر شده یا نه
		cout << " please enter name mahsol ";
		cin.ignore();
		getline(cin, a[count].name);
		cout << " plaese enter price : ";
		cin >> a[count].price;

		cout << " please enter mojodi : ";
		cin >> a[count].mojodi;

		cout << " pleaes enter id mohsol :";
		cin >> a[count].id;
		count++; // یکی به محصولات فروشگاه اضافه میکنیم
		cout << " mahsol ba movafaghiat ezafe shad " << endl;
	}
	else {
		cout << " tedad mohsol ha por shode " << endl;
	}
}

//(تابع برای حذف محصول (شیفت دادن ارایه
void deletemahsol(mahsol a[], int &count) {
	string name;
	cout << "lotfan name mahsol mored nazar baray hazf kardan ra vared konid : ";
	cin.ignore();
	getline(cin, name);

	int found = 0;
	for (int i = 0; i < count; i++) {
		if (a[i].name == name) {
			for (int j = i; j < count - 1; j++) {
				a[j] = a[j + 1];
			}
			count--; //یک عدد از تعداد محصولات فروشگاه کم میشود 
			cout << "mahsol mored nazar ba movafaghiyat hazf shod" << endl;
			found = 1; // این برای اینه که  ایف پایین اجرا نشه
			break;
		}
	}

	// اگر شرط بالا اجرا نشه یعنی محصولی با اون اسم نداشته باشم 
	if (found == 0) {
		cout << "mahsol yaft nashod!!!" << endl;
	}
}

// تابع برای جست و جوی محصول 
void searchmahsol(mahsol a[], int &count) {
	string name;
	cout << "lotfan name mahsol mored nazar ra vared konid : ";
	cin.ignore();
	getline(cin, name);

	int found = 0;

	for (int i = 0; i < count; i++) {
		if (a[i].name == name) {
			cout << "mahsol yaft shod : " << endl;
			cout << "Name: " << a[i].name << ", Price: " << a[i].price << ", id: " << a[i].id << ", mojodi " << a[i].mojodi << endl;
			found = 1; //این برای اینه که  ایف پایین اجرا نشه
			break;
		}
	}
	// اگر شرط بالا اجرا نشه یعنی محصولی با اون اسم نداشته باشم
	if (found == 0) {
		cout << "mahsol mored nazar yaft nashod ";
	}
}

// ?تابع برای نمایش محصولاتمون 
void viewmahsolat(mahsol a[], int &count) {
	// ابتدا بررسی اینکه ایا اصلا محصولی داریم یا نه
	if (count == 0) {
		cout << "hich mahsoli nadarim";
	}
	else {
		cout << "List mahsolat:";
		for (int i = 0; i < count; i++) {
			cout << "Name: " << a[i].name << ", Price: " << a[i].price << ", id: " << a[i].id << ", mojodi " << a[i].mojodi << endl;
		}
	}
}

// نمایش تعداد محصولات موجود در مغازه
void tedadmahsolat(int Count) {
	cout << "Total number of mahsol : " << Count << endl;
}

//(تابع تنظیمات(اضافی
void taghirRang() {
// عکس رنگ های مختلف رو داخل دسکتاپ ذخیره کردم
	int n;
	cout << "                                        RANG MAORED ALAGHE RA VARED KONID :" << endl;
	cout << "                                                    1_blue" << endl;
	cout << "                                                    2_WHITE" << endl;
	cout << "                                                    3_GREEN" << endl;
	cout << "                                                    4_PURPULR" << endl;
	cin >> n;
	switch (n) {
	case 1:
		system("color 17");
		break;
	case 2:
		system("color 70");
		break;
	case 3:
		system("color 27");
		break;
	case 4:
		system("color 57");
		break;
	default:
		cout << "Invalid choice! Please try again." << endl;
	}
}

// تابع نمایش منو 
// اینو میشد داخل خود تابع اصلی هم نوشت فرقی نمیکنه

void showMenu() {

	cout << "\n______________________________________________WELCOME TO DIGITAL MARKET_______________________________________________\n";
	cout << "\n                                                 1. Add Product\n";
	cout << "                                                 2. Remove Product\n";
	cout << "                                                 3. Search Product\n";
	cout << "                                                 4. View All Products\n";
	cout << "                                                 5. Show Product Count\n";
	cout << "                                                 6. setting\n";
	cout << "                                                 7. Exit\n";
}
int main() {
	mahsol a[99]; // یک ارایه برای ذخیره محصولات
	int count = 0;   // شمارنده برای تعداد محصولات داخل مغازه
	int choice;             // گرفتن انتخاب کاربر از منو 

	do {
		showMenu(); // فراخوانی تابع منو برای نمایش منو 
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			addmahsol(a, count);  // اضافه کردن محصول
			break;
		case 2:
			deletemahsol(a, count); // حذف محصول
			break;
		case 3:
			searchmahsol(a, count); // جست و جو محصول
			break;
		case 4:
			viewmahsolat(a, count); // نمایش محصولات
			break;
		case 5:
			tedadmahsolat(count); // نمایش تعداد محصولات 
			break;
		case 6:
			taghirRang();
			break;
		case 7:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 7);  // زمانی که کاربر 6 رو بزن شرط روبرو برقرار نیس و برنامه تمام میشع

	return 0;
}