# Chess2Latex (libmatpgn)

Chess2Latex est une implémentation d'un convertisseur de PGN à LaTeX en pur C; Il repose sur libmatpgn présent dans le même dossier.

Le projet est séparé en plusieurs parties:

* libmem - Implémentations de structures de données utilitaires
* libgame - Implémentations de structures du jeu d'échecs.
* libparse - Implémentation du parseur à l'aide de PackCC.
* chess2latex - Implémentation du convertisseur vers LaTeX.
* render_latex.sh - Permet l'utilisation des flux stdin/stdout pour pdflatex.
* www/* - Implémentation de l'interface web en PHP / HTML / CSS / JS.

## Mise en route du projet.

### Utilisation de docker

`docker compose up -d` puis ouvrez `http://localhost:80`;

### Compilation manuelle.

Compilation de chess2latex.
```
mkdir build && cd build
cmake ..
make
```

Puis démarrez un serveurs apache2 ou nginx pouvant exécuter des scripts PHP vers le dossier www du projet.
Le projet sera disponible sur `http://localhost` (ou autre adresse de vôtre serveur web.)
