#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QtSql>

QString get_uuid_by_username(const QString& username);

QString calculateSHA256(const QString &data);

bool is_username_exist(const QString& username);

QJsonDocument convertQStringListToQJsonDocument(const QStringList& stringList);

QStringList convertJsonDoqumentToQStringList(const QJsonDocument& jsonDocument);

void insert_or_uuid(const QString& follower, const QString& followee);

QString get_username_by_uuid(const QString& uuid);

#endif // UTILS_H
