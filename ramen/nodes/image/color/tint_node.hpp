// Copyright (c) 2010 Esteban Tovagliari

#ifndef RAMEN_IMAGE_TINT_NODE_HPP
#define RAMEN_IMAGE_TINT_NODE_HPP

#include<ramen/nodes/image/pointop_node.hpp>

namespace ramen
{
namespace image
{

class tint_node_t : public pointop_node_t
{
public:

    static const node_metaclass_t& tint_node_metaclass();
    virtual const node_metaclass_t *metaclass() const;

    tint_node_t();

protected:

    tint_node_t( const tint_node_t& other) : pointop_node_t(other) {}
    void operator=( const tint_node_t&);

private:

    node_t *do_clone() const { return new tint_node_t(*this);}

    virtual void do_create_params();

    virtual void do_process( const image::const_image_view_t& src, const image::image_view_t& dst, const render::context_t& context);
};

} // namespace
} // namespace

#endif
