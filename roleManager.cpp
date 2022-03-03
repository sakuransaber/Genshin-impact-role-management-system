/*
 * @Author:sakuransaber
 * @Date: 2022-03-01 17:47:42
 * @LastEditTime: 2022-03-03 21:58:05
 * @LastEditors: sakuransaber
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \pro\workerManager\workerManager.cpp
 */
#include "roleManager.h"
#include "character.h"
#include "fourStarRole.h"
#include "fiveStarRole.h"
#include "superStarRole.h"
//*分三种情况读文件进行初始构造，调用一个算数量的函数并在堆区开辟数组空间
roleManager::roleManager()
{
    ifstream ifs;
    ifs.open(fileName, ios::in);

    // *文件不存在情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        m_fileIsEmpty = true;
        m_chanum = 0;
        m_chaArray = NULL;
        ifs.close();
        return;
    }
    // *文件存在为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        // cout << "文件为空" << endl;
        m_fileIsEmpty = true;
        m_chanum = 0;
        m_chaArray = NULL;
        ifs.close();
        return;
    }
    // *文件存在且有数据
    int num = get_chaNum();
    // cout << "职工个数为:" << num << endl;
    m_chanum = num;
    // *将文件中的数据存到数组中
    m_chaArray = new character *[m_chanum];
    init_cha();

    // // *测试代码
    // for (int i = 0; i < m_chanum; i++)
    // {
    //     cout << "角色编号: " << m_chaArray[i]->m_Id << " "
    //          << "角色姓名: " << m_chaArray[i]->m_Name << " "
    //          << "角色类别: " << m_chaArray[i]->m_DeptId << endl;
    // }
}

void roleManager::showMenu()
{
    cout << "****************************************************" << endl;
    cout << "*************** 欢迎使用原神角色管理系统 ***********" << endl;
    cout << "******************** 0.退出管理系统 ****************" << endl;
    cout << "******************** 1.增加角色信息 ****************" << endl;
    cout << "******************** 2.显示角色信息 ****************" << endl;
    cout << "******************** 3.删除毕业角色 ****************" << endl;
    cout << "******************** 4.修改角色信息 ****************" << endl;
    cout << "******************** 5.查找角色信息 ****************" << endl;
    cout << "******************** 6.按照编号排序 ****************" << endl;
    cout << "******************** 7.清空所有信息 ****************" << endl;
    cout << "****************************************************" << endl;
    cout << "****************************************************" << endl;
    cout << endl;
}

void roleManager::exitSystem()
{
    cout << "欢迎亲爱的旅行者下次光临哦" << endl;
    system("pause");
    exit(0);
}

// *建一个新数组将原来的数组和新的对象加进去，并释放原来的数组更新数据
void roleManager::add_cha()
{
    cout << "请输入角色数量:" << endl;

    int add_num = 0;
    cin >> add_num;

    if (add_num > 0)
    {
        int newSize = add_num + m_chanum;
        character **newspace = new character *[newSize];
        // *把原空间内容存到新空间下
        if (m_chaArray != NULL)
        {
            for (int i = 0; i < m_chanum; i++)
            {
                newspace[i] = m_chaArray[i];
            }
        }
        // *输入新数据
        for (int i = 0; i < add_num; i++)
        {
            int id;
            string name;
            int select;
            int sselect;

            cout << "请输入第" << i + 1 << "个新角色编号:" << endl;
            cin >> id;

            cout << "请输入第" << i + 1 << "个新角色姓名:" << endl;
            cin >> name;

            cout << "请选择该角色的星数:" << endl;
            cout << "1.四星" << endl;
            cout << "2.五星" << endl;
            cout << "3.超星" << endl;
            cin >> select;

            cout << "请选择该角色的属系:" << endl;
            cout << "1.火系" << endl;
            cout << "2.水系" << endl;
            cout << "3.冰系" << endl;
            cout << "4.雷系" << endl;
            cout << "5.风系" << endl;
            cout << "6.岩系" << endl;
            cin >> sselect;

            character *character = NULL;
            switch (select)
            {
            case 1:
                character = new fourStarRole(id, name, sselect);
                break;
            case 2:
                character = new fiveStarRole(id, name, sselect);
                break;
            case 3:
                character = new superStarRole(id, name, sselect);
                break;
            default:
                break;
            }
            newspace[m_chanum + i] = character;
        }
        // *释放原有空间
        delete[] m_chaArray;

        // *更改新空间指向
        m_chaArray = newspace;

        // *更新新的个数
        m_chanum = newSize;

        // *更新文件不为空
        m_fileIsEmpty = false;

        cout << "已成功添加" << add_num << "名新角色!" << endl;

        // *保存文件
        save();
    }
    else
    {
        cout << "输入有误" << endl;
    }
    system("pause");
    system("cls");
}

