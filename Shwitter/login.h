#ifndef LOGIN_H
#define LOGIN_H

#include <QString>
#include <QtSql>

bool is_valid_username_and_password(const QString& username, const QString& password);

#endif // LOGIN_H
