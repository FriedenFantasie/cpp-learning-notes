#include <iostream>
#include <string>

class BaseObject {
public:
    int publicValue = 10;
    static int sharedValue;

    void setPrivateValue(int value)
    {
        privateValue = value;
    }

    int getPrivateValue() const
    {
        return privateValue;
    }

protected:
    int protectedValue = 20;

private:
    int privateValue = 30;
};

int BaseObject::sharedValue = 100;

class DerivedObject : public BaseObject {
public:
    int derivedValue = 40;

    void showAccessibleMembers() const
    {
        std::cout << "Inside DerivedObject:\n";
        std::cout << "  publicValue: " << publicValue << '\n';
        std::cout << "  protectedValue: " << protectedValue << '\n';
        std::cout << "  privateValue through public getter: " << getPrivateValue() << '\n';
        std::cout << "  derivedValue: " << derivedValue << "\n\n";

        // privateValue cannot be accessed directly here, but it is still
        // inherited into the DerivedObject object layout.
    }
};

void showObjectSizes()
{
    std::cout << "Object sizes:\n";
    std::cout << "  sizeof(BaseObject): " << sizeof(BaseObject) << " bytes\n";
    std::cout << "  sizeof(DerivedObject): " << sizeof(DerivedObject) << " bytes\n";
    std::cout << "  non-static int count in BaseObject: 3\n";
    std::cout << "  non-static int count in DerivedObject: 4\n";
    std::cout << "  static member and member functions are not stored in each object.\n\n";
}

void showBaseSubobjectAddress(DerivedObject& object)
{
    BaseObject& basePart = object;

    std::cout << "Base subobject address:\n";
    std::cout << "  DerivedObject address: " << &object << '\n';
    std::cout << "  BaseObject part address: " << &basePart << "\n\n";
}

void showRuntimeAccess()
{
    DerivedObject object;

    object.showAccessibleMembers();

    std::cout << "Outside DerivedObject:\n";
    std::cout << "  publicValue is accessible: " << object.publicValue << '\n';
    std::cout << "  privateValue is accessible only through BaseObject public functions: "
              << object.getPrivateValue() << "\n\n";

    object.setPrivateValue(300);
    std::cout << "After modifying privateValue through BaseObject public function:\n";
    std::cout << "  privateValue: " << object.getPrivateValue() << "\n\n";

    // object.protectedValue; // Error: protected member cannot be accessed outside.
    // object.privateValue;   // Error: private member cannot be accessed anywhere outside BaseObject.

    showBaseSubobjectAddress(object);
}

void showStaticMemberSharing()
{
    DerivedObject first;
    DerivedObject second;

    first.sharedValue = 500;

    std::cout << "Static member sharing:\n";
    std::cout << "  first.sharedValue: " << first.sharedValue << '\n';
    std::cout << "  second.sharedValue: " << second.sharedValue << '\n';
    std::cout << "  BaseObject::sharedValue: " << BaseObject::sharedValue << "\n\n";
}

int main()
{
    std::cout << "C++ inheritance object model demo\n";
    std::cout << std::string(35, '=') << "\n\n";

    showObjectSizes();
    showRuntimeAccess();
    showStaticMemberSharing();

    return 0;
}
