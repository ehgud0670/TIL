# HTTP Cookie : User-Server Interaction

> HTTP는 "stateless" 한 속성을 가진다. 

* By default, HTTP is "stateless", so web servers are “forgetful”
  * server maintains no information about past client requests
    * Cf. protocols that maintain “state” are complex!
      * past history (state) must be maintained
      * if server/client crashes, their views of “state” may be inconsistent, must be reconciled

> HTTP Cookie (by wikipedia)

* a small piece of data sent from a website and stored in a user's web browser while the user is browsing that website 
<br> => 웹 사이트에서 전송되고 사용자가 해당 웹 사이트를 탐색하는 동안 사용자의 웹 브라우저에 저장되는 작은 데이터

* Cookies were designed to be a reliable mechanism for websites
  * to remember stateful information (such as items in a shopping cart)
  * to record the user's browsing activity (including logging in, or recording visited page
history, etc.) 

## HTTP Cookie

* 많은 웹사이트에서 쿠키를 사용한다. 
  * HTTP State Management Mechanism (RFC 2965)
* HTTP 쿠키를 사용하기 위한 4가지 구성요소 
  
  1. HTTP response 메시지의 cookie header line
  ```
  Set-Cookie: <cookie-name>=<cookie-value>
  ``` 
  2. 그 다음 HTTP request 메시지의 cookie header line
  ```
  Cookie: <cookie-name>=<cookie-value> 
  ```
  
  3. 쿠키 파일은 사용자의 브라우저에 의해 관리되고 사용자의 호스트에 보관된다. (cookie file kept on user's host, managed by user's browser)

  4. back-end database at Web site

# Keeping "state"

![http_cookie](https://user-images.githubusercontent.com/38216027/71318771-a5b72300-24d8-11ea-8027-068c7d16178a.png)

## what cookies can be used for : 

* authorization (로그인)
* shopping carts
* recommendations
* user session state (Web e-mail)

## Examples of information not to store in unencrypted cookie : 

* Passwords 
* Credit card numbers
* Social security numbers
* Student ID numbers
* Birthdates
* List of diseases the user has contracted 
* Anything that must be kept secret

## how to keep "state" : 

* protocol endpoints : 여러 transaction을 통해 sender/receiver state를 유지한다. 
  * endpoint : sender , receiver
* cookies : http messages carry state
     
## cookies and privacy : 
  
* cookies permit sites to learn a lot about you
* you may supply name and e-mail to sites  

> 쿠키만 있으면 따로 로그인 안해도 되고 사용자가 한국인이라면 웹페이지가 한국어 버전으로 뜰꺼야 ! 