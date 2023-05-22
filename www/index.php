<!DOCTYPE html>
<html lang="fr">

<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Récupération de document</title>
  <link rel="stylesheet" href="Style.css">
</head>

<body>
  <script src="main.js"></script>
  <div class="container">
    <form method="post" action="submit.php" enctype="multipart/form-data" target="_blank">
      <h1 class="main title">PGN to Latex</h1>
      <p style="width:fit-content;">
        Bienvenue sur notre logiciel de génération de PDF dédié aux échecs! 
        Choisissez votre fichier PGN ci-dessous et appuyez sur valider pour générer votre fichier LaTeX ou PDF.
      </p>
      <label class="main" for="pgn_file">Sélectionnez un fichier PGN:</label>

      <label for="pgn_file" class="button" id="content_file">
        Uploader un fichier
      </label>
      <input type="file" name="pgn_file" id="pgn_file" onchange="on_file_select(this)">
      <div class="main">
        <label for="render">Faire le rendu du fichier LaTeX:</label>
        <input type="checkbox" name="render" id="render" checked />
      </div>
      <div class="main">
        <label for="interval">Interval d'affichage du plateau:</label>
        <input type="number" name="interval" id="interval" min="1" max="100" value="5" />
      </div>
      <input type="submit" class="button button__big" value="Télécharger">
    </form>
  </div>
</body>

</html>