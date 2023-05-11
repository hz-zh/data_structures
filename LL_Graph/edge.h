#ifndef EDGED_
#define EDGED_

template<class V>
class Edge {
	V src;
	V dest;
	int edgeWeight;
public:
	Edge();
	Edge(V source, V dest, int weight) : src(source), dest(dest), edgeWeight(weight) {}
	~Edge();

	void setSrcDst(const V& s, const V& d) { src = s; dest = d; }
	void setSrcDstWeight(const V& s, const V& d, int w) { src = s; dest = d; edgeWeight = w; }
	void setWeight(int w) { edgeWeight = w; }
	V getSrc() { return src; }
	V getDest() { return dest; }
	V getWeight() { return edgeWeight; }

};


#endif