int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
/*
	While the Euclidean algorithm calculates only the greatest common divisor (GCD) of two integers x and y, the extended version also finds a way to represent GCD in terms of a and b, i.e. coefficients x and y for which:
	a.x+b.y=GCD(x,y)
	Now, we know Diophantine Equations.These are the polynomial equations for which integral solutions exist.Ex: 3x+7y=1 or x2-y2=z3.
	For CP, we only need to deal with ax+by=c . Here,  solutions exist only if gcd(a,b) divides c.
	Now, how to find x and y if we have to find the value of x and y if we are given the equation or we can come in a situation where we need to solve this equation.
	ax+by=gcd(a,b)
	gcd(a,b)=gcd(b,a%b)  
	gcd(b,a%b)=bx1+(a%b)y1 
	Now, a%b=a-(a/b)*b 
	From above, ax+by=bx1+(a%b)y1 
	ax+by=bx1+(a-(a/b)*b )y1
	ax+by=ay1+b(x1-(a/b)*y1)
	So, comparing the coefficients of a and b, 
	x=y1   and y=x1-(a/b)*y1
*/
Code:
struct Triplet
{
   int x,y,gcd;
};
Triplet extendedEuclid(int a, int b)
{
   if(b == 0){
       Triplet ans;
       ans.gcd = a;
       ans.x = 1;
       ans.y = 0;
       return ans;
   }
   Triplet next = extendedEuclid(b, a%b);
   Triplet ans;
   ans.gcd = next.gcd;
   ans.x = next.y;
   ans.y = next.x - (a/b)*next.y;
   return ans;
}

