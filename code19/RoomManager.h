#pragma once
#include "headline.h"

//����������
class RoomManager {
public:
	//���˵�
	void Menu();

	//��¼
	void LoginIn(string fileName,int type);

	//�������Ա�Ӳ˵�����,�ø���ָ�봫��manager��Ŀ�������ö�̬����operMenu()����
	void managerMenu(Identity * &manager);

	//����ѧ���Ӳ˵�����,�ø���ָ�봫��student,Ŀ�������ö�̬����operMenu()����
	void studentMenu(Identity * &student);

	//�����ʦ�Ӳ˵�����,�ø���ָ�봫��teacher,Ŀ�������ö�̬����operMenu()����
	void TeacherMenu(Identity * &teacher);
};