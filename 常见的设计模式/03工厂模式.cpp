


#include<iostream>
#include<memory>
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
	Car(string name):_name(name){}
	virtual void show() = 0;
protected:
	string _name;
};

// ����
class Bmw : public Car
{
public:
	// ���캯����ʼ��
	Bmw(string name):Car(name){}
	void show()
	{
		cout << "��ȡһ����������: " << _name<<endl;
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
		cout << "��ȡһ���µ�����: " <<_name<< endl;
	}
};

// ʹ�ü򵥵Ĺ��� + ö�ٷ���
// ö��
enum CarType
{
	BMW,
	AUDI
};

class SimpleFactory
{
public:
	Car* createCar(CarType ct)
	{
		switch (ct)
		{
		case BMW:
			return new 	Bmw("X3");
		case AUDI:
			return new  Audi("A5");
		default:
			cerr << "���빤���Ĳ�������ȷ��" << ct << endl;
			break;
		}
		return nullptr;
	}
};


int main()
{
	// ʹ����ָ����г�ʼ��
	Car* p1 = new Bmw("X1");
	Car* p2 = new Audi("A6");
	
	p1->show();
	p2->show();

	delete p1;
	delete p2;

	// ʹ������ָ����
	unique_ptr<Car> p3(new Bmw("X1"));
	unique_ptr<Car> p4(new Audi("A6"));
	p3->show();
	p4->show();

	// ʹ�ü򵥵Ĺ���ģʽ
	// ��ȡ����ָ��
	unique_ptr<SimpleFactory> factory(new SimpleFactory());
	// ��ȡCarָ��
	unique_ptr<Car>p5(factory->createCar(BMW));
	unique_ptr<Car>p6(factory->createCar(AUDI));
	p5->show();
	p6->show();
	
	return 0;
}