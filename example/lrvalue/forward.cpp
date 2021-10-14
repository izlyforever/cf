#include <bits/stdc++.h>

void overloaded( int const& arg ) { std::cout << arg << " by lvalue\n"; }
void overloaded( int&& arg ) { std::cout << arg << " by rvalue\n"; }
 
template< typename t >
/* "t&& " with "t" being template param is special, and  adjusts "t" to be
  (for example) "int& " or non-ref "int" so std::forward knows what to do. */
void forwarding( t&& arg ) {
  std::cout << "via std::forward: ";
  overloaded( std::forward< t >( arg ) );
  std::cout << "via std::move: ";
  overloaded( std::move( arg ) ); // conceptually this would invalidate arg
  std::cout << "by simple passing: ";
  overloaded( arg );
}
 
int main() {
  std::cout << "initial caller passes rvalue:\n";
  forwarding( 5 );
  std::cout << "initial caller passes lvalue:\n";
  int x = 6;
  forwarding( x );
}