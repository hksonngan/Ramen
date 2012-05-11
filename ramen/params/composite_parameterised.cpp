// Copyright (c) 2012 Esteban Tovagliari
// Licensed under the terms of the CDDL License.
// See CDDL_LICENSE.txt for a copy of the license.

#include<ramen/params/composite_parameterised.hpp>

#include<ramen/container/ptr_vector_util.hpp>

namespace ramen
{

composite_parameterised_t::composite_parameterised_t() : parameterised_t() {}

composite_parameterised_t::composite_parameterised_t( const composite_parameterised_t& other) : parameterised_t( other) {}

composite_parameterised_t::~composite_parameterised_t()
{
	// empty destructor to allow auto_prt to use an incomplete type.
	// Do not remove.
}

void composite_parameterised_t::add_parameterised( std::auto_ptr<parameterised_t> p)
{
    p->set_parent( this);
    children().push_back( p);
}

std::auto_ptr<parameterised_t> composite_parameterised_t::remove_parameterised( parameterised_t *p)
{
    return container::release_ptr( p, children_);
}

} // namespace