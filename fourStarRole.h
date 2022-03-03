/*
 * @Author: sakuransaber
 * @Date: 2022-03-02 08:18:29
 * @LastEditTime: 2022-03-03 21:59:46
 * @LastEditors: sakuransaber
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \pro\workerManager\fourStarRole.h
 */
#pragma once
#include <iostream>
#include <string>
#include "character.h"
using namespace std;

class fourStarRole : public character
{
public:
    // 构造函数
    fourStarRole(int id, string name, int dId);

    // 显示角色信息
    void showInfo();

    // 获取角色属系名称
    string getDeptname();
};
