#include <iostream>
#include <string>

class BaseInfo {
public:
    std::string publicInfo = "BaseInfo::publicInfo";

    std::string getPrivateInfo() const
    {
        return privateInfo;
    }

protected:
    std::string protectedInfo = "BaseInfo::protectedInfo";

private:
    std::string privateInfo = "BaseInfo::privateInfo";
};

// Syntax: class Child : public Base
class PublicInheritanceDemo : public BaseInfo {
public:
    void showInsideAccess() const
    {
        std::cout << "[public inheritance] inside derived class\n";
        std::cout << "  public member: " << publicInfo << '\n';
        std::cout << "  protected member: " << protectedInfo << '\n';
        std::cout << "  private member through public getter: " << getPrivateInfo() << "\n\n";

        // privateInfo cannot be accessed directly here.
    }
};

// Syntax: class Child : protected Base
class ProtectedInheritanceDemo : protected BaseInfo {
public:
    void showInsideAccess() const
    {
        std::cout << "[protected inheritance] inside derived class\n";
        std::cout << "  public member becomes protected: " << publicInfo << '\n';
        std::cout << "  protected member stays protected: " << protectedInfo << '\n';
        std::cout << "  private member through inherited getter: " << getPrivateInfo() << "\n\n";

        // privateInfo cannot be accessed directly here.
    }

    std::string readPublicInfoByWrapper() const
    {
        return publicInfo;
    }
};

// A child of ProtectedInheritanceDemo can still use BaseInfo public/protected
// members because they became protected members.
class GrandChildOfProtectedDemo : public ProtectedInheritanceDemo {
public:
    void showGrandChildAccess() const
    {
        std::cout << "[protected inheritance] inside grandchild class\n";
        std::cout << "  inherited public member is protected here: " << publicInfo << '\n';
        std::cout << "  inherited protected member is protected here: " << protectedInfo << "\n\n";
    }
};

// Syntax: class Child : private Base
class PrivateInheritanceDemo : private BaseInfo {
public:
    void showInsideAccess() const
    {
        std::cout << "[private inheritance] inside derived class\n";
        std::cout << "  public member becomes private: " << publicInfo << '\n';
        std::cout << "  protected member becomes private: " << protectedInfo << '\n';
        std::cout << "  private member through inherited getter: " << getPrivateInfo() << "\n\n";

        // privateInfo cannot be accessed directly here.
    }

    std::string readPublicInfoByWrapper() const
    {
        return publicInfo;
    }
};

void testPublicInheritance()
{
    PublicInheritanceDemo demo;

    demo.showInsideAccess();
    std::cout << "Outside PublicInheritanceDemo\n";
    std::cout << "  publicInfo is still public: " << demo.publicInfo << '\n';
    std::cout << "  getPrivateInfo is still public: " << demo.getPrivateInfo() << "\n\n";

    // demo.protectedInfo; // Error: protected member cannot be accessed outside.
}

void testProtectedInheritance()
{
    ProtectedInheritanceDemo demo;

    demo.showInsideAccess();
    std::cout << "Outside ProtectedInheritanceDemo\n";
    std::cout << "  publicInfo is not public anymore, use wrapper: "
              << demo.readPublicInfoByWrapper() << "\n\n";

    // demo.publicInfo;       // Error: publicInfo became protected.
    // demo.getPrivateInfo(); // Error: getPrivateInfo became protected.

    GrandChildOfProtectedDemo grandChild;
    grandChild.showGrandChildAccess();
}

void testPrivateInheritance()
{
    PrivateInheritanceDemo demo;

    demo.showInsideAccess();
    std::cout << "Outside PrivateInheritanceDemo\n";
    std::cout << "  publicInfo is not public anymore, use wrapper: "
              << demo.readPublicInfoByWrapper() << "\n\n";

    // demo.publicInfo;       // Error: publicInfo became private.
    // demo.getPrivateInfo(); // Error: getPrivateInfo became private.
}

int main()
{
    std::cout << "C++ inheritance access modes demo\n";
    std::cout << "Syntax: class Child : inheritance_mode Base\n\n";

    testPublicInheritance();
    testProtectedInheritance();
    testPrivateInheritance();

    return 0;
}
