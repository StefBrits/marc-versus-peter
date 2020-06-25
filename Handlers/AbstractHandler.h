#ifndef STEFSPACE_ABSTRACTHANDLER_H
#define STEFSPACE_ABSTRACTHANDLER_H

namespace gameLogic {
    class AbstractHandler {
    public:
        virtual void initialize(const char *title, int width, int height) = 0;
        virtual void clear() = 0;
        virtual void render() = 0;
        virtual void handleEvents() = 0;
        virtual void setIsOnce(bool isOnces) = 0;
    };

}
#endif //STEFSPACE_ABSTRACTHANDLER_H
