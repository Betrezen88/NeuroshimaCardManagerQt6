#ifndef OTHERSKILLDATA_H
#define OTHERSKILLDATA_H

#include <QString>

struct OtherSkillData {
    QString name;
    int value{0};
    bool used{false};
    QString attribute;
};

#endif // OTHERSKILLDATA_H
