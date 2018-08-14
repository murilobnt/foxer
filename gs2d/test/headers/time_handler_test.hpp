#include <cxxtest/TestSuite.h>
#include "../../include/gs2d_engine/concrete/time_handler.hpp"

class TimeHandlerTest : public CxxTest::TestSuite,
        public TimeHandler {
public:
void testAddition( void )
{
        TS_ASSERT( 1 + 1 > 1 );
        TS_ASSERT_EQUALS( 1 + 1, 2 );
}
};
