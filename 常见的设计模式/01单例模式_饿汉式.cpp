
#include<iostream>
using namespace std;

/*
	����ģʽ�����ܴ������ٴΣ���ֻ�ܻ��һ������ʵ��
	1������ʹ�õ���������־ģ�飬���ݿ�ģ��
	2������ģʽ��Ϊ����ʽ����ģʽ������ʽ����ģʽ
	3������ʽ����ģʽ�̰߳�ȫ---����û�л�ȡʵ������ʵ��������Ѿ�����
	Ҳ����˵ʵ����û�����ɾ��Ѿ������˶���-----�����ݶλ������ں������Ȳ���
	----�����Զ���ʽ����ģʽ���̰߳�ȫ�ģ������ȡ��ʵ���������������ݶ����ɣ���̬����

	4������ʽģʽ�̲߳���ȫ---��Ψһ��ʵ������ֱ����һ�λ�ȡ����ʱ�򣬲Ų���-----��
	Ҳ����˵���˺������ò����ɸö���
*/

// ����ʽ����ģʽ
# if 0
class Singleton
{
public:
	// ��ȡΨһ�ľ�̬ʵ��
	static Singleton* getInstance()
	{
		return &instance; // ����ʵ���ĵ�ַ��ָ�룩
	}
private:
	static Singleton instance; // ����һ�����ʵ������
	// ���캯��˽�л�
	Singleton()
	{

	}
	// ��ֹ��������͸�ֵ���캯��
	Singleton(const Singleton&) = delete;
	Singleton & operator=(const Singleton&) = delete;
};

// �����ʼ��
Singleton Singleton::instance;



// ����һ��Ψһ��ʵ������

// ���ݶεĴ����ں���֮ǰ
int main_01()
{
	singleton* p1 = singleton::getinstance();
	singleton* p2 = singleton::getinstance();
	singleton* p3 = singleton::getinstance();
	// �������ָ��ĵ�ַ�������Ƿ�һ��
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;
	return 0;
}

#endif