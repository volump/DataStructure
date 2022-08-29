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

/*********************************拼音匹配****************************************/

const int Max_size = 1e3;//可以不到1000的,300就够
string hashs[Max_size][Max_size];//拼音库hashs表

__declspec (naked) unsigned __int64 GetCpuCycle(void)
{
	_asm
	{
		rdtsc
		ret
	}
}

//生成名字
void NAME(string& name, string& phone1)
{



	const char* NA1[444] = { "赵", "钱", "孙", "李", "周", "吴", "郑", "王", "冯", "陈", "褚", "卫", "蒋", "沈", "韩", "杨", "朱", "秦", "尤", "许", "何", "吕", "施", "张", "孔", "曹", "严", "华", "金", "魏", "陶", "姜", "戚", "谢", "邹", "喻", "柏", "水", "窦", "章", "云", "苏", "潘", "葛", "奚", "范", "彭", "郎", "鲁", "韦", "昌", "马", "苗", "凤", "花", "方", "俞", "任", "袁", "柳", "酆", "鲍", "史", "唐", "费", "廉", "岑", "薛", "雷", "贺", "倪", "汤", "滕", "殷", "罗", "毕", "郝", "邬", "安", "常", "乐", "于", "时", "傅", "皮", "卞", "齐", "康", "伍", "余", "元", "卜", "顾", "孟", "平", "黄", "和", "穆", "萧", "尹", "姚", "邵", "湛", "汪", "祁", "毛", "禹", "狄", "米", "贝", "明", "臧", "计", "伏", "成", "戴", "谈", "宋", "茅", "庞", "熊", "纪", "舒", "屈", "项", "祝", "董", "梁", "杜", "阮", "蓝", "闵", "席", "季", "麻", "强", "贾", "路", "娄", "危", "江", "童", "颜", "郭", "梅", "盛", "林", "刁", "钟", "徐", "邱", "骆", "高", "夏", "蔡", "田", "樊", "胡", "凌", "霍", "虞", "万", "支", "柯", "昝", "管", "卢", "莫", "经", "房", "裘", "缪", "干", "解", "应", "宗", "丁", "宣", "贲", "邓", "郁", "单", "杭", "洪", "包", "诸", "左", "石", "崔", "吉", "钮", "龚", "程", "嵇", "邢", "滑", "裴", "陆", "荣", "翁", "荀", "羊", "於", "惠", "甄", "麴", "家", "封", "芮", "羿", "储", "靳", "汲", "邴", "糜", "松", "井", "段", "富", "巫", "乌", "焦", "巴", "弓", "牧", "隗", "山", "谷", "车", "侯", "宓", "蓬", "全", "郗", "班", "仰", "秋", "仲", "伊", "宫", "宁", "仇", "栾", "暴", "甘", "钭", "厉", "戎", "祖", "武", "符", "刘", "景", "詹", "束", "龙", "叶", "幸", "司", "韶", "郜", "黎", "蓟", "薄", "印", "宿", "白", "怀", "蒲", "邰", "从", "鄂", "索", "咸", "籍", "赖", "卓", "蔺", "屠", "蒙", "池", "乔", "阴", "郁", "胥", "能", "苍", "双", "闻", "莘", "党", "翟", "谭", "贡", "劳", "逄", "姬", "申", "扶", "堵", "冉", "宰", "郦", "雍", "舄", "璩", "桑", "桂", "濮", "牛", "寿", "通", "边", "扈", "燕", "冀", "郏", "浦", "尚", "农", "温", "别", "庄", "晏", "柴", "瞿", "阎", "充", "慕", "连", "茹", "习", "宦", "艾", "鱼", "容", "向", "古", "易", "慎", "戈", "廖", "庾", "终", "暨", "居", "衡", "步", "都", "耿", "满", "弘", "匡", "国", "文", "寇", "广", "禄", "阙", "东", "殴", "殳", "沃", "利", "蔚", "越", "夔", "隆", "师", "巩", "厍", "聂", "晁", "勾", "敖", "融", "冷", "訾", "辛", "阚", "那", "简", "饶", "空", "曾", "毋", "沙", "乜", "养", "鞠", "须", "丰", "巢", "关", "蒯", "相", "查", "後", "荆", "红", "游", "竺", "权", "逯", "盖", "益", "桓", "公", "仉", "督", "晋", "楚", "闫", "法", "汝", "鄢", "涂", "钦", "归", "海", "岳", "帅", "缑", "亢", "况", "后", "有", "琴", "商", "牟", "佘", "佴", "伯", "赏", "墨", "哈", "谯", "笪", "年", "爱", "阳", "佟", "言", "福" };

	//百家姓-复姓
	const char* NA2[59] = { "万俟", "司马", "上官", "欧阳", "夏侯", "诸葛", "闻人", "东方", "赫连", "皇甫", "尉迟", "公羊", "澹台", "公冶", "宗政", "濮阳", "淳于", "单于", "太叔", "申屠", "公孙", "仲孙", "轩辕", "令狐", "钟离", "宇文", "长孙", "慕容", "鲜于", "闾丘", "司徒", "司空", "亓官", "司寇", "子车", "颛孙", "端木", "巫马", "公西", "漆雕", "乐正", "壤驷", "公良", "拓跋", "夹谷", "宰父", "谷梁", "百里", "东郭", "南门", "呼延", "羊舌", "微生", "梁丘", "左丘", "东门", "西门", "南宫", "第五" };

	//男性常用名
	const char* ME1m[140] = { "伟", "刚", "勇", "毅", "俊", "峰", "强", "军", "平", "保", "东", "文", "辉", "力", "明", "永", "健", "世", "广", "志", "义", "兴", "良", "海", "山", "仁", "波", "宁", "贵", "福", "生", "龙", "元", "全", "国", "胜", "学", "祥", "才", "发", "武", "新", "利", "清", "飞", "彬", "富", "顺", "信", "子", "杰", "涛", "昌", "成", "康", "星", "光", "天", "达", "安", "岩", "中", "茂", "进", "林", "有", "坚", "和", "彪", "博", "诚", "先", "敬", "震", "振", "壮", "会", "思", "群", "豪", "心", "邦", "承", "乐", "绍", "功", "松", "善", "厚", "庆", "磊", "民", "友", "裕", "河", "哲", "江", "超", "浩", "亮", "政", "谦", "亨", "奇", "固", "之", "轮", "翰", "朗", "伯", "宏", "言", "若", "鸣", "朋", "斌", "梁", "栋", "维", "启", "克", "伦", "翔", "旭", "鹏", "泽", "晨", "辰", "士", "以", "建", "家", "致", "树", "炎", "德", "行", "时", "泰", "盛" };
	const char* ME2m[140] = { "伟", "刚", "勇", "毅", "俊", "峰", "强", "军", "平", "保", "东", "文", "辉", "力", "明", "永", "健", "世", "广", "志", "义", "兴", "良", "海", "山", "仁", "波", "宁", "贵", "福", "生", "龙", "元", "全", "国", "胜", "学", "祥", "才", "发", "武", "新", "利", "清", "飞", "彬", "富", "顺", "信", "子", "杰", "涛", "昌", "成", "康", "星", "光", "天", "达", "安", "岩", "中", "茂", "进", "林", "有", "坚", "和", "彪", "博", "诚", "先", "敬", "震", "振", "壮", "会", "思", "群", "豪", "心", "邦", "承", "乐", "绍", "功", "松", "善", "厚", "庆", "磊", "民", "友", "裕", "河", "哲", "江", "超", "浩", "亮", "政", "谦", "亨", "奇", "固", "之", "轮", "翰", "朗", "伯", "宏", "言", "若", "鸣", "朋", "斌", "梁", "栋", "维", "启", "克", "伦", "翔", "旭", "鹏", "泽", "晨", "辰", "士", "以", "建", "家", "致", "树", "炎", "德", "行", "时", "泰", "盛" };


	//女性常用名
	const char* ME1f[165] = { "秀", "娟", "英", "华", "慧", "巧", "美", "娜", "静", "淑", "惠", "珠", "翠", "雅", "芝", "玉", "萍", "红", "娥", "玲", "芬", "芳", "燕", "彩", "春", "菊", "兰", "凤", "洁", "梅", "琳", "素", "云", "莲", "真", "环", "雪", "荣", "爱", "妹", "霞", "香", "月", "莺", "媛", "艳", "瑞", "凡", "佳", "嘉", "琼", "勤", "珍", "贞", "莉", "桂", "娣", "叶", "璧", "璐", "娅", "琦", "晶", "妍", "茜", "秋", "珊", "莎", "锦", "黛", "青", "倩", "婷", "姣", "婉", "娴", "瑾", "颖", "露", "瑶", "怡", "婵", "雁", "蓓", "纨", "仪", "荷", "丹", "蓉", "眉", "君", "琴", "蕊", "薇", "菁", "梦", "岚", "苑", "筠", "柔", "竹", "霭", "凝", "晓", "欢", "霄", "枫", "芸", "菲", "寒", "欣", "滢", "伊", "亚", "宜", "可", "姬", "舒", "影", "荔", "枝", "思", "丽", "秀", "飘", "育", "馥", "琦", "晶", "妍", "茜", "秋", "珊", "莎", "锦", "黛", "青", "倩", "婷", "宁", "蓓", "纨", "苑", "婕", "馨", "瑗", "琰", "韵", "融", "园", "艺", "咏", "卿", "聪", "澜", "纯", "毓", "悦", "昭", "冰", "爽", "琬", "茗", "羽", "希" };
	const char* ME2f[165] = { "秀", "娟", "英", "华", "慧", "巧", "美", "娜", "静", "淑", "惠", "珠", "翠", "雅", "芝", "玉", "萍", "红", "娥", "玲", "芬", "芳", "燕", "彩", "春", "菊", "兰", "凤", "洁", "梅", "琳", "素", "云", "莲", "真", "环", "雪", "荣", "爱", "妹", "霞", "香", "月", "莺", "媛", "艳", "瑞", "凡", "佳", "嘉", "琼", "勤", "珍", "贞", "莉", "桂", "娣", "叶", "璧", "璐", "娅", "琦", "晶", "妍", "茜", "秋", "珊", "莎", "锦", "黛", "青", "倩", "婷", "姣", "婉", "娴", "瑾", "颖", "露", "瑶", "怡", "婵", "雁", "蓓", "纨", "仪", "荷", "丹", "蓉", "眉", "君", "琴", "蕊", "薇", "菁", "梦", "岚", "苑", "筠", "柔", "竹", "霭", "凝", "晓", "欢", "霄", "枫", "芸", "菲", "寒", "欣", "滢", "伊", "亚", "宜", "可", "姬", "舒", "影", "荔", "枝", "思", "丽", "秀", "飘", "育", "馥", "琦", "晶", "妍", "茜", "秋", "珊", "莎", "锦", "黛", "青", "倩", "婷", "宁", "蓓", "纨", "苑", "婕", "馨", "瑗", "琰", "韵", "融", "园", "艺", "咏", "卿", "聪", "澜", "纯", "毓", "悦", "昭", "冰", "爽", "琬", "茗", "羽", "希" };
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
	int NA1Roll = rand() % 444;//单姓
	int NA2Roll = rand() % 59;//复姓
	int ME1mRoll = rand() % 140;//男名
	int ME2mRoll = rand() % 140;//男名
	int ME1fRoll = rand() % 165;//女名
	int ME2fRoll = rand() % 165;//女名

	switch (control)
	{
	case 8:
		name = name + NA1[NA1Roll] + ME1m[ME1mRoll]; break;
	case 1:
		name = name + NA1[NA1Roll] + ME1f[ME1fRoll]; break;
	case 2:
		//单姓双名男
		name = name + NA1[NA1Roll] + ME1m[ME1mRoll] + ME1m[ME2mRoll]; break;
	case 3:
		//单姓双名女
		name = name + NA1[NA1Roll] + ME1f[ME1fRoll] + ME1f[ME2fRoll]; break;
	case 4:
		//复姓单名男
		name = name + NA2[NA2Roll] + ME1m[ME1mRoll]; break;
	case 5:
		//复姓单名女
		name = name + NA2[NA2Roll] + ME1f[ME1fRoll]; break;
	case 6:
		//复姓双名男
		name = name + NA2[NA2Roll] + ME1m[ME1mRoll] + ME2m[ME2mRoll]; break;
	case 7:
		//复姓双名女
		name = name + NA2[NA2Roll] + ME1f[ME1fRoll] + ME2f[ME2fRoll]; break;
	default:
		break;
	}

}

