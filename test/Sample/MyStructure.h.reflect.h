#ifndef __RECLECT_MYSTRUCTURE_H_REFLECT_H__
#define __RECLECT_MYSTRUCTURE_H_REFLECT_H__
/* This file was generated on 2015-Jul-07 23:08:33 by Reflect */

#include <Enseed/Reflect/API/Class.h>

namespace reflect {


template<> struct Class<MyStructure, 0> : public ClassBase<MyStructure>
{
	typedef MyStructure type;
	static constexpr int parent_count = 0;
	static constexpr int field_count = 2 ;

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
	};

	template<typename CB> static void visitParents(CB &cb = CB())
	{
	}

	template<typename CB> static void visitFields(CB &cb = CB())
	{
		cb(Fields::intValue());
		cb(Fields::stringValue());
	}
};

template<> struct Field<MyStructure, 0> : public Class<MyStructure>::Fields::intValue{};
template<> struct Field<MyStructure, 1> : public Class<MyStructure>::Fields::stringValue{};

template<> struct SortedField<MyStructure, 0> : public Class<MyStructure>::Fields::intValue{};
template<> struct SortedField<MyStructure, 1> : public Class<MyStructure>::Fields::stringValue{};

} // namespace reflect

#endif // __RECLECT_MYSTRUCTURE_H_REFLECT_H__
