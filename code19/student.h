#pragma once
#include "headline.h"

//ѧ����
class Student :public Identity {
public:
	//Ĭ�Ϲ���
	Student();

	//�вι��� (ѧ�ţ�����������)
	//�Ѿ��̳��˸���Identity�е��û���������
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//��ʼ������
	void initVector();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;

};