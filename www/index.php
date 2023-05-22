<!DOCTYPE html>
<html lang="fr">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Récupération de document</title>
    <link rel="stylesheet" href="Style.css">
    <style>
      body {
        background-color: burlywood;
        font-family: Arial, sans-serif;
        font-size: 16px;
        line-height: 1.6;
        color: #333;
      }
      .container {
        max-width: 800px;
        margin: 0 auto;
        padding: 20px;
        background-color: tan ;
        border-radius: 5px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.4);
      }
      h1 {
        font-size: 36px;
        margin-bottom: 20px;
        text-align: center;
      }
      label {
        display: block;
        margin-bottom: 10px;
        font-weight: bold;
      }
      input[type="submit"] {
        background-color: #333;
        color: #fff;
        padding: 10px 20px;
        border: none;
        border-radius: 5px;
        cursor: pointer;
        transition: background-color 0.2s ease-in-out;
      }
      input[type="submit"]:hover {
        background-color: #555;
      }
    </style>
  </head>
  <body>
    <header>
      <h1>PGN to Latex</h1>
    </header>
    <div class="container">
      <h2>Récupération de document</h2>
      <form method="post" enctype="multipart/form-data">
        <label for="document">Type de Format :</label>
        <select id="document" name="document">
          <option value="PGN">PGN</option>
          <option value="PDF">PDF</option>
          <option value="JPEG">JPEG</option>
          <option value="autre">Autre</option>
        </select>
        <br><br>
        <label for="pgn_file">Sélectionnez un fichier PGN:</label>
        <input type="file" name="pgn_file" id="pgn_file">
        <br><br>
        <input type="submit" value="Télécharger">
      </form>
      <?php
      if(isset($_FILES['pgn_file'])) {
          $upload_dir = 'uploads/'; // Le répertoire où le fichier sera téléchargé
          $file_name = basename($_FILES['pgn_file']['name']);
          $file_extension = pathinfo($file_name, PATHINFO_EXTENSION);
          // On vérifie si le fichier a bien une extension .pgn
          if($file_extension != 'pgn') {
              echo "<p>Le fichier doit avoir une extension .pgn</p>";
          } else {
              //Permet d'afficher si oui on non le fichier .pgn à été téléchargé correctement
              $file_path = $upload_dir . $file_name;
              if(move_uploaded_file($_FILES['pgn_file']['tmp_name'], $file_path)) {
                  echo "<p>Le fichier $file_name a été téléchargé avec succès.</p>";
              } else {
                  echo "<p>Une erreur s'est produite lors du téléchargement du fichier PGN.</p>";
              }
          }
      }




