#include <qglobal.h>

#define KITEMMODELS_EXPORT
#define KITEMMODELS_ENABLE_DEPRECATED_SINCE(x, y) QT_VERSION < QT_VERSION_CHECK(5, 10, 0)
#define KITEMMODELS_BUILD_DEPRECATED_SINCE KITEMMODELS_ENABLE_DEPRECATED_SINCE
#define KITEMMODELS_DEPRECATED_VERSION(x, y, z)
