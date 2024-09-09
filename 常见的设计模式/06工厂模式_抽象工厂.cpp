


#include<iostream>
#include<string>
using namespace std;


/*
	�򵥹���	Simple Factory --��
		�ŵ㣺�Ѷ���Ĵ�����װ��һ���ӿ��У�ͨ�����벻ͬ�ı�ʶ�����ش����Ķ���,�ͻ������Լ�����new���󣬲����˽�
		���󴴽�����ϸ����
		ȱ�㣺��߶���Ľӿں������պϣ����ܶ��޸Ĺر�

	��������	Factory Method	----��
		�ŵ㣺Factory�Ǹ����࣬����Ϊ���麯����ֻ�ṩһ���ӿڣ�������ֻ��Ҫ��������д�麯������ʵ�ֲ�ͬ�Ĳ�Ʒ
		�ܹ��ܺõĽ����޸���ر�
		ȱ�㣺ֻ�ܼ򵥵Ľ���ĳһ�ֲ�Ʒ����������Ǻܶ��Ʒ֮�����й�����ϵ�ģ�����һ����Ʒ�飬������û�п���
	���󹤳�	Abstract Factory
		�ŵ㣺�ѹ����Ĺ�ϵ��д�������У�����һ����Ʒ�����нӿں�����������������̳���ʱ��ֻ��Ҫ��д���еĽӿھͿ���
		ȱ�㣺��һЩ�ӿ�ֻ��ĳ����Ʒ��Ҫʹ�ã�����д�˽ӿ��Ժ�ÿ�������඼������д

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

// ����
class Light
{
public:
	// ���캯����ʼ��
	Light(string light):_light(light)
	{

	}
	virtual void show() = 0;
protected:
	string _light;
};

// BMW��
class BmwLight : public Light
{
public:
	// ���캯����ʼ��
	BmwLight(string light) :Light(light) {}
	void show()
	{
		cout << "��ȡһ�����������Ƶ��ͺ�: " << _light<< endl;
	}
};


// audi��
class AudiLight : public Light
{
public:
	// ���캯����ʼ��
	AudiLight(string light) :Light(light) {}
	void show()
	{
		cout << "��ȡһ��Audi�����Ƶ��ͺ�: " << _light << endl;
	}
};




// ʹ�ù���ģʽ + ���󹤳�
// ���麯����ֻ�ṩһ���ӿ�----��ʹ��������̳�
class AbstractFactory{
public:
	virtual Car* CreateCar(string name) = 0;
	virtual Light* CreateLight(string light) = 0;
};

// ����������ص����
class BMWFactory :public AbstractFactory
{
	Car* CreateCar(string name)
	{
		return new Bmw(name);
	}
	//
	Light* CreateLight(string light)
	{
		return new BmwLight(light);
	}
};

// �����µ���ص����
class AUDIFactory :public AbstractFactory
{
	Car* CreateCar(string name)
	{
		return new Audi(name);
	}
	Light* CreateLight(string light)
	{
		return new AudiLight(light);
	}
};

int main_06()
{


	// ʹ�ü򵥵Ĺ���ģʽ
	// ��ȡ����ָ��
	// �����ָ��ָ������
	unique_ptr<AbstractFactory> bmwfactory(new BMWFactory());
	unique_ptr<AbstractFactory> audifactory(new AUDIFactory());
	// �麯��ʵ�ֵĶ�̬��ֱ�ӵ�������Ķ�Ӧ�ĺ���
	// ������
	unique_ptr<Car> p1(bmwfactory->CreateCar("X6"));
	unique_ptr<Light> l1(bmwfactory->CreateLight("xxxxx"));
	// audi ����
	unique_ptr<Car> p2(audifactory->CreateCar("A8"));
	unique_ptr<Light> l2(audifactory->CreateLight("aaaaa"));

	// ������
	p1->show();
	l1->show();
	// �µϹ���
	p2->show();
	l2->show();
	return 0;
}