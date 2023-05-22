<?php
if (isset($_FILES['pgn_file'])) {
    $file_name = basename($_FILES['pgn_file']['name']);
    $file_extension = pathinfo($file_name, PATHINFO_EXTENSION);

    if ($file_extension !== 'pgn') {
        http_response_code(400);
        die("Le fichier doit avoir une extension .pgn");
    }

    // Description des pipes de processus pour utilisation de proc_open.
    $descriptorspec = array(
        0 => array("pipe", "r"),
        1 => array("pipe", "w"),
    );

    // Récupération du contenu du fichier en mémoire.
    $content = file_get_contents($_FILES['pgn_file']['tmp_name']);
    // Afficher le plateau tout les n coups.
    $interval = intval($_POST['interval'] || "0");
    // Création du processus chess2latex.
    $chess2latex = proc_open("/usr/bin/chess2latex -n $interval", $descriptorspec, $chess2latex_pipes);

    if (!is_resource($chess2latex)) {
        http_response_code(500);
        die("L'exécution du processus chess2latex à échoué.");
    }

    // Ecriture du contenu dans stdin de chess2latex.
    fwrite($chess2latex_pipes[0], $content);
    fclose($chess2latex_pipes[0]);

    // Récupération du contenu du stdout de chess2latex.
    $latex = stream_get_contents($chess2latex_pipes[1]);
    fclose($chess2latex_pipes[1]);

    $chess2latex_return = proc_close($chess2latex);

    if ($chess2latex_return !== 0) {
        http_response_code(500);
        die("L'exécution du processus chess2latex à échoué.");
    }

    $should_render = isset($_POST['render']);

    if ($should_render) {
        // Exécution du processus render_latex.sh
        $render = proc_open("bash /usr/bin/render_latex.sh", $descriptorspec, $render_pipes);
        if (!is_resource($render)) {
            http_response_code(500);
            die("L'exécution du processus de rendu à échoué.");
        }

        fwrite($render_pipes[0], $latex);
        fclose($render_pipes[0]);

        $pdf = stream_get_contents($render_pipes[1]);
        fclose($render_pipes[1]);

        $render_return = proc_close($render);
        if ($render_return !== 0) {
            http_response_code(500);
            die("L'exécution du processus de rendu à échoué.");
        }

        header('Content-Type: application/pdf');
        header("Content-disposition: attachment; filename=\"generated.pdf\"");
        echo $pdf;

    } else {
        header("Content-Type: application/x-latex");
        echo $latex;
    }
}
?>