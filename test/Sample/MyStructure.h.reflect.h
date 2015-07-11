#ifndef __RECLECT_MYSTRUCTURE_H_REFLECT_H__
#define __RECLECT_MYSTRUCTURE_H_REFLECT_H__
/* This file was generated on 2015-Jul-11 15:29:47 by Reflect */

#include <Enseed/Reflect/API/Class.h>

namespace reflect {


template<> struct Class<MySubStructure, 0> : public ClassBase<MySubStructure>
{
	typedef MySubStructure type;
	static constexpr int parent_count = 0;
	static constexpr int field_count = 2 ;

	struct Fields
	{
		struct mySubStructure
		{
			typedef mySubStructure field_type;
			typedef std::string type;
			typedef const std::string const_type;
			typedef MySubStructure host_type;
			typedef const MySubStructure const_host_type;
			static const char* name() { return "mySubStructure"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::string& readRef(const MySubStructure &target) { return target.mySubStructure; }
			static std::string* writePtr(MySubStructure *target) { return &target->mySubStructure; }
		};
		struct sharedIntPtr
		{
			typedef sharedIntPtr field_type;
			typedef std::shared_ptr<int> type;
			typedef const std::shared_ptr<int> const_type;
			typedef MySubStructure host_type;
			typedef const MySubStructure const_host_type;
			static const char* name() { return "sharedIntPtr"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::shared_ptr<int>& readRef(const MySubStructure &target) { return target.sharedIntPtr; }
			static std::shared_ptr<int>* writePtr(MySubStructure *target) { return &target->sharedIntPtr; }
		};
	};

	template<typename CB> static void visitParents(CB &cb = CB())
	{
	}

	template<typename CB> static void visitFields(CB &cb = CB())
	{
		cb(Fields::mySubStructure());
		cb(Fields::sharedIntPtr());
	}
};

template<> struct Field<MySubStructure, 0> : public Class<MySubStructure>::Fields::mySubStructure{};
template<> struct Field<MySubStructure, 1> : public Class<MySubStructure>::Fields::sharedIntPtr{};

template<> struct SortedField<MySubStructure, 0> : public Class<MySubStructure>::Fields::mySubStructure{};
template<> struct SortedField<MySubStructure, 1> : public Class<MySubStructure>::Fields::sharedIntPtr{};

template<> struct Class<MyStructure, 0> : public ClassBase<MyStructure>
{
	typedef MyStructure type;
	static constexpr int parent_count = 0;
	static constexpr int field_count = 8 ;

	struct Fields
	{
		struct intValue
		{
			typedef intValue field_type;
			typedef int type;
			typedef const int const_type;
			typedef MyStructure host_type;
			typedef const MyStructure const_host_type;
			static const char* name() { return "intValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const int& readRef(const MyStructure &target) { return target.intValue; }
			static int* writePtr(MyStructure *target) { return &target->intValue; }
		};
		struct stringValue
		{
			typedef stringValue field_type;
			typedef std::string type;
			typedef const std::string const_type;
			typedef MyStructure host_type;
			typedef const MyStructure const_host_type;
			static const char* name() { return "stringValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::string& readRef(const MyStructure &target) { return target.stringValue; }
			static std::string* writePtr(MyStructure *target) { return &target->stringValue; }
		};
		struct vectorOfInt
		{
			typedef vectorOfInt field_type;
			typedef std::vector<int> type;
			typedef const std::vector<int> const_type;
			typedef MyStructure host_type;
			typedef const MyStructure const_host_type;
			static const char* name() { return "vectorOfInt"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::vector<int>& readRef(const MyStructure &target) { return target.vectorOfInt; }
			static std::vector<int>* writePtr(MyStructure *target) { return &target->vectorOfInt; }
		};
		struct mapOfInt
		{
			typedef mapOfInt field_type;
			typedef std::map<std::string, int> type;
			typedef const std::map<std::string, int> const_type;
			typedef MyStructure host_type;
			typedef const MyStructure const_host_type;
			static const char* name() { return "mapOfInt"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::map<std::string, int>& readRef(const MyStructure &target) { return target.mapOfInt; }
			static std::map<std::string, int>* writePtr(MyStructure *target) { return &target->mapOfInt; }
		};
		struct optionalInt
		{
			typedef optionalInt field_type;
			typedef boost::optional<int> type;
			typedef const boost::optional<int> const_type;
			typedef MyStructure host_type;
			typedef const MyStructure const_host_type;
			static const char* name() { return "optionalInt"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::optional<int>& readRef(const MyStructure &target) { return target.optionalInt; }
			static boost::optional<int>* writePtr(MyStructure *target) { return &target->optionalInt; }
		};
		struct subStruct
		{
			typedef subStruct field_type;
			typedef struct MySubStructure type;
			typedef const struct MySubStructure const_type;
			typedef MyStructure host_type;
			typedef const MyStructure const_host_type;
			static const char* name() { return "subStruct"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const struct MySubStructure& readRef(const MyStructure &target) { return target.subStruct; }
			static struct MySubStructure* writePtr(MyStructure *target) { return &target->subStruct; }
		};
		struct timeValue
		{
			typedef timeValue field_type;
			typedef boost::posix_time::ptime type;
			typedef const boost::posix_time::ptime const_type;
			typedef MyStructure host_type;
			typedef const MyStructure const_host_type;
			static const char* name() { return "timeValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::posix_time::ptime& readRef(const MyStructure &target) { return target.timeValue; }
			static boost::posix_time::ptime* writePtr(MyStructure *target) { return &target->timeValue; }
		};
		struct uuidValue
		{
			typedef uuidValue field_type;
			typedef boost::uuids::uuid type;
			typedef const boost::uuids::uuid const_type;
			typedef MyStructure host_type;
			typedef const MyStructure const_host_type;
			static const char* name() { return "uuidValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::uuids::uuid& readRef(const MyStructure &target) { return target.uuidValue; }
			static boost::uuids::uuid* writePtr(MyStructure *target) { return &target->uuidValue; }
		};
	};

	template<typename CB> static void visitParents(CB &cb = CB())
	{
	}

	template<typename CB> static void visitFields(CB &cb = CB())
	{
		cb(Fields::intValue());
		cb(Fields::stringValue());
		cb(Fields::vectorOfInt());
		cb(Fields::mapOfInt());
		cb(Fields::optionalInt());
		cb(Fields::subStruct());
		cb(Fields::timeValue());
		cb(Fields::uuidValue());
	}
};

template<> struct Field<MyStructure, 0> : public Class<MyStructure>::Fields::intValue{};
template<> struct Field<MyStructure, 1> : public Class<MyStructure>::Fields::stringValue{};
template<> struct Field<MyStructure, 2> : public Class<MyStructure>::Fields::vectorOfInt{};
template<> struct Field<MyStructure, 3> : public Class<MyStructure>::Fields::mapOfInt{};
template<> struct Field<MyStructure, 4> : public Class<MyStructure>::Fields::optionalInt{};
template<> struct Field<MyStructure, 5> : public Class<MyStructure>::Fields::subStruct{};
template<> struct Field<MyStructure, 6> : public Class<MyStructure>::Fields::timeValue{};
template<> struct Field<MyStructure, 7> : public Class<MyStructure>::Fields::uuidValue{};

template<> struct SortedField<MyStructure, 0> : public Class<MyStructure>::Fields::intValue{};
template<> struct SortedField<MyStructure, 1> : public Class<MyStructure>::Fields::mapOfInt{};
template<> struct SortedField<MyStructure, 2> : public Class<MyStructure>::Fields::optionalInt{};
template<> struct SortedField<MyStructure, 3> : public Class<MyStructure>::Fields::stringValue{};
template<> struct SortedField<MyStructure, 4> : public Class<MyStructure>::Fields::subStruct{};
template<> struct SortedField<MyStructure, 5> : public Class<MyStructure>::Fields::timeValue{};
template<> struct SortedField<MyStructure, 6> : public Class<MyStructure>::Fields::uuidValue{};
template<> struct SortedField<MyStructure, 7> : public Class<MyStructure>::Fields::vectorOfInt{};

} // namespace reflect

#endif // __RECLECT_MYSTRUCTURE_H_REFLECT_H__
