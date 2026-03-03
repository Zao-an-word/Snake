# 贪吃蛇游戏（C++ EasyX 实现）
基于 C++ 和 EasyX 图形库开发的经典贪吃蛇小游戏，支持方向键控制、自动移动、吃食物变长、碰撞检测等核心功能，适配 Windows 平台（Visual Studio/VSCode）。

## 📋 项目介绍
### 核心功能
- 方向控制：W/S/A/D 键控制蛇的上下左右移动
- 自动移动：无按键时蛇沿当前方向自动前进
- 食物系统：随机生成食物，吃到后蛇身变长、分数增加
- 碰撞检测：撞围墙/撞自身时游戏结束，显示最终分数
- 界面展示：网格背景、围墙、实时分数显示

### 技术栈
- 编程语言：C++（C++11 及以上）
- 图形库：EasyX Graphics Library（Windows 专属）
- 开发环境：Visual Studio 2022 

## 🛠️ 环境配置
### 前置条件
1. 操作系统：Windows 10/11（EasyX 仅支持 Windows）
2. 编译器：
   - Visual Studio 2022（推荐）：自带 MSVC 编译器
   - VSCode：需安装 MinGW-w64（x86_64-posix-seh 版本）
3. EasyX 图形库：
   - VS 版本：[EasyX 官网](http://www.easyx.cn) 下载对应 VS 版本安装包
   - MinGW 版本：下载 EasyX for MinGW，将 `easyx.h`/`graphics.h` 放入 MinGW `include` 目录，`libeasyx.a` 放入 `lib` 目录

### 快速配置（Visual Studio）
1. 打开 Visual Studio，新建「空项目」，将 `snake.cpp` 添加到项目中；
2. 安装 EasyX 图形库（安装时选择对应 VS 版本）；
3. 直接编译运行（无需额外配置）。
