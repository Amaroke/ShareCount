#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QDialog>

namespace Ui {
class Inscription;
}

class Inscription : public QDialog
{
    Q_OBJECT

public:
    explicit Inscription(QWidget *parent = nullptr);
    ~Inscription();

private slots:
    void on_validation_accepted();

    void on_validation_rejected();

private:
    Ui::Inscription *ui;
};

#endif // INSCRIPTION_H
