#include "frame_metadata_swift_interop_test.h"

#include "frame_metadata.pb.h"

extern "C" {

bool canParseFromArrayWithExpectedValues(const void* data, int size) {
  bazel_scratch::FrameMetadataTestOnly frame_metadata;
  return frame_metadata.ParseFromArray(data, size) &&
         frame_metadata.timestamp_ns() == 10 &&
         frame_metadata.exposure_time_ns() == 5 &&
         frame_metadata.gain() == 3.3f;
}

}  // extern "C"
