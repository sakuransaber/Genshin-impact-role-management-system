/*
 * @Author: sakuransaber
 * @Date: 2022-03-01 22:32:04
 * @LastEditTime: 2022-03-03 22:00:20
 * @LastEditors: sakuransaber
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \pro\workerManager\worker.h
 */

#pragma once
#include <iostream>
#include <string>
using namespace std;

// *本质构建多态，一个父类对三个子类
// 角色抽象基类
class character
{
public:
    // 显示个人信息
    virtual void showInfo() = 0;
    // 获取属系名称
    virtual string getDeptname() = 0;

    virtual ~character() {}

    int m_Id;      //角色编号
    string m_Name; //角色姓名
    int m_DeptId;  //角色所属系编号  火-1 水-2 冰-3 雷-4 风-5 岩-6  草-ignore
};