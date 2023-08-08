#include <iostream>
#include <memory>
using namespace std;

class IBox
{
    public:
    virtual void open() = 0;
    virtual ~IBox() = default;
};

class SimpleBox : public IBox
{
    public :
    virtual void open () override
    {
       cout << "Opening the Box "    ;
    }
};

class ProxyBox : public IBox
{
    public:
    ProxyBox(string sUserName, string sPwd):m_UserName(), m_Pwd(sPwd)
    {}
    
    void open () override
    {
        if (iSAuthenticated())
        {
            cout << "\nAuthentication Success";
            m_Box.open();
            cout << "Open is called " ;
        }
        else
        cout << "\nAuthentication Failure, you can't open the Box";
    }
    private:
    bool  iSAuthenticated ()
    {
        bool bAuthenticated = false;
        if (m_UserName == "Admin" && m_Pwd == "Tes123" )
        {
            bAuthenticated = true;

        }
        return bAuthenticated;
    }

    private:
    string m_UserName;
    string m_Pwd;
    SimpleBox m_Box;
};

int main ()
{
    IBox* box = new ProxyBox("Admin" , "Tes123");
    box->open();
   delete box;
}