//写数据到文件
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

//拼音顺序表
struct StringList {
	string* item;
	int capacity;
	int length;

	//构造函数
	StringList(int c = 10) {
		capacity = c;
		length = 0;
		item = new string[capacity];
	}

	//添加元素
	void append(string s) {
		if (length == capacity) {
			capacity += 10;
			item = new string[capacity];
		}
		item[length++] = s;
	}

	//返回指定位置index的元素
	string getItem(int index) {
		return item[index];
	}

	//显示全部元素
	void show() {
		for (int i = 0; i < length; i++) {
			cout << item[i] << " ";
		}
		cout << endl;
	}

};

//初始化hashs拼音库表
void initHashMap() {
	string str;
	ifstream inf;
	//d盘保存为ANSI编码格式
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

//输入汉字得到全部拼音字符串
string getYinJie(string s) {
	int a1 = s[0];
	int a0 = s[1];
	a1 = -a1;
	a0 = -a0;
	return hashs[a1][a0];
}

//联系人顺序表
struct PeopleList
{
	string name[1000];
	string phone[1000];
	int length = 0;

	//建表
	void createList(const string& filename) {
		ifstream in(filename);
		string line;
		string str1;
		string str2;
		int i, j;
		if (in) // 有该文件
		{
			while (getline(in, line)) // line中不包括每行的换行符
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
		else // 没有该文件
		{
			cout << "no such file" << endl;
		}

	}

	//对arr[l...r]进行partition操作 
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

	//对arr[l...r]部分进行排序(递归)
	void __quicksort(int l, int r)
	{
		if (l >= r)
			return;

		int p = partition(l, r);
		__quicksort(l, p - 1);
		__quicksort(p + 1, r);
	}

	//快速排序接口
	void quicksort()
	{
		__quicksort(0, length - 1);
	}

};

//得到某个字符在字符串中第几次出现的位置
int IndexOf(string s1, char s, int index) {
	int i = index;
	for (; i < s1.length(); i++) {
		if (s1[i] == s) return i;
	}
	if (i >= s1.length()) return -1;
}

//辅助变量：用于取到在辅助函数中第几层开始判断每个音节首字母顺序
int startFloorIndex = -1;

//辅助匹配函数,确保pyItem.getItem(n)[0]都按照顺序出现
//防止guan yu chang匹配gc(跳过了yu达到匹配的这种情况)
bool keyMatch(string search, StringList pyItem, int yinjieIndex) {
	int lastIndex = 0;
	int i;//i代表开始的层数
	for (i = startFloorIndex; i < yinjieIndex + startFloorIndex; i++) {
		lastIndex = IndexOf(search, pyItem.getItem(i)[0], lastIndex);
		if (lastIndex == -1) return false;
		lastIndex++;
	}
	return true;
}

//匹配算法(递归回溯)
bool Match(string search, int searchIndex, StringList pyItem, int yinjieIndex, int yinjieStart) {
	//这个if是规定第一个首字母必须匹配的一种匹配方法，例如yc是匹配不到gyc的
	//if (searchIndex == 0)//如果在输入的search[]的第一个字母位置
	//	//第一个必须匹配&&如果只有一个字符，算匹配成功，否则从第二个字符开始比较,进入下一层递归
	//	return search[0] == pyItem.getItem(0)[0] && (search.length() == 1 || Match(search, 1, pyItem, 0, 1));

	//这里处理如果guan yun chang，yc可以匹配，c不能匹配
	if (searchIndex == 0) {
		if (yinjieIndex > pyItem.length - 1) return false;
		startFloorIndex++;
		return search[0] == pyItem.getItem(yinjieIndex)[0] ? Match(search, 1, pyItem, yinjieIndex, 1) : Match(search, 0, pyItem, yinjieIndex + 1, 0);
	}
	//判断不越界&&判断匹配
	if (pyItem.getItem(yinjieIndex).length() > yinjieStart && search[searchIndex] == pyItem.getItem(yinjieIndex)[yinjieStart])
		//如果这是最后一个字符，检查之前的声母是否依次出现
		//如果不是最后一个字符，同一个字的拼音连续匹配
		return searchIndex == search.length() - 1 ? keyMatch(search, pyItem, yinjieIndex) : Match(search, searchIndex + 1, pyItem, yinjieIndex, yinjieStart + 1);
	//判断不越界&&不能拼音连续匹配的情况下，看看下一个字的拼音的首字母能否匹配
	else if (pyItem.length > yinjieIndex + 1 && search[searchIndex] == pyItem.getItem(yinjieIndex + 1)[0])
		//如果这是最后一个字符，检查之前的声母是否依次出现
		//如果不是最后一个字符，去判断下一个字拼音的第二个字母
		return searchIndex == search.length() - 1 ? keyMatch(search, pyItem, yinjieIndex) : Match(search, searchIndex + 1, pyItem, yinjieIndex + 1, 1);
	else if (pyItem.length > yinjieIndex + 1)//回退
		for (int i = 1; i < searchIndex; i++)
			if (Match(search, searchIndex - i, pyItem, yinjieIndex + 1, 0)) return true;
	//return false;
	return true;
}

//不完全拼音模糊匹配(不处理多音字)
bool PinyinMatch(string search, string name) {
	StringList pinyinItem;
	for (int i = 0; i < name.length(); i += 2) {
		string s = getYinJie(name.substr(i, 2));//从拼音表中获得音节字符串
		//cout << s.length() << endl;//验证一下存进去的字符串长度,是否截断
		int pos = 0;
		for (int j = 0; j < s.length(); j++) {
			//判断是否含有空格，这里不考虑多音字，直接在第一个空格处截断取第一个读音
			if (s[j] == ' ') { pos = j; break; }
		}
		if (pos == 0) pinyinItem.append(s);//不含空格，直接存入pinyinItem[]
		else {
			string yinjie = s.substr(0, pos);//含空格，截断以后存入pinyinItem[]
			pinyinItem.append(yinjie);
		}
	}
	//pinyinItem.show();//输出音节表测试

	//调用匹配核心算法
	if (Match(search, 0, pinyinItem, 0, 0) == true) return true;//如果匹配算法通过，认为该条记录匹配通过，返回true
	return false;//匹配未通过返回false

	//屏蔽核心算法测试pyItem，直接return true
	//return true;
}

//不完全拼音模糊匹配(处理多音字)
//考虑实际情况，多音匹配的前提：
//1.匹配三个字的名字。
//2.名字中只有一个多音字。
//3.多音字最多有4个多音。
bool PinyinMatchPolyphone(string search, string name) {
	if (name.length() / 2 == 2) {
		int polyCount[2];//每个字的多音数
		int maxCount = 1;//最大多音数
		string duoyin[2][4];//每个字的对应音节表，例如“丁云长”，生成表 |ding zheng \0 \0|yun \0 \0 \0|zhang chang \0 \0|
		memset(polyCount, 0, sizeof(polyCount));//开始全部置为0
		for (int i = 0; i < name.length(); i += 2) {
			string s = getYinJie(name.substr(i, 2));//从拼音表中获得音节字符串
			//循环扫描该音节，判断有几个多音
			int count = 1;//每个字最少有一个读音
			for (int j = 0; j < s.length(); j++) {
				//判断是否含有空格，如果有一个空格，多音数+1
				if (s[j] == ' ') {
					count++;
				}
			}
			if (count > maxCount) maxCount = count;

			//填表polyCount[]
			polyCount[i / 2] = count;

			//填表duoyin[][]
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
						//到达最后一个位置
						if (pos == s.length() - 1) {
							duoyin[i / 2][k] = s.substr(start, s.length() - start);
						}
					}
				}
			}

		}


		//两个“指针”，记录两层多音的位置
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
		int polyCount[3];//每个字的多音数
		int maxCount = 1;//最大多音数
		string duoyin[3][4];//每个字的对应音节表，例如“丁云长”，生成表 |ding zheng \0 \0|yun \0 \0 \0|zhang chang \0 \0|
		memset(polyCount, 0, sizeof(polyCount));//开始全部置为0
		for (int i = 0; i < name.length(); i += 2) {
			string s = getYinJie(name.substr(i, 2));//从拼音表中获得音节字符串
			//循环扫描该音节，判断有几个多音
			int count = 1;//每个字最少有一个读音
			for (int j = 0; j < s.length(); j++) {
				//判断是否含有空格，如果有一个空格，多音数+1
				if (s[j] == ' ') {
					count++;
				}
			}
			if (count > maxCount) maxCount = count;

			//填表polyCount[]
			polyCount[i / 2] = count;

			//填表duoyin[][]
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
						//到达最后一个位置
						if (pos == s.length() - 1) {
							duoyin[i / 2][k] = s.substr(start, s.length() - start);
						}
					}
				}
			}

		}

		//测试每个汉字的多音数，多音节输出
		//cout << maxCount << endl;
		/*for (int i = 0; i < 3; i++) cout << polyCount[i];
		cout << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++)
				cout << duoyin[i][j] << " ";
			cout << endl;
		}*/

		//测试多音
		/*for (int i = 0; i < polyCount[0]; i++) {
			StringList pinyinItem;
			pinyinItem.append(duoyin[0][i]);
			pinyinItem.append(duoyin[1][0]);
			pinyinItem.append(duoyin[2][0]);
			pinyinItem.show();
			if (Match(search, 0, pinyinItem, 0, 0)) return true;
		}*/

		//循环建表pinyinItem,匹配多音
		//三个“指针”，记录三层多音的位置
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
		int polyCount[4];//每个字的多音数
		int maxCount = 1;//最大多音数
		string duoyin[4][4];//每个字的对应音节表，例如“丁云长”，生成表 |ding zheng \0 \0|yun \0 \0 \0|zhang chang \0 \0|
		memset(polyCount, 0, sizeof(polyCount));//开始全部置为0
		for (int i = 0; i < name.length(); i += 2) {
			string s = getYinJie(name.substr(i, 2));//从拼音表中获得音节字符串
			//循环扫描该音节，判断有几个多音
			int count = 1;//每个字最少有一个读音
			for (int j = 0; j < s.length(); j++) {
				//判断是否含有空格，如果有一个空格，多音数+1
				if (s[j] == ' ') {
					count++;
				}
			}
			if (count > maxCount) maxCount = count;

			//填表polyCount[]
			polyCount[i / 2] = count;

			//填表duoyin[][]
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
						//到达最后一个位置
						if (pos == s.length() - 1) {
							duoyin[i / 2][k] = s.substr(start, s.length() - start);
						}
					}
				}
			}

		}

		//测试每个汉字的多音数，多音节输出
		//cout << maxCount << endl;
		/*for (int i = 0; i < 3; i++) cout << polyCount[i];
		cout << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++)
				cout << duoyin[i][j] << " ";
			cout << endl;
		}*/

		//测试多音
		/*for (int i = 0; i < polyCount[0]; i++) {
			StringList pinyinItem;
			pinyinItem.append(duoyin[0][i]);
			pinyinItem.append(duoyin[1][0]);
			pinyinItem.append(duoyin[2][0]);
			pinyinItem.show();
			if (Match(search, 0, pinyinItem, 0, 0)) return true;
		}*/

		//循环建表pinyinItem,匹配多音
		//四个“指针”，记录四层多音的位置
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


