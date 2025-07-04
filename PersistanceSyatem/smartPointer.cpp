#include <iostream>
using namespace std;

template <typename T>
class smrtPtr
{

private:
    T *data = nullptr;
public:
    explicit smrtPtr(T *fdata)
    {
        data = fdata;
    }
    // delete pointer using destructor
    ~smrtPtr()
    {
        if (data != nullptr)
        {
            delete data;
        }
    }
    // overloaded functions
    T &operator*()
    {
        return *data;
    } 
    T &operator&()
    {
        return data;
    }
};

int main()
{

    smrtPtr<int> data(new int(100));
    cout << *data << endl;
}