// *输出流进行保存
void roleManager::save()
{
    ofstream ofs;
    ofs.open(fileName, ios::out);

    for (int i = 0; i < m_chanum; i++)
    {
        ofs << m_chaArray[i]->m_Id << " "
            << m_chaArray[i]->m_Name << " "
            << m_chaArray[i]->m_DeptId << " " << endl;
    }
    ofs.close();
}

// *读一个对象数目加一
int roleManager::get_chaNum()
{
    ifstream ifs;
    ifs.open(fileName, ios::in);

    int id;
    string name;
    int dId;
    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        //记录人数
        num++;
    }
    ifs.close();

    return num;
}

//*从文件里读取数据并进行初始化操作
void roleManager::init_cha()
{
    ifstream ifs;
    ifs.open(fileName, ios::in);

    int id;
    string name;
    int dId;
    int index = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        character *character = NULL;
        // *根据不同的星数创建不同的对象
        if (dId == 1)
        {
            character = new fourStarRole(id, name, dId);
        }
        else if (dId == 2)
        {
            character = new fiveStarRole(id, name, dId);
        }
        else
        {
            character = new superStarRole(id, name, dId);
        }
        // *存放在数组里面
        m_chaArray[index] = character;
        index++;
        m_fileIsEmpty = false;
    }

    ifs.close();
}

