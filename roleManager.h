/*
 * @Author: sakuransaber
 * @Date: 2022-03-01 17:47:54
 * @LastEditTime: 2022-03-03 21:58:34
 * @LastEditors: sakuransaber
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \pro\workerManager\workerManager.h
 */

#include <iostream>
#include <fstream>
#include "character.h"
using namespace std;

#define fileName "chaFile.txt"

class roleManager
{
public:
    //构造函数
    roleManager();

    void showMenu();

    void exitSystem();

    void add_cha();

    void save();

    int get_chaNum();

    void init_cha();

    void showChar();

    // *判断职工是否存在再去删除
    int isExist(int id);

    //*删除员工
    void del_Cha();

    // *修改职工
    void mod_Cha();

    // *得到属系名称
    string getDeptname();

    // *查找员工
    void find_Cha();

    // *排序
    void sort_Cha();

    // *清空文件
    void clean_File();

    // 析构函数
    ~roleManager();

    // 记录角色个数
    int m_chanum;
    //角色数组的指针
    character **m_chaArray;
    // *标志文件是否为空，复用次数很多
    bool m_fileIsEmpty;
};
