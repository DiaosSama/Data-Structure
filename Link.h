#pragma once
template <typename Elem>
class Link {
public:
	Elem element;
	Link *next;
	Link(const Elem& elemval, Link* nextval = NULL) {
		element = elemval;
		next = nextval;
	}
	Link(Link* nextval = NULL) { next = nextval; }
};