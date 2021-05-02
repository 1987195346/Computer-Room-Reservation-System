#pragma once
#include "headline.h"

//机房管理类
class RoomManager {
public:
	//主菜单
	void Menu();

	//登录
	void LoginIn(string fileName,int type);

	//进入管理员子菜单界面,用父类指针传的manager，目的是利用多态调用operMenu()函数
	void managerMenu(Identity * &manager);

	//进入学生子菜单界面,用父类指针传的student,目的是利用多态调用operMenu()函数
	void studentMenu(Identity * &student);

	//进入教师子菜单界面,用父类指针传的teacher,目的是利用多态调用operMenu()函数
	void TeacherMenu(Identity * &teacher);
};