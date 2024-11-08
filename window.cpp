#include "window.h"
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    // Création des widgets
    idLineEdit = new QLineEdit;
    idLineEdit->setPlaceholderText("Identifiant");
    idLineEdit->setMaxLength(9);

    passwordLineEdit = new QLineEdit;
    passwordLineEdit->setPlaceholderText("Mot de passe");
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    montreMDPCheckBox = new QCheckBox("Afficher Mot de Passe");
    connect(montreMDPCheckBox, &QCheckBox::toggled, this, &Window::echoChanged);

    connexionButton = new QPushButton("Connexion");
    connexionButton->setEnabled(false); // Le bouton est désactivé au départ

    // Connexion du bouton "Connexion" à la méthode connection
    connect(connexionButton, &QPushButton::clicked, this, &Window::connection);

    statusLabel = new QLabel;

    // Création du pavé numérique avec une disposition en grille
    QGridLayout *gridLayout = new QGridLayout;

    // Création des boutons et connexion des slots
    QPushButton *button0 = new QPushButton("0");
    connect(button0, &QPushButton::clicked, this, &Window::slot_button0);
    gridLayout->addWidget(button0, 3, 1); // ligne puis colonne

    QPushButton *button1 = new QPushButton("1");
    connect(button1, &QPushButton::clicked, this, &Window::slot_button1);
    gridLayout->addWidget(button1, 0, 0);

    QPushButton *button2 = new QPushButton("2");
    connect(button2, &QPushButton::clicked, this, &Window::slot_button2);
    gridLayout->addWidget(button2, 0, 1);

    QPushButton *button3 = new QPushButton("3");
    connect(button3, &QPushButton::clicked, this, &Window::slot_button3);
    gridLayout->addWidget(button3, 0, 2);

    QPushButton *button4 = new QPushButton("4");
    connect(button4, &QPushButton::clicked, this, &Window::slot_button4);
    gridLayout->addWidget(button4, 1, 0);

    QPushButton *button5 = new QPushButton("5");
    connect(button5, &QPushButton::clicked, this, &Window::slot_button5);
    gridLayout->addWidget(button5, 1, 1);

    QPushButton *button6 = new QPushButton("6");
    connect(button6, &QPushButton::clicked, this, &Window::slot_button6);
    gridLayout->addWidget(button6, 1, 2);

    QPushButton *button7 = new QPushButton("7");
    connect(button7, &QPushButton::clicked, this, &Window::slot_button7);
    gridLayout->addWidget(button7, 2, 0);

    QPushButton *button8 = new QPushButton("8");
    connect(button8, &QPushButton::clicked, this, &Window::slot_button8);
    gridLayout->addWidget(button8, 2, 1);

    QPushButton *button9 = new QPushButton("9");
    connect(button9, &QPushButton::clicked, this, &Window::slot_button9);
    gridLayout->addWidget(button9, 2, 2);

    // Disposition des widgets
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(idLineEdit);
    mainLayout->addWidget(passwordLineEdit);
    mainLayout->addWidget(montreMDPCheckBox);
    mainLayout->addWidget(connexionButton);
    mainLayout->addWidget(statusLabel);
    mainLayout->addLayout(gridLayout);

    setLayout(mainLayout);

    // Connexion des signaux
    connect(idLineEdit, &QLineEdit::textChanged, this, &Window::valide);
    connect(passwordLineEdit, &QLineEdit::textChanged, this, &Window::valide);
}

void Window::echoChanged(bool checked)
{
    passwordLineEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
}


void Window::slot_button0()
{
    passwordLineEdit->setText(passwordLineEdit->text() + "0");
}

void Window::slot_button1()
{
    passwordLineEdit->setText(passwordLineEdit->text() + "1");
}

void Window::slot_button2()
{
    passwordLineEdit->setText(passwordLineEdit->text() + "2");
}

void Window::slot_button3()
{
    passwordLineEdit->setText(passwordLineEdit->text() + "3");
}

void Window::slot_button4()
{
    passwordLineEdit->setText(passwordLineEdit->text() + "4");
}

void Window::slot_button5()
{
    passwordLineEdit->setText(passwordLineEdit->text() + "5");
}

void Window::slot_button6()
{
    passwordLineEdit->setText(passwordLineEdit->text() + "6");
}

void Window::slot_button7()
{
    passwordLineEdit->setText(passwordLineEdit->text() + "7");
}

void Window::slot_button8()
{
    passwordLineEdit->setText(passwordLineEdit->text() + "8");
}

void Window::slot_button9()
{
    passwordLineEdit->setText(passwordLineEdit->text() + "9");
}




void Window::valide()
{

    connexionButton->setEnabled(!idLineEdit->text().isEmpty() && !passwordLineEdit->text().isEmpty());
}

void Window::connection()
{
    // Vérification de l'identifiant et du mot de passe
    if (idLineEdit->text() == "SLIM" && passwordLineEdit->text() == "1234") {
        statusLabel->setText("Connexion réussie !");
    } else {
        statusLabel->setText("Identifiant et/ou mot de passe incorrect !");
    }
}
