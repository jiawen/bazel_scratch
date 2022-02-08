workspace(name = "bazel_scratch")

# Protocol buffers.
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "gtest",
    branch = "v1.10.x",
    remote = "https://github.com/google/googletest",
)

http_archive(
    name = "com_google_protobuf",
    sha256 = "3bd7828aa5af4b13b99c191e8b1e884ebfa9ad371b0ce264605d347f135d2568",
    strip_prefix = "protobuf-3.19.4",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/v3.19.4.tar.gz"],
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")

protobuf_deps()

http_archive(
    name = "rules_proto",
    sha256 = "b9e1268c5bce4bb01ef31730300b8a4f562dc1211088f125c39af716f6f65f60",
    strip_prefix = "rules_proto-e507ccded37c389186afaeb2b836ec576dc875dc",
    urls = [
        "https://github.com/bazelbuild/rules_proto/archive/e507ccded37c389186afaeb2b836ec576dc875dc.tar.gz",
    ],
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

## Swift rules.

http_archive(
    name = "build_bazel_rules_swift",
    sha256 = "3e52a508cdc47a7adbad36a3d2b712e282cc39cc211b0d63efcaf608961eb36b",
    url = "https://github.com/bazelbuild/rules_swift/releases/download/0.26.0/rules_swift.0.26.0.tar.gz",
)

load(
    "@build_bazel_rules_swift//swift:repositories.bzl",
    "swift_rules_dependencies",
)

swift_rules_dependencies()

load(
    "@build_bazel_rules_swift//swift:extras.bzl",
    "swift_rules_extra_dependencies",
)

swift_rules_extra_dependencies()
