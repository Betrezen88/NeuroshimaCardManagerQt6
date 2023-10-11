#ifndef TYPES_CREATION_H
#define TYPES_CREATION_H

#include "qobjectdefs.h"
#include "qtmetamacros.h"

namespace TypesCreation {
Q_NAMESPACE

enum class Skillpack { General, Choosable };
Q_ENUM_NS(Skillpack)

enum class Skill { Single, List };
Q_ENUM_NS(Skill)

} // TypesCreation

#endif // TYPES_CREATION_H
