#include "login.h"

bool is_valid_username_and_password(const QString& username, const QString& password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ? AND password = ?");
    query.addBindValue(username);
    query.addBindValue(password);
    query.exec();
    return query.next();
}
