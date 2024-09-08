


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* NewWidgetController)
{
	WidgetController = NewWidgetController;
	WidgetControllerSet();
}
