#include "frame_metadata.pb.h"
#include "gtest/gtest.h"

namespace bazel_scratch {
namespace {

TEST(FrameMetadataTest, BasicCorrectness) {
  FrameMetadataTestOnly frame_metadata;
  frame_metadata.set_timestamp_ns(5);

  EXPECT_EQ(frame_metadata.timestamp_ns(), 5);
}

}  // namespace
}  // namespace bazel_scratch
