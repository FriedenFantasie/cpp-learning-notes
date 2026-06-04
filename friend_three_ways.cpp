#include <iostream>
#include <string>
#include <utility>

class Building;

void globalFriendVisit(const Building& building);

class MemberFriendVisitor {
public:
    void visitLivingRoom(const Building& building) const;
    void visitBedroom(const Building& building) const;
};

class Building {
    // 1. 全局函数做友元：这个函数可以访问 Building 的私有成员。
    friend void globalFriendVisit(const Building& building);

    // 2. 类做友元：ClassFriendVisitor 的所有成员函数都可以访问 Building 的私有成员。
    friend class ClassFriendVisitor;

    // 3. 成员函数做友元：只有这个指定的成员函数可以访问 Building 的私有成员。
    friend void MemberFriendVisitor::visitBedroom(const Building& building) const;

public:
    Building(std::string livingRoom, std::string bedroom)
        : livingRoom(std::move(livingRoom))
        , bedroom(std::move(bedroom))
    {
    }

    const std::string& getLivingRoom() const
    {
        return livingRoom;
    }

private:
    std::string livingRoom;
    std::string bedroom;
};

void globalFriendVisit(const Building& building)
{
    std::cout << "1. 全局函数做友元\n";
    std::cout << "   通过公有接口访问: " << building.getLivingRoom() << '\n';
    std::cout << "   直接访问私有成员: " << building.bedroom << "\n\n";
}

class ClassFriendVisitor {
public:
    void visitAllRooms(const Building& building) const
    {
        std::cout << "2. 类做友元\n";
        std::cout << "   直接访问私有成员 livingRoom: " << building.livingRoom << '\n';
        std::cout << "   直接访问私有成员 bedroom: " << building.bedroom << "\n\n";
    }
};

void MemberFriendVisitor::visitLivingRoom(const Building& building) const
{
    std::cout << "3. 成员函数做友元 - 普通成员函数\n";
    std::cout << "   这个函数不是友元，只能通过公有接口访问: " << building.getLivingRoom() << '\n';
    std::cout << "   如果在这里写 building.bedroom，会编译报错。\n\n";
}

void MemberFriendVisitor::visitBedroom(const Building& building) const
{
    std::cout << "3. 成员函数做友元 - 被声明为友元的成员函数\n";
    std::cout << "   直接访问私有成员 bedroom: " << building.bedroom << '\n';
}

int main()
{
    Building home("客厅", "卧室");

    globalFriendVisit(home);

    ClassFriendVisitor classFriend;
    classFriend.visitAllRooms(home);

    MemberFriendVisitor memberFriend;
    memberFriend.visitLivingRoom(home);
    memberFriend.visitBedroom(home);

    return 0;
}
