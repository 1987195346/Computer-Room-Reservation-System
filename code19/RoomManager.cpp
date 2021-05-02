#pragma once
#include "headline.h"

//���˵�
void RoomManager::Menu() {
	cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================="
		<< endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: ";
}

//��¼
void RoomManager::LoginIn(string fileName, int type) {
	//����ָ�룬����ָ���������
	Identity * person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ļ����������
	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1) {
		//ѧ����¼
		cout << "���������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2) {
		//��ʦ��¼
		cout << "���������ְ���ţ�";
		cin >> id;
	}

	cout << "�������û�����" ;
	cin >> name;

	cout << "���������룺";
	cin >> pwd;

	if (type == 1) {
		//ѧ����¼��֤
		int fId;      //���ļ��ж�ȡ��id��
		string fName; //���ļ��ж�ȡ������
		string fPwd;  //���ļ��ж�ȡ������
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			//���û�������Ϣ���Ա�
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�
				studentMenu(person);

				return;
			}
		}

	}
	else if (type == 2) {
		//��ʦ�����֤
		int fId;      //���ļ��ж�ȡ��id��
		string fName; //���ļ��ж�ȡ������
		string fPwd;  //���ļ��ж�ȡ������	
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ��ݵ��Ӳ˵�
				this->TeacherMenu(person);

				return;
			}
		}

	}
	else if (type == 3) {
		//����Ա��¼��֤
		string fName; //���ļ��ж�ȡ������
		string fPwd;  //���ļ��ж�ȡ������	
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա��ݵ��Ӳ˵�
				this->managerMenu(person);
				
				return;
			}
		}
	}

	cout << "��֤��¼ʧ�ܣ�" << endl;

	system("pause");
	system("cls");
	return;
}


//�������Ա�Ӳ˵�����,�ø���ָ�봫��manager,Ŀ�������ö�̬����operMenu()����
void RoomManager::managerMenu(Identity * &manager) {
	while (true) {
		//���ù���Ա���Ӳ˵�
		manager->operMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Manager *man = (Manager*)manager;

		int select = 0;
		cin >> select;

		if (select == 1) {			
			//����˺�
			man->addPerson();
		}
		else if (select == 2) {		
			//�鿴�˺�
			man->showPerson();
		}
		else if (select == 3) {		
			//�鿴����
			man->showComputer();
		}
		else if (select == 4) {		
			//���ԤԼ
			man->cleanFile();
		}
		else {
			//ע����¼
			delete manager;  //���ٶ�������
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ���Ӳ˵�����,�ø���ָ�봫��student,Ŀ�������ö�̬����operMenu()����
void RoomManager::studentMenu(Identity * &student) {
	while (true) {
		//ѧ���˵�
		student->operMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Student *stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1) {
			//����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2) {
			//�鿴����ԤԼ
			stu->showMyOrder();
		}
		else if (select == 3) {
			//�鿴����ԤԼ
			stu->showAllOrder();
		}
		else if (select == 4) {
			//ȡ��ԤԼ
			stu->cancelOrder();
		}
		else {
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ�Ӳ˵�����,�ø���ָ�봫��teacher,Ŀ�������ö�̬����operMenu()����
void RoomManager::TeacherMenu(Identity * &teacher) {
	while (true) {
		////���ý�ʦ���Ӳ˵�
		teacher->operMenu();

		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Teacher * tea = (Teacher *)teacher;

		int select = 0;
		cin >> select;
		if (select == 1) {
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2) {
			//���ԤԼ
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}