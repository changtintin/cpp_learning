<?php
    // connect database
    $link = mysqli_connect("localhost","root","","my_website_db");
    if(!$link) {
        die("Connection failed: " . mysqli_connect_error());
    }

    // add message into database
    if(isset($_POST["msg"])) {
        $msg = ($_POST["msg"])? $_POST["msg"]: "a";
        echo "msg = " . $msg . "<br>";
        $insert = "insert into `message`(`content`) values ('".$msg."')";
        mysqli_query($link, $insert);
    }
?>

<html>
<head>
    <title>範例網頁</title>
</head>
<body>
    <form action="./a_index.php" method="post">
        <input type="text" name="msg" placeholder="message">
        <input type="submit">
    </form>
</body>
</html>