#include "talepitem.h"

Talep::TalepItem::TalepItem(TalepItem *other) : Item(Key::Collection)
{
    if( other != nullptr )
    {
        this->setDocumentView (other->view ());
    }
}
