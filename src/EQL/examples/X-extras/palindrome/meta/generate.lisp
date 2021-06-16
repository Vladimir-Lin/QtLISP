;;;
;;; generate Html5; uses <canvas>, JS
;;;

(defun generate-html (image-count &key (width 450) (resizable t) (pause 1000) (delay 50) (background "black"))
  (let ((width/2 (truncate (+ 0.5 (/ width 2)))))
    (with-open-file (s "html/palindrome.htm" :direction :output :if-exists :supersede)
      (format s "~%<!-- best viewed in full screen mode -->~
                 ~%~
                 ~%<html>~
                 ~%<head></head>~
                 ~%<body style=\"background-color: ~A;\" onload=\"draw()\">"
              background)
      (when resizable
        (format s "~%<input id=\"size\" type=\"text\" value=\"~D\" size=\"3\" onkeyup=\"resize()\">"
                width))
      (format s "~%<div style=\"position: absolute; left: 50%; top: 50%; width: ~D; height: ~D; margin: -~D 0 0 -~D;\">~
                 ~%<canvas id=\"canvas\" width=\"~D\" height=\"~D\"></canvas>~
                 ~%</div>~
                 ~%<script>~
                 ~%~
                 ~%  var images = new Array(~D);~
                 ~%~
                 ~%  for(var n = 0; n < ~D; n++) {~
                 ~%      images[n] = new Image;~
                 ~%      images[n].src = \"img/\" + (n + 1) + \".png\"; }~%"
              width width width/2 width/2
              width width
              image-count
              image-count)
      (with-open-file (in "meta/positions.js" :direction :input)
        (let ((buf (make-string (file-length in))))
          (read-sequence buf in)
          (write-sequence buf s)))
      (format s "~%  var positions = [p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, null];~
                 ~%  var p = positions[0];~
                 ~%  var canvas = document.getElementById(\"canvas\");~
                 ~%  var painter = canvas.getContext(\"2d\");~
                 ~%  var i = 0;~
                 ~%  var j = 0;~
                 ~%~
                 ~%  painter.rect(0, 0, ~D, ~D);~
                 ~%  painter.fillStyle = ~S;~
                 ~%~
                 ~%  function draw() {~
                 ~%      painter.fill();~
                 ~%      for(var n = 0; n < ~D; n++) {~
                 ~%          painter.drawImage(images[n], p[i++], p[i++]); }~
                 ~%      if(p[i] == null) {~
                 ~%          i = 0;~
                 ~%          j++;~
                 ~%          if(positions[j] == null) {~
                 ~%              j = 0; }~
                 ~%          p = positions[j];~
                 ~%          setTimeout(draw, ~D); }~
                 ~%      else {~
                 ~%          setTimeout(draw, ~D); }}~
                 ~%"
              width width
              background
              image-count
              pause
              delay)
      (when resizable
        (format s "~%  var size = document.getElementById(\"size\");~
                   ~%~
                   ~%  function resize() {~
                   ~%      var w = size.value;~
                   ~%      if(w < 1) {~
                   ~%          w = ~D; }~
                   ~%      var x = (~D - w) / 2;~
                   ~%      canvas.style.position = \"absolute\";~
                   ~%      canvas.style.left = x;~
                   ~%      canvas.style.top = x;~
                   ~%      canvas.style.width = w;~
                   ~%      canvas.style.height = w; }~
                   ~%"
                width width))
      (format s "~%</script>~
                 ~%</body>~
                 ~%</html>"))))

