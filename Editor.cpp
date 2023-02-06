#include "Editor.h"

//default 
Editor::Editor()
{
	init();
}

void Editor::init()
{
	//init window
	m_window.create(sf::VideoMode(1080, 720), "Level Editor");
	m_window.setFramerateLimit(60);

	//init view
	view.setSize(1080, 720);
	view.setCenter(m_window.getSize().x / 2, m_window.getSize().y / 2);

	//init text
	
	 
	 
	//init grid elements

	//init() creates the window for the editor to display in//////////////////////////
}


/* The run() function calls the functions needed every frame
* and keeps track of the number of frames passed in the currentFrame variable
* it then incrememnts the currentFrame variable
*/
void Editor::run()
{
	while (m_running)
	{
		sUserInput();
		sCollision();
		Render();

		currentFrame++;
	}
}


/// <Render>
/// The Render function handles drawing everything to the screen in the right place
/// Entities are drawn by iterating throught the corresponding vector and drawing them in the correct grid coordinates. This includes moving objects by a velocity (and gravity) component
/// game related stuff is drawn first and then anaything UI related is drawn last to appear over the rest of the program
/// <Render>
void Editor::Render()
{
	m_window.clear(sf::Color(25, 25, 25, 50));
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(m_window);
	m_window.setView(view);
	mousePosView = m_window.mapPixelToCoords(mousePosWindow);
	if (mousePosView.x >= 0.f);
	{
		mousePosGrid.x = mousePosView.x / gridSizeU;
	}
	if (mousePosView.y >= 0.f)
	{
		mousePosGrid.y = mousePosView.y / gridSizeU;
	}

	//render everything game related
	sf::RectangleShape tileSelector(sf::Vector2f(gridSize, gridSize));
	tileSelector.setOrigin(gridSize / 2, gridSize / 2);
	tileSelector.setFillColor(sf::Color::Transparent);
	tileSelector.setOutlineThickness(1.f);
	tileSelector.setOutlineColor(sf::Color::Green);
	tileSelector.setPosition((mousePosGrid.x * gridSize), (mousePosGrid.y * gridSize));
	m_window.draw(tileSelector);

	for (auto t : m_tiles.get_tiles())
	{
		t->shape->rectangle.setPosition(t->transform->pos.x, t->transform->pos.y);
		m_window.draw(t->shape->rectangle);
	}

	for (auto obj : m_objects.get_Objects())
	{
		obj->shape->sprite.setPosition(obj->transform->pos.x, obj->transform->pos.y);
		m_window.draw(obj->shape->sprite);

		obj->transform->velocity.y += obj->gravity->acceleration.y;
		obj->transform->pos.y += obj->transform->velocity.y;

		obj->transform->pos.x += obj->transform->velocity.x;
	}



	//draw everything UI related

	if (bMenu)
	{
		auto Menu = m_menu.create_sidebar();
		menu_pos = sf::Vector2f((view.getCenter().x - (view.getSize().x / 2)), view.getCenter().y - (view.getSize().y / 2));
		Menu.setPosition(menu_pos);
		m_window.draw(Menu);

		//default option position on the sidebar
		option_pos = sf::Vector2f((view.getCenter().x - (view.getSize().x / 2)), view.getCenter().y - (view.getSize().y / 2));

		//drawing each option to the sidebar
		for (auto options : m_menu.create_sidebar_options())
		{
			options.setPosition(option_pos);
			option_pos.y += 50.f;
			m_window.draw(options);
		}


	}

	m_window.setView(m_window.getDefaultView());
	m_window.display();
}

