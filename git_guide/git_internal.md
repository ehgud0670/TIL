1. echo "hello world"\
  >>README.md
2. git add README.md
3. git commit -m\
  "add README.md file"
4. blob은 파일의 내용을 담고 있는 object.
  blob은 git에서 사용하는 object로 특정 해쉬값을 사용하여 파일들을 구분한다. 
  또 blob의 구성에서 어떠한 변수(시간,파일모드...)도 사용하지 않기에 파일의 내용만 똑같다면 어떠한 파일이름, 어떠한 파일 path이든 전세계 모든 사람의 blob 파일의 이름은 동일하다. 


