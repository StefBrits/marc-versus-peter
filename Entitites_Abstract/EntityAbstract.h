#ifndef STEFSPACE_ENTITYABSTRACT_H
#define STEFSPACE_ENTITYABSTRACT_H

namespace gameLogic {
    class EntityAbstract {
        int xCoordinate;
        int yCoordinate;
        int speed;
        int width;
        int height;
        int xBound;
        int yBound;
        bool isExisting;
    public:
        EntityAbstract(int xCoordinate, int yCoordinate, int speed, int width, int height, int xBound, int yBound, bool isExisting);
        int getxCoordinate();
        int getyCoordinate();
        int getSpeed();
        int getWidth();
        int getHeight();
        int getxBound();
        int getyBound();
        bool getIsExisting();

        void setxCoordinate(int xCoordinate);
        void setyCoordinate(int yCoordinate);
        void setSpeed(int speed);
        void setWidth(int width);
        void setHeight(int height);
        void setxBound(int xBound);
        void setyBound(int yBound);
        void setIsExisting(bool isExisting);

        void deleteEntity();
        virtual void update() = 0;
        virtual void draw() = 0;
    };

}
#endif //STEFSPACE_ENTITYABSTRACT_H
