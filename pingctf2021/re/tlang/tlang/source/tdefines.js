let a = (x, n) => {
	let i = 1;
	for (let j = 0; j < n; j++) i *= x;
	return i;
}
let b = (x) => {
	return !x;
}
let c = (x, y) => {
	return x + y != 0;
}
let d = (x, y) => {
	return x + y == 0;
}
let e = (x, y) => {
	return x + y == 2;
}
let f = (x, y) => {
	return x + y != 2;
}
let g = (x, y) => {
	return c(b(c(b(x),e(x,y))),b(c(b(y),e(x,y))));
}
let z = (x, y) => {
	return b(c(b(c(b(x),e(x,y))),b(c(b(y),e(x,y)))));
}
let m = (x, y) => {
	return f(z(x, y), b(y));
}
let n = (x, y) => {
	return f(z(x, y), b(x));
}
let o = (x, y) => {
	return f(n(x,e(y,x)),z(y,x));
}
let s = (x, y) => {
	return e(b(c(y,x)), x);
}
let u = (x, y) => {
	return d(e(f(y,x),y),y);
}
let q = (x, y) => {
	return x == y;
}
let A = (x, y) => {
	return x & y;
}
let B = (x, y) => {
	return x | y;
}
let C = (x, y) => {
	return b(z(z(z(x,y),y),x));
}
let D = (x, y) => {
	return d(s(C(x, q(y, x)),z(b(x),y)),A(x,y));
}
let R = (x, y) => {
	return q(o(x,y), n(x,y));
}
let E = (x, y) => {
	return o(B(A(R(A(x,y),y),x),y),x);
}




let h = (w, v, p) => {
	let r = 0;
	let x = w > v ? w : v;
	let y = w <= v ? w : v;
	for (let i = 0; x > 0; i++) {
		y = y <= 0 ? 0 : y;
		r += (+p(!!(y%2),!!(x%2)))*a(2,i);
		y = parseInt(y / 2);
		x = parseInt(x / 2);
	}
	return r;
}
module.exports = [a,b,c,d,e,f,g,z,m,n,o,s,u,q,A,B,C,D,E,R,h];