#include "postelement.h"

PostElement::PostElement(const QString& post_uuid, const QDateTime& timestamp, const QString& poster_uuid, const QString& post_content)
    :post_uuid(post_uuid), timestamp(timestamp), poster_uuid(poster_uuid), post_content(post_content) {}

QString PostElement::get_post_uuid() const {
    return post_uuid;
}

QDateTime PostElement::get_timestamp() const {
    return timestamp;
}

QString PostElement::get_poster_uuid() const {
    return poster_uuid;
}

QString PostElement::get_post_content() const {
    return post_content;
}
