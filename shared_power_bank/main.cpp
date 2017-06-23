//#pragma comment(lib,"json_vc71_libmt.lib")
//#pragma comment(lib,"json_vc71_libmtd.lib")
#include <iostream>
#include "pow_bank_user.h"
#include <time.h>
#include <map>
#include <algorithm>

int optcode;
using namespace std;
int main() {
	//新版本
	PowBankUser user;
	string name, number,password;		//用户要存储的姓名和电话
	vector<vector<string>> interface;
	cout << "欢迎来到XX共享充电宝！！！" << endl;
	//cout << "本程序包含一下界面" << endl;
	//  退出程序
	// 0 开始界面
	// 1 用户界面
	// 2 选择存放机界面
	// 3 借还界面
	// 4 支付界面
	
	interface.push_back(vector<string>{"退出程序", "注册新用户","现在登陆"});
	//登陆后直接进入用户界面
	interface.push_back(vector<string>{"退出程序", "显示用户信息","显示当前余额","打开选择存放机界面"});
	interface.push_back(vector<string>{"退出程序", "选择存放机","打开借还界面"});
	interface.push_back(vector<string>{"退出程序", "借一个充电宝","归还一个充电宝","显示当前验证码","回到选择存放机器界面","回到用户界面","打开支付界面"});
	interface.push_back(vector<string>{"退出程序", "查看本次消费金额","查看您的余额","回到用户界面"});
	

	cout << "当前界面为入口界面，您可选择以下操作:" << endl;
	int i = 0;
	for (auto c : interface[0]) {
		cout <<"["<<i++<<"]"<<"	"<< c << endl;
	}
	//注册登录界面
	cin >> optcode;
	switch (optcode) {
	case 0:
		return 0;
	case11:
	case 1:
	{
		bool sign1 = user.SignUp();
		//get给数据库发送信息核对信息
		if (sign1 == true)
			cout << "恭喜您，注册成功！" << endl;
		if (sign1 == false) {
			cout << "对不起，此用户已存在" << endl << "是否要重新注册呢？ 0 or 1" << endl;
			cin >> optcode;
			if (optcode == 1)
				goto case11;
			else
				return 0;
		}
		cout << "请问您要现在登陆吗？ 0 or 1" << endl;
		cin >> optcode;
		if (optcode != 1)
			return 0;
		if (optcode == 1)
			goto case12;
		
	}
	break;
	case 2:
	case12:
		//get于数据库检查信息是否一致
	{
		bool sign2 = user.SignIn();
		if (sign2 == true)
			cout << "登陆成功！即将跳转到用户界面" << endl;
		else {
			cout << "您输入的密码有误，需要重新输入吗？ 0 or 1" << endl;
			cin >> optcode;
			if (optcode != 1)
				return 0;
			if (optcode == 1)
				goto case12;
		}
		break;
	}
	default:
		return 0;
		
	}

	//用户界面
	user_:
	cout << "当前界面为用户界面，您可选择以下操作:" << endl;
	i = 0;
	for (auto c : interface[1]) {
		cout << "[" << i++ << "]" << "	" << c << endl;
	}
	cin >> optcode;
	switch (optcode) {
	case 0:
		return 0;
	case 1:
		user.ShowInfo();
		cout << "是否返回到用户界面？ 0 or 1" << endl;
		cin >> optcode;
		if (optcode == 0)
			;
		if (optcode == 1)
			goto user_;
		break;
	case 2:
		user.ShowMoney();
		cout << "是否返回到用户界面？ 0 or 1" << endl;
		cin >> optcode;
		if (optcode == 0)
			;
		if (optcode == 1)
			goto user_;
		break;
	case 3:
		goto repositry;
	default:
		return 0;
	}

	//存放机界面
repositry:
	cout << "当前界面为选择存放机器界面，您可选择以下操作:" << endl;
	i = 0;
	for (auto c : interface[2]) {
		cout << "[" << i++ << "]" << "	" << c << endl;
	}
	cin >> optcode;
	switch (optcode) {
	case 0:
		return 0;
	case 1:
		user.GetLocation();
		user.ChoosePowDep();
		break;
	case 2:
		if (user.IfGetPowDep())
			goto borrowandlend;
		else {
			cout << "您还没有选择一个存放机" << endl;
			cout << "是否要选择一个存放机? 0 or 1" << endl;
			cin >> optcode;
			if (optcode == 0) {
				goto repositry;
			}
			if (optcode == 1)
				goto borrowandlend;
		}
		break;
	default:
		return 0;
	}

	//借还界面
borrowandlend:
	cout << "当前界面为借还界面，您可选择以下操作:" << endl;
	i = 0;
	for (auto c : interface[3]) {
		cout << "[" << i++ << "]" << "	" << c << endl;
	}
	cin >> optcode;
	switch (optcode) {
	case 0:
		return 0;
	case 1:
		user.ShowChkCode();
		user.BorrowPow();
		break;
case22:
	case 2:
		if (user.IfGetPow()) {
			user.ReturnPow();
		}
		else {
			cout << "您还没有借充电宝，不需要归还" << endl;
			cout << "现在去借一个充电宝？ 0 or  1" << endl;
			cin >> optcode;
			if (optcode == 0)
				goto borrowandlend;
			if (optcode == 1)
				goto case22;
		}
		break;
	case 3:
		user.ShowChkCode();
		break;
	case 4:
		goto repositry;
	case 5:
		goto user_;
	case 6:
		goto pay;
	default:
		return 0;
	}

	//支付界面
	pay:
	cout << "当前界面为支付界面，您可选择以下操作:" << endl;
	i = 0;
	for (auto c : interface[4]) {
		cout << "[" << i++ << "]" << "	" << c << endl;
	}
	cin >> optcode;
	switch (optcode) {
	case 0:
		return 0;
	case 1:
		cout << "你本次消费的金额为：" <<user.CalculateCost(begin,end)<< endl;
		break;
	case 2:
		user.ShowMoney();
		break;
	case 3:
		goto user_;
	default:
		return 0;

	}

	getchar();
	getchar();

	return 0;
}



























/*std::string strValue = "{\"key1\":\"value1\",\"array\":[{\"key2\":\"value2\"},{\"key2\":\"value3\"},{\"key2\":\"value4\"}]}";
Json::Reader reader;
Json::Value value;
if (reader.parse(strValue, value))
{
std::string out = value["key1"].asString();
std::cout << out << std::endl;
const Json::Value arrayObj = value["array"];
for (int i = 0; i<arrayObj.size(); i++)
{
out = arrayObj[i]["key2"].asString();
std::cout << out;
if (i != arrayObj.size()-1)
std::cout << std::endl;
}
}
getchar();
getchar();*/