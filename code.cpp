#include<iostream>
#include<string>
#include<memory>
#include<fstream>
#include <conio.h> 
#include <time.h>
#include <sys/timeb.h>  
#include <thread>         
#include<Windows.h>
using namespace std;

/*********************************ƴ��ƥ��****************************************/

const int Max_size = 1e3;//���Բ���1000��,300�͹�
string hashs[Max_size][Max_size];//ƴ����hashs��

__declspec (naked) unsigned __int64 GetCpuCycle(void)
{
	_asm
	{
		rdtsc
		ret
	}
}

//��������
void NAME(string& name, string& phone1)
{



	const char* NA1[444] = { "��", "Ǯ", "��", "��", "��", "��", "֣", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʩ", "��", "��", "��", "��", "��", "��", "κ", "��", "��", "��", "л", "��", "��", "��", "ˮ", "�", "��", "��", "��", "��", "��", "��", "��", "��", "��", "³", "Τ", "��", "��", "��", "��", "��", "��", "��", "��", "Ԭ", "��", "ۺ", "��", "ʷ", "��", "��", "��", "�", "Ѧ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʱ", "��", "Ƥ", "��", "��", "��", "��", "��", "Ԫ", "��", "��", "��", "ƽ", "��", "��", "��", "��", "��", "Ҧ", "��", "տ", "��", "��", "ë", "��", "��", "��", "��", "��", "�", "��", "��", "��", "��", "̸", "��", "é", "��", "��", "��", "��", "��", "��", "ף", "��", "��", "��", "��", "��", "��", "ϯ", "��", "��", "ǿ", "��", "·", "¦", "Σ", "��", "ͯ", "��", "��", "÷", "ʢ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "֧", "��", "��", "��", "¬", "Ī", "��", "��", "��", "��", "��", "��", "Ӧ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʯ", "��", "��", "ť", "��", "��", "��", "��", "��", "��", "½", "��", "��", "��", "��", "�", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ɽ", "��", "��", "��", "�", "��", "ȫ", "ۭ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ղ", "��", "��", "Ҷ", "��", "˾", "��", "۬", "��", "��", "��", "ӡ", "��", "��", "��", "��", "ۢ", "��", "��", "��", "��", "��", "��", "׿", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "˫", "��", "ݷ", "��", "��", "̷", "��", "��", "��", "��", "��", "��", "��", "Ƚ", "��", "۪", "Ӻ", "��", "�", "ɣ", "��", "�", "ţ", "��", "ͨ", "��", "��", "��", "��", "ۣ", "��", "��", "ũ", "��", "��", "ׯ", "��", "��", "��", "��", "��", "Ľ", "��", "��", "ϰ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "»", "��", "��", "Ź", "�", "��", "��", "ε", "Խ", "��", "¡", "ʦ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ɳ", "ؿ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "Ȩ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "۳", "Ϳ", "��", "��", "��", "��", "˧", "��", "��", "��", "��", "��", "��", "��", "Ĳ", "��", "٦", "��", "��", "ī", "��", "��", "��", "��", "��", "��", "١", "��", "��" };

	//�ټ���-����
	const char* NA2[59] = { "��ٹ", "˾��", "�Ϲ�", "ŷ��", "�ĺ�", "���", "����", "����", "����", "�ʸ�", "ξ��", "����", "�̨", "��ұ", "����", "���", "����", "����", "̫��", "����", "����", "����", "��ԯ", "���", "����", "����", "����", "Ľ��", "����", "����", "˾ͽ", "˾��", "����", "˾��", "�ӳ�", "���", "��ľ", "����", "����", "���", "����", "����", "����", "�ذ�", "�й�", "�׸�", "����", "����", "����", "����", "����", "����", "΢��", "����", "����", "����", "����", "�Ϲ�", "����" };

	//���Գ�����
	const char* ME1m[140] = { "ΰ", "��", "��", "��", "��", "��", "ǿ", "��", "ƽ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "־", "��", "��", "��", "��", "ɽ", "��", "��", "��", "��", "��", "��", "��", "Ԫ", "ȫ", "��", "ʤ", "ѧ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "˳", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ï", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "׳", "��", "˼", "Ⱥ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ԣ", "��", "��", "��", "��", "��", "��", "��", "ǫ", "��", "��", "��", "֮", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ά", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʿ", "��", "��", "��", "��", "��", "��", "��", "��", "ʱ", "̩", "ʢ" };
	const char* ME2m[140] = { "ΰ", "��", "��", "��", "��", "��", "ǿ", "��", "ƽ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "־", "��", "��", "��", "��", "ɽ", "��", "��", "��", "��", "��", "��", "��", "Ԫ", "ȫ", "��", "ʤ", "ѧ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "˳", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ï", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "׳", "��", "˼", "Ⱥ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ԣ", "��", "��", "��", "��", "��", "��", "��", "ǫ", "��", "��", "��", "֮", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ά", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ʿ", "��", "��", "��", "��", "��", "��", "��", "��", "ʱ", "̩", "ʢ" };


	//Ů�Գ�����
	const char* ME1f[165] = { "��", "��", "Ӣ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "֥", "��", "Ƽ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "÷", "��", "��", "��", "��", "��", "��", "ѩ", "��", "��", "��", "ϼ", "��", "��", "ݺ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "�", "Ҷ", "�", "�", "�", "��", "��", "��", "��", "��", "ɺ", "ɯ", "��", "��", "��", "ٻ", "��", "�", "��", "�", "�", "ӱ", "¶", "��", "��", "�", "��", "��", "��", "��", "��", "��", "��", "ü", "��", "��", "��", "ޱ", "ݼ", "��", "�", "Է", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ܿ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "Ӱ", "��", "֦", "˼", "��", "��", "Ʈ", "��", "�", "��", "��", "��", "��", "��", "ɺ", "ɯ", "��", "��", "��", "ٻ", "��", "��", "��", "��", "Է", "�", "ܰ", "�", "��", "��", "��", "԰", "��", "ӽ", "��", "��", "��", "��", "ع", "��", "��", "��", "ˬ", "��", "��", "��", "ϣ" };
	const char* ME2f[165] = { "��", "��", "Ӣ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "֥", "��", "Ƽ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "÷", "��", "��", "��", "��", "��", "��", "ѩ", "��", "��", "��", "ϼ", "��", "��", "ݺ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "�", "Ҷ", "�", "�", "�", "��", "��", "��", "��", "��", "ɺ", "ɯ", "��", "��", "��", "ٻ", "��", "�", "��", "�", "�", "ӱ", "¶", "��", "��", "�", "��", "��", "��", "��", "��", "��", "��", "ü", "��", "��", "��", "ޱ", "ݼ", "��", "�", "Է", "��", "��", "��", "��", "��", "��", "��", "��", "��", "ܿ", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "Ӱ", "��", "֦", "˼", "��", "��", "Ʈ", "��", "�", "��", "��", "��", "��", "��", "ɺ", "ɯ", "��", "��", "��", "ٻ", "��", "��", "��", "��", "Է", "�", "ܰ", "�", "��", "��", "��", "԰", "��", "ӽ", "��", "��", "��", "��", "ع", "��", "��", "��", "ˬ", "��", "��", "��", "ϣ" };
	unsigned __int64 iCpuCycle = GetCpuCycle();
	srand(time(0));
	unsigned srnd = (unsigned)iCpuCycle;

	srand(srnd);
	char phone[12] = "0";
	char p1[45][4] = {
		"174", "177", "180", "181",
		"189", "199",
		"130", "131", "132", "145",
		"155", "156", "166", "171",
		"175", "176", "185", "186",
		"134", "135", "136", "137",
		"138", "139", "147", "148",
		"150", "151", "152", "157",
		"158", "159", "172", "178",
		"182", "183", "184", "187",
		"178", "188", "198"
	};

	strcpy_s(phone, p1[rand() % 45]);
	for (int i = 3; i < 11; i++)
		phone[i] = rand() % 10 + '0';
	phone[11] = '\0';
	phone1 = phone;
	int control = rand() % 8 + 1;
	int NA1Roll = rand() % 444;//����
	int NA2Roll = rand() % 59;//����
	int ME1mRoll = rand() % 140;//����
	int ME2mRoll = rand() % 140;//����
	int ME1fRoll = rand() % 165;//Ů��
	int ME2fRoll = rand() % 165;//Ů��

	switch (control)
	{
	case 8:
		name = name + NA1[NA1Roll] + ME1m[ME1mRoll]; break;
	case 1:
		name = name + NA1[NA1Roll] + ME1f[ME1fRoll]; break;
	case 2:
		//����˫����
		name = name + NA1[NA1Roll] + ME1m[ME1mRoll] + ME1m[ME2mRoll]; break;
	case 3:
		//����˫��Ů
		name = name + NA1[NA1Roll] + ME1f[ME1fRoll] + ME1f[ME2fRoll]; break;
	case 4:
		//���յ�����
		name = name + NA2[NA2Roll] + ME1m[ME1mRoll]; break;
	case 5:
		//���յ���Ů
		name = name + NA2[NA2Roll] + ME1f[ME1fRoll]; break;
	case 6:
		//����˫����
		name = name + NA2[NA2Roll] + ME1m[ME1mRoll] + ME2m[ME2mRoll]; break;
	case 7:
		//����˫��Ů
		name = name + NA2[NA2Roll] + ME1f[ME1fRoll] + ME2f[ME2fRoll]; break;
	default:
		break;
	}

}

//д���ݵ��ļ�
void Data(int num) {
	ofstream ofs;
	ofs.open("D:\\people.txt", ios::out);
	for (int i = 0; i < num; i++) {
		string phone;
		string name;
		NAME(name, phone);

		for (int i = 0; i < 10000; i++) {};
		//cout << name << " " << phone << endl;
		if (name.length() && phone.length())
			ofs << name << " " << phone << endl;
	}
	ofs.close();
}

//ƴ��˳���
struct StringList {
	string* item;
	int capacity;
	int length;

	//���캯��
	StringList(int c = 10) {
		capacity = c;
		length = 0;
		item = new string[capacity];
	}

	//���Ԫ��
	void append(string s) {
		if (length == capacity) {
			capacity += 10;
			item = new string[capacity];
		}
		item[length++] = s;
	}

	//����ָ��λ��index��Ԫ��
	string getItem(int index) {
		return item[index];
	}

	//��ʾȫ��Ԫ��
	void show() {
		for (int i = 0; i < length; i++) {
			cout << item[i] << " ";
		}
		cout << endl;
	}

};

//��ʼ��hashsƴ�����
void initHashMap() {
	string str;
	ifstream inf;
	//d�̱���ΪANSI�����ʽ
	inf.open("D://yinjie.txt");
	while (getline(inf, str)) {
		//cout << str << endl;
		int a1 = str[0];
		int a0 = str[1];
		a1 = -a1;
		a0 = -a0;
		string str1;

		str1 = str.substr(2, str.length() - 2);
		string str3 = str1;
		hashs[a1][a0] = str3;
	}
	inf.close();
}

//���뺺�ֵõ�ȫ��ƴ���ַ���
string getYinJie(string s) {
	int a1 = s[0];
	int a0 = s[1];
	a1 = -a1;
	a0 = -a0;
	return hashs[a1][a0];
}

//��ϵ��˳���
struct PeopleList
{
	string name[1000];
	string phone[1000];
	int length = 0;

	//����
	void createList(const string& filename) {
		ifstream in(filename);
		string line;
		string str1;
		string str2;
		int i, j;
		if (in) // �и��ļ�
		{
			while (getline(in, line)) // line�в�����ÿ�еĻ��з�
			{
				str1 = ""; str2 = "";
				int pos = 0;
				for (int i = 0; i < line.length(); i++) {
					if (line[i] == ' ') {
						pos = i;
					}
				}
				str1 = line.substr(0, pos);
				str2 = line.substr(pos + 1, line.length() - pos);
				name[length] = str1;
				phone[length] = str2;
				length++;
			}
		}
		else // û�и��ļ�
		{
			cout << "no such file" << endl;
		}

	}

	//��arr[l...r]����partition���� 
	int  partition(int l, int r)
	{
		string xing = getYinJie(name[l].substr(0, 2));
		string ming = getYinJie(name[l].substr(2, 2));

		int j;
		j = l;
		for (int i = l + 1; i <= r; i++)
		{

			string xtemp = getYinJie(name[i].substr(0, 2));
			string mtemp = getYinJie(name[i].substr(2, 2));


			if (xtemp[0] < xing[0])
			{
				swap(name[j + 1], name[i]);
				swap(phone[j + 1], phone[i]);
				j++;
			}
			/*if (strcmp(xtemp.c_str(), xing.c_str()) < 0)
			{
				swap(name[j + 1], name[i]);
				swap(phone[j + 1], phone[i]);
				j++;
			}*/
			if (xtemp[0] == xing[0])
				if (mtemp[0] < ming[0])
				{
					swap(name[j + 1], name[i]);
					swap(phone[j + 1], phone[i]);
					j++;
				}

		}

		swap(name[l], name[j]);
		swap(phone[l], phone[j]);
		return j;

	}

	//��arr[l...r]���ֽ�������(�ݹ�)
	void __quicksort(int l, int r)
	{
		if (l >= r)
			return;

		int p = partition(l, r);
		__quicksort(l, p - 1);
		__quicksort(p + 1, r);
	}

	//��������ӿ�
	void quicksort()
	{
		__quicksort(0, length - 1);
	}

};

//�õ�ĳ���ַ����ַ����еڼ��γ��ֵ�λ��
int IndexOf(string s1, char s, int index) {
	int i = index;
	for (; i < s1.length(); i++) {
		if (s1[i] == s) return i;
	}
	if (i >= s1.length()) return -1;
}

//��������������ȡ���ڸ��������еڼ��㿪ʼ�ж�ÿ����������ĸ˳��
int startFloorIndex = -1;

//����ƥ�亯��,ȷ��pyItem.getItem(n)[0]������˳�����
//��ֹguan yu changƥ��gc(������yu�ﵽƥ����������)
bool keyMatch(string search, StringList pyItem, int yinjieIndex) {
	int lastIndex = 0;
	int i;//i����ʼ�Ĳ���
	for (i = startFloorIndex; i < yinjieIndex + startFloorIndex; i++) {
		lastIndex = IndexOf(search, pyItem.getItem(i)[0], lastIndex);
		if (lastIndex == -1) return false;
		lastIndex++;
	}
	return true;
}

//ƥ���㷨(�ݹ����)
bool Match(string search, int searchIndex, StringList pyItem, int yinjieIndex, int yinjieStart) {
	//���if�ǹ涨��һ������ĸ����ƥ���һ��ƥ�䷽��������yc��ƥ�䲻��gyc��
	//if (searchIndex == 0)//����������search[]�ĵ�һ����ĸλ��
	//	//��һ������ƥ��&&���ֻ��һ���ַ�����ƥ��ɹ�������ӵڶ����ַ���ʼ�Ƚ�,������һ��ݹ�
	//	return search[0] == pyItem.getItem(0)[0] && (search.length() == 1 || Match(search, 1, pyItem, 0, 1));

	//���ﴦ�����guan yun chang��yc����ƥ�䣬c����ƥ��
	if (searchIndex == 0) {
		if (yinjieIndex > pyItem.length - 1) return false;
		startFloorIndex++;
		return search[0] == pyItem.getItem(yinjieIndex)[0] ? Match(search, 1, pyItem, yinjieIndex, 1) : Match(search, 0, pyItem, yinjieIndex + 1, 0);
	}
	//�жϲ�Խ��&&�ж�ƥ��
	if (pyItem.getItem(yinjieIndex).length() > yinjieStart && search[searchIndex] == pyItem.getItem(yinjieIndex)[yinjieStart])
		//����������һ���ַ������֮ǰ����ĸ�Ƿ����γ���
		//����������һ���ַ���ͬһ���ֵ�ƴ������ƥ��
		return searchIndex == search.length() - 1 ? keyMatch(search, pyItem, yinjieIndex) : Match(search, searchIndex + 1, pyItem, yinjieIndex, yinjieStart + 1);
	//�жϲ�Խ��&&����ƴ������ƥ�������£�������һ���ֵ�ƴ��������ĸ�ܷ�ƥ��
	else if (pyItem.length > yinjieIndex + 1 && search[searchIndex] == pyItem.getItem(yinjieIndex + 1)[0])
		//����������һ���ַ������֮ǰ����ĸ�Ƿ����γ���
		//����������һ���ַ���ȥ�ж���һ����ƴ���ĵڶ�����ĸ
		return searchIndex == search.length() - 1 ? keyMatch(search, pyItem, yinjieIndex) : Match(search, searchIndex + 1, pyItem, yinjieIndex + 1, 1);
	else if (pyItem.length > yinjieIndex + 1)//����
		for (int i = 1; i < searchIndex; i++)
			if (Match(search, searchIndex - i, pyItem, yinjieIndex + 1, 0)) return true;
	//return false;
	return true;
}

//����ȫƴ��ģ��ƥ��(�����������)
bool PinyinMatch(string search, string name) {
	StringList pinyinItem;
	for (int i = 0; i < name.length(); i += 2) {
		string s = getYinJie(name.substr(i, 2));//��ƴ�����л�������ַ���
		//cout << s.length() << endl;//��֤һ�´��ȥ���ַ�������,�Ƿ�ض�
		int pos = 0;
		for (int j = 0; j < s.length(); j++) {
			//�ж��Ƿ��пո����ﲻ���Ƕ����֣�ֱ���ڵ�һ���ո񴦽ض�ȡ��һ������
			if (s[j] == ' ') { pos = j; break; }
		}
		if (pos == 0) pinyinItem.append(s);//�����ո�ֱ�Ӵ���pinyinItem[]
		else {
			string yinjie = s.substr(0, pos);//���ո񣬽ض��Ժ����pinyinItem[]
			pinyinItem.append(yinjie);
		}
	}
	//pinyinItem.show();//������ڱ����

	//����ƥ������㷨
	if (Match(search, 0, pinyinItem, 0, 0) == true) return true;//���ƥ���㷨ͨ������Ϊ������¼ƥ��ͨ��������true
	return false;//ƥ��δͨ������false

	//���κ����㷨����pyItem��ֱ��return true
	//return true;
}

//����ȫƴ��ģ��ƥ��(���������)
//����ʵ�����������ƥ���ǰ�᣺
//1.ƥ�������ֵ����֡�
//2.������ֻ��һ�������֡�
//3.�����������4��������
bool PinyinMatchPolyphone(string search, string name) {
	if (name.length() / 2 == 2) {
		int polyCount[2];//ÿ���ֵĶ�����
		int maxCount = 1;//��������
		string duoyin[2][4];//ÿ���ֵĶ�Ӧ���ڱ����硰���Ƴ��������ɱ� |ding zheng \0 \0|yun \0 \0 \0|zhang chang \0 \0|
		memset(polyCount, 0, sizeof(polyCount));//��ʼȫ����Ϊ0
		for (int i = 0; i < name.length(); i += 2) {
			string s = getYinJie(name.substr(i, 2));//��ƴ�����л�������ַ���
			//ѭ��ɨ������ڣ��ж��м�������
			int count = 1;//ÿ����������һ������
			for (int j = 0; j < s.length(); j++) {
				//�ж��Ƿ��пո������һ���ո񣬶�����+1
				if (s[j] == ' ') {
					count++;
				}
			}
			if (count > maxCount) maxCount = count;

			//���polyCount[]
			polyCount[i / 2] = count;

			//���duoyin[][]
			if (count == 1) duoyin[i / 2][0] = s;
			else
			{
				int start = 0, end = 0, pos = 0;
				for (int k = 0; k < count; k++) {
					for (; pos < s.length(); pos++) {
						if (s[pos] == ' ') {
							end = pos;
							duoyin[i / 2][k] = s.substr(start, end - start);
							start = end + 1;
							pos++;
							break;
						}
						//�������һ��λ��
						if (pos == s.length() - 1) {
							duoyin[i / 2][k] = s.substr(start, s.length() - start);
						}
					}
				}
			}

		}


		//������ָ�롱����¼���������λ��
		for (int p2 = 0; p2 < polyCount[1]; p2++) {
			int p1 = 0;
			for (; p1 < polyCount[0]; p1++) {
				StringList pinyinItem;
				pinyinItem.append(duoyin[0][p1]);
				pinyinItem.append(duoyin[1][p2]);
				startFloorIndex = -1;
				if (Match(search, 0, pinyinItem, 0, 0)) return true;
			}
		}
	}

	if (name.length() / 2 == 3) {
		int polyCount[3];//ÿ���ֵĶ�����
		int maxCount = 1;//��������
		string duoyin[3][4];//ÿ���ֵĶ�Ӧ���ڱ����硰���Ƴ��������ɱ� |ding zheng \0 \0|yun \0 \0 \0|zhang chang \0 \0|
		memset(polyCount, 0, sizeof(polyCount));//��ʼȫ����Ϊ0
		for (int i = 0; i < name.length(); i += 2) {
			string s = getYinJie(name.substr(i, 2));//��ƴ�����л�������ַ���
			//ѭ��ɨ������ڣ��ж��м�������
			int count = 1;//ÿ����������һ������
			for (int j = 0; j < s.length(); j++) {
				//�ж��Ƿ��пո������һ���ո񣬶�����+1
				if (s[j] == ' ') {
					count++;
				}
			}
			if (count > maxCount) maxCount = count;

			//���polyCount[]
			polyCount[i / 2] = count;

			//���duoyin[][]
			if (count == 1) duoyin[i / 2][0] = s;
			else
			{
				int start = 0, end = 0, pos = 0;
				for (int k = 0; k < count; k++) {
					for (; pos < s.length(); pos++) {
						if (s[pos] == ' ') {
							end = pos;
							duoyin[i / 2][k] = s.substr(start, end - start);
							start = end + 1;
							pos++;
							break;
						}
						//�������һ��λ��
						if (pos == s.length() - 1) {
							duoyin[i / 2][k] = s.substr(start, s.length() - start);
						}
					}
				}
			}

		}

		//����ÿ�����ֵĶ����������������
		//cout << maxCount << endl;
		/*for (int i = 0; i < 3; i++) cout << polyCount[i];
		cout << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++)
				cout << duoyin[i][j] << " ";
			cout << endl;
		}*/

		//���Զ���
		/*for (int i = 0; i < polyCount[0]; i++) {
			StringList pinyinItem;
			pinyinItem.append(duoyin[0][i]);
			pinyinItem.append(duoyin[1][0]);
			pinyinItem.append(duoyin[2][0]);
			pinyinItem.show();
			if (Match(search, 0, pinyinItem, 0, 0)) return true;
		}*/

		//ѭ������pinyinItem,ƥ�����
		//������ָ�롱����¼���������λ��
		for (int p2 = 0; p2 < polyCount[1]; p2++) {
			int p1 = 0;
			for (; p1 < polyCount[0]; p1++) {
				int p3 = 0;
				for (; p3 < polyCount[2]; p3++) {
					StringList pinyinItem;
					pinyinItem.append(duoyin[0][p1]);
					pinyinItem.append(duoyin[1][p2]);
					pinyinItem.append(duoyin[2][p3]);
					//pinyinItem.show();
					startFloorIndex = -1;
					if (Match(search, 0, pinyinItem, 0, 0)) return true;
				}
			}
		}
	}

	if (name.length() / 2 == 4) {
		int polyCount[4];//ÿ���ֵĶ�����
		int maxCount = 1;//��������
		string duoyin[4][4];//ÿ���ֵĶ�Ӧ���ڱ����硰���Ƴ��������ɱ� |ding zheng \0 \0|yun \0 \0 \0|zhang chang \0 \0|
		memset(polyCount, 0, sizeof(polyCount));//��ʼȫ����Ϊ0
		for (int i = 0; i < name.length(); i += 2) {
			string s = getYinJie(name.substr(i, 2));//��ƴ�����л�������ַ���
			//ѭ��ɨ������ڣ��ж��м�������
			int count = 1;//ÿ����������һ������
			for (int j = 0; j < s.length(); j++) {
				//�ж��Ƿ��пո������һ���ո񣬶�����+1
				if (s[j] == ' ') {
					count++;
				}
			}
			if (count > maxCount) maxCount = count;

			//���polyCount[]
			polyCount[i / 2] = count;

			//���duoyin[][]
			if (count == 1) duoyin[i / 2][0] = s;
			else
			{
				int start = 0, end = 0, pos = 0;
				for (int k = 0; k < count; k++) {
					for (; pos < s.length(); pos++) {
						if (s[pos] == ' ') {
							end = pos;
							duoyin[i / 2][k] = s.substr(start, end - start);
							start = end + 1;
							pos++;
							break;
						}
						//�������һ��λ��
						if (pos == s.length() - 1) {
							duoyin[i / 2][k] = s.substr(start, s.length() - start);
						}
					}
				}
			}

		}

		//����ÿ�����ֵĶ����������������
		//cout << maxCount << endl;
		/*for (int i = 0; i < 3; i++) cout << polyCount[i];
		cout << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++)
				cout << duoyin[i][j] << " ";
			cout << endl;
		}*/

		//���Զ���
		/*for (int i = 0; i < polyCount[0]; i++) {
			StringList pinyinItem;
			pinyinItem.append(duoyin[0][i]);
			pinyinItem.append(duoyin[1][0]);
			pinyinItem.append(duoyin[2][0]);
			pinyinItem.show();
			if (Match(search, 0, pinyinItem, 0, 0)) return true;
		}*/

		//ѭ������pinyinItem,ƥ�����
		//�ĸ���ָ�롱����¼�Ĳ������λ��
		for (int p2 = 0; p2 < polyCount[1]; p2++) {
			int p1 = 0;
			for (; p1 < polyCount[0]; p1++) {
				int p3 = 0;
				for (; p3 < polyCount[2]; p3++) {
					int p4 = 0;
					for (; p4 < polyCount[3]; p4++) {
						StringList pinyinItem;
						pinyinItem.append(duoyin[0][p1]);
						pinyinItem.append(duoyin[1][p2]);
						pinyinItem.append(duoyin[2][p3]);
						pinyinItem.append(duoyin[3][p4]);
						//pinyinItem.show();
						startFloorIndex = -1;
						if (Match(search, 0, pinyinItem, 0, 0)) return true;
					}
				}
			}
		}
	}

	return false;

}


/*********************************Ӣ��ƥ��****************************************/
struct Node {
	string name;                    //����
	string phone;                   //����
	int getNameLength() {
		return 2;
	}

	//�洢ÿһ��Ӣ�ĵ�˳���
	StringList getnameItemList() {
		StringList nameItemList;
		for (int i = 0; i < name.length(); i++) {
			if (name[i] == ' ') {
				string strin = name.substr(0, i);
				nameItemList.append(strin);
				string strin2 = name.substr(i + 1, name.length() - i);
				nameItemList.append(strin2);
				break;
			}

		}
		return nameItemList;
	}
	//�洢ÿһ��Сдƴ����˳���
	StringList getSmallItemList() {
		int nameLength = getNameLength();
		StringList pinYinItemList;
		StringList nameItemList = getnameItemList();
		for (int i = 0; i < nameLength; i++) {
			string items = nameItemList.item[i];
			for (auto& c : items) {
				c = tolower(c);
			}
			pinYinItemList.append(items);
		}
		return pinYinItemList;
	}
	/*
	void showHanZhi() {
		int nameLength = getNameLength();
		StringList nameItemList = getnameItemList();
		for (int i = 0; i < nameLength; i++) {
			cout << nameItemList.item[i] << " ";
		}
		cout << endl;
	}

	void showPinYin() {
		int nameLength = getNameLength();
		StringList pinYinItemList = getSmallItemList();
		for (int i = 0; i < nameLength; i++) {
			cout << pinYinItemList.item[i] << " ";
		}
		cout << endl;
	}
	*/
};

//���������Ϣ���Ϊ�����͵绰������
//str���ܵ��ַ������飬nΪ���鳤��
Node* getNode(string* str, int n) {
	Node* node;
	node = new Node[n];
	for (int i = 0; i < n; i++) {
		int pos;
		for (int j = 0; j < str[i].length(); j++) {
			if (str[i][j] == ',') {
				pos = j;
			}
		}
		string str1, str2;
		str1 = str[i].substr(0, pos);
		str2 = str[i].substr(pos + 1, str[i].length() - pos);
		node[i].name = str1;
		node[i].phone = str2;
	}
	return node;
}

//��һ�����ַ���ת��Ϊһ���ַ�����˳���
StringList getEnglishList(string yinjie) {
	StringList EnglishList;
	//cout << yinjie;
	int pos1 = 0;
	int pos2 = 0;
	int flag = 0;
	for (int i = 1; i < yinjie.length(); i++) {
		pos2++;

		if (yinjie[i] >= 'A' && yinjie[i] <= 'Z') {
			flag = 1;
			string str1 = yinjie.substr(0, i);
			for (auto& c : str1) {
				c = tolower(c);
			}
			string str2 = yinjie.substr(i, yinjie.length() - 1);
			for (auto& c : str2) {
				c = tolower(c);
			}
			EnglishList.append(str1);
			EnglishList.append(str2);
		}
	}
	if (!flag) {
		for (auto& c : yinjie) {
			c = tolower(c);
		}
		EnglishList.append(yinjie);
	}
	return EnglishList;
}

//��ö�Ӧ���ڵ������͵绰
void getNameAndPhone(Node* node, StringList yinJieList, int len) {
	for (int i = 0; i < len; i++) {                                    //���������ڴ�
		int flag = 0;
		if (yinJieList.length == 2) {
			for (int j = 0; j < yinJieList.length; j++) {                //������������
				for (int k = 0; k < yinJieList.item[j].length(); k++) {  //�Ա�ÿ��Ԫ��
					StringList pinYinItemList = node[i].getSmallItemList();
					char cinPinYinItem = yinJieList.item[j][k];
					char neiChunPinYinItem = pinYinItemList.item[j][k];
					if (cinPinYinItem != neiChunPinYinItem) {
						flag = 1;
						break;
					}
				}
				if (flag) {
					break;
				}
			}
		}
		else {
			int flag1 = 0;
			int flag2 = 0;
			for (int k = 0; k < yinJieList.item[0].length(); k++) {  //�Ա�ÿ��Ԫ��
				StringList pinYinItemList = node[i].getSmallItemList();
				char cinPinYinItem = yinJieList.item[0][k];
				char neiChunPinYinItem = pinYinItemList.item[0][k];
				if (cinPinYinItem != neiChunPinYinItem) {
					flag1 = 1;
					break;
				}
			}
			for (int k = 0; k < yinJieList.item[0].length(); k++) {  //�Ա�ÿ��Ԫ��
				StringList pinYinItemList = node[i].getSmallItemList();
				char cinPinYinItem = yinJieList.item[0][k];
				char neiChunPinYinItem = pinYinItemList.item[1][k];
				if (cinPinYinItem != neiChunPinYinItem) {
					flag2 = 1;
					break;
				}
			}
			if (flag1 && flag2) {
				flag = 1;
			}
		}
		if (!flag) {
			cout << node[i].name << "," << node[i].phone << endl;
		}
	}
}

StringList getHZFGYinJieList(string yinjie, int& flag) {
	StringList yinJieList;
	for (auto& c : yinjie) {
		c = tolower(c);
	}
	//cout << yinjie;
	int pos1 = 0;
	int pos2 = 0;


	for (int i = 0; i < yinjie.length(); i++) {
		pos2++;
		
		if (yinjie[i] < 'a' || yinjie[i] > 'z' || (i == yinjie.length() - 1)) {
			if (i == yinjie.length() - 1) {
				pos2 += 1;
			}
			string strYinJie = yinjie.substr(pos1, pos2 - pos1 - 1);
			yinJieList.append(strYinJie);
			pos1 = pos2;
		}
		if (yinjie[i] < 'a' || yinjie[i] > 'z') {
			flag = 1;
		}
	}
	return yinJieList;
}

//��������
int main() {
	//��ʼ��
	initHashMap();
	PeopleList Peoplelist;
	int peopleNumber = 1000;
	//Data(peopleNumber);
	//Sleep(10000);
	Peoplelist.createList("D:\\people.txt");
	Peoplelist.quicksort();
	//���������������
	/*
	for (int i = 0; i < Peoplelist.length; i++)
	{
		cout << Peoplelist.name[i] << endl;
	}
	*/
	//cout << peopleNumber << endl;

	//����Ҫ����ƥ���ƴ���ַ�����search[]
	string search;
	while (cin >> search) {
		int flag = 0;
		StringList getSearchYinJie = getHZFGYinJieList(search, flag);
		if (flag) {
			for (int i = 0; i < Peoplelist.length; i++) {
				
				startFloorIndex = -1;
				//if(PinyinMatch(search, Peoplelist.name[i]))//�Ƕ���
				if (PinyinMatchPolyphone(getSearchYinJie.item[0], Peoplelist.name[i])) {//����
					int flag1 = 0;
					for (int j = 1; j < getSearchYinJie.length; j++) {
						if (!PinyinMatchPolyphone(getSearchYinJie.item[j], Peoplelist.name[i])) {
							flag1 = 1;
						}
					}
					if (!flag1) {
						cout << Peoplelist.name[i] << " " << Peoplelist.phone[i] << endl;
					}

				}
				
			}

		}
		else {
			for (int i = 0; i < Peoplelist.length; i++) {
				startFloorIndex = -1;
				//if(PinyinMatch(search, Peoplelist.name[i]))//�Ƕ���
				if (PinyinMatchPolyphone(search, Peoplelist.name[i]))//����
					cout << Peoplelist.name[i] << " " << Peoplelist.phone[i] << endl;
			}
		}
		/*
		system("pause");

		//Ӣ�Ĳ���
		string str[6];
		str[0] = "Michael Jackon,1863552615123";
		str[1] = "Tom Javae,1863552615123";
		str[2] = "Som Jare,1863552615123";
		str[3] = "Zonsfe Daodf,1863552615123";
		str[4] = "Woaga FGAE,1863552615123";
		str[5] = "Aasdf Savsd,1863552615123";

		//�ڴ��е���Ϣ���ֿ����ֺͺ���
		StringList yinjielist;
		Node* node = getNode(str, 6);

		//while (getline(cin, yinjie)) {
		//	//����������ڵ�˳���
		//	StringList yinJieList;
		//	yinJieList = getYinJieList(yinjie);
		//	getNameAndPhone(node, yinJieList, 6);
		//}
		//����������ڵ�˳���
		StringList EnglishList;
		EnglishList = getEnglishList(search);
		getNameAndPhone(node, EnglishList, 6);
		*/
	}
	return 0;
}