// Copyright (c) 2012 Esteban Tovagliari
// Licensed under the terms of the CDDL License.
// See CDDL_LICENSE.txt for a copy of the license.

#ifndef RAMEN_UI_GRAPH_LAYOUT_HPP
#define RAMEN_UI_GRAPH_LAYOUT_HPP

#include<ramen/config.hpp>

#include<ramen/ui/graph_layout_fwd.hpp>

#include<boost/noncopyable.hpp>

namespace ramen
{
namespace ui
{

class RAMEN_API graph_layout_t : boost::noncopyable
{
public:

    graph_layout_t();
    virtual ~graph_layout_t();

    graph_layout_t *clone() const;

protected:

    graph_layout_t( const graph_layout_t& other);
    void operator=( const graph_layout_t&);

private:

    virtual graph_layout_t *do_clone() const = 0;
};

/*************************************************************************/

class RAMEN_API simple_graph_layout_t : public graph_layout_t
{
public:

    simple_graph_layout_t();

protected:

    simple_graph_layout_t( const simple_graph_layout_t& other);

private:

    virtual graph_layout_t *do_clone() const;
};

} // namespace
} // namespace

#endif
