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

```sql
CREATE TABLE IF NOT EXISTS subscription (uuid UUID PRIMARY KEY, uuid_list JSONB)
```



#### 发布内容

```sql
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
		- customsubscriptionitemwidget.h
		- custompostitemwidget.h
		- login.h
		- post.h
		- postelement.h
		- postwindow.h
		- subscription.h
		- utils.h
		- widget.h
	- Source Files
		- customsubscriptionitemwidget.cpp
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

  - `customsubscriptionitemwidget.h` 和 `customsubscriptionitemwidget.cpp`

    定义了 `CustomSubscriptionItemWidget` 类。该类定义了展示当前用户的关注列表时，关注列表的组件布局。

  - `custompostitemwidget.h` 和 `custompostitemwidget.cpp`

    定义了 `CostomPostItemWidget` 类。该类定义了展示当前用户关注的所有用户的所有动态时，展示动态的列表的组件布局。

  - `postelement.h` 和 `postelement.cpp`

    定义了 `PostElement` 类。该类定义了用户发表的动态的结构。具体而言，一个动态由以下部分组成：

    - 该动态的唯一标识符
    - 该动态的发表时间，以时间戳表示
    - 该动态的发表者
    - 该动态的内容

  - `postwindow.h` 和 `postwindow.cpp`

    定义了 `PostWindow` 类。该类定义了在用户发表新动态时，弹出输入发表内容的窗口，该窗口的布局。

  - `widget.h` 和 `widget.cpp`

    定义了 `Widget` 类。该类定义了整个应用程序窗口的布局。

- 函数库

  - `login.h` 和 `login.cpp`

    负责与数据库交互，管理用户登录注册相关操作。例如：

    - 判断用户名和密码是否正确

  - `post.h` 和 `post.cpp`

    负责与数据库交互，管理用户动态相关操作。例如：

    - 插入/删除某一条用户动态
    - 获取当前用户关注的所有用户的所有动态

  - `subscription.h` 和 `subscription.cpp`

    负责与数据库交互，管理用户关注其他用户相关操作。例如：

    - 新增/删除关注某个用户
    - 获取当前用户关注的所有用户组成的列表

  - `utils.h` 和 `utils.cpp`

    辅助函数库，它负责定义一些常用的、能使代码组织结构更清晰的功能函数。例如：

    - 判断用户名是否合法
    - 判断密码是否合法
    - 计算一个字符串的 SHA256 值
    - 将 `QStringList` 转换为 `QJsonDocument`
    - 将 `QJsonDocument` 转换为 `QStringList`
    - 判断一个用户名是否存在
    - 由用户唯一标识符得到用户名

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
