#ifndef CHANGELAYERORDERCOMMAND_H
#define CHANGELAYERORDERCOMMAND_H

#include"tools/undo/commands.h"
#include"tools/undoframework/commands.h"
#include"include/QtCore/QSize"
#include"include/QtCore/QDebug"
#include"include/QtCore/QVector"


class   LayeredImageProject;

class   ChangeLayerOrderCommand :   public  UndoCommand
{
        Q_OBJECT

public:
    ChangeLayerOrderCommand(LayeredImageProject *project, int previousIndex, int newIndex,
        UndoCommand *parent = nullptr);

    void    undo();
    void    redo();

    int id()    const;
    QDebug operator<<(QDebug debug, const ChangeLayerOrderCommand *command);

    LayeredImageProject *mProject;
    int mPreviousIndex;
    int mNewIndex;

};



#endif // CHANGELAYERORDERCOMMAND_H
