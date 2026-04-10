#include "doctest.h"
#include "Enemy.h"
#include "Drop.h"
TEST_CASE("Enemy with a drop reports it correctly") {
	Drop d{ "Iron Shards", 10 };
	Enemy e{ "Golem", 200, 100, d };


	SUBCASE("hasDrop returns true") {
		CHECK(e.hasDrop());
	}
	SUBCASE("getDrop returns correct name") {
		CHECK(e.getDrop()->name == "Iron Shard");
	}
	SUBCASE("getDrop returns correct gold value") {
		CHECK(e.getDrop()->goldValue == 10);
	}
};
TEST_CASE("Enemy::DropLoot returns and removes the drop") {
	Drop d{ "Iron Shards", 10 };
	Enemy e{ "Golem", 200, 100, d };

	SUBCASE("returns the correct drop") {
		auto dropped = e.dropLoot();
		CHECK(dropped.has_value());
		CHECK(dropped->name == "Iron Shard");
		CHECK(dropped->goldValue == 10);
	}
	SUBCASE("removes the drop so haDrop becomse false") {
		e.dropLoot();
		CHECK(!e.hasDrop());
	}
	SUBCASE("returns nullopt when there is no drop") {
		Enemy noDrop{ "Dummy ", 100, 50 };
		CHECK(!noDrop.dropLoot().has_value());
	}
}