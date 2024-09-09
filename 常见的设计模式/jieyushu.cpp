
#include<iostream>
#include<vector>

using namespace std;



void trap(vector<int>& height) {
    // �����ŵķ�������
    // ��������������ֵ����Сֵ���Լ��ıȽϼ���
    // ʹ��ǰ��׺�ֽ�ķ�ʽ
    int size = height.size();
    vector<int>hou_(size, height[size - 1]), qian_(size, height[0]);
    // ���ǰ��׺����
    for (int i = 1; i < size; i++)
    {
        qian_[i] = max(qian_[i - 1], height[i]);
    }
    for (auto a : qian_)
    {
        cout << a << " ";
    }
    cout << endl;
    // ����׺����
    for (int i = size - 2; i >= 0; i--)
    {
        hou_[i] = max(hou_[i + 1], height[i]);
    }
    for (auto a : hou_)
    {
        cout << a << " ";
    }



    // �������಻����װˮ
    //int ans = 0; // װˮ�Ķ���
    //for (int i = 1; i < size - 1; i++)
    //{
    //    ans += min(qian_[i], hou_[i]) - height[i];
    //}
    //return ans;
}

int main()
{
    vector<int>ans = { 5,4,1,2 };
    trap(ans);
    return 0;
}