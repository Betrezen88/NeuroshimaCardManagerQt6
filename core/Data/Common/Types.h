#ifndef TYPES_H
#define TYPES_H

#include "qobjectdefs.h"
#include "qtmetamacros.h"

namespace Types {
Q_NAMESPACE


enum class Requirement { Attribute, Skill, Profession };
Q_ENUM_NS(Requirement)

enum class Modifier { Attribute, Test };
Q_ENUM_NS(Modifier)

enum class Wound { Scratch, Light, Heavy, Critical };
Q_ENUM_NS(Wound)

} // Types

#endif // TYPES_H
