#include <cstdio>
#include <boost/date_time/posix_time/posix_time.hpp>

int main( void  )
{
    namespace pt = boost::posix_time;
    pt::ptime now = pt::second_clock::local_time();

    printf( "%s\t->\t%04d-%02d-%02d %02d:%02d:%02d\n"
          , "date '+%Y-%m-%d %H:%M:%S'"
          , now.date().year()
          , now.date().month()
          , now.date().day()
          , now.time_of_day().hours()
          , now.time_of_day().minutes()
          , now.time_of_day().seconds() );

    return 0;
}
