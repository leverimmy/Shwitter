#ifndef POSTELEMENT_H
#define POSTELEMENT_H

#include <QString>
#include <QDateTime>

class PostElement
{
public:
    explicit PostElement(const QString& post_uuid, const QDateTime& timestamp, const QString& poster_uuid, const QString& post_content);

    QString post_uuid;
    QDateTime timestamp;
    QString poster_uuid;
    QString post_content;
};

#endif // POSTELEMENT_H
