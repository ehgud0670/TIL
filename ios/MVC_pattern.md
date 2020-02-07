# MVC Pattern - Apple Document 번역 

출처 : <https://developer.apple.com/library/archive/documentation/General/Conceptual/DevPedia-CocoaCore/MVC.html>

## 모델 - 뷰 - 컨트롤러

모델 - 뷰 - 컨트롤러(MVC) 디자인 패턴은 어플리케이션의 객체들에게 세 가지 역할을 할당하는 것입니다: 모델 , 뷰, 컨트롤러. 
이 패턴은 앱 안에 객체들의 역할(M,V,C)을 정의할 뿐만 아니라, **이들이 서로 통신하는 방법도 정의합니다. ( 뷰 <-> 컨트롤러 , 모델 <-> 컨트롤러 )**
객체들의 이 세 가지 타입 각각은 각각은 다른 타입과 추상 경계로 분리되어 있으며, **이 추상 경계를 넘어서 다른 타입의 객체들과 통신**합니다. 
하나의 어플리케이션에서 하나의 특정한 MVC 타입의 객체들의 콜렉션은 때때로 layer로서 언급됩니다. - 예를 들면, model layer

MVC 는 CoCoa 어플리케이션을 위한 좋은 디자인의 중심입니다. 
이 패턴을 적용하는 것의 이점은 매우 많습니다. 이 앱들의 많은 객체들은 더 재사용이 높고, 그들의 인터페이스는 더 잘 정의되는 경향이 있습니다.
MVC 디자인을 가지는 어플리케이션들은 또한 다른 앱들보다 더 쉽게 확장될 수 있습니다.
더욱이, 많은 Cocoa 기술들과 아키텍쳐들은 MVC 패턴을 기반으로 만들어졌고, 당신의 custom 객체들이 MVC 의 세 가지 역할 중 하나를 역할해야 한다고 요구합니다.

=> 기술들과 아키텍쳐까지 MVC 패턴을 기반으로 만들어졌으니 MVC 패턴에 맞게 코드를 짜거라.

## 모델 객체 

모델 객체들은 어플리케이션과 관련된 데이터들을 **캡슐화**합니다. 그리고 **그 데이터를 처리하고 조작하는 논리와 연산을 정의**합니다. ( => 데이터를 캡슐화하는 것에서부터 그 데이터를 처리하고 조작하는 논리와 연산과 관련된 메소드들을 만드는 것까지 다 하는 구나!)
<br> 예를 들어, 모델 객체는 한 게임의 캐릭터를 나타낼 수 있고, 주소록의 한 연락처를 나타낼 수도 있습니다. 
모델 객체는 다른 모델 객체들과 일 대 다 관계를 가질 수도 있는데 그래서 때때로 한 앱의 모델 레이어는 효과적으로 하나이거나 더 많은 객체 그래프일 수 있습니다. ( 하나의 모델 레이어에서 하나의 모델만 있는게 아니라 여러 모델로 그래프화 될 수 있다는 의미 ) 
<br>앱의 지속적 상태(이 지속적 상태가 파일이든 혹은 데이터베이스든)의 부분인 데이터들은 앱 안으로 데이터들이 로드된 이후 모델 객체들 안에 살아야 합니다. ( 파일이든 데이터베이스든 거기에 있는 데이터들이 앱이 켜져서 앱 쪽 메모리로 로드된 이후에 모델 객체에 있어야 한다는 뜻)
왜냐하면 모델 객체는 특정한 문제 도메인과 관련된 지식과 전문 지식을 나타내기 때문에, 그들은 비슷한 문제 도메인에서 재사용될 수 있습니다. **이상적으로** 모델 객체는 데이터를 제공하는 뷰 객체에 **명시적으로 연결되어 있지 않아야 하며** 사용자는 해당 데이터를 편집 할 수 있어야 합니다. 사용자 인터페이스 및 프리젠 테이션 문제와 관련해서는 안됩니다. ( 모델 객체가 뷰 관련 문제와 관련되서는 안된다는 얘기)
## View Objects

A view object is an object in an application that users can see. A view object knows how to draw itself and can respond to user actions. A major purpose of view objects is to display data from the application’s model objects and to enable the editing of that data. Despite this, view objects are typically decoupled from model objects in an MVC application.

Because you typically reuse and reconfigure them, view objects provide consistency between applications. Both the UIKit and AppKit frameworks provide collections of view classes, and Interface Builder offers dozens of view objects in its Library.

Communication: View objects learn about changes in model data through the application’s controller objects and communicate user-initiated changes—for example, text entered in a text field—through controller objects to an application’s model objects.

## Controller Objects

A controller object acts as an intermediary between one or more of an application’s view objects and one or more of its model objects. Controller objects are thus a conduit through which view objects learn about changes in model objects and vice versa. Controller objects can also perform setup and coordinating tasks for an application and manage the life cycles of other objects.

Communication: A controller object interprets user actions made in view objects and communicates new or changed data to the model layer. When model objects change, a controller object communicates that new model data to the view objects so that they can display it.
