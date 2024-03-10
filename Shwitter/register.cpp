#include "register.h"

bool is_valid_username(const QString& username) {

    // 检查字符串长度
    if (username.length() < 1 || username.length() > 20) {
        return false;
    }

    // 检查是否只包含字母、数字、下划线
    for (QChar ch : username) {
        if (!ch.isLetterOrNumber() && ch != '_') {
            return false;
        }
    }
    return true;
}

bool is_valid_password(const QString& password) {

    // 检查字符串长度
    if (password.length() < 8 || password.length() > 20) {
        return false;
    }

    // 检查是否只包含字母、数字、下划线
    for (QChar ch : password) {
        if (!ch.isLetterOrNumber() && ch != '_') {
            return false;
        }
    }
    return true;
}
