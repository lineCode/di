//
// Copyright (c) 2012-2013 Krzysztof Jusiak (krzysztof at jusiak dot net)
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef BOOST_DI_CONFIG_HPP
#define BOOST_DI_CONFIG_HPP

#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/arithmetic/sub.hpp>
#include <boost/mpl/limits/vector.hpp>
#include <boost/mpl/aux_/na.hpp>
#include <boost/config.hpp>

#if !defined(BOOST_DI_CTOR_CFG_VA_ARGS) &&          \
    !defined(BOOST_DI_CTOR_CFG_BRACKET)
    #define BOOST_DI_CTOR_CFG_VA_ARGS
#endif

#if !defined(BOOST_DI_CONSTRUCTOR)
    #define BOOST_DI_CONSTRUCTOR boost_di_constructor__
#endif

#if !defined(BOOST_DI_CREATE)
    #define BOOST_DI_CREATE boost_di_create__
#endif

#define BOOST_DI_ITERATION_PARAMS(start, file)      \
     3, (start, BOOST_MPL_LIMIT_VECTOR_SIZE, file)

#define BOOST_DI_TYPES_DEFAULT_MPL(T)               \
     BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(           \
         BOOST_MPL_LIMIT_VECTOR_SIZE                \
       , typename T                                 \
       , ::boost::mpl::na                           \
     )

#define BOOST_DI_TYPES_MPL(T)                       \
     BOOST_PP_ENUM_PARAMS(                          \
         BOOST_MPL_LIMIT_VECTOR_SIZE                \
       , typename T                                 \
     )

#define BOOST_DI_TYPES_MPL_NA(count)                \
     BOOST_PP_ENUM_PARAMS(                          \
         BOOST_PP_SUB(                              \
             BOOST_MPL_LIMIT_VECTOR_SIZE            \
           , count                                  \
         )                                          \
       , ::boost::mpl::na BOOST_PP_INTERCEPT        \
     )

#define BOOST_DI_TYPES_PASS_MPL(T)                  \
     BOOST_PP_ENUM_PARAMS(                          \
         BOOST_MPL_LIMIT_VECTOR_SIZE                \
       , T                                          \
     )

#define BOOST_DI_TYPES(T)                           \
     BOOST_PP_ENUM_PARAMS(                          \
         BOOST_PP_ITERATION()                       \
       , typename T                                 \
     )

#define BOOST_DI_TYPES_PASS(T)                      \
     BOOST_PP_ENUM_PARAMS(                          \
         BOOST_PP_ITERATION()                       \
       , T                                          \
     )

#define BOOST_DI_ARGS(T, arg)                       \
     BOOST_PP_ENUM_BINARY_PARAMS(                   \
         BOOST_PP_ITERATION()                       \
       , const T                                    \
       , &arg                                       \
     )

#define BOOST_DI_ARGS_NOT_USED(T)                   \
     BOOST_PP_ENUM_BINARY_PARAMS(                   \
         BOOST_PP_ITERATION()                       \
       , const T                                    \
       , & BOOST_PP_INTERCEPT                       \
     )

#define BOOST_DI_ARGS_PASS(arg)                     \
     BOOST_PP_ENUM_PARAMS(                          \
         BOOST_PP_ITERATION()                       \
       , arg                                        \
     )

#endif

