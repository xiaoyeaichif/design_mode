
#include<iostream>
#include<vector>

using namespace std;



void trap(vector<int>& height) {
    // 往竖着的方向上想
    // 检查左右两侧最大值中最小值与自己的比较即可
    // 使用前后缀分解的方式
    int size = height.size();
    vector<int>hou_(size, height[size - 1]), qian_(size, height[0]);
    // 填充前后缀数组
    for (int i = 1; i < size; i++)
    {
        qian_[i] = max(qian_[i - 1], height[i]);
    }
    for (auto a : qian_)
    {
        cout << a << " ";
    }
    cout << endl;
    // 填充后缀数组
    for (int i = size - 2; i >= 0; i--)
    {
        hou_[i] = max(hou_[i + 1], height[i]);
    }
    for (auto a : hou_)
    {
        cout << a << " ";
    }



    // 数组两侧不可能装水
    //int ans = 0; // 装水的多少
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