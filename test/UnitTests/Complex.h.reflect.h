#ifndef __RECLECT_COMPLEX_H_REFLECT_H__
#define __RECLECT_COMPLEX_H_REFLECT_H__
/* This file was generated on 2015-Jul-12 00:02:32 by Reflect */

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

template<> struct Class<Complex, 0> : public ClassBase<Complex>
{
	typedef Complex type;
	static constexpr int parent_count = 0;
	static constexpr int field_count = 10 ;

	struct Fields
	{
		struct intValue
		{
			typedef intValue field_type;
			typedef int type;
			typedef const int const_type;
			typedef Complex host_type;
			typedef const Complex const_host_type;
			static const char* name() { return "intValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const int& readRef(const Complex &target) { return target.intValue; }
			static int* writePtr(Complex *target) { return &target->intValue; }
		};
		struct stringValue
		{
			typedef stringValue field_type;
			typedef std::string type;
			typedef const std::string const_type;
			typedef Complex host_type;
			typedef const Complex const_host_type;
			static const char* name() { return "stringValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::string& readRef(const Complex &target) { return target.stringValue; }
			static std::string* writePtr(Complex *target) { return &target->stringValue; }
		};
		struct vectorOfInt
		{
			typedef vectorOfInt field_type;
			typedef std::vector<int> type;
			typedef const std::vector<int> const_type;
			typedef Complex host_type;
			typedef const Complex const_host_type;
			static const char* name() { return "vectorOfInt"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::vector<int>& readRef(const Complex &target) { return target.vectorOfInt; }
			static std::vector<int>* writePtr(Complex *target) { return &target->vectorOfInt; }
		};
		struct mapOfSharedInt
		{
			typedef mapOfSharedInt field_type;
			typedef std::map<std::string, std::shared_ptr<int> > type;
			typedef const std::map<std::string, std::shared_ptr<int> > const_type;
			typedef Complex host_type;
			typedef const Complex const_host_type;
			static const char* name() { return "mapOfSharedInt"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::map<std::string, std::shared_ptr<int> >& readRef(const Complex &target) { return target.mapOfSharedInt; }
			static std::map<std::string, std::shared_ptr<int> >* writePtr(Complex *target) { return &target->mapOfSharedInt; }
		};
		struct mapOfInt
		{
			typedef mapOfInt field_type;
			typedef std::map<std::string, int> type;
			typedef const std::map<std::string, int> const_type;
			typedef Complex host_type;
			typedef const Complex const_host_type;
			static const char* name() { return "mapOfInt"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::map<std::string, int>& readRef(const Complex &target) { return target.mapOfInt; }
			static std::map<std::string, int>* writePtr(Complex *target) { return &target->mapOfInt; }
		};
		struct optionalInt
		{
			typedef optionalInt field_type;
			typedef boost::optional<int> type;
			typedef const boost::optional<int> const_type;
			typedef Complex host_type;
			typedef const Complex const_host_type;
			static const char* name() { return "optionalInt"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::optional<int>& readRef(const Complex &target) { return target.optionalInt; }
			static boost::optional<int>* writePtr(Complex *target) { return &target->optionalInt; }
		};
		struct subStruct
		{
			typedef subStruct field_type;
			typedef struct MySubStructure type;
			typedef const struct MySubStructure const_type;
			typedef Complex host_type;
			typedef const Complex const_host_type;
			static const char* name() { return "subStruct"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const struct MySubStructure& readRef(const Complex &target) { return target.subStruct; }
			static struct MySubStructure* writePtr(Complex *target) { return &target->subStruct; }
		};
		struct timeValue
		{
			typedef timeValue field_type;
			typedef boost::posix_time::ptime type;
			typedef const boost::posix_time::ptime const_type;
			typedef Complex host_type;
			typedef const Complex const_host_type;
			static const char* name() { return "timeValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::posix_time::ptime& readRef(const Complex &target) { return target.timeValue; }
			static boost::posix_time::ptime* writePtr(Complex *target) { return &target->timeValue; }
		};
		struct uuidValue
		{
			typedef uuidValue field_type;
			typedef boost::uuids::uuid type;
			typedef const boost::uuids::uuid const_type;
			typedef Complex host_type;
			typedef const Complex const_host_type;
			static const char* name() { return "uuidValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::uuids::uuid& readRef(const Complex &target) { return target.uuidValue; }
			static boost::uuids::uuid* writePtr(Complex *target) { return &target->uuidValue; }
		};
		struct uriValue
		{
			typedef uriValue field_type;
			typedef network::uri type;
			typedef const network::uri const_type;
			typedef Complex host_type;
			typedef const Complex const_host_type;
			static const char* name() { return "uriValue"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const network::uri& readRef(const Complex &target) { return target.uriValue; }
			static network::uri* writePtr(Complex *target) { return &target->uriValue; }
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

template<> struct Field<Complex, 0> : public Class<Complex>::Fields::intValue{};
template<> struct Field<Complex, 1> : public Class<Complex>::Fields::stringValue{};
template<> struct Field<Complex, 2> : public Class<Complex>::Fields::vectorOfInt{};
template<> struct Field<Complex, 3> : public Class<Complex>::Fields::mapOfSharedInt{};
template<> struct Field<Complex, 4> : public Class<Complex>::Fields::mapOfInt{};
template<> struct Field<Complex, 5> : public Class<Complex>::Fields::optionalInt{};
template<> struct Field<Complex, 6> : public Class<Complex>::Fields::subStruct{};
template<> struct Field<Complex, 7> : public Class<Complex>::Fields::timeValue{};
template<> struct Field<Complex, 8> : public Class<Complex>::Fields::uuidValue{};
template<> struct Field<Complex, 9> : public Class<Complex>::Fields::uriValue{};

template<> struct SortedField<Complex, 0> : public Class<Complex>::Fields::intValue{};
template<> struct SortedField<Complex, 1> : public Class<Complex>::Fields::mapOfInt{};
template<> struct SortedField<Complex, 2> : public Class<Complex>::Fields::mapOfSharedInt{};
template<> struct SortedField<Complex, 3> : public Class<Complex>::Fields::optionalInt{};
template<> struct SortedField<Complex, 4> : public Class<Complex>::Fields::stringValue{};
template<> struct SortedField<Complex, 5> : public Class<Complex>::Fields::subStruct{};
template<> struct SortedField<Complex, 6> : public Class<Complex>::Fields::timeValue{};
template<> struct SortedField<Complex, 7> : public Class<Complex>::Fields::uriValue{};
template<> struct SortedField<Complex, 8> : public Class<Complex>::Fields::uuidValue{};
template<> struct SortedField<Complex, 9> : public Class<Complex>::Fields::vectorOfInt{};

} // namespace reflect

#endif // __RECLECT_COMPLEX_H_REFLECT_H__
