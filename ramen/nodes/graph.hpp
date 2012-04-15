// Copyright (c) 2010 Esteban Tovagliari
// Licensed under the terms of the CDDL License.
// See CDDL_LICENSE.txt for a copy of the license.

#ifndef RAMEN_NODES_GRAPH_HPP
#define RAMEN_NODES_GRAPH_HPP

#include<algorithm>
#include<memory>
#include<vector>
#include<map>

#include<boost/bind.hpp>
#include<boost/noncopyable.hpp>

#include<boost/intrusive_ptr.hpp>

#include<ramen/nodes/node.hpp>
#include<ramen/nodes/edge.hpp>

namespace ramen
{

class graph : boost::noncopyable
{
public:

    typedef std::vector<node_ptr_t>   node_container_type;

    typedef node_container_type::iterator       node_iterator;
    typedef node_container_type::const_iterator	const_node_iterator;

    typedef node_container_type::reverse_iterator       reverse_node_iterator;
    typedef node_container_type::const_reverse_iterator	const_reverse_node_iterator;

    typedef node_container_type         node_range_type;
    typedef const node_container_type	const_node_range_type;

    typedef std::vector<edge_t>::iterator       edge_iterator;
    typedef std::vector<edge_t>::const_iterator const_edge_iterator;

    typedef std::vector<edge_t>::reverse_iterator       reverse_edge_iterator;
    typedef std::vector<edge_t>::const_reverse_iterator const_reverse_edge_iterator;

    typedef std::vector<edge_t>			edge_range_type;
    typedef const std::vector<edge_t>	const_edge_range_type;

    graph();

    void add_node( node_ptr_t n);
    node_ptr_t release_node( node_t *n);

    void add_edge( const edge_t& e);
    void remove_edge( const edge_t& e);

    node_iterator nodes_begin() { return nodes_.begin();}
    node_iterator nodes_end()   { return nodes_.end();}

    const_node_iterator nodes_begin() const { return nodes_.begin();}
    const_node_iterator nodes_end() const   { return nodes_.end();}

    node_range_type& nodes()                { return nodes_;}
    const_node_range_type& nodes() const    { return nodes_;}

    edge_iterator edges_begin() { return edges_.begin();}
    edge_iterator edges_end()   { return edges_.end();}

    const_edge_iterator edges_begin() const { return edges_.begin();}
    const_edge_iterator edges_end() const   { return edges_.end();}

    const_edge_range_type& edges() const    { return edges_;}
    edge_range_type& edges()                { return edges_;}

    // connections
    void connect( node_t *src, node_t *dst, int port);
    void disconnect( node_t *src, node_t *dst, int port);

private:

    node_container_type nodes_;
    std::vector<edge_t> edges_;
};

} // namespace

#endif