/*All user input is handled by the sUserInput function
* mouse clicks primarily used for selecting and placing things
* keyboard presses primarily used for bringing up menus and moving the current view
*/
void Editor::sUserInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_running = false;
		}


		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				mousePosWindow = sf::Mouse::getPosition(m_window);
				sf::Vector2f current_mouse_pos_view = sf::Vector2f(mousePosView.x, mousePosView.y);
				sf::Vector2f current_mouse_pos_grid = sf::Vector2f((mousePosGrid.x * gridSize), (mousePosGrid.y * gridSize));
				sBuildTile(tile_type, current_mouse_pos_grid);
				std::cout << mousePosView.x << ", " << mousePosView.y << "\n";
			}

			if (event.mouseButton.button == sf::Mouse::Right)
			{
				mousePosWindow = sf::Mouse::getPosition(m_window);
				sf::Vector2f current_mouse_pos_view = sf::Vector2f(mousePosView.x, mousePosView.y);
				sf::Vector2f current_mouse_pos_grid = sf::Vector2f((mousePosGrid.x * gridSize), (mousePosGrid.y * gridSize));
				if (bDelete)
				{
					sDelete(current_mouse_pos_grid);
				}
				else
				{
					sPlaceObject(obj_type, current_mouse_pos_view);
				}

				if (bMenu)
				{
					tile_type = m_menu.SelectTileTexture(current_mouse_pos_view);
				}

				

			}
		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{

			}
		}

		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::A:
				if (mousePosView.x > 0.f)
				{
					view.move(-view_speed, 0.f);
					view_top_hor -= view_speed;
				}
				break;

			case sf::Keyboard::D:
				view.move(+view_speed, 0.f);
				break;

			case sf::Keyboard::W:
				if (mousePosView.y > 0.f)
				{
					view.move(0.f, -view_speed);
				}
				break;

			case sf::Keyboard::S:
				view.move(0.f, +view_speed);
				break;

			case sf::Keyboard::T:
				if (bDelete)
				{
					bDelete = false;
				}
				else if (!bDelete)
				{
					bDelete = true;
				}
				break;

			case sf::Keyboard::Tab:
				switch (bMenu)
				{
				case false:
					bMenu = true;
					break;

				case true:
					bMenu = false;
					break;
				}
				break;

			case sf::Keyboard::Escape:
				m_running = false;
			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::T:
				break;

			}
		}
	}
}

void Editor::sBuildTile(const Tile::TileType tile_type, sf::Vector2f mouse_pos)
{
	auto t = m_tiles.add_tile(tile_type);
	t->transform = std::make_shared<CTransform>((mouse_pos), Vec2(0, 0), 0);
	t->shape = std::make_shared<CShape>(sf::Vector2f(50, 50));
	t->collision = std::make_shared<CCollision>(Vec2(12.5, 12.5));
	t->setTexture(tile_type);
}

/* sPlaceObject will create an object in the Objects class and place it in the the obj_vec vector
* the object is created with a gravity component
* a transform position at the mouse click and a default velocity of 0
* all objects are made as sprites not rectangle shapes or circle shapes
* finaly the object texture is set using setObjectType()

*/
void Editor::sPlaceObject(const Objects::ObjectType obj_type, sf::Vector2f mouse_pos)
{
	auto obj = m_objects.add_object(obj_type);
	obj->gravity = std::make_shared<CGravity>(Vec2(0, 0.1f));
	obj->transform = std::make_shared<CTransform>((mouse_pos), Vec2(5.f, 0), 0);
	obj->shape = std::make_shared<CShape>();
	obj->collision = std::make_shared<CCollision>(14.f);
	obj->setObjectType(obj_type);
	std::cout << mouse_pos.x << " " << mouse_pos.y << "\n";
}


void Editor::sCollision()
{
	for (auto obj : m_objects.get_Objects())
	{
		for (auto t : m_tiles.get_tiles())
		{
			//float x2 = ((x - rhs.x) * (x - rhs.x));
			//float y2 = ((y - rhs.y) * (y - rhs.y));
			//return sqrtf(x2 + y2);
			float x = (t->transform->pos.x - obj->transform->pos.x) * (t->transform->pos.x - obj->transform->pos.x);
			float y = (t->transform->pos.y -  obj->transform->pos.y) * (t->transform->pos.y - obj->transform->pos.y);
			float dist = sqrtf(x + y);

			float collision_x = (t->collision->collision_rect.x + obj->collision->radius) * (t->collision->collision_rect.x + obj->collision->radius);
			float collision_y = (t->collision->collision_rect.y + obj->collision->radius) * (t->collision->collision_rect.y + obj->collision->radius);
			float collision_dist = sqrtf(collision_x + collision_y);

			if (dist < collision_dist)
			{
				obj->transform->velocity.x *= -1;
				obj->transform->velocity.y *= -1;
				obj->transform->velocity.y -= obj->gravity->acceleration.y;
			}
			else
			{
				continue;
			}
		}
	}
}


void Editor::sDelete(sf::Vector2f mousePosGrid)
{
	for (auto t : m_tiles.get_tiles())
	{
		if (mousePosGrid.x == (t->transform->pos.x / gridSizeU) & mousePosGrid.y == (t->transform->pos.y / gridSizeU))
		{
			t->delete_tile();
			t->remove_tile();
		}
	}
}