#include "postelement.h"

PostElement::PostElement(const QString& post_uuid, const QDateTime& timestamp, const QString& poster_uuid, const QString& post_content)
    :post_uuid(post_uuid), timestamp(timestamp), poster_uuid(poster_uuid), post_content(post_content) {}
