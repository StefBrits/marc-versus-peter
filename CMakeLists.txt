cmake_minimum_required(VERSION 3.15)
project(StefSpace)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR/cmake})

set(CMAKE_CXX_STANDARD 14)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
add_executable(StefSpace main.cpp GameLogic/Game.cpp GameLogic/Game.h Entitites_Abstract/Player.cpp Entitites_Abstract/Player.h Entities_SDL/PlayerSDL.cpp Entities_SDL/PlayerSDL.h Entitites_Abstract/EntityAbstract.cpp Entitites_Abstract/EntityAbstract.h Entitites_Abstract/Enemy.cpp Entitites_Abstract/Enemy.h Entitites_Abstract/Bullet.cpp Entitites_Abstract/Bullet.h Entitites_Abstract/Bonus.cpp Entitites_Abstract/Bonus.h Entities_SDL/BulletSDL.cpp Entities_SDL/BulletSDL.h Entities_SDL/EnemySDL.cpp Entities_SDL/EnemySDL.h Entities_SDL/BonusSDL.cpp Entities_SDL/BonusSDL.h Factories/AbstractFactory.cpp Factories/AbstractFactory.h Factories/FactorySDL.cpp Factories/FactorySDL.h Controllers/AbstractController.cpp Controllers/AbstractController.h Controllers/ControllerSDL.cpp Controllers/ControllerSDL.h Handlers/AbstractHandler.cpp Handlers/AbstractHandler.h Handlers/HandlerSDL.cpp Handlers/HandlerSDL.h Entitites_Abstract/GameOver.cpp Entitites_Abstract/GameOver.h Entities_SDL/GameOverSDL.cpp Entities_SDL/GameOverSDL.h)
target_link_libraries(StefSpace ${SDL2_LIBRARY} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image)
target_link_libraries(StefSpace winmm)
