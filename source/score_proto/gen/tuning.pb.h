// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tuning.proto

#ifndef PROTOBUF_INCLUDED_tuning_2eproto
#define PROTOBUF_INCLUDED_tuning_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_tuning_2eproto 

namespace protobuf_tuning_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_tuning_2eproto
namespace score_proto {
class Tuning;
class TuningDefaultTypeInternal;
extern TuningDefaultTypeInternal _Tuning_default_instance_;
}  // namespace score_proto
namespace google {
namespace protobuf {
template<> ::score_proto::Tuning* Arena::CreateMaybeMessage<::score_proto::Tuning>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace score_proto {

// ===================================================================

class Tuning : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:score_proto.Tuning) */ {
 public:
  Tuning();
  virtual ~Tuning();

  Tuning(const Tuning& from);

  inline Tuning& operator=(const Tuning& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Tuning(Tuning&& from) noexcept
    : Tuning() {
    *this = ::std::move(from);
  }

  inline Tuning& operator=(Tuning&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Tuning& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Tuning* internal_default_instance() {
    return reinterpret_cast<const Tuning*>(
               &_Tuning_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Tuning* other);
  friend void swap(Tuning& a, Tuning& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Tuning* New() const final {
    return CreateMaybeMessage<Tuning>(NULL);
  }

  Tuning* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Tuning>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Tuning& from);
  void MergeFrom(const Tuning& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Tuning* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated uint32 notes = 2;
  int notes_size() const;
  void clear_notes();
  static const int kNotesFieldNumber = 2;
  ::google::protobuf::uint32 notes(int index) const;
  void set_notes(int index, ::google::protobuf::uint32 value);
  void add_notes(::google::protobuf::uint32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
      notes() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
      mutable_notes();

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // uint32 capo = 3;
  void clear_capo();
  static const int kCapoFieldNumber = 3;
  ::google::protobuf::uint32 capo() const;
  void set_capo(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:score_proto.Tuning)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 > notes_;
  mutable int _notes_cached_byte_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::uint32 capo_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_tuning_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Tuning

// string name = 1;
inline void Tuning::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Tuning::name() const {
  // @@protoc_insertion_point(field_get:score_proto.Tuning.name)
  return name_.GetNoArena();
}
inline void Tuning::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:score_proto.Tuning.name)
}
#if LANG_CXX11
inline void Tuning::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:score_proto.Tuning.name)
}
#endif
inline void Tuning::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:score_proto.Tuning.name)
}
inline void Tuning::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:score_proto.Tuning.name)
}
inline ::std::string* Tuning::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:score_proto.Tuning.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Tuning::release_name() {
  // @@protoc_insertion_point(field_release:score_proto.Tuning.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Tuning::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:score_proto.Tuning.name)
}

// repeated uint32 notes = 2;
inline int Tuning::notes_size() const {
  return notes_.size();
}
inline void Tuning::clear_notes() {
  notes_.Clear();
}
inline ::google::protobuf::uint32 Tuning::notes(int index) const {
  // @@protoc_insertion_point(field_get:score_proto.Tuning.notes)
  return notes_.Get(index);
}
inline void Tuning::set_notes(int index, ::google::protobuf::uint32 value) {
  notes_.Set(index, value);
  // @@protoc_insertion_point(field_set:score_proto.Tuning.notes)
}
inline void Tuning::add_notes(::google::protobuf::uint32 value) {
  notes_.Add(value);
  // @@protoc_insertion_point(field_add:score_proto.Tuning.notes)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
Tuning::notes() const {
  // @@protoc_insertion_point(field_list:score_proto.Tuning.notes)
  return notes_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
Tuning::mutable_notes() {
  // @@protoc_insertion_point(field_mutable_list:score_proto.Tuning.notes)
  return &notes_;
}

// uint32 capo = 3;
inline void Tuning::clear_capo() {
  capo_ = 0u;
}
inline ::google::protobuf::uint32 Tuning::capo() const {
  // @@protoc_insertion_point(field_get:score_proto.Tuning.capo)
  return capo_;
}
inline void Tuning::set_capo(::google::protobuf::uint32 value) {
  
  capo_ = value;
  // @@protoc_insertion_point(field_set:score_proto.Tuning.capo)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace score_proto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_tuning_2eproto
