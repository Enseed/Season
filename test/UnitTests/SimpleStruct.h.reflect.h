#ifndef __RECLECT_SIMPLESTRUCT_H_REFLECT_H__
#define __RECLECT_SIMPLESTRUCT_H_REFLECT_H__
/* This file was generated on 2015-Jul-13 22:14:57 by Reflect */

#include <Enseed/Reflect/API/Class.h>

namespace reflect {


template<> struct Class<SimpleStruct, 0> : public ClassBase<SimpleStruct>
{
	typedef SimpleStruct type;
	static constexpr int parent_count = 0;
	static constexpr int field_count = 2 ;

	struct Fields
	{
		struct a
		{
			typedef a field_type;
			typedef int type;
			typedef const int const_type;
			typedef SimpleStruct host_type;
			typedef const SimpleStruct const_host_type;
			static const char* name() { return "a"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const int& readRef(const SimpleStruct &target) { return target.a; }
			static int* writePtr(SimpleStruct *target) { return &target->a; }
		};
		struct b
		{
			typedef b field_type;
			typedef double type;
			typedef const double const_type;
			typedef SimpleStruct host_type;
			typedef const SimpleStruct const_host_type;
			static const char* name() { return "b"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const double& readRef(const SimpleStruct &target) { return target.b; }
			static double* writePtr(SimpleStruct *target) { return &target->b; }
		};
	};

	template<typename CB> static void visitParents(CB &cb = CB())
	{
	}

	template<typename CB> static void visitFields(CB &cb = CB())
	{
		cb(Fields::a());
		cb(Fields::b());
	}
};

template<> struct Field<SimpleStruct, 0> : public Class<SimpleStruct>::Fields::a{};
template<> struct Field<SimpleStruct, 1> : public Class<SimpleStruct>::Fields::b{};

template<> struct SortedField<SimpleStruct, 0> : public Class<SimpleStruct>::Fields::a{};
template<> struct SortedField<SimpleStruct, 1> : public Class<SimpleStruct>::Fields::b{};

} // namespace reflect

#endif // __RECLECT_SIMPLESTRUCT_H_REFLECT_H__
