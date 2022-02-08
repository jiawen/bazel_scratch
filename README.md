# bazel_scratch

Tests demonstrating how to interop protobuf instances between C++ and Swift by serialization.

## Run tests (MacOS)

`bazel test //:all`.

## Run tests (Linux with Swift 5.4.1+ and Clang)

### clang 12: works

`CC=clang-12 bazel test //:all`

### clang 13: broken

`CC=clang-13 bazel test //:all`

```
ld.lld: error: undefined hidden symbol: __start_swift5_protocols
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())
>>> the encapsulation symbol needs to be retained under --gc-sections properly; consider -z nostart-stop-gc (see https://lld.llvm.org/ELF/start-stop-gc)

ld.lld: error: undefined hidden symbol: __stop_swift5_protocols
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())

ld.lld: error: undefined hidden symbol: __start_swift5_protocol_conformances
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())
>>> the encapsulation symbol needs to be retained under --gc-sections properly; consider -z nostart-stop-gc (see https://lld.llvm.org/ELF/start-stop-gc)

ld.lld: error: undefined hidden symbol: __stop_swift5_protocol_conformances
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())

ld.lld: error: undefined hidden symbol: __start_swift5_type_metadata
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())
>>> the encapsulation symbol needs to be retained under --gc-sections properly; consider -z nostart-stop-gc (see https://lld.llvm.org/ELF/start-stop-gc)

ld.lld: error: undefined hidden symbol: __stop_swift5_type_metadata
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())

ld.lld: error: undefined hidden symbol: __start_swift5_assocty
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())
>>> the encapsulation symbol needs to be retained under --gc-sections properly; consider -z nostart-stop-gc (see https://lld.llvm.org/ELF/start-stop-gc)

ld.lld: error: undefined hidden symbol: __stop_swift5_assocty
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())

ld.lld: error: undefined hidden symbol: __start_swift5_replace
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())
>>> the encapsulation symbol needs to be retained under --gc-sections properly; consider -z nostart-stop-gc (see https://lld.llvm.org/ELF/start-stop-gc)

ld.lld: error: undefined hidden symbol: __stop_swift5_replace
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())

ld.lld: error: undefined hidden symbol: __start_swift5_replac2
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())
>>> the encapsulation symbol needs to be retained under --gc-sections properly; consider -z nostart-stop-gc (see https://lld.llvm.org/ELF/start-stop-gc)

ld.lld: error: undefined hidden symbol: __stop_swift5_replac2
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())

ld.lld: error: undefined hidden symbol: __start_swift5_builtin
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())
>>> the encapsulation symbol needs to be retained under --gc-sections properly; consider -z nostart-stop-gc (see https://lld.llvm.org/ELF/start-stop-gc)

ld.lld: error: undefined hidden symbol: __stop_swift5_builtin
>>> referenced by SwiftRT-ELF.cpp
>>>               /usr/lib/swift/linux/x86_64/swiftrt.o:(swift_image_constructor())
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```
