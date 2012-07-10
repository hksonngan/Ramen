// Copyright (c) 2010 Esteban Tovagliari
// Licensed under the terms of the CDDL License.
// See CDDL_LICENSE.txt for a copy of the license.

#include<ramen/app/preferences.hpp>

#include<ramen/assert.hpp>

namespace ramen
{

preferences_t::preferences_t( boost::python::object obj)
{
    RAMEN_ASSERT( !obj.is_none());
    impl_ = obj;
}

} // namespace
