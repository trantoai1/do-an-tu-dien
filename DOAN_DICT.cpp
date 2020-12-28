#include <iostream>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<string>
#include<io.h>
#include <fcntl.h>
#define Show 20
#define doc1 186
#define tt 201
#define td 200
#define pt 187
#define pd 188
#define ngang 205
#define doc 186
#define hang 40
#define cot 24
#define F1 59
#define DEL 83
#define INS 82
#define UP 72
#define DOWN 80
#define ENTER 13
#define TAB 9
#define ESC 27
#define BSP 8
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hConsoleColor= GetStdHandle(STD_OUTPUT_HANDLE);
void TiengViet(const wchar_t *str)/*in tieng viet*/
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << str;
	_setmode(_fileno(stdout), _O_TEXT);
}

void gotoxy(int x, int y)
{
  if(!console)
    console = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(console,c);
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void SetColor()
{
	SetConsoleTextAttribute(hConsoleColor, FOREGROUND_GREEN);
}
void DeleteColor()
{
	SetConsoleTextAttribute(hConsoleColor, 15);
}

struct nghia
{
	string mean;
	nghia *next;
};

struct item
{
	nghia *first;
	nghia *last;
	string word;
	string type;
	string *examp[5]; 
	string temp;
};

struct node
{
	item data;
	node *left = NULL;
	node *right = NULL;
};

struct hashtable
{
	node *head;
	node *tail;
};
hashtable *tudien = new hashtable[26];

int Ham_bam(node *p)
{
	if(p == NULL) return 0;
	int l = (int)p->data.word[0] - 97;
	return l;
}

nghia *tao_nodeLKD (string mean)
{
	nghia *p = new nghia;
	p->mean = mean;
	p->next = NULL;
	return p;
}

void chen_cuoiLKD(nghia *&first, nghia *&last, string mean)
{
	nghia *p = new nghia();
	p = tao_nodeLKD(mean);
	if(first == NULL)
	{
		first = last = p;
	}
	else
	{
		last->next = p;
		last = p;
	}
}

node *tao_node (item data)
{
	node *p = new node;
	p->data = data;
	p->left=NULL;
	p->right=NULL;
	return p;
}

void chen_cuoi(node *&head, node *&tail, item data)
{
	node *p = new node;
	p = tao_node(data);
	if (head == NULL)
	{
		head=p;
		tail=p;
	}
	else
	{
		tail->right=p;
		p->left=tail;
		tail=p;
	}
}
void space(int x1, int x2, int y1, int y2)
{
	for(int i = 0; i <= x2 - x1; i++)
	{
		gotoxy(x1, i + 3);
		for(int j = 0; j <= y2 - y1; j++)
		{
			cout<<" ";
		}
		cout<<endl;
	}
}
void Clear(int x)
{
	for(int i = 0; i < x; i++)
	{
		cout<<" ";
	}
}

void HD()
{
	DeleteColor();
	gotoxy(10, 25);
	TiengViet(L"1 . C\u00F3 2 c\u00E1ch tra t\u1EEB \u0111i\u1EC3n...");
	gotoxy(10, 26);
	cout<<"2. Hieu chinh tu: Chinh sua loai tu (7 loai tu co ban ung voi cac so tu 1 - 7), nghia tu (toi da 10 nghia), ";
	gotoxy(10, 27);
	cout<<"cac vi du (toi da 5 vi du).";
	gotoxy(10, 28);
	cout<<"3. Them tu moi (Tab), xoa tu cu (Backspace)";
	gotoxy(70, 28);
	SetColor();
	cout<<"Nhan ENTER de tiep tuc.";
	char key = getch();
	if(key == ENTER)
	{
		gotoxy(10, 25);
		Clear(600);
		return;
	}
}

CONSOLE_SCREEN_BUFFER_INFO csbi;
int getX()//lay toa do x hien tai cua con tro console.
{
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int getY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}

void Khung1()
{
	SetConsoleTextAttribute(hConsoleColor, 50);
	gotoxy(20, 1);
	for(int x = 0; x < 40; x++)
	{
		cout<<" ";
	}
	
	DeleteColor();
	gotoxy(20, 0);
	cout<<char(tt);
	for(int i = 1; i < hang;i++)
	{
		
		cout<<char(ngang);
	}
	cout<<char(pt)<<endl;
	for(int i = 1; i < cot;i++)
	{
		gotoxy(20, i);
		cout<<char(doc)<<endl;
	}
	gotoxy(20, 23);
	cout<<char(td);
	for(int i = 1; i < hang;i++)
	{
		
		cout<<char(ngang);
	}
	cout<<char(pd);
	for(int i = 1; i < cot - 1;i++)
	{
		gotoxy(60, i);
		cout<<char(doc)<<endl;
	}
	gotoxy(21, 2);
	cout<<"Tra cuu: ";
	
	SetColor();
	gotoxy(3, 3);
	cout<<"F1: Huong Dan";
	gotoxy(3, 5);
	cout<<"Insert: Them";
	gotoxy(3, 7);
	cout<<"Delete: Xoa";
	gotoxy(3, 9);
	cout<<"Enter: Chon";
	gotoxy(3, 11);
	cout<<"Esc: Thoat";
	gotoxy(35, 0);
	cout<<"DICTIONARY"<<endl;
	DeleteColor();
	return;		
}

void Khung2()
{
	space(69, 69+15, 3, 37);
	DeleteColor();
	gotoxy(68, 2);
	cout<<char(tt);
	for(int i = 0; i < 35;i++)
	{
		
		cout<<char(ngang);
	}
	cout<<char(pt)<<endl;
	for(int i = 1; i < 20;i++)
	{
		gotoxy(68, i + 2);
		cout<<char(doc)<<endl;
	}
	gotoxy(68, 22);
	cout<<char(td);
	for(int i = 0; i < 35;i++)
	{
		
		cout<<char(ngang);
	}
	cout<<char(pd);
	for(int i = 1; i < 20;i++)
	{
		gotoxy(104, i + 2);
		cout<<char(doc)<<endl;
	}	
	SetColor();
	gotoxy(80, 2);
	cout<<"TRA CUU"<<endl;
	DeleteColor();
}

string Nhap_dung1(int x, int y, char c)
{
	string s = "";
	int gh = 22;
	int dem = 0;
	gotoxy(x, y);
	while (true)
	{
		if (c >= 97 && c <= 122)
		{
			
			s.push_back(c);
			dem++;
			if (dem<gh)
			{
				cout << c;
			}
			if (dem>=gh)
			{
				gotoxy(x, y);
				for (int i=0; i < gh; i++)
				{
					cout << " ";
				}
				gotoxy(x, y);
				for (int i = dem-gh;i<dem;i++)
				{
					cout << s[i];
				}
			}
		}

		if (c == ENTER || c == ESC)
		{
			gotoxy(x, y);
			if (dem>gh)
			{
				for (int i=0;i<gh;i++)
				{
					cout << s[i];
				}
				cout << "...";
			}
			else cout << s;
			return s;
		}
		if (c == BSP && dem > 0)
		{
			s[dem-1]='\0';
			dem--;
			s = s.substr(0, dem);
			if (dem>=gh)
			{
				gotoxy(x, y);
				for (int i=0;i<gh;i++)
				{
					cout << " ";
				}
				gotoxy(x,y);
				for (int i=dem-gh;i<dem;i++)
				{
					cout << s[i];
				}
			}
			if (dem < gh)
			{
				gotoxy(x, y);
				for (int i=0;i<gh;i++)
				{
					cout << " ";
				}
				gotoxy(x,y);
				for (int i=dem-gh;i<dem;i++)
				{
					if (s[i]>=97 && s[i]<=122 || s[i] == 32)
					{
						cout << s[i];
					}
				}
				if(dem == 0)
				{
					s = "";
				}
			}
		}
		c =_getch();
	}
}

string Nhap_dung(int x, int y, char c)
{
	string s = "";
	int gh = 22;
	int dem = 0;
	gotoxy(x, y);
	while (true)
	{
		if (c >= 97 && c <= 122 || c == 32 || c >= 48 && c <= 57)
		{
			s.push_back(c);
			dem++;
			if (dem<gh)
			{
				cout << c;
			}
			if (dem>=gh)
			{
				gotoxy(x, y);
				for (int i=0; i < gh; i++)
				{
					cout << " ";
				}
				gotoxy(x, y);
				for (int i = dem-gh;i<dem;i++)
				{
					cout << s[i];
				}
			}
		}

		if (c == ENTER || c == ESC)
		{
			gotoxy(x, y);
			if (dem>gh)
			{
				for (int i=0;i<gh;i++)
				{
					cout << s[i];
				}
				cout << "...";
			}
			else
			{
				cout << s;	
			} 
			return s;
		}
		if (c == BSP && dem > 0)
		{
			s[dem-1]='\0';
			dem--;
			s = s.substr(0, dem);
			if (dem >= gh)
			{
				gotoxy(x, y);
				for (int i=0;i<gh;i++)
				{
					cout << " ";
				}
				gotoxy(x,y);
				for (int i=dem-gh;i<dem;i++)
				{
					cout << s[i];
				}
			}
			if (dem < gh)
			{
				gotoxy(x, y);
				for (int i=0;i<gh;i++)
				{
					cout << " ";
				}
				gotoxy(x,y);
				for (int i=dem-gh;i<dem;i++)
				{
					if (s[i]>=97 && s[i]<=122 || s[i] == 32)
					{
						cout << s[i];
					}
				}
				if(dem == 0)
				{
					s = "";
				}
			}
		}
		c =_getch();
	}
}

string Cat_tu(node *p)
{
	for(int i = 0; i < 5; i++)
	{
		p->data.examp[i] = new string();
	}
	string chuoi = p->data.word;
	string word;
	string type;
	int len = 0;
	for(int i = 0; i < chuoi.length(); i++)
	{
		len++;
		if(chuoi[i]==' ')
		{
			
			word = chuoi.substr(0, len);
			p->data.word = word;
			break;
		}
	}

	int temp = 0;
	for(int i = len; i < chuoi.length(); i++)
	{
		temp++;
		if(chuoi[i]==' ')
		{
			type = chuoi.substr(len, temp);
			p->data.type = type;
			break;
		}
	}
	string mean = chuoi.substr(len + type.length() - 1, chuoi.length() - type.length());
	int count = 0;
	p->data.first = NULL;
	p->data.last = NULL;
	for(int i = 0; i <= mean.length(); i++)
	{
		count++;
		if(mean[i] == ',' ||mean[i] == ';' || i == mean.length())
		{
			string nghiaviet = mean.substr(i - count + 2, count - 2);
			chen_cuoiLKD(p->data.first, p->data.last, nghiaviet);
			count = 0;
		}
		if(mean[i] == '|')
		{
			string vidu = mean.substr(i, mean.length() - i);
			int temp = 0;
			count = 0;
			for(int j = 1; j <= vidu.length();j++)
			{
				count++;
				if(vidu[j] == '|' || j == vidu.length() )
				{
					*p->data.examp[temp++] = vidu.substr(j - count + 1, count - 1);
					count = 0;
				}
			}
			break;
		}
	}
	
	return p->data.word;
}

bool KhoidongHT()
{
	item data;
	fstream p;
	p.open("test2.txt", ios::in|ios::out);
	if(!p.is_open())
	{
		p<<"";
	}
	for(int j = 0; j < 26; j++)
	{
		tudien[j].head = NULL;
		tudien[j].tail = NULL;
	}
	
	getline(p, data.word);
	if(data.word == "")
	{
		cout<<"FILE KHONG CO DU LIEU. NHAP TU MOI";
		return 0;
	}
	int i = 0;
	while (!p.eof() && i < 26)
	{
		while(!p.eof() && data.word[0] == i + 97)
		{
			data.temp = data.word;
			chen_cuoi(tudien[i].head, tudien[i].tail, data);
			getline(p, data.word);
		}
		i++;
	}
	p.close();
	return 1;
}

string Noi_tu(node *p)
{
	if(p==NULL) return "";
	string s1 = ", ";
	string chuoi = p->data.word;
	chuoi = chuoi.insert(chuoi.length(), p->data.type);
	nghia *g = new nghia();
	nghia *q = p->data.first;
	int flag = 0;
	while(q != NULL)
	{
		if(q->mean == "" && q == p->data.first)
		{
			
			g = p->data.first; 
			p->data.first = q->next;
			q = p->data.first;
			delete(g);
			nghia *g = new nghia();
		}
		else if(q->mean == "" && q->next == NULL)
		{
			p->data.last = g;
			q = p->data.last;
			delete(g);
			break;
		}
		else
		{
			if(q->mean != "")
			{
				chuoi = chuoi.insert(chuoi.length(), q->mean);
				chuoi = chuoi.insert(chuoi.length(), s1);
				flag = 0;
			}
			else
			{
				g->next = q->next;
				q = g;
				delete(g);
				nghia *g = new nghia();
				flag = 1;
			}
			g = q;
			if(flag == 0)
			{
				q = q->next;
			}
		}
	}
	for(int i = 0; i < 5; i++)
	{
		if(*p->data.examp[i]!="")
		{
			string s = "|";
			s1 = s.insert(s.length(), *p->data.examp[i]); 
			chuoi = chuoi.insert(chuoi.length(), s1);
		}
	}	
	return chuoi;
}

void Luufile()
{
	fstream q;
	q.open("test2.txt", ios::out);
	for(int i = 0; i < 26; i++)
	{
		node *p = tudien[i].head;
		if(p == NULL) continue;
		for(; p != NULL && Ham_bam(p) == i ;p = p->right)
		{
			string s = p->data.word;
			q<<p->data.temp<<endl;
			if(p->right != NULL && s.compare(p->right->data.word) == 0)
			{
				break;
			}
		}
	}
	q.close();
}


void chen_k(node *&head, node *&tail, node *p)
{
	if(head == NULL)
	{
		head = p;
		tail = p;
		return;
	}
	if((head->data.word).compare(p->data.word) > 0)
	{
		p->right=head;
		head->left=p;
		head = p;
		return;
	}
	for(node* q = head->right; q != NULL; q = q->right)
	{
		if((q->data.word).compare(p->data.word) < 0 && (q->right->data.word).compare(p->data.word) > 0)
		{
			p->left = q;
			p->right = q->right;
			q->right->left = p;
      		q->right = p;
      		return;
		}
	}
	tail->right = p;
	p->left = tail;
	tail = p;
}

void Xoa_k(node *p)
{
	if(p == NULL) return;
	node* temp = p->right;
    temp->right->left = p;
    p->right = temp->right;
    delete temp;
}

void Xoa_dau(node *&head, node *&tail)
{
	node *temp = head;
	head->right->left = NULL;
    head = head->right;
    delete temp;
}

void Xoa_cuoi(node *&head, node *&tail)
{
	node* temp = tail;
    tail->left->right = NULL;
    tail = tail->left;
    delete temp;
}

void Tran_khung1(node *p, int i)
{
	if(p == NULL) return;
	int count = 0;
	nghia *q = new nghia();
	for(q = p->data.first; q != NULL; q = q->next)
	{
		count++;
		if(q->mean.length() > 22 && count == i)
		{
			gotoxy(68, 24);
			cout<<(char)219<<" "<<q->mean;
			return;
		}
	}
}


void Tran_khung2(node *p, int i)
{
	if(p == NULL) return;
	if((*p->data.examp[i]).length() > 22)
	{
		gotoxy(68, 24);
		cout<<(char)219<<" "<<*p->data.examp[i];
	}
}

string Loai_tu(string type)
{
	int count = 0;
	string s = "";
	string n = "Danh tu; ";
	string v = "Dong tu; ";
	string adj = "Tinh tu; ";
	string adv = "Trang tu; ";
	string prep = "Gioi tu; ";
	string conj = "Lien tu; ";
	string pron = "Dai tu; ";
	
	int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0;
	for(int i = 0; i < type.length(); i++)
	{
		count++;
		if(type[i] == ',' || i == type.length() - 1)
		{
			string loai = type.substr(i - count + 1, count-1);
			count = 0;
		    if(loai.compare("n") == 0 && s1 == 0)
		    {
		        s = s.insert(s.length(), n);
		        s1 = 1;
		    }
		    else if(loai.compare("v")== 0 && s2 == 0)
		    {
		        s = s.insert(s.length(), v);
		        s2 = 1;
		    }
		    else if(loai.compare("adj")== 0 && s3 == 0)
		    {
		        s = s.insert(s.length(), adj);
		        s3 = 1;
		    }
		    else if(loai.compare("adv")== 0 && s4 == 0)
		    {
		        s = s.insert(s.length(), adv);
		        s4 = 1;
		    }
		    else if(loai.compare("prep")== 0 && s5 == 0)
		    {
		        s = s.insert(s.length(), prep);
		        s5 = 1;
		    }
		    else if(loai.compare("conj")== 0 && s6 == 0)
		    {
		        s = s.insert(s.length(), conj);
		        s6 = 1;
		    }
		    else if(loai.compare("pron")== 0 && s7 == 0)
		    {
		        s = s.insert(s.length(), pron);
		        s7 = 1;
		    }
		}
	}
	gotoxy(70, 4);
	if(s.length() < 30)
	{
		cout<<s;
		gotoxy(70, 4);
	}
	else
	{
		for(int j = 0; j < s.length() && j < 28; j++)
		{
			cout<<s[j];
			if(j == 27)
			{
				cout<<"...";
			}
		}
		gotoxy(68, 24);
		cout<<(char)219<<" "<<s;
	}
	gotoxy(70, 4);
	return s;
}

void Menu2(node *p)
{
	if(p == NULL) return;
	Khung2();
	gotoxy(70, 3);	
	cout<<p->data.word;
	string s = Loai_tu(p->data.type);
	int i;
	int count = 0;
	nghia *q = new nghia();
	i = 0; 
	for(q = p->data.first; q != NULL && q->mean != "";q = q->next)
	{
		gotoxy(70, 5 + i);
		cout<<"Nghia "<<++i<<": ";
		for(int j = 0; j < (q->mean).length() && j < 22; j++)
		{
			cout<<(q->mean)[j];
			if(j == 21)
			{
				cout<<"...";
			}
		}
		count++;
	}
	q = p->data.first;
	
	for(int k = 0; k < 5; k++)
	{
		DeleteColor();
		gotoxy(70, 6 + i);
		if(*p->data.examp[k] != "")
		{
			cout<<"Vi du "<<k + 1<<": ";
			for(int j = 0; j < (*p->data.examp[k]).length() && j < 22; j++)
			{
				cout<<(*p->data.examp[k])[j];
				if(j == 21)
				{
					cout<<"...";
				}
			}
		}
		else
		{
			cout<<"Vi du "<<k + 1<<": ";
		}
		i++;
	}
	
	gotoxy(105, 3);
	cout<<"1: Danh tu";
	gotoxy(105, 4);
	cout<<"2: Dong tu";
	gotoxy(105, 5);
	cout<<"3: Tinh tu";
	gotoxy(105, 6);
	cout<<"4: Trang tu";
	gotoxy(105, 7);
	cout<<"5: Gioi tu";
	gotoxy(105, 8);
	cout<<"6: Lien tu";
	gotoxy(105, 9);
	cout<<"7: Dai tu";
	gotoxy(105, 10);
	cout<<"DEL: Xoa";
	gotoxy(70, count + 11);
	SetColor();
	cout<<"Nhan F de chinh sua.";
	
	char key = getch();
	if(key == 102)
	{
		gotoxy(70, count + 11);
		cout<<"Nhan Tab de luu.       ";
		DeleteColor();
		i = 0;
		gotoxy(70, 4);
		while(true)
		{
			if(i < 0 || i > count + 6)
			{
				gotoxy(70, 4);
				i = 0;
			}
			char key = getch();
			if(key == DOWN)
			{
				i++;
				gotoxy(79, 4 + i);
				if(i > 0 && i < count + 1)
				{
					gotoxy(68,24);
					Clear(150);
					Tran_khung1(p, i);
				}
				else if(i > count + 1 && i != 5 + count + 2)
				{
					gotoxy(68,24);
					Clear(150);
					Tran_khung2(p, i - count - 2);
				}
				gotoxy(79, 4 + i);
			}
			else if(key == UP)
			{
				i--;
				gotoxy(79, 4 + i);
				if(i > 0 && i < count + 1)
				{
					gotoxy(68,24);
					Clear(150);
					Tran_khung1(p, i);
				}
				else if(i > count + 1 && i != 5 + count + 2)
				{
					gotoxy(68,24);
					Clear(150);
					Tran_khung2(p, i - count - 2);
				}
				gotoxy(79, 4 + i);
			}
			else if((key >= 49 && key <= 57) ||(key >= 97 && key <= 122) ||key == BSP ||  key == DEL)
			{
				if(i == 0 && (key >= 49 && key <= 57) || key == DEL)
				{
					while(key != ESC || key != ENTER)
					{
						if(key == 49)
						{
							p->data.type = p->data.type.insert(p->data.type.length() - 1, ",n");
							s = Loai_tu(p->data.type);
						}
						if(key == 50)
						{
							p->data.type = p->data.type.insert(p->data.type.length() - 1, ",v");
							s = Loai_tu(p->data.type);
						}
						if(key == 51)
						{
							p->data.type = p->data.type.insert(p->data.type.length() - 1, ",adj");
							s = Loai_tu(p->data.type);
						}
						if(key == 52)
						{
							p->data.type = p->data.type.insert(p->data.type.length() - 1, ",adv");
							s = Loai_tu(p->data.type);
						}
						if(key == 53)
						{
							p->data.type = p->data.type.insert(p->data.type.length() - 1, ",prep");
							s = Loai_tu(p->data.type);
						}
						if(key == 54)
						{
							p->data.type = p->data.type.insert(p->data.type.length() - 1, ",conj");
							s = Loai_tu(p->data.type);
						}
						if(key == 55)
						{
							p->data.type = p->data.type.insert(p->data.type.length() - 1, ",pron");
							s = Loai_tu(p->data.type);
						}
						if(key == DEL)
						{
							p->data.type = " ";
							s = "";
							gotoxy(70, 4);
							Clear(32);
							gotoxy(68, 24);
							Clear(150);
						}
						gotoxy(70, 4);
						break;
					}
				}
				else if(key == BSP)
				{
					if(i != 0)
					{	
						gotoxy(79, 4 + i);
						cout<<"                         ";
						int l = 0;
						for(q = p->data.first; q != NULL; q = q->next)
						{
							l++;
							if(l == i)
							{
								q->mean = "";
							}
						}
						gotoxy(79, 4 + i);
					}	
				} 
				else if(i > 0 && i < count + 1)
				{
					gotoxy(79, 4 + i);
					cout<<"                         ";
					int l = 0;
					for(q = p->data.first; q != NULL; q = q->next)
					{
						l++;
						if(l == i)
						{
							q->mean = Nhap_dung(79, 4 + i, key);
							break;
						}
					}
					if(q->mean == "")
					{
						gotoxy(79, 4 + i);
					}
					else
					{
						gotoxy(79, 5 + i);
						i++;
					}
				}
				else if(i > count + 1)
				{
					gotoxy(79, 4 + i);
					cout<<"                         ";
					*p->data.examp[i - count - 2] = Nhap_dung(79, 4 + i, key);
					if(*p->data.examp[i - count - 2] == "")
					{
						gotoxy(79, 4 + i);
					}
					else
					{
						gotoxy(79, 5 + i);
						i++;
					}
				}
				else if(i == count + 1 && count < 10)
				{
					int l = i;
					gotoxy(70, 4 + i);
					cout<<"Nghia "<<i<<": ";
					gotoxy(70, count + 11);
					cout<<"                       ";
					i++;
					gotoxy(70, 4 + i);
					cout<<"                                  ";
					
					for(int k = 0; k < 5; k++)
					{
						DeleteColor();
						gotoxy(70, 5 + i);
						if(*p->data.examp[k] != "")
						{
							cout<<"Vi du "<<k + 1<<": ";
							for(int j = 0; j < (*p->data.examp[k]).length() && j < 22; j++)
							{
								cout<<(*p->data.examp[k])[j];
								if(j == 21)
								{
									cout<<"...";
								}
							}
						}
						else
						{
							cout<<"Vi du "<<k + 1<<": ";
						}
						i++;
					}
					count++;
					gotoxy(70, count + 11);
					SetColor();
					cout<<"Nhan Tab de luu.       ";
					DeleteColor();
					i = l;
					string s1 = Nhap_dung(79, 4 + i, key);
					chen_cuoiLKD(p->data.first,p->data.last,s1);
					gotoxy(79, 5 + i);
					i++;
				}
			}
			else if(key == ENTER && i == count + 1)
			{
				gotoxy(70, 4 + i);
				cout<<"Nghia "<< count + 1<<": ";
			}
			else if(key == 9)
			{
				p->data.temp = Noi_tu(p);
				Luufile();
				gotoxy(70, count + 11);
				cout<<"                        ";
				gotoxy(70, count + 11);
				SetColor();
				cout<<"Da luu.   ";
				DeleteColor();
				space(105, 125, 3, 3+12);
				DeleteColor();
				gotoxy(68, 24);
				Clear(150);
				return;
			}
			else if(key == 27)
			{
				gotoxy(68, 24);
				Clear(150);
				if(p->data.word == "" || p->data.type == "")
				{
					gotoxy(68, 24);
					cout<<"Khong The luu vi mot so truong con bo trong.";
					gotoxy(70, 4);
					i = 0;
				}
				else
				{
					DeleteColor();
					return;
				}
			}
		}
	}
	DeleteColor();
	space(105, 125, 3, 3+12);
	gotoxy(68, 24);
	Clear(150);
}

bool Kiem_tra(string chuoi)
{
	int l = (int)chuoi[0] - 97;
	node* p = tudien[l].head;
	if(p==NULL)return 1;
	if(p->data.word.compare(chuoi) == 0)return 0;
	for(; p != NULL&&p->right!=tudien[l].head; p = p->right)
	{
		if(p->data.word.compare(chuoi) == 0)
		{
			return 0;
		}
	}
	return 1;
}

node* Them_tu()
{
	Khung2();
	string chuoi;
	node *p = new node();
	p->left = NULL;
	p->right = NULL;
	DeleteColor();
	for(int i = 0; i < 5; i++)
	{
		p->data.examp[i] = new string();
	}
	gotoxy(80, 2);
	cout<<"THEM TU"<<endl;
	gotoxy(70, 3);
	cout<<"Tu moi: ";
	char key = _getch();
	chuoi = Nhap_dung1(78, 3, key);
	
	if(chuoi == "")
	{
		return NULL;
	}
	p->data.word = chuoi + " ";
	if(Kiem_tra(p->data.word) == 0)
	{
		gotoxy(70, 3);
		cout<<chuoi<<" da co trong tu dien";
		return tudien[(int)chuoi[0] - 97].head;
	}
	gotoxy(70, 4);
	cout<<"Loai tu: ";
	gotoxy(105, 3);
	cout<<"1: Danh tu";
	gotoxy(105, 4);
	cout<<"2: Dong tu";
	gotoxy(105, 5);
	cout<<"3: Tinh tu";
	gotoxy(105, 6);
	cout<<"4: Trang tu";
	gotoxy(105, 7);
	cout<<"5: Gioi tu";
	gotoxy(105, 8);
	cout<<"6: Lien tu";
	gotoxy(105, 9);
	cout<<"7: Dai tu";
	
	chuoi = "";
	string s = "";
	key = _getch();
	while(key != 27 && key != 13)
	{
		if(key == 49)
		{
			s = s.insert(s.length(), "n,");
			chuoi = Loai_tu(s);
		}
		if(key == 50)
		{
			s = s.insert(s.length(), "v,");
			chuoi = Loai_tu(s);
		}
		if(key == 51)
		{
			s = s.insert(s.length(), "adj,");
			chuoi = Loai_tu(s);
		}
		if(key == 52)
		{
			s = s.insert(s.length(), "adv,");
			chuoi = Loai_tu(s);
		}
		if(key == 53)
		{
			s = s.insert(s.length(), "prep,");
			chuoi = Loai_tu(s);
		}
		if(key == 54)
		{
			s = s.insert(s.length(), "conj,");
			chuoi = Loai_tu(s);
		}
		if(key == 55)
		{
			s = s.insert(s.length(), "pron,");
			chuoi = Loai_tu(s);
		}
		key = _getch();
	}
	p->data.type = s + " ";
	space(105, 125, 3, 3+12);
	
	p->data.first = NULL;
	p->data.last = NULL;
	gotoxy(70, 5);
	cout<<"Nghia 1: ";
	key = _getch();
	int i = 0;
	int count = 0;
	do
	{
		count++;
		chuoi = Nhap_dung(79, i + 5, key);
		if(chuoi != "")
		{
			chen_cuoiLKD(p->data.first, p->data.last, chuoi);
			i++;
			gotoxy(70, i + 5);
			cout<<"Nghia "<<i + 1<<": ";
			key = _getch();
		}
		if(chuoi == "")
		{
			chen_cuoiLKD(p->data.first, p->data.last, chuoi);
		}
	}
	while(chuoi != "");
	
	for(i = 0; i < 5; i++)
	{
		gotoxy(70, 6 + count + i);
		cout<<"Vi du "<<i + 1<<": ";
	}
	gotoxy(70, count + 11);
	cout<<"Nhan Tab de luu.       ";
	gotoxy(79, 6 + count);
	i = count + 2;
	
	nghia *q = p->data.first;
	while(true)
	{
		if(i < 0 || i > count + 6)
		{
			gotoxy(79, 4);
			i = 0;
		}
		char key = getch();
		if(key == DOWN)
		{
			i++;
			gotoxy(79, 4 + i);
		}
		else if(key == UP)
		{
			i--;
			gotoxy(79, 4 + i);
		}
		else if(key >= 97 && key <= 122 && i != count + 1)
		{
			if(i > 0 && i < count + 1)
			{
				gotoxy(79, 4 + i);
				cout<<"                        ";
				int l = 0;
				for(q = p->data.first; q != NULL; q = q->next)
				{
					l++;
					if(l == i)
					{
						q->mean = Nhap_dung(79, 4 + i, key);
						if(q->mean != "")
						{
							gotoxy(79, 5 + i);
							i++;
						}
					}
				}
			}
			else if(i > count + 1)
			{
				gotoxy(79, 4 + i);
				Clear (26);
				*p->data.examp[i - count - 2] = Nhap_dung(79, 4 + i, key);
				if(*p->data.examp[i - count - 2] != "")
				{
					gotoxy(79, 5 + i);
					i++;
				}
			}
			else
			{
				continue;
			}
		}
		else if(key == TAB)
		{
			p->data.temp = Noi_tu(p);
			chen_k(tudien[Ham_bam(p)].head, tudien[Ham_bam(p)].tail, p);
			gotoxy(70, count + 11);
			Clear(25);
			gotoxy(70, count + 11);
			cout<<"Da luu.";
			return p;
		}
		else if(key == ESC)
		{
			return tudien[Ham_bam(p)].head;
		}
	}
}

node* tim_tu(node *head, string word)
{
	bool flag = false;
	for(node *p = head; p != NULL; p = p->right)
	{
		string temp;
		temp = p->data.word;
		temp = temp.substr(0, word.length());
		if(temp.compare(word) == 0)
		{
			flag = true;
			return p;
		}
	}
	return NULL;
}

void Intu(node *p)
{
	if(p == NULL) return;
	int count = 0;
	int key;
	string s;
	for(;p != NULL && count <= 19;p = p->right)
	{
		gotoxy(21, count + 3);
		cout<<p->data.word;
		count++;
		key = (int)p->data.word[0];
	}
	gotoxy(0, 2);
	if(count <= 19)
	{
		int check = key - 97;
		int i = key - 97 + 1;
		for(; i <= 26 && count <= 19; i++)
		{
			while(i < 26 && tudien[i].head == NULL)
			{
				i++;
			}
			if(i == 26)
			{
				i = 0;
			}
			if( i == check)
			{
				return;
			}
			for(p = tudien[i].head;p!= NULL && count <= 19 && Ham_bam(p) == i && s.compare(p->data.word) != 0;p = p->right)
			{
				gotoxy(21, count + 3);
				cout<<p->data.word;
				s = p->data.word;
				count++;
			}
		}
	}
}

node* Input_word(char c)
{
	string word;
	int check = 0;
	int flag = 0;
	int dem = 0;
	node *head;
	gotoxy(30, 2);
	Clear(28);
	while (true)
	{
		if (c >= 97 && c <= 122)
		{
			if(check == 0)
			{
				gotoxy(30, 2);
				Clear(28);
			}
			gotoxy(30 + flag, 2);
			check = 1;
			cout << c;
			word.push_back(c);
			flag++;
			dem++;
			space(21, 40, 1, 30);
			if(flag == 1)
			{
				head = tudien[int(c) - 97].head;
				Intu(head);
				if(head == NULL)
				{
					gotoxy(21, 3);
					cout<<"Khong xuat hien tu can tra.";
				}
			}
			else
			{
				if(head != NULL)
				{
					for(node *p = head; p != NULL; p = p->right)
					{
						if(word.compare(p->data.word.substr(0, flag)) == 0)
						{
							Intu(p);
							break;
						}
						else if(word.compare(p->data.word.substr(0, flag)) != 0 && p->right == NULL)
						{
							gotoxy(21, 3);
							cout<<"Khong xuat hien tu can tra.";
							check = -1;
						}
					}
				}
				else
				{
					gotoxy(21, 3);
					cout<<"Khong xuat hien tu can tra.";
					check = -1;
				}
				gotoxy(30 + flag, 2);
			}
			if( word.length() > 28)
			{
				gotoxy(30, 2);
				Clear(29);
				gotoxy(30, 2);
				for (int i = dem - 28;i < word.length();i++)
				{
					cout << word[i];
				}
				flag--;
			}
		}
		else if (c == ENTER)
		{
			if (check == 0 || check == -1)
			{
				gotoxy(30, 2);
				Clear(29);
				gotoxy(30, 2);
				cout << "Moi Nhap Lai";
				check = 0;
				flag = 0;
				dem = 0;
				word = "";
			}
			else
			{
				node *p = tim_tu(head, word);
				if(word.length() < p->data.word.length() - 1)
				{
					return p;
				}
				Menu2(p);
				return p;
			}
		}
		else if(c == UP || c == DOWN)
		{
			if(word == "" || check == 0)
			{
				gotoxy(21, 3);
				Clear(29);
				gotoxy(30, 2);
				Clear(29);
				return(tudien[0].head);
			}
			else
			{
				node *p = tim_tu(head, word);
				gotoxy(30, 2);
				Clear(28);
				return p;
			}
		}
		else if (c == BSP && dem > 0)
		{
			word[dem-1]='\0';
			dem--;
			word = word.substr(0, dem);
			if (dem < 28)
			{
				gotoxy(30, 2);
				Clear(28);
				gotoxy(30,2);
				for (int i = 0;i < word.length();i++)
				{
					cout << word[i];
				}
				if(dem == 0)
				{
					word = "";
				}
			}
			if (dem >= 28)
			{
				gotoxy(30, 2);
				Clear(28);
				gotoxy(30, 2);
				for (int i = word.length() - 28;i < word.length();i++)
				{
					cout << word[i];
				}
			}
			int x = getX();
			flag = x - 30;
		}
		else if(c == INS || c == DEL || c == ESC)
		{
			gotoxy(30, 2);
			Clear(28);
			return NULL;
		}
		c = _getch();
	}
	return NULL;
}

void Menu1()
{
	if (KhoidongHT())
	{
		int checkrong[26];
		for(int i = 0; i < 26; i++)
		{
			node *p = tudien[i].head;
			if(p == NULL)
			{
				checkrong[i] = 0;
				continue;
			}
			for(;p != NULL;p = p->right)
			{
				checkrong[i] = 1;
				p->data.word = Cat_tu(p);
			}
		}
		Khung1();
		int k;
		for(int i = 0; i < 26; i++)
		{
			if(checkrong[i] == 1)
			{
				k = i;
				break;
			}
		}
		int i = 2;
		int flag = 1;
		char key;
		node *p = tudien[k].head;
		Intu(p);
		gotoxy(30, 2);
		while(true)
		{
			if(p->right == NULL)
			{
				k = Ham_bam(p);
				k++;
				if(k == 26)
				{
					k = 0;
				}
				while(tudien[k].head == NULL)
				{
					k++;
					if(k == 26)
					{
						k = 0;
					}
				}
				k--;
				tudien[++k].head->left = p;
				p->right = tudien[k].head;
			}
			
			if(p->left == NULL)
			{
				k = Ham_bam(p);
				int k1;
				if(k == 0)
				{
					k1 = 25;
					int check = 1;
					while(tudien[k1].head == NULL)
					{
						check = 0;
						k1--;
					}
				}
				else
				{
					k1 = k - 1;
					int check = 1;
					while(tudien[k1].head == NULL)
					{
						if(k1 < 1)
						{
							k1 = 25;
							if(tudien[k1].head == NULL)
							{
								k1--;
							}
						}
						else
						{
							check = 0;
							k1--;
						}
					}
				}
				tudien[k].head->left = tudien[k1].tail;
				tudien[k1].tail->right = tudien[k].head;
			}
			if(i > 22 || i < 2)
			{
				DeleteColor();
				space(21, 40, 1, 30);
				Intu(p);
				gotoxy(30, 2);
				i = 2;
			}
			if(flag == 1)
			{
				key = getch();
			}
			if(key == F1)
			{
				int x = getX();
				int y = getY();
				HD();
				gotoxy(x, y);
			}
			else if(key == DOWN && i >= 2)
			{
				i++;
				if(i > 3)
				{
					DeleteColor();
					gotoxy(21, i - 1);
					cout<<p->left->data.word<<endl;
				}
				if(i == 3)
				{
					DeleteColor();
					gotoxy(21, 2);
					cout<<"Tra cuu: ";
				}
				if(i < 23)
				{
					SetColor();
					gotoxy(21, i);
					cout<<p->data.word;
					p = p->right;
					flag = 1;
				}
				
			}
			else if(key == UP)
			{
				i--;
				p = p->left;
				if(p != NULL && i >= 2)
				{
					DeleteColor();
					gotoxy(21, i + 1);
					cout<<p->data.word<<endl;
					gotoxy(21 + p->left->data.word.length(), i);
					if(i == 2)
					{
						SetColor();
						gotoxy(21, 2);
						cout<<"Tra cuu: ";
						gotoxy(30, 2);
					}
				}
				if(p->left!=NULL && i > 2)
				{
					SetColor();
					gotoxy(21, i);
					cout<<p->left->data.word<<endl;
					gotoxy(21 + p->left->data.word.length(), i);
				}
			}
			else if(key == ENTER && i != 2)
			{
				int x = getX();
				int y = getY();
				Menu2(p->left);
				gotoxy(x, y);
			}
			else if(key >=  97 && key <= 122 && i == 2)
			{
				SetColor();
				gotoxy(21, 2);
				cout<<"Tra cuu: ";
				DeleteColor();
				p = Input_word((char)key);
				if(p == NULL)
				{
					p = tudien[k].head;
					gotoxy(21,3);
					Clear(30);
					Intu(p);
				}
				else
				{
					Intu(p);
					k = Ham_bam(p);
				}
				key = DOWN;
				flag = 0;
			}	
			else if(key == INS)
			{
				space(69, 69+15, 3, 37);
				p = Them_tu();
				if(p == NULL)
				{
					p = tudien[k].head;
					Intu(p);
				}
				else
				{
					Luufile();
					int l = Ham_bam(p);
					space(21, 40, 1, 30);
					Intu(tudien[l].head);
					p = tudien[l].head;
					k = l;
				}
				i = 2;
				gotoxy(30, 2);
			}
			else if(key == DEL)
			{
				int x = getX();
				int y = getY();
				space(69, 69+15, 3, 37);
				if(i == 2)
				{
					gotoxy(70,4);
					cout<<"CHON TU CAN XOA TRUOC"<<endl;
				}
				else
				{
					DeleteColor();
					gotoxy(70,4);
					cout<<"BAN MUON XOA TU: "<<p->left->data.word<<endl;
					gotoxy(70,5);
					cout<<"Nhan Y de tiep tuc.";
					char c = getch();
					if(int(c) == 121)
					{
						int l = Ham_bam(p->left);
						if(p->left->data.word.compare(tudien[l].head->data.word) == 0)
						{
							Xoa_dau(tudien[l].head, tudien[l].tail);
						}
						else if(p->left->data.word.compare(tudien[l].tail->data.word) == 0)
						{
							Xoa_cuoi(tudien[l].head, tudien[l].tail);
						}
						else
						{
							Xoa_k(p->left->left);
						}
						space(21, 40, 1, 30);
						p = tudien[l].head;
						Intu(tudien[l].head);
						i = 2;
						space(69, 69+15, 3, 37);
						gotoxy(30, 2);
						/*if(BoNhoTrong)
						{
							ofstream file;
							file.open("test2.txt",ios::out|iostrunc);
							file<<"";
							file.close();
							Menu1();
							return;
						}
						else*/
						Luufile();
						//break;
					}
					else
					{
						gotoxy(70,4);
						Clear(30);
						gotoxy(70,5);
						Clear(30);
						gotoxy(x, y);
					}
				}
			}
			else if(key == ESC)
			{
				Luufile();
				return;
			}
		}
	}
	else 
	{
		node *p = Them_tu();
		Luufile();
		gotoxy(0, 0);
		Clear(150);
		Menu1();
	}
}

int main()
{
	Menu1();
	DeleteColor();
	gotoxy(0, 100);
	return 0;
}



