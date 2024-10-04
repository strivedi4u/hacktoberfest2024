<?php
if(isset($_POST['submit'])) {
    $targetDir = "uploads/";  // Directory to store uploaded images
    $targetFile = $targetDir . basename($_FILES['image']['name']);
    $uploadOk = 1;
    $imageFileType = strtolower(pathinfo($targetFile, PATHINFO_EXTENSION));

    // Check if image file is a actual image or fake image
    if(isset($_POST['submit'])) {
        $check = getimagesize($_FILES['image']['tmp_name']);
        if($check !== false) {
            echo "File is an image - " . $check['mime'] . ".";
            $uploadOk = 1;
        } else {
            echo "File is not an image.";
            $uploadOk = 0;
        }
    }

    // Check if file already exists
    if(file_exists($targetFile)) {
        echo "Sorry, file already exists.";
        $uploadOk = 0;
    }

    // Upload the image
    if($uploadOk == 0) {
        echo "Sorry, your file was not uploaded.";
    } else {
        if(move_uploaded_file($_FILES['image']['tmp_name'], $targetFile)) {
            echo "The file ". basename( $_FILES['image']['name']). " has been uploaded.";
        } else {
            echo "Sorry, there was an error uploading your file.";
        }
    }
}
?>
