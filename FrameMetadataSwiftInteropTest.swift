import XCTest
import bazel_scratch
import frame_metadata_proto

class FrameMetadataSwiftTest: XCTestCase {

  func testCanSerializeSwiftStructAndCanParseFromArrayWithExpectedValuesInCpp() throws {
    let frameMetadata = BazelScratch_FrameMetadataTestOnly.with {
      $0.timestampNs = 10
      $0.exposureTimeNs = 5
      $0.gain = 3.3
    }

    // Serialize to binary protobuf format.
    let binaryData: Data = try frameMetadata.serializedData()

    // Zero-copy the Data buffer to C++, attempt to parse it there, and ask the C++ side to validate
    // each Message field.
    binaryData.withUnsafeBytes { rawBufferPointer in
      let ptr = rawBufferPointer.baseAddress!
      let count = rawBufferPointer.count
      XCTAssertTrue(canParseFromArrayWithExpectedValues(ptr, Int32(count)))
    }
  }

  static var allTests = [
    (
      "testCanSerializeSwiftStructAndCanParseFromArrayWithExpectedValuesInCpp",
      testCanSerializeSwiftStructAndCanParseFromArrayWithExpectedValuesInCpp
    )
  ]
}

#if os(Linux)
  XCTMain([
    testCase(FrameMetadataSwiftTest.allTests)
  ])
#endif
