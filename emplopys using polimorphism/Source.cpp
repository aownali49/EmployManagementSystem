#include<iostream>
#include<string>
#define MAX 100
using namespace std;
class employ
{

	int eno;
	string ename;
	string cnic;
public:
	employ() :eno(0), ename(" "), cnic(" ") {}
	virtual void setter();
	virtual void getter();
	virtual void outstanding() = 0 {};
};
void employ::setter()
{
	cin.ignore(50, '\n');
	cout << "Enter employ name : ";
	getline(cin, ename);
	cout << "Enter employ number : ";
	cin >> eno;
	cin.ignore(50, '\n');
	cout << "Enter cnic no : ";
	getline(cin, cnic);
}
void employ::getter()
{
	cout << endl;
	cout << "Employ name is : " << ename << endl;
	cout << "Employ no is : " << eno << endl;
	cout << "Employ cnic is : " << cnic << endl;
	cout << endl;
}
class manager :virtual public employ
{
	string title;
	double club_dues;
	static int mcount;
	static int ocount;
public:
	manager() :employ(), title(" "), club_dues(0) { mcount++; }
	void setter()
	{
		employ::setter();
		cin.ignore(50, '\n');
		cout << "Enter job Title : ";
		getline(cin, title);
		cout << "Enter club dues : ";
		cin >> club_dues;
	}
	void getter()
	{
		employ::getter();
		cout << endl;
		cout << "Job Title is " << title << endl;
		cout << "Club dues are : " << club_dues << endl;
		cout << "Number of managers: " << mcount << endl;
		cout << "Number of outstanding managers: " << ocount << endl;
		cout << endl;
	}
	void outstanding()
	{
		if (club_dues <= 1000)
		{
			cout << "\n\noutstanding\n\n";
			ocount++;
		}
		else
			cout << " \n\nayash\n\n";
	}



};
int manager::mcount = 0;
int manager::ocount = 0;
class scientist :virtual public employ
{
	string re_fie;
	int n_o_p;
	static int scount;
	static int oscount;

public:
	scientist() :employ(), re_fie(" "), n_o_p(0) { scount++; }
	void setter()
	{
		employ::setter();
		cin.ignore(50, '\n');
		cout << "Enter research field(subject) : ";
		getline(cin, re_fie);
		cout << "Enter no of publications";
		cin >> n_o_p;
	}
	void getter()
	{
		employ::getter();
		cout << endl;
		cout << "Research field is " << re_fie << endl;
		cout << "No of publications are " << n_o_p << endl;
		cout << "number of scientist is" << scount << endl;
		cout << "number of outstanding scientist is:" << oscount << endl;
		cout << endl;
	}
	void outstanding()
	{

		if (n_o_p >= 10)
		{
			cout << "outstanding" << endl;
			oscount++;
		}
		else
			cout << " invalid" << endl;
	}




};
int scientist::scount = 0;
int scientist::oscount = 0;





class labour :virtual public employ
{
	char s;
	float h_w;
	float h_r;
	static int lcount;
	static int locount;
public:
	labour() :employ(), s(' '), h_w(0.0), h_r(0.0) { lcount++; }
	void setter();
	void getter();
	void outstanding();
};
int labour::lcount = 0;
int labour::locount = 0;


void labour::setter()
{
	employ::setter();
	cout << "Enter m for morning shift\nEnter e for evening shift\nEnter n for night shift\n";
	cout << "Enter your choice ";
	cin >> s;
	cout << "Enter hours worked : ";
	cin >> h_w;
	cout << "Enter hours rate :";
	cin >> h_r;
}
void labour::getter()
{
	employ::getter();
	cout << "Shift is ";
	if (s == 'm')
		cout << "morning";
	else if (s == 'n')
		cout << "night";
	else if (s == 'e')
		cout << "evening";
	else
		cout << "Invalid";
	cout << endl;
	cout << endl;
	cout << "Hours worked is " << h_w << endl;
	cout << "Hour rate is " << h_r << endl;
	cout << " number of labour:" << lcount << endl;
	cout << "number of outstanding labour is" << locount << endl;
	cout << endl; cout << endl;
}
void labour::outstanding()
{
	if (h_w > 8)
	{
		cout << "outstanding" << endl;
		locount++;
	}

	else
		cout << " invalid" << endl;
}





class foreman :public labour
{
	int n;
	static int fcount;
	static int ofcount;
public:
	foreman() : n(0) { fcount++; }
	void setter()
	{
		labour::setter();
		cout << "enter number of dependent:" << endl;
		cin >> n;
	}
	void getter()
	{
		labour::getter();
		cout << "number of dependent is:" << n << endl;
		cout << "number of foreman is:" << fcount << endl;
		cout << "number of outstanding foreman is:" << ofcount << endl;
	}
	void outstanding()
	{
		if (n > 2)
		{
			cout << "foreman is outstanding:";
			ofcount++;
		}

		else
			cout << " invalid" << endl;

	}

};
int foreman::fcount = 0;
int foreman::ofcount = 0;


int main()
{
	employ *e[MAX];
	char ch;
	int count = 0;
	do
	{

		cout << "................menu.............." << endl;
		cout << "\t1)manager\n";
		cout << "\t2)scientist\n";
		cout << "\t3)labour\n";
		cout << "\t4)foreman\n";
		cout << "\t5) display all data\n";
		cout << "\t6)Exit\n";
		cout << "enter choice:";
		cin >> ch;
		switch (ch)
		{
		case'1':
			e[count] = new manager;
			e[count++]->setter();

			break;

		case'2':
			e[count] = new scientist;
			e[count++]->setter();
			break;

		case'3':
			e[count] = new labour;
			e[count++]->setter();
			break;

		case'4':
			e[count] = new foreman;
			e[count++]->setter();


			break;

		case'5':
			for (int i = 0; i < count; i++)
			{
				e[i]->outstanding();
				e[i]->getter();

			}


			break;
		case '6':

			exit(-1);
		}
	} while (true);


	system("pause");
	return 0;
}