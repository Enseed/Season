#ifndef __RECLECT_COMPLEXSTRUCT_H_REFLECT_H__
#define __RECLECT_COMPLEXSTRUCT_H_REFLECT_H__
/* This file was generated on 2015-Jul-12 00:04:13 by Reflect */

#include <Enseed/Reflect/API/Class.h>

namespace reflect {


template<> struct Class<SubComplexStruct, 0> : public ClassBase<SubComplexStruct>
{
	typedef SubComplexStruct type;
	static constexpr int parent_count = 0;
	static constexpr int field_count = 2 ;

	struct Fields
	{
		struct mySubStructure
		{
			typedef mySubStructure field_type;
			typedef std::string type;
			typedef const std::string const_type;
			typedef SubComplexStruct host_type;
			typedef const SubComplexStruct const_host_type;
			static const char* name() { return "mySubStructure"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::string& readRef(const SubComplexStruct &target) { return target.mySubStructure; }
			static std::string* writePtr(SubComplexStruct *target) { return &target->mySubStructure; }
		};
		struct sharedIntPtr
		{
			typedef sharedIntPtr field_type;
			typedef std::shared_ptr<int> type;
			typedef const std::shared_ptr<int> const_type;
			typedef SubComplexStruct host_type;
			typedef const SubComplexStruct const_host_type;
			static const char* name() { return "sharedIntPtr"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::shared_ptr<int>& readRef(const SubComplexStruct &target) { return target.sharedIntPtr; }
			static std::shared_ptr<int>* writePtr(SubComplexStruct *target) { return &target->sharedIntPtr; }
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

template<> struct Field<SubComplexStruct, 0> : public Class<SubComplexStruct>::Fields::mySubStructure{};
template<> struct Field<SubComplexStruct, 1> : public Class<SubComplexStruct>::Fields::sharedIntPtr{};

template<> struct SortedField<SubComplexStruct, 0> : public Class<SubComplexStruct>::Fields::mySubStructure{};
template<> struct SortedField<SubComplexStruct, 1> : public Class<SubComplexStruct>::Fields::sharedIntPtr{};

template<> struct Class<ComplexStruct, 0> : public ClassBase<ComplexStruct>
{
	typedef ComplexStruct type;
	static constexpr int parent_count = 0;
	static constexpr int field_count = 10 ;

	struct Fields
	{
		struct intValue
		{
			typedef intValue field_type;
			typedef int type;
			typedef const int const_type;
			typedef ComplexStruct host_type;
			typedef const ComplexStruct const_host_type;
			static const char* name() { return "intValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const int& readRef(const ComplexStruct &target) { return target.intValue; }
			static int* writePtr(ComplexStruct *target) { return &target->intValue; }
		};
		struct stringValue
		{
			typedef stringValue field_type;
			typedef std::string type;
			typedef const std::string const_type;
			typedef ComplexStruct host_type;
			typedef const ComplexStruct const_host_type;
			static const char* name() { return "stringValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::string& readRef(const ComplexStruct &target) { return target.stringValue; }
			static std::string* writePtr(ComplexStruct *target) { return &target->stringValue; }
		};
		struct vectorOfInt
		{
			typedef vectorOfInt field_type;
			typedef std::vector<int> type;
			typedef const std::vector<int> const_type;
			typedef ComplexStruct host_type;
			typedef const ComplexStruct const_host_type;
			static const char* name() { return "vectorOfInt"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::vector<int>& readRef(const ComplexStruct &target) { return target.vectorOfInt; }
			static std::vector<int>* writePtr(ComplexStruct *target) { return &target->vectorOfInt; }
		};
		struct mapOfSharedInt
		{
			typedef mapOfSharedInt field_type;
			typedef std::map<std::string, std::shared_ptr<int> > type;
			typedef const std::map<std::string, std::shared_ptr<int> > const_type;
			typedef ComplexStruct host_type;
			typedef const ComplexStruct const_host_type;
			static const char* name() { return "mapOfSharedInt"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::map<std::string, std::shared_ptr<int> >& readRef(const ComplexStruct &target) { return target.mapOfSharedInt; }
			static std::map<std::string, std::shared_ptr<int> >* writePtr(ComplexStruct *target) { return &target->mapOfSharedInt; }
		};
		struct mapOfInt
		{
			typedef mapOfInt field_type;
			typedef std::map<std::string, int> type;
			typedef const std::map<std::string, int> const_type;
			typedef ComplexStruct host_type;
			typedef const ComplexStruct const_host_type;
			static const char* name() { return "mapOfInt"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::map<std::string, int>& readRef(const ComplexStruct &target) { return target.mapOfInt; }
			static std::map<std::string, int>* writePtr(ComplexStruct *target) { return &target->mapOfInt; }
		};
		struct optionalInt
		{
			typedef optionalInt field_type;
			typedef boost::optional<int> type;
			typedef const boost::optional<int> const_type;
			typedef ComplexStruct host_type;
			typedef const ComplexStruct const_host_type;
			static const char* name() { return "optionalInt"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::optional<int>& readRef(const ComplexStruct &target) { return target.optionalInt; }
			static boost::optional<int>* writePtr(ComplexStruct *target) { return &target->optionalInt; }
		};
		struct subStruct
		{
			typedef subStruct field_type;
			typedef struct SubComplexStruct type;
			typedef const struct SubComplexStruct const_type;
			typedef ComplexStruct host_type;
			typedef const ComplexStruct const_host_type;
			static const char* name() { return "subStruct"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const struct SubComplexStruct& readRef(const ComplexStruct &target) { return target.subStruct; }
			static struct SubComplexStruct* writePtr(ComplexStruct *target) { return &target->subStruct; }
		};
		struct timeValue
		{
			typedef timeValue field_type;
			typedef boost::posix_time::ptime type;
			typedef const boost::posix_time::ptime const_type;
			typedef ComplexStruct host_type;
			typedef const ComplexStruct const_host_type;
			static const char* name() { return "timeValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::posix_time::ptime& readRef(const ComplexStruct &target) { return target.timeValue; }
			static boost::posix_time::ptime* writePtr(ComplexStruct *target) { return &target->timeValue; }
		};
		struct uuidValue
		{
			typedef uuidValue field_type;
			typedef boost::uuids::uuid type;
			typedef const boost::uuids::uuid const_type;
			typedef ComplexStruct host_type;
			typedef const ComplexStruct const_host_type;
			static const char* name() { return "uuidValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::uuids::uuid& readRef(const ComplexStruct &target) { return target.uuidValue; }
			static boost::uuids::uuid* writePtr(ComplexStruct *target) { return &target->uuidValue; }
		};
		struct uriValue
		{
			typedef uriValue field_type;
			typedef network::uri type;
			typedef const network::uri const_type;
			typedef ComplexStruct host_type;
			typedef const ComplexStruct const_host_type;
			static const char* name() { return "uriValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const network::uri& readRef(const ComplexStruct &target) { return target.uriValue; }
			static network::uri* writePtr(ComplexStruct *target) { return &target->uriValue; }
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
		cb(Fields::mapOfSharedInt());
		cb(Fields::mapOfInt());
		cb(Fields::optionalInt());
		cb(Fields::subStruct());
		cb(Fields::timeValue());
		cb(Fields::uuidValue());
		cb(Fields::uriValue());
	}
};

template<> struct Field<ComplexStruct, 0> : public Class<ComplexStruct>::Fields::intValue{};
template<> struct Field<ComplexStruct, 1> : public Class<ComplexStruct>::Fields::stringValue{};
template<> struct Field<ComplexStruct, 2> : public Class<ComplexStruct>::Fields::vectorOfInt{};
template<> struct Field<ComplexStruct, 3> : public Class<ComplexStruct>::Fields::mapOfSharedInt{};
template<> struct Field<ComplexStruct, 4> : public Class<ComplexStruct>::Fields::mapOfInt{};
template<> struct Field<ComplexStruct, 5> : public Class<ComplexStruct>::Fields::optionalInt{};
template<> struct Field<ComplexStruct, 6> : public Class<ComplexStruct>::Fields::subStruct{};
template<> struct Field<ComplexStruct, 7> : public Class<ComplexStruct>::Fields::timeValue{};
template<> struct Field<ComplexStruct, 8> : public Class<ComplexStruct>::Fields::uuidValue{};
template<> struct Field<ComplexStruct, 9> : public Class<ComplexStruct>::Fields::uriValue{};

template<> struct SortedField<ComplexStruct, 0> : public Class<ComplexStruct>::Fields::intValue{};
template<> struct SortedField<ComplexStruct, 1> : public Class<ComplexStruct>::Fields::mapOfInt{};
template<> struct SortedField<ComplexStruct, 2> : public Class<ComplexStruct>::Fields::mapOfSharedInt{};
template<> struct SortedField<ComplexStruct, 3> : public Class<ComplexStruct>::Fields::optionalInt{};
template<> struct SortedField<ComplexStruct, 4> : public Class<ComplexStruct>::Fields::stringValue{};
template<> struct SortedField<ComplexStruct, 5> : public Class<ComplexStruct>::Fields::subStruct{};
template<> struct SortedField<ComplexStruct, 6> : public Class<ComplexStruct>::Fields::timeValue{};
template<> struct SortedField<ComplexStruct, 7> : public Class<ComplexStruct>::Fields::uriValue{};
template<> struct SortedField<ComplexStruct, 8> : public Class<ComplexStruct>::Fields::uuidValue{};
template<> struct SortedField<ComplexStruct, 9> : public Class<ComplexStruct>::Fields::vectorOfInt{};

} // namespace reflect

#endif // __RECLECT_COMPLEXSTRUCT_H_REFLECT_H__
