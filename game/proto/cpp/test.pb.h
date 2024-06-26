// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef PROTOBUF_test_2eproto__INCLUDED
#define PROTOBUF_test_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_test_2eproto();
void protobuf_AssignDesc_test_2eproto();
void protobuf_ShutdownFile_test_2eproto();

class sTest;

// ===================================================================

class sTest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:sTest) */ {
 public:
  sTest();
  virtual ~sTest();

  sTest(const sTest& from);

  inline sTest& operator=(const sTest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const sTest& default_instance();

  void Swap(sTest* other);

  // implements Message ----------------------------------------------

  inline sTest* New() const { return New(NULL); }

  sTest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const sTest& from);
  void MergeFrom(const sTest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(sTest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 uid = 1;
  void clear_uid();
  static const int kUidFieldNumber = 1;
  ::google::protobuf::int32 uid() const;
  void set_uid(::google::protobuf::int32 value);

  // optional string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // repeated int32 nums = 3;
  int nums_size() const;
  void clear_nums();
  static const int kNumsFieldNumber = 3;
  ::google::protobuf::int32 nums(int index) const;
  void set_nums(int index, ::google::protobuf::int32 value);
  void add_nums(::google::protobuf::int32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      nums() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_nums();

  // @@protoc_insertion_point(class_scope:sTest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > nums_;
  mutable int _nums_cached_byte_size_;
  ::google::protobuf::int32 uid_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_test_2eproto();
  friend void protobuf_AssignDesc_test_2eproto();
  friend void protobuf_ShutdownFile_test_2eproto();

  void InitAsDefaultInstance();
  static sTest* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// sTest

// optional int32 uid = 1;
inline void sTest::clear_uid() {
  uid_ = 0;
}
inline ::google::protobuf::int32 sTest::uid() const {
  // @@protoc_insertion_point(field_get:sTest.uid)
  return uid_;
}
inline void sTest::set_uid(::google::protobuf::int32 value) {
  
  uid_ = value;
  // @@protoc_insertion_point(field_set:sTest.uid)
}

// optional string name = 2;
inline void sTest::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& sTest::name() const {
  // @@protoc_insertion_point(field_get:sTest.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void sTest::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:sTest.name)
}
inline void sTest::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:sTest.name)
}
inline void sTest::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:sTest.name)
}
inline ::std::string* sTest::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:sTest.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* sTest::release_name() {
  // @@protoc_insertion_point(field_release:sTest.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void sTest::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:sTest.name)
}

// repeated int32 nums = 3;
inline int sTest::nums_size() const {
  return nums_.size();
}
inline void sTest::clear_nums() {
  nums_.Clear();
}
inline ::google::protobuf::int32 sTest::nums(int index) const {
  // @@protoc_insertion_point(field_get:sTest.nums)
  return nums_.Get(index);
}
inline void sTest::set_nums(int index, ::google::protobuf::int32 value) {
  nums_.Set(index, value);
  // @@protoc_insertion_point(field_set:sTest.nums)
}
inline void sTest::add_nums(::google::protobuf::int32 value) {
  nums_.Add(value);
  // @@protoc_insertion_point(field_add:sTest.nums)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
sTest::nums() const {
  // @@protoc_insertion_point(field_list:sTest.nums)
  return nums_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
sTest::mutable_nums() {
  // @@protoc_insertion_point(field_mutable_list:sTest.nums)
  return &nums_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_test_2eproto__INCLUDED
