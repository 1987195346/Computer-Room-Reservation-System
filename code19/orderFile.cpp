#pragma once
#include "headline.h"

//构造函数
OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;     //日期
	string interval; //时间段
	string stuId;    //学生编号
	string stuName;  //学生姓名
	string roomId;   //机房编号
	string status;   //预约状态

	vector<string> v;//存放每个字符串

	this->m_Size = 0;  //预约记录个数
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {
		
		vector<string> v;//存放每个字符串

		v.push_back(date);
		v.push_back(interval);
		v.push_back(stuId);
		v.push_back(stuName);
		v.push_back(roomId);
		v.push_back(status);
		////测试代码
		//for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		//	cout << *it << " ";
		//}
		//cout << endl;

		string key;
		string value;
		map<string, string> m;
		for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
			int pos = it->find(":");//例如date:1111 找到了返回4，找不到返回-1
			if (pos != -1) {
				key = it->substr(0, pos);
				value = it->substr(pos + 1, it->size() - pos - 1);//size=9,pos=4 ,size-pos=5 
				//cout << "key=" << key << endl;
				//cout << "value=" << value << endl;
				m.insert(make_pair(key, value));
			}
		}
		//将小容器放入大容器中
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	////测试代码,顺序改变是因为map容器自动排序了
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++) {
	//	cout << "key=" << it->first << "  value=" << endl;
	//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++) {
	//		cout << mit->first << " " << mit->second << "   ";
	//	}
	//	cout << endl;
	//}

	ifs.close();
}

//更新预约记录
void OrderFile::updateOrder() {
	if (this->m_Size == 0) {
		return;   //预约记录0条，直接return
	}
	//更新记录打开文件方式是trunc，是删了再重新创建文件，学生保存文件是追加方式
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
