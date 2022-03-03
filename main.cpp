/*
 * @Author: sakuransaber
 * @Date: 2022-03-01 17:33:47
 * @LastEditTime: 2022-03-03 21:59:30
 * @LastEditors: sakuransaber
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \pro\hello\hello.cpp
 */
#include <iostream>
#include <stdlib.h>
#include "roleManager.h"

using namespace std;
//*本质一个选择结构，每个选择调用一个接口
int main()
{
    roleManager rm;
    int choice = 0;
    while (true)
    {
        rm.showMenu();

        cout << "向着星辰与深渊,请旅行者输入您的选择:" << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "耽误太多时间，事情可就做不完了" << endl;
            rm.exitSystem();
            break;
        case 1:
            cout << "罩子越大,嘟嘟大魔王越坏" << endl;
            rm.add_cha();
            break;
        case 2:
            cout << "破绽,稍纵即逝" << endl;
            rm.showChar();
            break;
        case 3:
            cout << "霜寒化生,风雪的缩影,如琉璃般飘落" << endl;
            rm.del_Cha();
            break;
        case 4:
            cout << "剑光如我，斩尽芜杂" << endl;
            rm.mod_Cha();
            break;
        case 5:
            cout << "飘摇风雨中，带刀归来赤脚行" << endl;
            rm.find_Cha();
            break;
        case 6:
            cout << "我虽无意逐鹿，却知苍生苦楚" << endl;
            rm.sort_Cha();
            break;
        case 7:
            cout << "心有所向，日复一日，必有精进。" << endl;
            rm.clean_File();
            break;
        default:
            system("cls");
        }
    }
}
