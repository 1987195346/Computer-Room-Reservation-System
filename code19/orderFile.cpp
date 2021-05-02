#pragma once
#include "headline.h"

//���캯��
OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;     //����
	string interval; //ʱ���
	string stuId;    //ѧ�����
	string stuName;  //ѧ������
	string roomId;   //�������
	string status;   //ԤԼ״̬

	vector<string> v;//���ÿ���ַ���

	this->m_Size = 0;  //ԤԼ��¼����
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
		
		vector<string> v;//���ÿ���ַ���

		v.push_back(date);
		v.push_back(interval);
		v.push_back(stuId);
		v.push_back(stuName);
		v.push_back(roomId);
		v.push_back(status);
		////���Դ���
		//for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		//	cout << *it << " ";
		//}
		//cout << endl;

		string key;
		string value;
		map<string, string> m;
		for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
			int pos = it->find(":");//����date:1111 �ҵ��˷���4���Ҳ�������-1
			if (pos != -1) {
				key = it->substr(0, pos);
				value = it->substr(pos + 1, it->size() - pos - 1);//size=9,pos=4 ,size-pos=5 
				//cout << "key=" << key << endl;
				//cout << "value=" << value << endl;
				m.insert(make_pair(key, value));
			}
		}
		//��С���������������
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	////���Դ���,˳��ı�����Ϊmap�����Զ�������
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++) {
	//	cout << "key=" << it->first << "  value=" << endl;
	//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++) {
	//		cout << mit->first << " " << mit->second << "   ";
	//	}
	//	cout << endl;
	//}

	ifs.close();
}

//����ԤԼ��¼
void OrderFile::updateOrder() {
	if (this->m_Size == 0) {
		return;   //ԤԼ��¼0����ֱ��return
	}
	//���¼�¼���ļ���ʽ��trunc����ɾ�������´����ļ���ѧ�������ļ���׷�ӷ�ʽ
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}
