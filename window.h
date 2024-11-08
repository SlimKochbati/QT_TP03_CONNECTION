#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QCheckBox;
class QLabel;
QT_END_NAMESPACE

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    void echoChanged(bool checked);

private:
    void slot_button0();
    void slot_button1();
    void slot_button2();
    void slot_button3();
    void slot_button4();
    void slot_button5();
    void slot_button6();
    void slot_button7();
    void slot_button8();
    void slot_button9();


    void valide();
    void connection();
    // Widgets pour les champs de texte et le pavé numérique
    QLineEdit *idLineEdit;
    QLineEdit *passwordLineEdit;
    QCheckBox *montreMDPCheckBox;
    QPushButton *connexionButton;
    QLabel *statusLabel;  // Affiche l'état actuel (bouton cliqué, etc.)

};

#endif // WINDOW_H
