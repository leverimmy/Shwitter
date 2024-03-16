#ifndef POSTELEMENT_H
#define POSTELEMENT_H

#include <QDateTime>
#include <QString>

class PostElement {
public:
    explicit PostElement(const QString& post_uuid, const QDateTime& timestamp, const QString& poster_uuid, const QString& post_content);
    QString get_post_uuid() const;
    QDateTime get_timestamp() const;
    QString get_poster_uuid() const;
    QString get_post_content() const;

private:
    QString post_uuid;
    QDateTime timestamp;
    QString poster_uuid;
    QString post_content;
};

#endif // POSTELEMENT_H
