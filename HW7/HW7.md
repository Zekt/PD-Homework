##Problem 1

(a)
Because in every single loop, srand() will take current time as the seed of next rand(), but the loop can be run very fast that 10 loops are all aompleted in the same second, which makes rand() generates the same number evert time.

(b)
It happens when ten times of loop cross two different seconds, and take two different numbers as seeds, which makes rand() generates two kinds of numbers.

##Problem 2

(a)

	double area(Triangle t) {
		double d1,d2,d3,d4;
		d1 = static_cast<double>(t.p2.x-t.p1.x);
		d2 = static_cast<double>(t.p3.y-t.p1.y);
		d3 = static_cast<double>(t.p3.x-t.p1.x);
		d4 = static_cast<double>(t.p2.y-t.p1.y);
		cout << d1 << d2 << d3 << d4 << endl;
		return abs(0.5 * (d1*d2-d3*d4));
	}

(b)

	double Triangle::area() {
		double d1,d2,d3,d4;
		d1 = static_cast<double>(p2.x-p1.x);
		d2 = static_cast<double>(p3.y-p1.y);
		d3 = static_cast<double>(p3.x-p1.x);
		d4 = static_cast<double>(p2.y-p1.y);
		cout << d1 << d2 << d3 << d4 << endl;
		return abs(0.5 * (d1*d2-d3*d4));
	}

(c)
I prefer the implementation of (b), because the area() function is closely and only related to one Triangle structure, and the only variables used in it are all belong to Triangle, so if we take it as a member function, it's more trivial that area() is a function that return a value about Triangle, and it takes less codes in area() since you can ignore anything outside the structure. In short, it's more OO and easier to maintain.
