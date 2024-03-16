# Shwitter
清华大学软件学院春季学期课程《面向对象程序设计基础》大作业报告（2024 春）。

**目录**



## 作业描述

> 题目 4.27【***】简易社交媒体应用实现
>
> - 实现一个类似 Twitter 的社交媒体应用
> - 支持用户进行登录、注册、发布和删除内容
> - 支持不同用户之间相互关注，关注对方后可看对方发布内容

我实现了一个名为 *Shwitter* 的应用程序，满足以上要求，支持多用户同时在线，且能在本地利用数据库进行持久存储。

## 构建环境

### IDE 以及编译器

- IDE：Qt Creator 12.0.2 (Enterprise)
- 编译器：Qt 6.6.2 以及配套版本的 MinGW 编译器

### 操作系统

Windows 规格：

|     条目     |                       内容                        |
| :----------: | :-----------------------------------------------: |
|     版本     |               Windows 11 家庭中文版               |
|     版本     |                       22H2                        |
|   安装日期   |                     ‎2023/‎9/‎14                     |
| 操作系统版本 |                    22621.3296                     |
|     体验     | Windows Feature Experience Pack 1000.22687.1000.0 |

## 设计思路

### 数据库的表结构

#### 账号

```sql
CREATE TABLE IF NOT EXISTS users (uuid UUID PRIMARY KEY, username VARCHAR(20), password VARCHAR(20))
```

#### 关注列表

```sqlite
CREATE TABLE IF NOT EXISTS subscription (uuid UUID PRIMARY KEY, uuid_list JSONB)
```



#### 发布内容

```sqlite
CREATE TABLE IF NOT EXISTS posts (post_uuid UUID PRIMARY KEY, timestamp DATETIME, poster_uuid UUID, post_content TEXT)
```

### 页面跳转相关逻辑



### 用户登录与注册相关逻辑



### 用户新增关注相关逻辑



### 用户发表动态相关逻辑



### 展示关注列表相关逻辑



### 展示其他用户动态相关逻辑



## 代码结构

```
- Shwitter
	- Header Files
		- customlistitemwidget.h
		- custompostitemwidget.h
		- login.h
		- post.h
		- postelement.h
		- postwindow.h
		- subscription.h
		- utils.h
		- widget.h
	- Source Files
		- customlistitemwidget.cpp
		- custompostitemwidget.cpp
		- login.cpp
		- main.cpp
		- post.cpp
		- postelement.cpp
		- postwindow.cpp
		- subscription.cpp
		- utils.cpp
		- widget.cpp
	- Shwitter.pro
	- widget.ui
```

- 类

  - `customlistitemwidget.h` 和 `customlistitemwidget.cpp`

    

  - `custompostitemwidget.h` 和 `custompostitemwidget.cpp`

  - `postelement.h` 和 `postelement.cpp`

  - `postwindow.h` 和 `postwindow.cpp`

  - `widget.h` 和 `widget.cpp`

- 函数库

  - `login.h` 和 `login.cpp`
  - `post.h` 和 `post.cpp`
  - `subscription.h` 和 `subscription.cpp`
  - `utils.h` 和 `utils.cpp`

- `main.cpp`

- `widget.ui`

  界面文件，描述了本项目的应用界面 UI。

- `Shwitter.pro`

  项目文件，它描述了 Qt 项目的配置和组织结构。本项目使用 QMake (Qt Make) 作为构建系统，`Shwitter.pro` 中包含了构建项目所需的信息，如源文件列表、编译选项、依赖关系等。


## 具体实现



## 功能测试



## 参考文献



## 作者信息

- 姓名：
- 学号：
- Email：
- 手机：
