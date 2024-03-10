#include "login.h"
#include "utils.h"

bool is_valid_username_and_password(const QString& username, const QString& password) {

    // 查询数据库中是否有对应的 (username, password) 对
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(calculateSHA256(password));
    query.exec();
    return query.next();
}
