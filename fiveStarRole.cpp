/*
 * @Author: sakuransaber
 * @Date: 2022-03-02 08:42:42
 * @LastEditTime: 2022-03-03 22:00:12
 * @LastEditors: sakuransaber
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \pro\workerManager\fiveStarRole.cpp
 */
#include "fiveStarRole.h"

fiveStarRole::fiveStarRole(int id, string name, int did)
{
    m_Id = id;
    m_Name = name;
    m_DeptId = did;
}

void fiveStarRole::showInfo()
{
    cout << "角色编号: " << m_Id
         << "\t角色名称:" << m_Name
         << "\t角色属系:" << getDeptname()
         << "\t攻略:征服深境螺旋11层的强力角色,推荐刻晴迪卢克等" << endl;
}
string fiveStarRole::getDeptname()
{
    switch (m_DeptId)
    {
    case 1:
        return "火系";
        break;
    case 2:
        return "水系";
        break;
    case 3:
        return "冰系";
        break;
    case 4:
        return "雷系";
        break;
    case 5:
        return "风系";
        break;
    case 6:
        return "岩系";
        break;
    default:
        return "此系不存在";
    }
}
