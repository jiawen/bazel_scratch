#ifndef FRAME_METADATA_SWIFT_INTEROP_TEST_H
#define FRAME_METADATA_SWIFT_INTEROP_TEST_H

#ifndef __cplusplus
#include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern bool canParseFromArrayWithExpectedValues(const void *data, int size);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // FRAME_METADATA_SWIFT_INTEROP_TEST_H
