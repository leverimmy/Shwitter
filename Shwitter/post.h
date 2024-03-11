#ifndef POST_H
#define POST_H

#include <QString>
#include <QtSql>

#include "postelement.h"
#include "utils.h"
#include "subscription.h"

void insert_or_post(const QString& poster_uuid, const QString& text);

void remove_or_post(const QString& post_uuid);

QList<PostElement> get_following_posts(const QString& follower_uuid);

#endif // POST_H
