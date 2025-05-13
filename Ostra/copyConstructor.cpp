
//Signature of copy constructor and assignment operator and what is the difference 
//of it 
class copyConstructor{
    public :
    // copyConstructor(int x, int y ){
    //     x = x;
    //     y = y;
    // }
    copyConstructor(int x, int y )x:({
        x = x;
        y = y;
    }
    copyConstructor(const copyConstructor &cpconstructor){

    }
    operator = (const copyConstructor &cpconstructor)

    private:
    int x, y;
}


class obj; obj1;
 
obj1(obj);

obj1 = obj;


class A
{
    int x;
    public:
        A() 
        { 
            x = 0;
        }
        void fun() 
        {
            delete this;
            x = 4;
        }
};

int main()
{
    A ob; 
    ob.fun();
    return 0;
}



class Test
{
    public:
    void t1() const
    {
      cout<<"t1 const\n";
    }
    void t2()
    {
      cout<<"t2 non-const\n";
    }
};

int main()
{
    Test ob1;
    ob1.t1(); //t1 const
    const Test ob2;
    ob2.t2(); // t2 non-const

    //ob2 = ob1;
}



class Point
{
    public:
        Point() { cout << "Normal Constructor called\n"; }
        Point(const Point &t) { cout << "Copy constructor called\n"; }
};
 
int main()
{
    Point *t1, *t2;
    t1 = new Point(); // 
    t2 = new Point(*t1);
    Point t3 = *t1;
    Point t4;
    t4 = t3;
    return 0;
}
Normal Constructor called {88}
Copy constructor called { 89}
Normal Constructor called { 90}
Normal Constructor called { 91}

// 



class Test
{
public:
   Test(const Test &t) { }
   Test()        { }
};

Test fun()
{
    cout << "fun() Called";
    Test t;
    return t;
}

int main()
{
    Test t1;
    Test t2 = fun();
    return 0;
}