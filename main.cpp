#include "application.h"

int main(int argc, char *argv[])
{
    Application app(argc, argv, QStringLiteral("PeruseEditor Create Mode"));
    return app.run();
}
