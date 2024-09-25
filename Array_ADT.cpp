#include <iostream>
using namespace std;

class ADT
{
public:
    int total_data;
    int used_data;
    int *ptr;

    ADT() {};

    ADT(int tSize, int uSize)
    {
        total_data = tSize;
        used_data = uSize;
        ptr = new int[tSize];
    }

    void show()
    {
        for (int i = 0; i < used_data; i++)
        {
            cout << ptr[i] << endl;
        }
    }

    void setVal()
    {
        int n;
        for (int i = 0; i < used_data; i++)
        {
            cout << "Enter value " << i + 1 << " ";
            cin >> n;
            ptr[i] = n;
        }
    }

    ~ADT()
    {
        delete[] ptr;
    }
};

int main()
{
    ADT marks(10, 2);
    marks.setVal();
    marks.show();
    return 0;
}