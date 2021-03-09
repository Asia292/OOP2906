#include "Lvl1.h"

Lvl1::Lvl1(TexManager * textMan, b2World * world)
{
	/*
	TO DO
		X See if enemy can not be affected by gravity - bee
		X Add sensor to move above ground
		X Split item class to coins and food
		X Enemy kill
		X Player animations
		X Deconstructor
		X HUD
		X Score
		X Lives
		X Level complete/fail
			X Fail screen
			X Obj to collide with home
		X Walls
		- Fix physics glitches
	*/
	
	textMan->setTexture("lvl1", this);
	setBg();

	player = new Player(world, textMan, sf::Vector2f(1.0f, 6.35f), sf::Vector2f(0.2f, 0.3f), 0.f);	//1.0f, 6.35f

	door = new Door(world, textMan, sf::Vector2f(29.92f, 7.04f), 1.5708f);
	sensor = new DoorSensor(world, sf::Vector2f(27.24f, 7.03f), sf::Vector2f(0.2f, 0.05f), door);
	box = new MovableObj(world, textMan, sf::Vector2f(25.71f, 7.36f), sf::Vector2f(0.14f, 0.14f), 0.f);

	home = new HomeSensor(world, sf::Vector2f(46.00f, 2.82f), sf::Vector2f(0.18f, 0.41f), player);

	floorOne[0].Set(0.41f, 5.45f);
	floorOne[1].Set(0.41f, 6.89f);
	floorOne[2].Set(1.21f, 6.89f);
	floorOne[3].Set(1.32f, 6.85f);
	floorOne[4].Set(1.58f, 6.73f);
	floorOne[5].Set(1.88f, 6.73f);
	floorOne[6].Set(2.28f, 6.88f);
	floorOne[7].Set(2.55f, 6.88f);
	floorOne[8].Set(2.55f, 10.73f);
	floorOne[9].Set(2.88f, 10.73f);
	floorOne[10].Set(2.88f, 10.65f);
	floorOne[11].Set(3.00f, 10.56f);

	floors[0] = new Floor(floorOne, 12, world);


	floorTwo[0].Set(3.27f, 10.08f);
	floorTwo[1].Set(2.88f, 9.81f);
	floorTwo[2].Set(2.88f, 6.88f);
	floorTwo[3].Set(3.03f, 6.84f);
	floorTwo[4].Set(3.23f, 6.84f);
	floorTwo[5].Set(3.37f, 6.89f);
	floorTwo[6].Set(4.33f, 6.88f);
	floorTwo[7].Set(4.33f, 7.67f);
	floorTwo[8].Set(4.95f, 7.67f);
	floorTwo[9].Set(4.95f, 6.89f);

	floors[1] = new Floor(floorTwo, 10, world);


	floorThree[0].Set(5.92f, 6.95f);
	floorThree[1].Set(5.92f, 7.67f);
	floorThree[2].Set(6.87f, 7.67f);
	floorThree[3].Set(6.87f, 6.88f);
	floorThree[4].Set(7.96f, 6.88f);
	floorThree[5].Set(8.28f, 6.74f);
	floorThree[6].Set(9.21f, 5.82f);
	floorThree[7].Set(9.50f, 5.65f);
	floorThree[8].Set(9.66f, 5.60f);
	floorThree[9].Set(9.86f, 5.60f);
	floorThree[9].Set(10.10f, 5.68f);
	floorThree[10].Set(10.35f, 5.86f);
	floorThree[11].Set(12.46f, 7.97f);
	floorThree[12].Set(12.64f, 8.08f);
	floorThree[13].Set(12.90f, 8.17f);
	floorThree[14].Set(15.03f, 8.17f);
	floorThree[15].Set(15.03f, 10.07f);

	floors[2] = new Floor(floorThree, 16, world);


	floorFour[0].Set(15.36f, 10.56f);
	floorFour[1].Set(15.36f, 8.17f);
	floorFour[2].Set(18.18f, 8.16f);
	floorFour[3].Set(18.34f, 8.11f);
	floorFour[4].Set(18.88f, 7.85f);
	floorFour[5].Set(19.24f, 7.84f);
	floorFour[6].Set(19.24f, 8.32f);

	floors[3] = new Floor(floorFour, 7, world);


	floorFive[0].Set(20.73f, 8.32f);
	floorFive[1].Set(20.73f, 7.84f);
	floorFive[2].Set(20.91f, 7.84f);
	floorFive[3].Set(21.07f, 7.79f);
	floorFive[4].Set(21.91f, 7.37f);
	floorFive[5].Set(22.02f, 7.36f);
	floorFive[6].Set(26.18f, 7.36f);
	floorFive[7].Set(26.34f, 7.31f);
	floorFive[8].Set(26.87f, 7.05f);
	floorFive[9].Set(32.96f, 7.05f);
	floorFive[10].Set(33.12f, 7.19f);
	floorFive[11].Set(33.12f, 7.63f);
	floorFive[12].Set(33.44f, 7.63f);
	floorFive[13].Set(33.44f, 7.19f);
	floorFive[14].Set(33.59f, 7.05f);
	floorFive[15].Set(33.92f, 7.05f);
	floorFive[16].Set(33.92f, 6.56f);

	floors[4] = new Floor(floorFive, 17, world);


	floorSix[0].Set(28.92f, 2.72f);
	floorSix[1].Set(30.52f, 2.72f);
	floorSix[2].Set(30.73f, 2.79f);
	floorSix[3].Set(30.92f, 2.91f);
	floorSix[4].Set(32.81f, 4.80f);
	floorSix[5].Set(33.13f, 4.97f);
	floorSix[6].Set(33.13f, 6.38f);

	floors[5] = new Floor(floorSix, 7, world);

	floorSeven[0].Set(33.49f, 6.38f);
	floorSeven[1].Set(33.49f, 5.06f);
	floorSeven[2].Set(33.70f, 5.12f);
	floorSeven[3].Set(39.52f, 5.12f);
	floorSeven[4].Set(39.52f, 2.34f);

	floors[6] = new Floor(floorSeven, 5, world);


	floorEight[0].Set(39.31f, 2.08f);
	floorEight[1].Set(40.80f, 2.08f);
	floorEight[2].Set(41.06f, 2.20f);
	floorEight[3].Set(42.84f, 3.96f);
	floorEight[4].Set(43.09f, 4.11f);
	floorEight[5].Set(43.29f, 4.16f);
	floorEight[6].Set(43.45f, 4.16f);
	floorEight[7].Set(43.64f, 4.10f);
	floorEight[8].Set(43.88f, 3.97f);
	floorEight[9].Set(44.81f, 3.04f);
	floorEight[10].Set(44.94f, 3.00f);
	floorEight[11].Set(45.04f, 3.01f);
	floorEight[12].Set(45.11f, 3.04f);
	floorEight[13].Set(47.53f, 3.04f);
	floorEight[14].Set(47.53f, 1.46f);

	floors[7] = new Floor(floorEight, 15, world);
	

	platforms[0] = new NormPlat(world, textMan, sf::Vector2f(5.45f, 6.95f), sf::Vector2f(1.0f, 0.1f), 0.f);
	platforms[1] = new NormPlat(world, textMan, sf::Vector2f(14.55f, 6.90f), sf::Vector2f(2.36f, 0.1f), 0.f);
	platforms[2] = new NormPlat(world, textMan, sf::Vector2f(16.92f, 7.08f), sf::Vector2f(1.32f, 0.1f), 0.f);
	platforms[3] = new NormPlat(world, textMan, sf::Vector2f(9.19f, 10.60f), sf::Vector2f(12.31f, 0.1f), 0.f);

	moving[0] = new MovingPlat(world, textMan, sf::Vector2f(13.28f, 2.59f), sf::Vector2f(1.37f, 0.1f), 0.f);
	moving[1] = new MovingPlat(world, textMan, sf::Vector2f(17.78f, 3.38f), sf::Vector2f(1.33f, 0.1f), 0.f);
	moving[2] = new MovingPlat(world, textMan, sf::Vector2f(9.30, 1.80), sf::Vector2f(1.38f, 0.1f), 0.f);

	bounce[0] = new BouncyPlat(world, textMan, sf::Vector2f(14.56f, 6.73f), sf::Vector2f(0.32f, 0.32f), 0.f);
	bounce[1] = new BouncyPlat(world, textMan, sf::Vector2f(33.29f, 7.67f), sf::Vector2f(0.32f, 0.32f), 0.f);
	bounce[2] = new BouncyPlat(world, textMan, sf::Vector2f(35.04f, 4.98f), sf::Vector2f(0.32f, 0.32f), 0.f);
	bounce[3] = new BouncyPlat(world, textMan, sf::Vector2f(35.52f, 4.98f), sf::Vector2f(0.32f, 0.32f), 0.f);
	bounce[4] = new BouncyPlat(world, textMan, sf::Vector2f(36.00f, 4.98f), sf::Vector2f(0.32f, 0.32f), 0.f);
	bounce[5] = new BouncyPlat(world, textMan, sf::Vector2f(36.49f, 4.98f), sf::Vector2f(0.32f, 0.32f), 0.f);
	bounce[6] = new BouncyPlat(world, textMan, sf::Vector2f(36.97f, 4.98f), sf::Vector2f(0.32f, 0.32f), 0.f);
	bounce[7] = new BouncyPlat(world, textMan, sf::Vector2f(37.44f, 4.98f), sf::Vector2f(0.32f, 0.32f), 0.f);
	bounce[8] = new BouncyPlat(world, textMan, sf::Vector2f(37.93f, 4.98f), sf::Vector2f(0.32f, 0.32f), 0.f);
	bounce[9] = new BouncyPlat(world, textMan, sf::Vector2f(38.40f, 4.98f), sf::Vector2f(0.32f, 0.32f), 0.f);
	bounce[10] = new BouncyPlat(world, textMan, sf::Vector2f(2.73f, 10.71f), sf::Vector2f(0.32f, 0.32f), 0.f);

	oneWay[0] = new OneWayPlat(world, textMan, sf::Vector2f(2.71f, 6.93f), sf::Vector2f(0.34f, 0.12f), 0.f);
	oneWay[1] = new OneWayPlat(world, textMan, sf::Vector2f(33.34f, 5.08f), sf::Vector2f(0.53f, 0.10f), 0.296706f);
	oneWay[2] = new OneWayPlat(world, textMan, sf::Vector2f(23.78f, 6.73f), sf::Vector2f(0.71f, 0.1f), 0.f);
	oneWay[3] = new OneWayPlat(world, textMan, sf::Vector2f(22.92f, 6.47f), sf::Vector2f(0.58f, 0.1f), 0.f);
	oneWay[4] = new OneWayPlat(world, textMan, sf::Vector2f(22.54f, 5.83f), sf::Vector2f(0.52f, 0.1f), 0.f);
	oneWay[5] = new OneWayPlat(world, textMan, sf::Vector2f(24.01f, 5.84f), sf::Vector2f(0.90f, 0.1f), 0.f);
	oneWay[6] = new OneWayPlat(world, textMan, sf::Vector2f(26.03f, 6.74f), sf::Vector2f(0.66f, 0.1f), 0.f);
	oneWay[7] = new OneWayPlat(world, textMan, sf::Vector2f(25.16f, 6.45f), sf::Vector2f(0.46f, 0.1f), 0.f);
	oneWay[8] = new OneWayPlat(world, textMan, sf::Vector2f(24.82f, 5.83f), sf::Vector2f(0.51f, 0.1f), 0.f);
	oneWay[9] = new OneWayPlat(world, textMan, sf::Vector2f(26.10f, 5.82f), sf::Vector2f(0.53f, 0.1f), 0.f);
	oneWay[10] = new OneWayPlat(world, textMan, sf::Vector2f(26.04f, 4.87f), sf::Vector2f(0.79f, 0.1f), 0.f);
	oneWay[11] = new OneWayPlat(world, textMan, sf::Vector2f(28.11f, 6.41f), sf::Vector2f(0.63f, 0.1f), 0.f);
	oneWay[12] = new OneWayPlat(world, textMan, sf::Vector2f(27.22f, 6.14f), sf::Vector2f(0.55f, 0.1f), 0.f);
	oneWay[13] = new OneWayPlat(world, textMan, sf::Vector2f(28.33f, 5.51f), sf::Vector2f(0.84f, 0.1f), 0.f);
	oneWay[14] = new OneWayPlat(world, textMan, sf::Vector2f(27.39f, 4.39f), sf::Vector2f(0.54f, 0.1f), 0.f);
	oneWay[15] = new OneWayPlat(world, textMan, sf::Vector2f(28.12f, 3.75f), sf::Vector2f(0.83f, 0.1f), 0.f);
	oneWay[16] = new OneWayPlat(world, textMan, sf::Vector2f(26.39f, 3.10f), sf::Vector2f(0.38f, 0.1f), 0.f);
	oneWay[17] = new OneWayPlat(world, textMan, sf::Vector2f(27.44f, 2.63f), sf::Vector2f(0.37f, 0.1f), 0.f);

	hazard[0] = new Hazard(world, sf::Vector2f(4.6f, 7.6f), sf::Vector2f(0.7f, 0.2f), 0.f);
	hazard[1] = new Hazard(world, sf::Vector2f(6.4f, 7.6f), sf::Vector2f(0.9f, 0.2f), 0.f);
	hazard[2] = new Hazard(world, sf::Vector2f(13.49, 6.77), sf::Vector2f(0.1f, 0.2f), 0.f);
	hazard[3] = new Hazard(world, sf::Vector2f(15.57f, 6.77f), sf::Vector2f(0.1f, 0.2f), 0.f);
	hazard[4] = new Hazard(world, sf::Vector2f(15.58f, 8.08f), sf::Vector2f(0.1f, 0.2f), 0.f);
	hazard[5] = new Hazard(world, sf::Vector2f(19.98f, 8.23f), sf::Vector2f(1.64f, 0.2f), 0.f);
	hazard[6] = new Hazard(world, sf::Vector2f(28.74f, 6.95f), sf::Vector2f(0.86f, 0.2f), 0.f);
	hazard[7] = new Hazard(world, sf::Vector2f(34.66f, 5.02f), sf::Vector2f(0.52f, 0.2f), 0.f);

	enemies[0] = new Enemy(world, textMan, 'H', sf::Vector2f(14.28f, 8.05), sf::Vector2f(0.4f, 0.3f), 0.f);
	enemies[1] = new Enemy(world, textMan, 'H', sf::Vector2f(16.92f, 6.92f), sf::Vector2f(0.4f, 0.3f), 0.f);
	enemies[2] = new Enemy(world, textMan, 'H', sf::Vector2f(17.08f, 8.04f), sf::Vector2f(0.4f, 0.3f), 0.f);

	enemies[3] = new Enemy(world, textMan, 'B', sf::Vector2f(24.21f, 6.45f), sf::Vector2f(0.3f, 0.15f), 0.f);
	enemies[4] = new Enemy(world, textMan, 'B', sf::Vector2f(24.43f, 5.55f), sf::Vector2f(0.3f, 0.15f), 0.f);
	enemies[5] = new Enemy(world, textMan, 'B', sf::Vector2f(25.92f, 4.33f), sf::Vector2f(0.3f, 0.15f), 0.f);
	enemies[6] = new Enemy(world, textMan, 'B', sf::Vector2f(26.68f, 6.50f), sf::Vector2f(0.3f, 0.15f), 0.f);
	enemies[7] = new Enemy(world, textMan, 'B', sf::Vector2f(26.75f, 5.48f), sf::Vector2f(0.3f, 0.15f), 0.f);
	enemies[8] = new Enemy(world, textMan, 'B', sf::Vector2f(28.56f, 3.27f), sf::Vector2f(0.3f, 0.15f), 0.f);

	items[0] = new PickUp(world, textMan, 'H', sf::Vector2f(2.63f, 6.80f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[1] = new PickUp(world, textMan, 'H', sf::Vector2f(2.79f, 6.80f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[2] = new PickUp(world, textMan, 'H', sf::Vector2f(5.35f, 6.80f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[3] = new PickUp(world, textMan, 'H', sf::Vector2f(9.68f, 5.52f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[4] = new PickUp(world, textMan, 'H', sf::Vector2f(9.84f, 5.52f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[5] = new PickUp(world, textMan, 'H', sf::Vector2f(14.82f, 6.80f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[6] = new PickUp(world, textMan, 'H', sf::Vector2f(9.04f, 1.67f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[7] = new PickUp(world, textMan, 'H', sf::Vector2f(9.36f, 1.67f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[8] = new PickUp(world, textMan, 'H', sf::Vector2f(13.04f, 2.47f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[9] = new PickUp(world, textMan, 'H', sf::Vector2f(13.52f, 2.47f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[10] = new PickUp(world, textMan, 'H', sf::Vector2f(17.52f, 3.27f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[11] = new PickUp(world, textMan, 'H', sf::Vector2f(18.00f, 3.27f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[12] = new PickUp(world, textMan, 'H', sf::Vector2f(20.72f, 7.75f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[13] = new PickUp(world, textMan, 'H', sf::Vector2f(21.04f, 7.59f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[14] = new PickUp(world, textMan, 'H', sf::Vector2f(21.36f, 7.43f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[15] = new PickUp(world, textMan, 'H', sf::Vector2f(21.68f, 7.27f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[16] = new PickUp(world, textMan, 'H', sf::Vector2f(34.16f, 5.03f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[17] = new PickUp(world, textMan, 'H', sf::Vector2f(34.16f, 4.87f), sf::Vector2f(0.1f, 0.1f), 0.f);

	items[18] = new PickUp(world, textMan, 'A', sf::Vector2f(3.44f, 6.81f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[19] = new PickUp(world, textMan, 'A', sf::Vector2f(3.76f, 6.82f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[20] = new PickUp(world, textMan, 'A', sf::Vector2f(10.48f, 5.86f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[21] = new PickUp(world, textMan, 'A', sf::Vector2f(10.80f, 6.18f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[22] = new PickUp(world, textMan, 'A', sf::Vector2f(11.12f, 6.50f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[23] = new PickUp(world, textMan, 'A', sf::Vector2f(11.44f, 6.82f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[24] = new PickUp(world, textMan, 'A', sf::Vector2f(11.76f, 7.14f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[25] = new PickUp(world, textMan, 'A', sf::Vector2f(12.08f, 7.46f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[26] = new PickUp(world, textMan, 'A', sf::Vector2f(12.40f, 7.78f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[27] = new PickUp(world, textMan, 'A', sf::Vector2f(24.08f, 6.66f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[28] = new PickUp(world, textMan, 'A', sf::Vector2f(26.32f, 6.66f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[29] = new PickUp(world, textMan, 'A', sf::Vector2f(28.40f, 6.34f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[30] = new PickUp(world, textMan, 'A', sf::Vector2f(30.96f, 2.82f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[31] = new PickUp(world, textMan, 'A', sf::Vector2f(31.28f, 3.14f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[32] = new PickUp(world, textMan, 'A', sf::Vector2f(31.60f, 3.46f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[33] = new PickUp(world, textMan, 'A', sf::Vector2f(31.92f, 3.78f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[34] = new PickUp(world, textMan, 'A', sf::Vector2f(32.24f, 4.10f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[35] = new PickUp(world, textMan, 'A', sf::Vector2f(32.56f, 4.42f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[36] = new PickUp(world, textMan, 'A', sf::Vector2f(46.64f, 2.98f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[37] = new PickUp(world, textMan, 'A', sf::Vector2f(46.96f, 2.98f), sf::Vector2f(0.1f, 0.1f), 0.f);

	items[38] = new PickUp(world, textMan, 'B', sf::Vector2f(8.41f, 6.49f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[39] = new PickUp(world, textMan, 'B', sf::Vector2f(8.73f, 6.17f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[40] = new PickUp(world, textMan, 'B', sf::Vector2f(9.05f, 5.85f), sf::Vector2f(0.1f, 0.1f), 0.f);

	items[41] = new PickUp(world, textMan, 'C', sf::Vector2f(3.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[42] = new PickUp(world, textMan, 'C', sf::Vector2f(3.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[43] = new PickUp(world, textMan, 'C', sf::Vector2f(4.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[44] = new PickUp(world, textMan, 'C', sf::Vector2f(4.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[45] = new PickUp(world, textMan, 'C', sf::Vector2f(5.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[46] = new PickUp(world, textMan, 'C', sf::Vector2f(5.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[47] = new PickUp(world, textMan, 'C', sf::Vector2f(6.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[48] = new PickUp(world, textMan, 'C', sf::Vector2f(6.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[49] = new PickUp(world, textMan, 'C', sf::Vector2f(7.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[50] = new PickUp(world, textMan, 'C', sf::Vector2f(7.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[51] = new PickUp(world, textMan, 'C', sf::Vector2f(8.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[52] = new PickUp(world, textMan, 'C', sf::Vector2f(8.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[53] = new PickUp(world, textMan, 'C', sf::Vector2f(9.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[54] = new PickUp(world, textMan, 'C', sf::Vector2f(9.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[55] = new PickUp(world, textMan, 'C', sf::Vector2f(10.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[56] = new PickUp(world, textMan, 'C', sf::Vector2f(10.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[57] = new PickUp(world, textMan, 'C', sf::Vector2f(11.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[58] = new PickUp(world, textMan, 'C', sf::Vector2f(11.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[59] = new PickUp(world, textMan, 'C', sf::Vector2f(12.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[60] = new PickUp(world, textMan, 'C', sf::Vector2f(12.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[61] = new PickUp(world, textMan, 'C', sf::Vector2f(13.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[62] = new PickUp(world, textMan, 'C', sf::Vector2f(13.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[63] = new PickUp(world, textMan, 'C', sf::Vector2f(14.32f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[64] = new PickUp(world, textMan, 'C', sf::Vector2f(14.82f, 10.45f), sf::Vector2f(0.1f, 0.1f), 0.f);

	items[65] = new PickUp(world, textMan, 'C', sf::Vector2f(35.04f, 4.12f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[66] = new PickUp(world, textMan, 'C', sf::Vector2f(35.04f, 3.40f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[67] = new PickUp(world, textMan, 'C', sf::Vector2f(35.04f, 2.68f), sf::Vector2f(0.1f, 0.1f), 0.f);

	items[68] = new PickUp(world, textMan, 'C', sf::Vector2f(35.52f, 3.76f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[69] = new PickUp(world, textMan, 'C', sf::Vector2f(35.52f, 3.04f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[70] = new PickUp(world, textMan, 'C', sf::Vector2f(35.52f, 2.32f), sf::Vector2f(0.1f, 0.1f), 0.f);

	items[71] = new PickUp(world, textMan, 'C', sf::Vector2f(36.00f, 4.12f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[72] = new PickUp(world, textMan, 'C', sf::Vector2f(36.00f, 3.40f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[73] = new PickUp(world, textMan, 'C', sf::Vector2f(36.00f, 2.68f), sf::Vector2f(0.1f, 0.1f), 0.f);

	items[74] = new PickUp(world, textMan, 'C', sf::Vector2f(36.49f, 3.76f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[75] = new PickUp(world, textMan, 'C', sf::Vector2f(36.49f, 3.04f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[76] = new PickUp(world, textMan, 'C', sf::Vector2f(36.49f, 2.32f), sf::Vector2f(0.1f, 0.1f), 0.f);

	items[77] = new PickUp(world, textMan, 'C', sf::Vector2f(36.97f, 4.12f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[78] = new PickUp(world, textMan, 'C', sf::Vector2f(36.97f, 3.40f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[79] = new PickUp(world, textMan, 'C', sf::Vector2f(36.97f, 2.68f), sf::Vector2f(0.1f, 0.1f), 0.f);

	items[80] = new PickUp(world, textMan, 'C', sf::Vector2f(37.44f, 3.76f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[81] = new PickUp(world, textMan, 'C', sf::Vector2f(37.44f, 3.04f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[82] = new PickUp(world, textMan, 'C', sf::Vector2f(37.44f, 2.32f), sf::Vector2f(0.1f, 0.1f), 0.f);

	items[83] = new PickUp(world, textMan, 'C', sf::Vector2f(37.93f, 4.12f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[84] = new PickUp(world, textMan, 'C', sf::Vector2f(37.93f, 3.40f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[85] = new PickUp(world, textMan, 'C', sf::Vector2f(37.93f, 2.68f), sf::Vector2f(0.1f, 0.1f), 0.f);

	items[86] = new PickUp(world, textMan, 'C', sf::Vector2f(38.40f, 3.76f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[87] = new PickUp(world, textMan, 'C', sf::Vector2f(38.40f, 3.04f), sf::Vector2f(0.1f, 0.1f), 0.f);
	items[88] = new PickUp(world, textMan, 'C', sf::Vector2f(38.40f, 2.32f), sf::Vector2f(0.1f, 0.1f), 0.f);

	//// USER DATA ////
	player->setUserData(new std::pair<std::string, void *>(typeid(decltype(*player)).name(), player));

	door->setUserData(new std::pair<std::string, void *>(typeid(decltype(*door)).name(), door));
	box->setUserData(new std::pair<std::string, void *>(typeid(decltype(*box)).name(), box));
	sensor->setUserData(sensor);
	home->setUserData(home);


	for (Floor* floor : floors) floor->setUserData(new std::pair<std::string, void *>(typeid(decltype(*floor)).name(), floor));
	for (NormPlat* plat : platforms) plat->setUserData(new std::pair<std::string, void *>(typeid(decltype(*plat)).name(), plat));
	for (MovingPlat* platM : moving) platM->setUserData(new std::pair<std::string, void *>(typeid(decltype(*platM)).name(), platM));
	for (BouncyPlat* platB : bounce) platB->setUserData(new std::pair<std::string, void *>(typeid(decltype(*platB)).name(), platB));
	for (OneWayPlat* platO : oneWay) platO->setUserData(new std::pair<std::string, void *>(typeid(decltype(*platO)).name(), platO));
	for (Hazard* haz : hazard) haz->setUserData(new std::pair<std::string, void *>(typeid(decltype(*haz)).name(), haz));
	for (Enemy* enemi : enemies) enemi->setUserData(new std::pair<std::string, void *> (typeid(decltype(*enemi)).name(), enemi));
	for (PickUp* item : items) item->setUserData(new std::pair<std::string, void *>(typeid(decltype(*item)).name(), item));
}


sf::Vector2f Lvl1::getPos()
{
	b2Vec2 Bpos = player->getPos();
	sf::Vector2f Vpos = sf::Vector2f(Bpos.x, Bpos.y);
	
	return Vpos;
}

void Lvl1::update(float timeStep, bool over)
{
	if (over)
		player->update(timeStep);
	else
	{
		Texture::update(timeStep);
		player->update(timeStep);
		box->update(timeStep);
		door->update(timeStep);
		for (MovingPlat* platM : moving) platM->update(timeStep);
		for (Enemy* enemi : enemies)
		{
			if (enemi != nullptr)
				enemi->update(timeStep);
		}
		for (PickUp* item : items)
		{
			if (item != nullptr)
			{
				item->update(timeStep);

				if (item->getType() == 'C')
					item->setSize(sf::Vector2f(0.005f, 0.005f));
			}
		}
		for (OneWayPlat* platO : oneWay)
		{
			if (player->getPos().y > platO->getPos().y)
			{
				platO->pass();
			}
			else if (player->getPos().y < platO->getPos().y)
			{
				platO->collide();
			}
		}
	}
}

void Lvl1::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(currSprite, states);
	target.draw(*sensor);
	box->draw(target, states);
	door->draw(target, states);
	for (MovingPlat* platM : moving) platM->draw(target, states);
	for (Enemy* enemi : enemies)
	{
		if (enemi != nullptr)
			enemi->draw(target, states);
	}
	for (PickUp* item : items)
	{
		if (item != nullptr)
			item->draw(target, states);
	}
	player->draw(target, states);
}

Lvl1::~Lvl1()
{
	for (NormPlat* plat : platforms)
	{
		delete plat;
		plat = nullptr;
	}
	for (BouncyPlat* platB : bounce)
	{
		delete platB;
		platB = nullptr;
	}
	for (MovingPlat* platM : moving)
	{
		delete platM;
		platM = nullptr;
	}
	for (Hazard* haz : hazard)
	{
		delete haz;
		haz = nullptr;
	}
	for (Enemy* enemi : enemies)
	{
		if (enemi != nullptr)
		{
			delete enemi;
			enemi = nullptr;
		}
	}
	for (PickUp* item : items)
	{
		if (item != nullptr)
		{
			delete item;
			item = nullptr;
		}
	}
	for (Floor* floor : floors)
	{
		delete floor;
		floor = nullptr;
	}
	delete box;
	box = nullptr;

	delete sensor;
	sensor = nullptr;

	delete door;
	door = nullptr;

	delete player;
	player = nullptr;
}