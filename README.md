# Système de Suivi Solaire Intelligent (Dual-Axis Solar Tracker)

## 💡 Description du Projet
Ce projet consiste en un prototype de tracker solaire à **double axe (bi-axial)** conçu pour maximiser le rendement énergétique d'un panneau solaire. Le système utilise un algorithme de contrôle en boucle fermée (Closed-Loop Control) pour ajuster sa position en temps réel en fonction de l'intensité lumineuse.

## ⚙️ Composants Matériels
| Composant | Quantité | Rôle |
| :--- | :--- | :--- |
| **Microcontrôleur** | Arduino Nano | Unité de traitement principale. |
| **Capteur de Lumière** | 4 x LDR | Détection de l'erreur d'orientation (Horizontal/Vertical). |
| **Actionneurs** | 2 x Servo Motors | Mouvement bi-axial. |
| **Structure** | Pièces Imprimées en 3D | Support mécanique du panneau et des capteurs. |

## 🧠 Algorithme de Contrôle
L'algorithme est basé sur la comparaison des valeurs analogiques provenant des quatre (4) capteurs LDRs :

1.  **Erreur Horizontale (Pan/Yaw):** `(LDR Top Left + LDR Down Left) - (LDR Top Right + LDR Down Right)`
2.  **Erreur Verticale (Tilt/Pitch):** `(LDR Top Left + LDR Top Right) - (LDR Down Left + LDR Down Right)`

Le système effectue des micro-ajustements tant que la différence (erreur) est supérieure au seuil défini (`THRESHOLD = 10`).

## 🔗 Liens et Preuves
| Type | Lien |
| :--- | :--- |
| **Démonstration Vidéo** | https://drive.google.com/file/d/VIDEO_YOUR_PROJECT |
| **Schéma de Câblage** | https://drive.google.com/file/d/SCHEMATIC_YOUR_PROJECT |
| **Code Source** | Le code est disponible dans le répertoire principal (`Solar_Tracker_Code.ino`). |
