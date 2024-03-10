#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H

#include <QString>
#include <QtSql>

void insert_or_uuid(const QString& follower_uuid, const QString& followee_uuid);

void remove_or_uuid(const QString& follower_uuid, const QString& followee_uuid);

QStringList get_following_uuid(const QString& follower_uuid);

#endif // SUBSCRIPTION_H
