


#include<iostream>
#include<string>
using namespace std;


/*
	�򵥹���	Simple Factory
	��������	Factory Method	----��
	���󹤳�	Abstract Factory
	����ģʽ����Ҫ�Ƿ�װ�˶���Ĵ���
*/

// �򵥹���ģʽ
// ��������
class Car
{
public:
	Car(string name) :_name(name) {}
	virtual void show() = 0;
protected:
	string _name;
};

// ����
class Bmw : public Car
{
public:
	// ���캯����ʼ��
	Bmw(string name) :Car(name) {}
	void show()
	{
		cout << "��ȡһ����������: " << _name << endl;
	}
};
// �µϳ�
class Audi : public Car
{
public:
	// ���캯����ʼ��
	Audi(string name) :Car(name) {}
	void show()
	{
		cout << "��ȡһ���µ�����: " << _name << endl;
	}
};

// ʹ�ù���ģʽ + ��������
// ���麯����ֻ�ṩһ���ӿ�----��ʹ��������̳�
class Factory {
public:
	virtual Car* CreateCar(string name) = 0;
};

// ����������
class BMWFactory :public Factory
{
	Car* CreateCar(string name)
	{
		return new Bmw(name);
	}
};

// �����µϹ���
class AUDIFactory :public Factory
{
	Car* CreateCar(string name)
	{
		return new Audi(name);
	}
};

int main_05()
{
	

	// ʹ�ü򵥵Ĺ���ģʽ
	// ��ȡ����ָ��
	// �����ָ��ָ������
	unique_ptr<Factory> bmwfactory(new BMWFactory());
	unique_ptr<Factory> audifactory(new AUDIFactory());
	// �麯��ʵ�ֵĶ�̬��ֱ�ӵ�������Ķ�Ӧ�ĺ���
	unique_ptr<Car> p1(bmwfactory->CreateCar("X6"));
	unique_ptr<Car> p2(audifactory->CreateCar("A8"));
	
	// 
	p1->show();
	p2->show();

	return 0;
}