#include "utils.h"

bool is_valid_username(const QString& username) {
    // 检查字符串长度
    if (username.length() < 1 || username.length() > 20) {
        return false;
    }
    // 检查是否只包含字母、数字、下划线
    for (QChar ch : username) {
        if (!ch.isDigit() && !ch.isLower() && !ch.isUpper() && ch != '_') {
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
        if (!ch.isDigit() && !ch.isLower() && !ch.isUpper() && ch != '_') {
            return false;
        }
    }
    return true;
}

QString get_uuid_by_username(const QString& username) {
    // 通过 username 查找 uuid
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

QString calculateSHA256(const QString &data) {
    QByteArray hash = QCryptographicHash::hash(data.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex();
}

bool is_username_exist(const QString& username) {
    // 判断某个用户名是否存在
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = :username");
    query.bindValue(":username", username);
    query.exec();
    return (bool)query.next();
}

QJsonDocument convertQStringListToQJsonDocument(const QStringList& stringList) {
    QJsonArray jsonArray;
    for (const QString& str : stringList) {
        jsonArray.append(str);
    }
    return QJsonDocument(jsonArray);
}

QStringList convertJsonDoqumentToQStringList(const QJsonDocument& jsonDocument) {
    QStringList stringList;
    if (jsonDocument.isArray()) {
        QJsonArray jsonArray = jsonDocument.array();
        for (const QJsonValue& jsonValue : jsonArray) {
            if (jsonValue.isString()) {
                stringList.append(jsonValue.toString());
            }
        }
    }
    return stringList;
}

QString get_username_by_uuid(const QString& uuid) {
    // 通过 uuid 查找 username
    QSqlQuery query;
    query.prepare("SELECT username FROM users WHERE uuid = :uuid");
    query.bindValue(":uuid", uuid);

    if (query.exec() && query.next()) {
        QString usernameString = query.value(0).toString();
        qDebug() << "用户名：" << usernameString;
        qDebug() << "对应的 UUID：" << uuid;
        return usernameString;
    } else {
        qDebug() << "未找到 UUID 为" << uuid << "的记录";
        return 0;
    }
}
