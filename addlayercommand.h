#ifndef ADDLAYERCOMMAND_H
#define ADDLAYERCOMMAND_H

#include"tools/undo/commands.h"
#include"tools/undoframework/commands.h"

class   ImageLayer;
class   LayeredImageProject;

class   AddLayerCommand : public UndoCommand
{
    Q_OBJECT

public :
      AddLayerCommand(LayeredImageProject *project, ImageLayer *layer, int index, UndoCommand *parent = nullptr);

        void undo();
        void    redo();

        int id()    const   override;
        QDebug operator<<(QDebug debug, const AddLayerCommand *command);



        LayeredImageProject *mProject;
        int mIndex;
        ImageLayer *mLayer;
    };





#endif // ADDLAYERCOMMAND_H
