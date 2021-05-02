#pragma once
#include "headline.h"

//����Ա��
class Manager :public Identity {
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι��� ����Ա����������
	Manager(string name, string pwd);

	//ѡ��˵�
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������ 
	void initVector();

	//����ظ� ����������id���������ͣ�����ֵ��true���ظ���falseû���ظ���
	bool checkRepeat(int id, int type);


	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom> vCom;
};