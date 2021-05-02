#pragma once
#include "headline.h"

//主菜单
void RoomManager::Menu() {
	cout << "======================  欢迎来到传智播客机房预约系统  ====================="
		<< endl;
	cout << endl << "请输入您的身份" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "输入您的选择: ";
}

//登录
void RoomManager::LoginIn(string fileName, int type) {
	//父类指针，用于指向子类对象
	Identity * person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在情况
	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1) {
		//学生登录
		cout << "请输入你的学号：";
		cin >> id;
	}
	else if (type == 2) {
		//教师登录
		cout << "请输入你的职工号：";
		cin >> id;
	}

	cout << "请输入用户名：" ;
	cin >> name;

	cout << "请输入密码：";
	cin >> pwd;

	if (type == 1) {
		//学生登录验证
		int fId;      //从文件中读取的id号
		string fName; //从文件中读取的姓名
		string fPwd;  //从文件中读取的密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//与用户输入信息做对比
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单
				studentMenu(person);

				return;
			}
		}

	}
	else if (type == 2) {
		//教师身份验证
		int fId;      //从文件中读取的id号
		string fName; //从文件中读取的姓名
		string fPwd;  //从文件中读取的密码	
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份的子菜单
				this->TeacherMenu(person);

				return;
			}
		}

	}
	else if (type == 3) {
		//管理员登录验证
		string fName; //从文件中读取的姓名
		string fPwd;  //从文件中读取的密码	
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份的子菜单
				this->managerMenu(person);
				
				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;

	system("pause");
	system("cls");
	return;
}


//进入管理员子菜单界面,用父类指针传的manager,目的是利用多态调用operMenu()函数
void RoomManager::managerMenu(Identity * &manager) {
	while (true) {
		//调用管理员的子菜单
		manager->operMenu();

		//将父类指针 转为子类指针，调用子类里其他接口
		Manager *man = (Manager*)manager;

		int select = 0;
		cin >> select;

		if (select == 1) {			
			//添加账号
			man->addPerson();
		}
		else if (select == 2) {		
			//查看账号
			man->showPerson();
		}
		else if (select == 3) {		
			//查看机房
			man->showComputer();
		}
		else if (select == 4) {		
			//清空预约
			man->cleanFile();
		}
		else {
			//注销登录
			delete manager;  //销毁堆区对象
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生子菜单界面,用父类指针传的student,目的是利用多态调用operMenu()函数
void RoomManager::studentMenu(Identity * &student) {
	while (true) {
		//学生菜单
		student->operMenu();

		//将父类指针 转为子类指针，调用子类里其他接口
		Student *stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1) {
			//申请预约
			stu->applyOrder();
		}
		else if (select == 2) {
			//查看自身预约
			stu->showMyOrder();
		}
		else if (select == 3) {
			//查看所有预约
			stu->showAllOrder();
		}
		else if (select == 4) {
			//取消预约
			stu->cancelOrder();
		}
		else {
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教师子菜单界面,用父类指针传的teacher,目的是利用多态调用operMenu()函数
void RoomManager::TeacherMenu(Identity * &teacher) {
	while (true) {
		////调用教师的子菜单
		teacher->operMenu();

		//将父类指针 转为子类指针，调用子类里其他接口
		Teacher * tea = (Teacher *)teacher;

		int select = 0;
		cin >> select;
		if (select == 1) {
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2) {
			//审核预约
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}