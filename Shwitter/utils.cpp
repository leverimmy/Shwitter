#include "utils.h"

QString get_uuid_by_username(const QString& username) {
    QSqlQuery query;
    query.prepare("SELECT uuid FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        QString uuidString = query.value(0).toString();
        qDebug() << "用户名：" << username;
        qDebug() << "对应的UUID：" << uuidString;
        return uuidString;
    } else {
        qDebug() << "未找到用户名为" << username << "的记录";
        return 0;
    }
}