void roleManager::showChar()
{
    if (m_fileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < m_chanum; i++)
        {
            // *利用多态调用接口
            m_chaArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

// *判断id是否存在数组中
int roleManager::isExist(int id)
{
    int index = -1;

    for (int i = 0; i < m_chanum; i++)
    {
        if (m_chaArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

// *将删除后的数组对象都向前移一格
void roleManager::del_Cha()
{
    if (m_fileIsEmpty)
    {
        cout << "文件不存在或记录为空!" << endl;
    }
    else
    {
        // *按职工编号删除
        cout << "请输入想删除的角色编号:" << endl;
        int id = 0;
        cin >> id;

        int index = isExist(id);

        if (index != -1)
        {
            for (int i = index; i < m_chanum - 1; i++)
            {
                m_chaArray[i] = m_chaArray[i + 1];
            }

            m_chanum--;
            save();
            cout << "删除成功!" << endl;
        }
        else
        {
            cout << "删除失败,未找到该角色" << endl;
        }
    }
    system("pause");
    system("cls");
}

// *修改职工
void roleManager::mod_Cha()
{
    if (m_fileIsEmpty)
    {
        cout << "文件不存在或记录为空!" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号:" << endl;
        int id;
        cin >> id;

        int ret = isExist(id);
        if (ret != -1)
        {
            delete m_chaArray[ret];

            int newId = 0;
            string newName = "";
            int select = 0;
            int sselect;

            cout << "已查到:" << id << "号员工,请输入新职工号:" << endl;
            cin >> newId;

            cout << "请输入新姓名:" << endl;
            cin >> newName;

            cout << "请输入星数:" << endl;
            cout << "1.四星" << endl;
            cout << "2.五星" << endl;
            cout << "3.超星" << endl;
            cin >> select;

            cout << "请选择该角色的属系:" << endl;
            cout << "1.火系" << endl;
            cout << "2.水系" << endl;
            cout << "3.冰系" << endl;
            cout << "4.雷系" << endl;
            cout << "5.风系" << endl;
            cout << "6.岩系" << endl;
            cin >> sselect;

            character *character = NULL;
            switch (select)
            {
            case 1:
                character = new fourStarRole(newId, newName, sselect);
                break;
            case 2:
                character = new fiveStarRole(newId, newName, sselect);
                break;
            case 3:
                character = new superStarRole(newId, newName, sselect);
                break;
            default:
                break;
            }

            m_chaArray[ret] = character;

            cout << "修改成功!" << endl;

            save();
        }
        else
        {
            cout << "修改失败,查无此人" << endl;
        }
    }
    system("pause");
    system("cls");
}

void roleManager::find_Cha()
{
    if (m_fileIsEmpty)
    {
        cout << "文件不存在或记录为空!" << endl;
    }
    else
    {
        cout << "请输入查找的方式:" << endl;
        cout << "1.按角色编号查找" << endl;
        cout << "2.按角色姓名查找" << endl;

        int select = 0;
        cin >> select;

        if (select == 1)
        {
            int id;
            cout << "请输入查找的角色编号:" << endl;
            cin >> id;

            int ret = isExist(id);
            if (ret != -1)
            {
                cout << "查找成功!该角色信息如下:" << endl;
                m_chaArray[ret]->showInfo();
            }
            else
            {
                cout << "该角色并不有伴随旅行者同行哦" << endl;
            }
        }
        else if (select == 2)
        {
            string name;
            cout << "请旅行者输入查找的姓名:" << endl;
            cin >> name;

            bool flag = false;
            for (int i = 0; i < m_chanum; i++)
            {
                if (m_chaArray[i]->m_Name == name)
                {
                    flag = true;
                    cout << "查找成功,角色编号为:" << m_chaArray[i]->m_Id
                         << "号的信息如下:" << endl;
                    m_chaArray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                cout << "该角色并不有伴随旅行者同行哦" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }
    system("pause");
    system("cls");
}

// *选择结构排序
void roleManager::sort_Cha()
{
    if (m_fileIsEmpty)
    {
        cout << "文件不存在或记录为空!" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序方式:" << endl;
        cout << "1.按角色编号进行升序" << endl;
        cout << "2.按角色编号进行降序" << endl;
        int select = 0;
        cin >> select;

        for (int i = 0; i < m_chanum; i++)
        {
            int minormax = i;
            for (int j = i + 1; j < m_chanum; j++)
            {
                if (select == 1)
                {
                    if (m_chaArray[minormax]->m_Id > m_chaArray[j]->m_Id)
                    {
                        minormax = j;
                    }
                }
                else
                {
                    if (m_chaArray[minormax]->m_Id < m_chaArray[j]->m_Id)
                    {
                        minormax = j;
                    }
                }
            }
            if (i != minormax)
            {
                character *temp = m_chaArray[i];
                m_chaArray[i] = m_chaArray[minormax];
                m_chaArray[minormax] = temp;
            }
        }
        cout << "排序成功,排序后结果为:" << endl;
        save();
        showChar();
    }
}

// *用trunc对文件删除再建立，并清空原数组，以下析构函数同
void roleManager::clean_File()
{
    cout << "确认清空?" << endl;
    cout << "1.确认" << endl;
    cout << "2.返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(fileName, ios::trunc);
        ofs.close();

        if (m_chaArray != NULL)
        {
            for (int i = 0; i < m_chanum; i++)
            {
                if (m_chaArray[i] != NULL)
                {
                    delete m_chaArray[i];
                }
            }
            m_chanum = 0;
            delete[] m_chaArray;
            m_chaArray = NULL;
            m_fileIsEmpty = true;
        }
        cout << "清空成功!" << endl;
    }
    system("pause");
    system("cls");
}

roleManager::~roleManager()
{
    if (m_chaArray != NULL)
    {
        for (int i = 0; i < m_chanum; i++)
        {
            if (m_chaArray[i] != NULL)
            {
                delete m_chaArray[i];
            }
        }
        delete[] m_chaArray;
        m_chaArray = NULL;
    }
}