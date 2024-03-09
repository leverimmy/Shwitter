#include "register.h"

bool is_valid_username(const QString& username) {
    // 检查字符串长度
    if (username.length() > 20) {
        return false;
    }

    // 检查是否只包含可见 ASCII 字符
    for (QChar ch : username) {
        if (!ch.isPrint()) {
            return false;
        }
    }
    return true;
}

bool is_valid_password(const QString& password) {
    // 检查字符串长度
    if (password.length() > 20) {
        return false;
    }

    // 检查是否只包含可见 ASCII 字符
    for (QChar ch : password) {
        if (!ch.isPrint()) {
            return false;
        }
    }
    return true;
}

bool is_registrable_username(const QString& username) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ?");
    query.addBindValue(username);
    query.exec();
    return !query.next();
}
