#include "subscription.h"
#include "utils.h"

void insert_or_uuid(const QString& follower_uuid, const QString& followee_uuid) {
    QSqlQuery query;

    // 检查当前项是否存在
    query.prepare("SELECT uuid_list FROM subscription WHERE uuid = :uuid");
    query.bindValue(":uuid", follower_uuid);
    query.exec();

    // 如果当前项存在
    if (query.next()) {
        QStringList uuidList = convertJsonDoqumentToQStringList(QJsonDocument::fromJson(query.value("uuid_list").toByteArray()));

        // 列表中已经包含要追加的 UUID，则跳过
        if (uuidList.contains(followee_uuid)) {
            qDebug() << "UUID already exists. Skipping..." << "\n" << uuidList;
            return;
        }

        // 在列表最后追加 UUID
        uuidList.append(followee_uuid);

        // 更新数据
        query.prepare("UPDATE subscription SET uuid_list = :uuid_list WHERE uuid = :uuid");
        query.bindValue(":uuid_list", convertQStringListToQJsonDocument(uuidList).toJson(QJsonDocument::Compact));
        query.bindValue(":uuid", follower_uuid);
        query.exec();

        qDebug() << "Data updated." << "\n" << uuidList;
    } else {

        // 插入新数据，列表只包含单个 UUID
        QStringList uuidList = { followee_uuid };
        query.prepare("INSERT INTO subscription (uuid, uuid_list) VALUES (:uuid, :uuid_list)");
        query.bindValue(":uuid", follower_uuid);
        query.bindValue(":uuid_list", convertQStringListToQJsonDocument(uuidList).toJson(QJsonDocument::Compact));
        query.exec();

        qDebug() << "Data inserted." << "\n" << uuidList;
    }
}

void remove_or_uuid(const QString& follower_uuid, const QString& followee_uuid) {
    QSqlQuery query;

    // 检查当前项是否存在
    query.prepare("SELECT uuid_list FROM subscription WHERE uuid = :uuid");
    query.bindValue(":uuid", follower_uuid);
    query.exec();

    // 如果当前项存在
    if (query.next()) {
        QStringList uuidList = convertJsonDoqumentToQStringList(QJsonDocument::fromJson(query.value("uuid_list").toByteArray()));

        if (uuidList.contains(followee_uuid)) {

            // 列表中已经包含要追加的 UUID，则删除
            uuidList.removeAll(followee_uuid);
            qDebug() << "UUID exists. Deleting..." << "\n" << uuidList;
        } else {
            qDebug() << "UUID doesn't exist. Skipping..." << "\n" << uuidList;
            return;
        }

        // 更新数据
        query.prepare("UPDATE subscription SET uuid_list = :uuid_list WHERE uuid = :uuid");
        query.bindValue(":uuid_list", convertQStringListToQJsonDocument(uuidList).toJson(QJsonDocument::Compact));
        query.bindValue(":uuid", follower_uuid);
        query.exec();

        qDebug() << "Data updated." << "\n" << uuidList;
    }
}

QStringList get_following_uuid(const QString& follower_uuid) {
    QSqlQuery query;

    // 检查当前项是否存在
    query.prepare("SELECT uuid_list FROM subscription WHERE uuid = :uuid");
    query.bindValue(":uuid", follower_uuid);
    query.exec();

    QStringList uuidList;
    // 如果当前项存在
    if (query.next()) {
        uuidList = convertJsonDoqumentToQStringList(QJsonDocument::fromJson(query.value("uuid_list").toByteArray()));
    }
    return uuidList;
}

