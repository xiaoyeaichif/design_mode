
#include<iostream>
#include<mutex>
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

#if 0

static mutex mtx;  // ����һ��������

// ����ʽ����ģʽ
class Singleton
{
public:
	// ��ȡΨһ�ľ�̬ʵ��
	static Singleton *getInstance()
	{
		// ����������Ļ������߳�ִ��Ч��̫��
		if (instance == nullptr)
		{
			// Ҫ��֤�̰߳�ȫ���������
			lock_guard<mutex>lock(mtx);
			if (instance == nullptr) // �� + ˫���ж�----��ȷ���̰߳�ȫ
			{
				instance = new Singleton();
			}
		}
		return instance;
	}
private:
	static Singleton *instance; // ����һ�����ʵ�������ָ��
	// ���캯��˽�л�
	Singleton()
	{

	}
	// ��ֹ��������͸�ֵ���캯��
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

// �����ʼ��
Singleton * Singleton::instance = nullptr;


// ����һ��Ψһ��ʵ������

// ���ݶεĴ����ں���֮ǰ
int main()
{
	Singleton* p1 = Singleton::getInstance();
	Singleton* p2 = Singleton::getInstance();
	Singleton* p3 = Singleton::getInstance();
	// �������ָ��ĵ�ַ�������Ƿ�һ��
	cout << "p1: " << p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p3: " << p3 << endl;
	return 0;
}

// �̰߳�ȫ----�����뺯��

#endif
