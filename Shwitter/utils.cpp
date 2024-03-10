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

QString calculateSHA256(const QString &data) {
    QByteArray hash = QCryptographicHash::hash(data.toUtf8(), QCryptographicHash::Sha256);
    return hash.toHex();
}

bool is_username_exist(const QString& username) {
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ?");
    query.addBindValue(username);
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
