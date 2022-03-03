/*
 * @Author: sakuransaber
 * @Date: 2022-03-02 08:41:45
 * @LastEditTime: 2022-03-03 22:00:04
 * @LastEditors: sakuransaber
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \pro\workerManager\fiveStarRole.h
 */
#pragma once
#include <iostream>
#include <string>
#include "character.h"
using namespace std;

class fiveStarRole : public character
{
public:
    // 构造函数
    fiveStarRole(int id, string name, int dId);

    // 显示角色信息
    void showInfo();

    // 获取角色属系名称
    string getDeptname();
};