/*********************************英文匹配****************************************/
struct Node {
	string name;                    //名字
	string phone;                   //号码
	int getNameLength() {
		return 2;
	}

	//存储每一个英文的顺序表
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
	//存储每一个小写拼音的顺序表
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

//将存入的信息拆分为姓名和电话两部分
//str是总的字符串数组，n为数组长度
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

//将一整个字符串转化为一个字符串的顺序表
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

//获得对应音节的姓名和电话
void getNameAndPhone(Node* node, StringList yinJieList, int len) {
	for (int i = 0; i < len; i++) {                                    //遍历整个内存
		int flag = 0;
		if (yinJieList.length == 2) {
			for (int j = 0; j < yinJieList.length; j++) {                //遍历输入音节
				for (int k = 0; k < yinJieList.item[j].length(); k++) {  //对比每个元素
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
			for (int k = 0; k < yinJieList.item[0].length(); k++) {  //对比每个元素
				StringList pinYinItemList = node[i].getSmallItemList();
				char cinPinYinItem = yinJieList.item[0][k];
				char neiChunPinYinItem = pinYinItemList.item[0][k];
				if (cinPinYinItem != neiChunPinYinItem) {
					flag1 = 1;
					break;
				}
			}
			for (int k = 0; k < yinJieList.item[0].length(); k++) {  //对比每个元素
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

//测试用例
int main() {
	//初始化
	initHashMap();
	PeopleList Peoplelist;
	int peopleNumber = 1000;
	//Data(peopleNumber);
	//Sleep(10000);
	Peoplelist.createList("D:\\people.txt");
	Peoplelist.quicksort();
	//快速排序输出测试
	/*
	for (int i = 0; i < Peoplelist.length; i++)
	{
		cout << Peoplelist.name[i] << endl;
	}
	*/
	//cout << peopleNumber << endl;

	//输入要进行匹配的拼音字符数组search[]
	string search;
	while (cin >> search) {
		int flag = 0;
		StringList getSearchYinJie = getHZFGYinJieList(search, flag);
		if (flag) {
			for (int i = 0; i < Peoplelist.length; i++) {
				
				startFloorIndex = -1;
				//if(PinyinMatch(search, Peoplelist.name[i]))//非多音
				if (PinyinMatchPolyphone(getSearchYinJie.item[0], Peoplelist.name[i])) {//多音
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
				//if(PinyinMatch(search, Peoplelist.name[i]))//非多音
				if (PinyinMatchPolyphone(search, Peoplelist.name[i]))//多音
					cout << Peoplelist.name[i] << " " << Peoplelist.phone[i] << endl;
			}
		}
		/*
		system("pause");

		//英文测试
		string str[6];
		str[0] = "Michael Jackon,1863552615123";
		str[1] = "Tom Javae,1863552615123";
		str[2] = "Som Jare,1863552615123";
		str[3] = "Zonsfe Daodf,1863552615123";
		str[4] = "Woaga FGAE,1863552615123";
		str[5] = "Aasdf Savsd,1863552615123";

		//内存中的信息，分开名字和号码
		StringList yinjielist;
		Node* node = getNode(str, 6);

		//while (getline(cin, yinjie)) {
		//	//获得输入音节的顺序表
		//	StringList yinJieList;
		//	yinJieList = getYinJieList(yinjie);
		//	getNameAndPhone(node, yinJieList, 6);
		//}
		//获得输入音节的顺序表
		StringList EnglishList;
		EnglishList = getEnglishList(search);
		getNameAndPhone(node, EnglishList, 6);
		*/
	}
	return 0;
}