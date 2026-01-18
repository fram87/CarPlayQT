#include "accueille.h"

// On inclut ce dont on a besoin
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

Accueille::Accueille(QWidget *parent)
    : QWidget(parent)
{
    // ===== TITRE =====
    QLabel *titre = new QLabel("CarPlay");
    titre->setAlignment(Qt::AlignCenter);
    titre->setStyleSheet("font-size: 30px; color: white;");

    // ===== BOUTONS =====
    QPushButton *btnMusique = new QPushButton("🎵\nMusique");
    QPushButton *btnAppels  = new QPushButton("📞\nAppels");
    QPushButton *btnContacts = new QPushButton("👤\nContacts");

    // Style commun aux boutons
    QString style =
        "background-color: #222;"
        "color: white;"
        "font-size: 16px;"
        "border-radius: 15px;";

    btnMusique->setStyleSheet(style);
    btnAppels->setStyleSheet(style);
    btnContacts->setStyleSheet(style);

    btnMusique->setFixedSize(140, 140);
    btnAppels->setFixedSize(140, 140);
    btnContacts->setFixedSize(140, 140);

    // ===== LAYOUT HORIZONTAL (icônes) =====
    QHBoxLayout *layoutBoutons = new QHBoxLayout;
    layoutBoutons->addWidget(btnMusique);
    layoutBoutons->addWidget(btnAppels);
    layoutBoutons->addWidget(btnContacts);
    layoutBoutons->setSpacing(30);

    // ===== LAYOUT PRINCIPAL =====
    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(titre);
    layoutPrincipal->addStretch();
    layoutPrincipal->addLayout(layoutBoutons);
    layoutPrincipal->addStretch();

    setLayout(layoutPrincipal);

    // ===== FOND NOIR =====
    setStyleSheet("background-color: black;");
}
