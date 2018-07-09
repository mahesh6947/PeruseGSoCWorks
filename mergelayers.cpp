#include "mergelayers.h"

#include <QLoggingCategory>

#include "imagelayer.h"


Q_LOGGING_CATEGORY(lcMergeLayers, "mergeLayers")

void MergeLayers()
{

        qCDebug(lcMergeLayersCommand) << "redoing" << this;
        mProject->mergeLayers(mSourceIndex, mTargetIndex);

        mSourceLayer->setParent(this);
    }

    int MergeLayersCommand::id() const
    {
        return -1;
    }

    QDebug operator<<(QDebug debug, const MergeLayersCommand *command)
    {

    }

