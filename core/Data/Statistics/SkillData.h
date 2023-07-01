#ifndef SKILLDATA_H
#define SKILLDATA_H

#include <QString>

struct SkillData {
    QString name;
    int value{0};
    bool used{false};
};

#endif // SKILLDATA_H
