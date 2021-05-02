#pragma once
#include "headline.h"

int main() {
	RoomManager rm;
	int select = 0;
	while (true) {
		rm.Menu();
		cout << "请输入您的选择：";
		cin >> select;
		switch (select) {
		case 1:   //学生代表登录
			rm.LoginIn(STUDENT_FILE, 1);
			break;
		case 2:   //老师登录
			rm.LoginIn(TEACHER_FILE, 2);
			break;
		case 3:   //管理员登录
			rm.LoginIn(ADMIN_FILE, 3);
			break;
		case 0:   //退出
			cout << "欢迎下次使用！" << endl;
			system("pause");
			exit(0);
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}