<!DOCTYPE html>
<html>
<head>
	<title>Wen-ting Zhang</title>
	<meta charset="UTF-8">
	<meta content="width=device-width, initial-scale=1" name="viewport">
	<style>
	       * {
	       box-sizing: border-box;
	       }
	       body {
	       font-family: Arial;
	       margin: 0;
	       }
	       .title{
	           padding: 60px;
	           text-align: center;
	           color:rgb(220, 226, 181) ;
	           background: rgb(182, 108, 95);
	           font-weight: bolder;
	           font-family: 'Montserrat';
	       }
	       .navbar {
	       height: 50px;
	       display: flex;
	       background-color: rgb(88, 127, 128);
	       color: rgb(49, 47, 31);
	       }
	       .navbar a { /*navbar link */
	       color: rgb(7, 4, 4);
	       padding: 14px 20px;
	       text-decoration: none;
	       text-align: center;
	       font-family: 'jf-openhuninn-1.1';
	       opacity: 0.5;
	       }
	       .navbar a:hover {
	       height: 50px;
	       background-color: #ddd;
	       color: black;
	       opacity: 1.0;
	       }
	       .flex-container > div {
	       background-color: transparent;
	       width: 80spx;
	       margin:20px;
	       text-align: left;
	       font-size: 20px;
	       font-family: 'jf-openhuninn-1.1';
	       color: rgb(69, 66, 41);
	       }
	       a:link {
	       color: rgb(69, 66, 41);
	       background-color: transparent;
	       text-decoration: none;
	       }
	       a:visited {
	       color: rgb(189, 160, 165);
	       background-color: transparent;
	       text-decoration: none;
	       }
	       a:hover {
	       background-color: rgb(211, 96, 62);
	       font-size: 24px;
	       }
	       a:active {
	       color: rgb(65, 128, 135);
	       background-color: transparent;
	       text-decoration: underline;
	       }
	       .row {  
	       display: flex;
	       flex-wrap: wrap;
	       }
	       .column.middle{
	           width:80%;
	           padding: 20px;
	           font-size: 16px ;
	           color: rgb(69, 66, 41);

	       }
	       .column.side{
	           width:20%;
	           padding: 20px;
	           font-size: 16px ;
	           color: rgb(69, 66, 41);
	           background-color: rgb(132, 146, 187);
	       }
	       .contact.me {
	           border: transparent;
	       }
	       @media screen and (max-width: 700px) {
                .row, .navbar {   
                    flex-direction: column;
                }
                img {
                width: 100%;
                height: auto;
                }
            }
	</style>
</head>
<body background="BeigeWallpaper.jpg">
	<div class="title">
		<h1>張雯婷 WEN-TING ZHANG</h1>
		<h5>1998年生，曾於台灣銀行、文化資產局實習，</h5>
		<p>注重時間管理，喜歡有條不紊的完成工作。</p>
	</div>
	<div class="navbar">
		<a href="#">我的專案</a> <a href="#">相關經歷</a> <a href="#">專長</a> <a href="#">求職條件</a>
	</div>
	<div class="row">
		<div class="column side">
			<h2 style="font-family: 'Montserrat';">外部連結<br>
			External Link</h2>
			<div class="flex-container">
				<div>
					<a href="https://drive.google.com/drive/folders/1NVA1EgtKfbT7siF6udKVsvmiPSxXgw5Z" target="https://drive.google.com/drive/folders/1NVA1EgtKfbT7siF6udKVsvmiPSxXgw5Z">企劃書作品</a>
				</div>
				<div>
					<a href="https://drive.google.com/drive/folders/1Ck0Z4rdf_avROOn-kxEjd5QoKUX1IpVd" target="https://drive.google.com/drive/folders/1Ck0Z4rdf_avROOn-kxEjd5QoKUX1IpVd">簡報作品</a>
				</div>
				<div>
					<a href="https://drive.google.com/drive/folders/1BDlWTubJBAHrM8idRCbmDK4MQmMl_EUq?usp=sharing" target="https://drive.google.com/drive/folders/1BDlWTubJBAHrM8idRCbmDK4MQmMl_EUq?usp=sharing">平面設計作品</a>
				</div>
				<hr style="border-top: 3px;">
				<h2 style="font-family: 'Montserrat';">其他平台</h2>
				<div>
					<a href="https://www.cakeresume.com/tintin-chang" target="https://www.cakeresume.com/tintin-chang">Cake Resume</a>
				</div>
				<div>
					<a href="https://pda.104.com.tw/profile/share/jHJPqMmhHStkJCV49p4eTfYfgiy2ZiRJ" target="https://pda.104.com.tw/profile/share/jHJPqMmhHStkJCV49p4eTfYfgiy2ZiRJ">104人力銀行</a>
				</div>
			</div>
			<div class="contact me">
				<hr style="border-width: 2px;color: wheat;">
				<h2 style="font-family: 'Montserrat';">留言<br>
				Leave your message!</h2><input placeholder="留言" style="border-radius: 4px; background-color: rgb(88, 127, 128);color: wheat;" type="text"><br>
				<p></p><button style="font-family: 'jf-openhuninn-1.1';border: transparent; background-color:rgb(211, 96, 62);color:rgb(220, 226, 181) ;">傳送 Enter</button>
				<hr>
			</div>
		</div>
		<div class="column middle">
			<h1 style="font-family: 'Montserrat';font-weight: bolder">關於我……<br>
			About me……</h1><img alt="yaki photo" src="http://fakeimg.pl/300x300/" width="460">
			<p>畢業於國立台南藝術大學，主修藝術管理。</p>
			<p>在學期間透過課堂報告，培養簡報製作以及條理分明的表達能力，於畢業前獨立完成《我的天空一直晴朗 邱荷恬畢業音樂會》之行政與企劃工作。</p>
			<p>課餘時間喜歡以英文汲取知識，透過閱讀原文小說以及觀賞美劇，考取多益金色證書865分。</p>
			<p>曾到菲律賓英文語言學校體驗當地生活，與不同國籍同學交流，對於從未離開台灣的我而言，第一次可以在日常生活中大量使用英文，也看見同齡的外國人比我們眼界寬廣太多，讓我比以往更加關注國際脈動，付出更多努力精進自我能力。</p>
			<p>大二下學期有幸與教授一同至中國福州與閩江學院進行學術交流，從中獲益良多，激勵自我必須放眼全球，且持續學習。</p>
		</div>
	</div>
</body>
</html>