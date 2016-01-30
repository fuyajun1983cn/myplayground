
#include <iostream>
namespace UnitedKingdom
{
  std::string London{"Big city"};
}
namespace UnitedStates
{
  namespace KY {
    std::string London{" in Kentucky"};
  }
  namespace OH {
    std::string London{" in Ohio"};
  }
}
int main()
{
  namespace USOH=UnitedStates::OH;
  std::cout<<"London is"<<USOH::London<<'\n';
}
