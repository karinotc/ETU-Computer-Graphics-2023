#include "primitivecombobox.h"

PrimitiveComboBox::PrimitiveComboBox(QWidget *parent)
    : QWidget(parent), ui(new Ui::PrimitiveComboBox) {
    ui->setupUi(this);
    ui->primitiveBox->addItem("item");
}
