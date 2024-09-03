
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
class Singleton
{
public:
	// ��ȡΨһ�ľ�̬ʵ��
	// ʹ�þ�̬��������---->��������
	static Singleton& getInstance()
	{
		static Singleton instance; // ��̬�������������ݶ�----���Ⱥ������ã������ɶ���---������������ʽ
		return instance;
	}
private:
	// ���캯��˽�л�
	Singleton()
	{

	}
	// ��ֹ��������͸�ֵ���캯��
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};



// ����һ��Ψһ��ʵ������

// ���ݶεĴ����ں���֮ǰ
int main()
{
	Singleton& p1 = Singleton::getInstance();
	Singleton& p2 = Singleton::getInstance();
	Singleton& p3 = Singleton::getInstance();
	// �������ָ��ĵ�ַ�������Ƿ�һ��
	cout << "p1: " << &p1 << endl;
	cout << "p2: " << &p2 << endl;
	cout << "p3: " << &p3 << endl;
	return 0;
}

// �̰߳�ȫ----�����뺯��


