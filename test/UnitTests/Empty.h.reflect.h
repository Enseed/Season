#ifndef __RECLECT_EMPTY_H_REFLECT_H__
#define __RECLECT_EMPTY_H_REFLECT_H__
/* This file was generated on 2015-Jul-13 22:14:55 by Reflect */

#include <Enseed/Reflect/API/Class.h>

namespace reflect {


template<> struct Class<Empty, 0> : public ClassBase<Empty>
{
	typedef Empty type;
	static constexpr int parent_count = 0;
	static constexpr int field_count = 0 ;

	struct Fields
	{
	};

	template<typename CB> static void visitParents(CB &cb = CB())
	{
	}

	template<typename CB> static void visitFields(CB &cb = CB())
	{
	}
};



} // namespace reflect

#endif // __RECLECT_EMPTY_H_REFLECT_H__
