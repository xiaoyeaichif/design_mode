

#include<iostream>
#include<unordered_map>
#include<string>
#include<list>
using namespace std;

/*
    观察者--监听者模式（发布订阅模式）
    更多强调的是当当一个对象A发生变化时，所有依赖这个对象的都需要得到对象A所发生的改变（更新）
    和我们项目有关的是zookeeper的watcher模式，也是观察到zookeeper有变化就会告知客户端（消费者）
*/

// 纯虚函数，子类重写父类的虚函数
// 观察者接口
class Observer
{
public:
    virtual void handle(int idmsg) = 0;
};

// 消费者
// 也就是消费者对生产者的需求-----》具体的观察者
class Observer1:public Observer
{
public:
    void handle(int idmsg)
    {
        switch (idmsg)
        {
        case 1:
            cout <<"idmsg = 1 is recv 1"<<endl;
            break;
        case 2:
            cout <<"idmsg = 1 is recv 2"<<endl;
            break;
        default:
            cout <<"idmsg = 1 is recv NO!"<<endl;
            break;
        }
    }
};


class Observer2:public Observer
{
public:
    void handle(int idmsg)
    {
        switch (idmsg)
        {
        case 2:
            cout <<"idmsg = 2 is recv 2"<<endl;
            break;
        default:
            cout <<"idmsg = 2 is recv NO!"<<endl;
            break;
        }
    }
};


class Observer3:public Observer
{
public:
    void handle(int idmsg)
    {
        switch (idmsg)
        {
        case 3:
            cout <<"idmsg = 3 is recv 3"<<endl;
            break;
        default:
            cout <<"idmsg = 3 is recv NO!"<<endl;
            break;
        }
    }
};

// 具体的主题
class Subject
{
public:
    // 给主题增加观察者
    void addObserver(int idmsg,Observer * obr)
    {
        // 如果当前idmsg没有对任何事情感兴趣，也就是说list为空
        auto it = _obMap.find(idmsg);
        // 说明当前的list中有感兴趣的事件，继续增加即可
        if(it != _obMap.end())
        {
            it->second.push_back(obr);
        }
        else{
            // 代表没有该事件，继续增加该事件
            list<Observer*>lis;
            lis.push_back(obr);
            // 填写哈希表
            _obMap.insert({idmsg,lis});
        }
    }
    // 主题检测发生改变，通知相应的处理事件
    // 通知观察者（消费者）被观察部分的改变
    void dispath(int msg)
    {
        auto it = _obMap.find(msg);
        // 表示找到发生变化的事件
        if(it != _obMap.end())
        {
            // poObr为Observer对象指针
            for(auto poObr : it->second)
            {
                poObr->handle(msg);
            }
        }
    }
private:
    // 一个id可能对应多个订阅的主题
    // 所以使用哈希表+链表（数组完成）
    unordered_map<int,list<Observer*>>_obMap;
};

int main()
{
    //生成观察者对象
    Subject subject;
    // 不同的观察对象，基类指针指向派生类对象
    Observer * p1 = new Observer1();
    Observer * p2 = new Observer2();
    Observer * p3 = new Observer3();
    // 通过观察对象添加
    subject.addObserver(1,p1);
    subject.addObserver(2,p1);
    subject.addObserver(2,p2);
    subject.addObserver(3,p3);
    // 输出
    int idmsg = 0;
    while(1)
    {
        cout<<"idmsg:";
        cin>>idmsg;
        if(idmsg == -1)
        {
            break;
        }
        subject.dispath(idmsg);
    }
    return 0;
}