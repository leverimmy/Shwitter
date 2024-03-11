#include "post.h"

void insert_or_post(const QString& poster_uuid, const QString& text) {
    QUuid uuid = QUuid::createUuid();
    QString uuidString = uuid.toString();

    QDateTime currentTimestamp = QDateTime::currentDateTime();

    QSqlQuery query;
    // 插入新数据，列表只包含单个 UUID
    query.prepare("INSERT INTO posts (post_uuid, timestamp, poster_uuid, post_content) VALUES (:post_uuid, :timestamp, :poster_uuid, :post_content)");
    query.bindValue(":post_uuid", uuidString);
    query.bindValue(":timestamp", currentTimestamp);
    query.bindValue(":poster_uuid", poster_uuid);
    query.bindValue(":post_content", text);
    query.exec();

    qDebug() << "Post inserted." << "\n" << text;
}

void remove_or_post(const QString& post_uuid) {
    QSqlQuery query;
    query.prepare("DELETE FROM posts WHERE post_uuid = :post_uuid");
    query.bindValue(":post_uuid", post_uuid);
    query.exec();
}

QList<PostElement> get_following_posts(const QString& follower_uuid) {
    QList<PostElement> postList;

    QStringList following_uuid_list = get_following_uuid(follower_uuid);

    for (const QString& followee_uuid : following_uuid_list) {
        QSqlQuery query;

        // 检查当前项是否存在
        query.prepare("SELECT * FROM posts WHERE poster_uuid = :uuid");
        query.bindValue(":uuid", followee_uuid);
        query.exec();

        while (query.next()) {
            // 从查询结果中提取数据并创建 PostElement 对象
            QString post_uuid = query.value("post_uuid").toString();
            QDateTime timestamp = query.value("timestamp").toDateTime();
            QString poster_uuid = query.value("poster_uuid").toString();
            QString post_content = query.value("post_content").toString();

            // 创建 PostElement 对象并将其添加到 postList
            PostElement postElement(post_uuid, timestamp, poster_uuid, post_content);
            postList.append(postElement);
        }
    }

    return postList;
}
