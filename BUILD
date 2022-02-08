load("@build_bazel_rules_swift//swift:swift.bzl", "swift_proto_library", "swift_test")
load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "frame_metadata_proto",
    srcs = ["frame_metadata.proto"],
)

cc_proto_library(
    name = "frame_metadata_cc_proto",
    deps = [":frame_metadata_proto"],
)

swift_proto_library(
    name = "frame_metadata_swift_proto",
    deps = [":frame_metadata_proto"],
)

cc_test(
    name = "frame_metadata_cc_test",
    srcs = ["frame_metadata_cc_test.cpp"],
    deps = [
        ":frame_metadata_cc_proto",
        "@gtest//:gtest_main",
    ],
)

swift_test(
    name = "frame_metadata_swift_interop_test",
    srcs = ["FrameMetadataSwiftInteropTest.swift"],
    deps = [
        ":frame_metadata_swift_interop_test-c",
        ":frame_metadata_swift_proto",
    ],
)

cc_library(
    name = "frame_metadata_swift_interop_test-c",
    hdrs = ["frame_metadata_swift_interop_test.h"],
    tags = ["swift_module=bazel_scratch"],
    deps = [":frame_metadata_swift_interop_test-cpp"],
)

cc_library(
    name = "frame_metadata_swift_interop_test-cpp",
    srcs = ["frame_metadata_swift_interop_test.cpp"],
    hdrs = ["frame_metadata_swift_interop_test.h"],
    deps = [":frame_metadata_cc_proto"],
)
