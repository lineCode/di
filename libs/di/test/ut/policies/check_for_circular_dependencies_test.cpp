//
// Copyright (c) 2012 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#define BOOST_DI_STATIC_ASSERT(cond, expr, types) typedef void _

#include <boost/test/unit_test.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include "boost/di/policies/check_for_circular_dependencies.hpp"
#include "data.hpp"

namespace boost {
namespace di {
namespace policies {
namespace test {
namespace ut {

BOOST_AUTO_TEST_CASE(no_circular_dependencies)
{
    BOOST_CHECK((
        !is_base_of<
            mpl::false_
          , check_for_circular_dependencies::verify<
                mpl::vector0<>
             ,  c8
            >::type
         >::value
    ));
}

BOOST_AUTO_TEST_CASE(direct)
{
    BOOST_CHECK((
        is_base_of<
            mpl::false_
          , check_for_circular_dependencies::verify<
                mpl::vector0<>
              , cd1
            >::type
        >::value
    ));
}

BOOST_AUTO_TEST_CASE(in_directo)
{
    BOOST_CHECK((
        is_base_of<
            mpl::false_
          , check_for_circular_dependencies::verify<
                mpl::vector0<>
              , cd5
            >::type
        >::value
    ));
}

} // namespace ut
} // namespace test
} // namespace policies
} // namespace di
} // namespace boost

