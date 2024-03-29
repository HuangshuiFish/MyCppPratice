#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void display( vector<int> vec )
{
    for (int ix = 0; ix < vec.size(); ++ix)
        cout << vec[ix] << ' ';
    cout << endl;
}

void swap(int &val1, int &val2)//前面加的&是reference，将参数声明为一个reference，具体可以参考书《Essential C++》P45的内容
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void bubble_sort(vector<int> &vec)//同上
{
    for (int ix = 0; ix < vec.size(); ++ix)
        for (int jx = ix + 1; jx < vec.size(); ++jx)
            if(vec[ix] > vec[jx])
                swap(vec[ix], vec[jx]);
}


int main()
{
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia + 8);

    cout << "vector before sort: ";
    display(vec);

    bubble_sort(vec);

    cout << "vector after sort: ";
    display(vec);
    return 0;
}
