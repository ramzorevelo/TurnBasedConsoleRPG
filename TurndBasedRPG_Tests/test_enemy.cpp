#include "doctest.h"
#include "Enemy.h"
#include "Drop.h"

TEST_CASE("Enemy without a drop has no drop") {
	Enemy e{ "Dummy", 100, 50 };
	CHECK(!e.hasDrop());
}
