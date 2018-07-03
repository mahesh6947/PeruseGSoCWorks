#ifndef ACBFFRAME_H
#define ACBFFRAME_H


#include "AcbfPage.h"

namespace AdvancedComicBookFormat {
class Frame;
class ACBF_EXPORT Frame : public QObject
{
    Q_OBJECT
public:
    explicit Frame(Page* parent = nullptr);
    ~Frame() override;


}

#endif // ACBFFRAME_H
